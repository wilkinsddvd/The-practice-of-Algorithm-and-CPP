/*
 * OCI_client - the UXsinoDB interactive terminal
 *
 * client.c
 */
#include "common.h"

extern OCIEnv *envhp;      //环境句柄
extern OCIError *errhp;    //错误句柄
extern OCISvcCtx *svchp;   //上下文句柄
extern OCIStmt *stmthp;    //语句句柄

//清理多余字符
void swallow_char_until(char c)
{
    int count = 0;
    while (getchar() != c)
        count++;

    if (count > 0)
        LOGOCI_WARRING("多余的 %d 个字符将被忽略", count);

    return;
}

//打印使用帮助
void echo_tables()
{
	printf("********************************************\n");
	printf("************ 请选择要操作的表 *************\n");
	printf("********************************************\n");
	printf("选择输入：                                   \n");
	printf("*********** 'a': award_punish *************\n");
	printf("*********** 'c': class *******************\n");
	printf("*********** 'k': course *******************\n");
	printf("*********** 'd': department *************\n");
	printf("*********** 'g': grade *******************\n");
	printf("*********** 'm': major *******************\n");
	printf("*********** 's': student ****************\n");
	printf("*******************************************\n");

    return;
}

//打印使用帮助
void echo_welcome()
{
	printf("********************************************\n");
	printf("*********** 欢迎使用学籍管理系统 ************\n");
	printf("********************************************\n");
	printf("选择输入：                                   \n");
	printf("*********** 'C': 进行创建结构 *************\n");
	printf("*********** 'D': 进行删除结构 *************\n");
	printf("*********** 'c': 进行导入数据 *************\n");
	printf("*********** 'i': 进行插入数据 *************\n");
	printf("*********** 'd': 进行删除数据 *************\n");
	printf("*********** 'u': 进行更新数据 *************\n");
	printf("*********** 's': 进行查询数据 *************\n");
	printf("*********** 'q': 退出管理系统 *************\n");
	printf("*******************************************\n");
	printf("请选择要进行的业务:\n");

    return;
}

//打印查询功能
void echo_select_item()
{
	printf("********************************************\n");
	printf("************** 请选择查询项目 ***************\n");
	printf("********************************************\n");
	printf("选择输入：                                   \n");
	printf("*********** '1': 查询学生基本信息 ************\n");
	printf("*********** '2': 查询学生成绩信息 ************\n");
	printf("*********** '3': 查询学生奖惩信息 ************\n");
	printf("*********** '4': 查询某学生成绩单 ************\n");
	printf("*********** '5': 查询某个具体的表 ************\n");
	printf("********************************************\n");
	printf("请选择要进行的业务:\n");

    return;
}

//选择要操作的表
sword pick_table(text * sql)
{
    char c_switch;
    echo_tables();

	//业务跳转
	c_switch = getchar();

    if (c_switch != '\n')
        swallow_char_until('\n');

	switch (c_switch)
	{
	case 'A':
	case 'a':
		strcat(sql, "award_punish ");
		break;
	case 'C':
	case 'c':
        strcat(sql, "class ");
		break;
	case 'K':
	case 'k':
		strcat(sql, "course ");
		break;
	case 'D':
	case 'd':
        strcat(sql, "department ");
		break;
	case 'G':
	case 'g':
        strcat(sql, "grade ");
		break;
	case 'M':
	case 'm':
        strcat(sql, "major ");
		break;
	case 'S':
	case 's':
        strcat(sql, "student ");
		break;

	default:
        LOGOCI_ERROR("目标表不存在");
		return OCI_ERROR;
	}
    return OCI_SUCCESS;
}

//执行查询
sword exec_select(text* sql)
{
    sb2         sb2aIndid[30];/* 指示器变量，用于取可能存在空值的字 */
    ub2         datalen = 0;/* 数据长度 */
    OCIDefine   *defnp[10] = {0};
    char        col_date[10][30] = {0};
	int         ret = OCI_ERROR;
    int         clo_pos = 0;
    sb4         col_num = 0;
    ub4         size;
    char        *colname = NULL;
    OCIParam    *param;
    ub4         position = 0;

	/*Todo 用适合的变量填空，替换关键词'todo'*/
    ret = simple_execute(sql, OCI_DESCRIBE_ONLY);
    if (OCI_SUCCESS != ret)
    {
        report_error();
        return ret;
    }

    //获取列个数 
    ret = OCIAttrGet((void *)stmthp, OCI_HTYPE_STMT, (void *)&col_num, &size,
                     OCI_ATTR_PARAM_COUNT, errhp);

    //准备语句
    ret = OCIStmtPrepare(stmthp, errhp, (text *)sql, strlen((char*)sql),
                         (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtPrepare");
        return ret;
    }

    while (clo_pos < col_num)
    {
        clo_pos++;
        //绑定输出参数
        ret = OCIDefineByPos(stmthp, &defnp[clo_pos], errhp, clo_pos, col_date[clo_pos],
                (ub4)sizeof(col_date[clo_pos]), SQLT_STR, &sb2aIndid[clo_pos], &datalen, NULL, OCI_DEFAULT);
        if (OCI_SUCCESS != ret)
        {
            LOGOCI_ERROR("%s position:%d", "参数绑定失败", clo_pos);
            report_error();
            return ret;
        }
    }

    //执行SQL
    ret = OCIStmtExecute(svchp, stmthp, errhp, (ub4)1, (ub4)0, (OCISnapshot *)NULL, 
                             (OCISnapshot *)NULL, (ub4)OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtExecute sqlselect");
        report_error();
        return ret;
    }

    //打印结果集表头
    while (position < col_num)
    {
        position++;
        //获取第 n 列的参数 
        ret = OCIParamGet((void *)stmthp, OCI_HTYPE_STMT, errhp, (void **)&param, position);
        //获取列名 
        ret = OCIAttrGet(param, OCI_DTYPE_PARAM, (void *)&colname, &size, OCI_ATTR_NAME, errhp);
        printf("%s\t", colname);
    }
    printf("\n");

    //利用游标提取信息NEXT 
    while (ret = OCIStmtFetch2(stmthp, errhp, 1, OCI_FETCH_NEXT, 0, OCI_DEFAULT) != OCI_NO_DATA)
    {
        clo_pos = 0;
        while (clo_pos < col_num)
        {
            clo_pos++;
            printf("%s\t", col_date[clo_pos]);
        }
        printf("\n");
    }
	
	return ret;
}

//执行查询业务
sword switch_select()
{
	char c_switch;
	int ret = OCI_ERROR;
    char sqlselect[MAX_SQL_LENS] = {0};
    text objptr[128];
    ub4 objp_len = 0;

    strcpy((char*)sqlselect, "SELECT * FROM ");
	echo_select_item();

	//业务跳转
	c_switch = getchar();

    if (c_switch != '\n')
        swallow_char_until('\n');

	switch (c_switch)
	{
	case '1':
        strcat(sqlselect, "a_student");
        exec_select((text*)sqlselect);
		break;

	case '2':
        strcat(sqlselect, "b_grade");
        exec_select((text*)sqlselect);
		break;

	case '3':
        strcat(sqlselect, "c_award_punish");
        exec_select((text*)sqlselect);
		break;

	case '4':
        printf("请输入学生id:\n");
        fgets(objptr, 127, stdin);
        objp_len = (ub4)strlen((char *)objptr);
        if (objp_len > 0 && objptr[objp_len - 1] == '\n')
            objptr[objp_len - 1] = '\0';

        strcat(sqlselect, "pro_grade('");
        strcat(sqlselect, objptr);
        strcat(sqlselect, "')");
        exec_select((text*)sqlselect);
		break;

	case '5':
        ret = pick_table(sqlselect);
        if (OCI_SUCCESS != ret)
            break;

        printf("是否增加筛选条件(Y/N):\n");

        c_switch = getchar();
        if (c_switch != '\n')
            swallow_char_until('\n');

        if (c_switch == 'Y' || c_switch == 'y')
        {
            printf("请输入筛选条件:\n");
            strcat(sqlselect, "WHERE ");

            fgets(objptr, 127, stdin);
            objp_len = (ub4)strlen((char *)objptr);
            if (objp_len > 0 && objptr[objp_len - 1] == '\n')
                objptr[objp_len - 1] = '\0';

            strcat(sqlselect, objptr);
        }

        LOGOCI_NOTICE("%s", sqlselect);
        exec_select((text*)sqlselect);
		break;
	case '6':
        printf("选择查询表:\n");
        ret = pick_table(sqlselect);
        if (OCI_SUCCESS != ret)
            break;
        while (1)
        {
            printf("是否增加查询表(Y/N):\n");
            c_switch = getchar();
            if (c_switch != '\n')
                swallow_char_until('\n');

            if (c_switch == 'Y' || c_switch == 'y')
            {
                strcat(sqlselect, ",");
                printf("请选择查询表");
                ret = pick_table(sqlselect);
                if (OCI_SUCCESS != ret)
                    break;
            }
            if (c_switch == 'N' || c_switch == 'n')
                break;
        }
        printf("请写出筛选条件(多条之间用and连接)\n");
        fgets(objptr, 127, stdin);
        objp_len = (ub4)strlen((char *)objptr);
        if (objp_len > 0 && objptr[objp_len - 1] == '\n')
            objptr[objp_len - 1] = '\0';
        strcat(sqlselect, "WHERE ");
        strcat(sqlselect, objptr);
        LOGOCI_NOTICE("%s", sqlselect);
        exec_select((text *)sqlselect);
        break;
    default:
        LOGOCI_ERROR("非法的输入项");
        return OCI_ERROR;
    }

    return ret;
}

//提交事务
sword CommitOrNot()
{
    char c_switch;
	int ret = OCI_ERROR;

	printf("是否确定提交(Y/N):\n");
    c_switch = getchar();

    if (c_switch == 'Y'|| c_switch == 'y')
    {
        ret = OCITransCommit(svchp, errhp, 0);
        if (OCI_SUCCESS != ret)
        {
        LOGOCI_ERROR("error : OCIStmtPrepare");
        return ret;
        }
        LOGOCI_NOTICE("成功提交");
    }
    else
    {
        LOGOCI_NOTICE("不被提交");
    }

    do{} while (getchar() != '\n');

	return ret;
}

//执行指定DDL
sword exec_DDL()
{
	int ret = OCI_ERROR;
	char sqlddl[MAX_SQL_LENS] = {0};
    text objptr[128];
    ub4 objp_len = 0;
	printf("请输入sql:\n");
    fgets(sqlddl, MAX_SQL_LENS - 1, stdin);
    LOGOCI_NOTICE("%s", sqlddl);
    ret = simple_execute(sqlddl, OCI_DEFAULT);
    ret = OCIStmtPrepare(stmthp, errhp, (text *)sqlddl, (ub4)strlen(sqlddl),
                         (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
    ret = OCIStmtExecute(svchp, stmthp, errhp, (ub4)1, (ub4)0, (OCISnapshot *)NULL,
                         (OCISnapshot *)NULL, (ub4)OCI_DEFAULT);

    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtExecute sqlcopy");
        report_error();
        return ret;
    }

    ret = CommitOrNot();

	return ret;
}

//执行指定drop
sword exec_drop()
{
	int ret = OCI_ERROR;
	/*Todo*/
    char sqldrop[MAX_SQL_LENS] = {0};
    strcpy((char *)sqldrop, "drop table ");
    ret = pick_table(sqldrop);
    strcat(sqldrop, ";");
    LOGOCI_NOTICE("%s", sqldrop);
    ret = OCIStmtPrepare(stmthp, errhp, (text *)sqldrop, (ub4)strlen(sqldrop),
                         (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
    ret = OCIStmtExecute(svchp, stmthp, errhp, (ub4)1, (ub4)0, (OCISnapshot *)NULL,
                         (OCISnapshot *)NULL, (ub4)OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtExecute sqlcopy");
        report_error();
        return ret;
    }
    ret = CommitOrNot();
    return ret;
}

//执行数据导入
sword exec_copy()
{
	int ret = OCI_ERROR;
    char sqlcopy[MAX_SQL_LENS] = {0};
    text objptr[128];
    ub4 objp_len = 0;
    
    strcpy((char *)sqlcopy, "copy ");
    printf("选择要导入的表:\n");
    ret = pick_table(sqlcopy);
    if (OCI_SUCCESS != ret)
    {
        report_error();
        return ret;
    }

    strcat(sqlcopy, "from '");
    printf("请输入导入同名csv文件全路径:\n");
    fgets(objptr, 127, stdin);
    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';
    strcat(sqlcopy, objptr);
    strcat(sqlcopy, "' ");
    strcat(sqlcopy, "csv header;");
    LOGOCI_NOTICE("%s", sqlcopy);
    ret = OCIStmtPrepare(stmthp, errhp, (text *)sqlcopy, (ub4)strlen(sqlcopy),
                         (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
    ret = OCIStmtExecute(svchp, stmthp, errhp, (ub4)1, (ub4)0, (OCISnapshot *)NULL,
                         (OCISnapshot *)NULL, (ub4)OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtExecute sqlcopy");
        report_error();
        return ret;
    }
    ret = CommitOrNot();
	return ret;
}

//执行插入业务
sword exec_insert()
{
	int ret = OCI_ERROR;
	char sqlinsert[MAX_SQL_LENS] = {'\0'};
	char objptr[128] = {'\0'};
    ub4 objp_len = 0;

    strcpy((char*)sqlinsert, "INSERT INTO ");

    ret = pick_table(sqlinsert);
    if (OCI_SUCCESS != ret)
        return ret;

	strcat(sqlinsert, "VALUES ");

	printf("请输入要插入该表的值:\n");

    fgets(objptr, 127, stdin);

    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';

	strcat(sqlinsert, objptr);

    LOGOCI_NOTICE("%s", sqlinsert);

    ret = simple_execute(sqlinsert, OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        report_error();
        return ret;
    }

    ret = CommitOrNot();

	return ret;
}

//执行删除业务
sword exec_delete()
{
	int ret = OCI_ERROR;
	char sqldelete[MAX_SQL_LENS] = {'\0'};
	char objptr[128] = {'\0'};
    ub4 objp_len = 0;
    char c_switch;

    strcpy((char*)sqldelete, "DELETE FROM ");

    ret = pick_table(sqldelete);
    if (OCI_SUCCESS != ret)
        return ret;

	printf("是否增加筛选条件(Y/N):\n");

    c_switch = getchar();
    if (c_switch != '\n')
        swallow_char_until('\n');

    if (c_switch == 'Y' || c_switch == 'y')
    {
        printf("请输入筛选条件:\n");
	    strcat(sqldelete, "WHERE ");

        fgets(objptr, 127, stdin);
        objp_len = (ub4)strlen((char *)objptr);
        if (objp_len > 0 && objptr[objp_len - 1] == '\n')
            objptr[objp_len - 1] = '\0';

	    strcat(sqldelete, objptr);
    }

    LOGOCI_NOTICE("%s", sqldelete);

    ret = simple_execute(sqldelete, OCI_DEFAULT);
    if (OCI_SUCCESS == ret)
        ret = CommitOrNot();
    else if (OCI_NO_DATA == ret)
        LOGOCI_WARRING("删除 0 项");
    else
        report_error();

	return ret;
}

//执行更改业务
sword exec_update()
{
	int ret = OCI_ERROR;
	/*Todo*/
    char sqlup[MAX_SQL_LENS] = {0};
    char objptr[128] = {'\0'};
    ub4 objp_len = 0;

    strcpy((char *)sqlup, "update ");
    printf("选择要更改的表:\n");
    ret = pick_table(sqlup);
    strcat(sqlup, " set ");
    printf("输入要更改的字段:\n");
    fgets(objptr, 127, stdin);
    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';

    strcat(sqlup, objptr);
    strcat(sqlup, " = '");
    printf("输入要更改的值:\n");
    fgets(objptr, 127, stdin);
    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';
    strcat(sqlup, objptr);
    strcat(sqlup, "' where ");
    printf("输入条件:\n");
    fgets(objptr, 127, stdin);
    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';

    strcat(sqlup, objptr);
    strcat(sqlup, ";");
    LOGOCI_NOTICE("%s", sqlup);
    ret = OCIStmtPrepare(stmthp, errhp, (text *)sqlup, (ub4)strlen(sqlup),
                         (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
    ret = OCIStmtExecute(svchp, stmthp, errhp, (ub4)1, (ub4)0, (OCISnapshot *)NULL,
                         (OCISnapshot *)NULL, (ub4)OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtExecute sqlcopy");
        report_error();
        return ret;
    }
    ret = CommitOrNot();


	return ret;
}

//主程序入口
int main()
{
	text *DbName =(text*)"localhost:5432";//数据源名
	text *username = (text *)"uxdb";//用户名
	text *password = (text *)"123456";//口令
	int logged_on = FALSE;
	char c_switch;

	//初始化各种句柄
	if (init_handles() != OCI_SUCCESS)
	{
		printf("FAILED: init_handles()\n");
		return finish_demo(logged_on);
	}
	
	//登录到数据库服务
	if (log_on(username, password, DbName) != OCI_SUCCESS)
	{
		printf("FAILED: log_on()\n");
		return finish_demo(logged_on);
	}	
    else
        logged_on = TRUE;

	//初始语句句柄
	if (OCIHandleAlloc((dvoid *)envhp, (dvoid **)&stmthp,
        (ub4)OCI_HTYPE_STMT, (CONST size_t)0, (dvoid **)0))
	{
		printf("FAILED: alloc statement handle\n");
		return finish_demo(logged_on);
	}

    // 业务跳转
    do
    {
	    //打印欢迎界面
	    echo_welcome();
        c_switch = getchar();

        if (c_switch == '\n')
            continue;
        else
            swallow_char_until('\n');

        switch (c_switch)
        {
        case 'C':
            exec_DDL();
            break;

        case 'D':
            exec_drop();
            break;

        case 'c':
            exec_copy();
            break;

        case 'i':
            exec_insert();
            break;

        case 'd':
            exec_delete();
            break;

        case 'u':
            exec_update();
            break;

        case 's':
            switch_select();
            break;

        case 'q':
            LOGOCI_NOTICE("结束业务");    
            break;

        default:
            LOGOCI_ERROR("错误的输入项");
            break;
        }
    } while (c_switch != 'q');

    //断开连接，清理各种句柄
	return finish_demo(logged_on);
}

