/*
 * OCI_client - the UXsinoDB interactive terminal
 *
 * client.c
 */
#include "common.h"

extern OCIEnv *envhp;      //�������
extern OCIError *errhp;    //������
extern OCISvcCtx *svchp;   //�����ľ��
extern OCIStmt *stmthp;    //�����

//��������ַ�
void swallow_char_until(char c)
{
    int count = 0;
    while (getchar() != c)
        count++;

    if (count > 0)
        LOGOCI_WARRING("����� %d ���ַ���������", count);

    return;
}

//��ӡʹ�ð���
void echo_tables()
{
	printf("********************************************\n");
	printf("************ ��ѡ��Ҫ�����ı� *************\n");
	printf("********************************************\n");
	printf("ѡ�����룺                                   \n");
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

//��ӡʹ�ð���
void echo_welcome()
{
	printf("********************************************\n");
	printf("*********** ��ӭʹ��ѧ������ϵͳ ************\n");
	printf("********************************************\n");
	printf("ѡ�����룺                                   \n");
	printf("*********** 'C': ���д����ṹ *************\n");
	printf("*********** 'D': ����ɾ���ṹ *************\n");
	printf("*********** 'c': ���е������� *************\n");
	printf("*********** 'i': ���в������� *************\n");
	printf("*********** 'd': ����ɾ������ *************\n");
	printf("*********** 'u': ���и������� *************\n");
	printf("*********** 's': ���в�ѯ���� *************\n");
	printf("*********** 'q': �˳�����ϵͳ *************\n");
	printf("*******************************************\n");
	printf("��ѡ��Ҫ���е�ҵ��:\n");

    return;
}

//��ӡ��ѯ����
void echo_select_item()
{
	printf("********************************************\n");
	printf("************** ��ѡ���ѯ��Ŀ ***************\n");
	printf("********************************************\n");
	printf("ѡ�����룺                                   \n");
	printf("*********** '1': ��ѯѧ��������Ϣ ************\n");
	printf("*********** '2': ��ѯѧ���ɼ���Ϣ ************\n");
	printf("*********** '3': ��ѯѧ��������Ϣ ************\n");
	printf("*********** '4': ��ѯĳѧ���ɼ��� ************\n");
	printf("*********** '5': ��ѯĳ������ı� ************\n");
	printf("********************************************\n");
	printf("��ѡ��Ҫ���е�ҵ��:\n");

    return;
}

//ѡ��Ҫ�����ı�
sword pick_table(text * sql)
{
    char c_switch;
    echo_tables();

	//ҵ����ת
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
        LOGOCI_ERROR("Ŀ�������");
		return OCI_ERROR;
	}
    return OCI_SUCCESS;
}

//ִ�в�ѯ
sword exec_select(text* sql)
{
    sb2         sb2aIndid[30];/* ָʾ������������ȡ���ܴ��ڿ�ֵ���� */
    ub2         datalen = 0;/* ���ݳ��� */
    OCIDefine   *defnp[10] = {0};
    char        col_date[10][30] = {0};
	int         ret = OCI_ERROR;
    int         clo_pos = 0;
    sb4         col_num = 0;
    ub4         size;
    char        *colname = NULL;
    OCIParam    *param;
    ub4         position = 0;

	/*Todo ���ʺϵı�����գ��滻�ؼ���'todo'*/
    ret = simple_execute(sql, OCI_DESCRIBE_ONLY);
    if (OCI_SUCCESS != ret)
    {
        report_error();
        return ret;
    }

    //��ȡ�и��� 
    ret = OCIAttrGet((void *)stmthp, OCI_HTYPE_STMT, (void *)&col_num, &size,
                     OCI_ATTR_PARAM_COUNT, errhp);

    //׼�����
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
        //���������
        ret = OCIDefineByPos(stmthp, &defnp[clo_pos], errhp, clo_pos, col_date[clo_pos],
                (ub4)sizeof(col_date[clo_pos]), SQLT_STR, &sb2aIndid[clo_pos], &datalen, NULL, OCI_DEFAULT);
        if (OCI_SUCCESS != ret)
        {
            LOGOCI_ERROR("%s position:%d", "������ʧ��", clo_pos);
            report_error();
            return ret;
        }
    }

    //ִ��SQL
    ret = OCIStmtExecute(svchp, stmthp, errhp, (ub4)1, (ub4)0, (OCISnapshot *)NULL, 
                             (OCISnapshot *)NULL, (ub4)OCI_DEFAULT);
    if (OCI_SUCCESS != ret)
    {
        LOGOCI_ERROR("error : OCIStmtExecute sqlselect");
        report_error();
        return ret;
    }

    //��ӡ�������ͷ
    while (position < col_num)
    {
        position++;
        //��ȡ�� n �еĲ��� 
        ret = OCIParamGet((void *)stmthp, OCI_HTYPE_STMT, errhp, (void **)&param, position);
        //��ȡ���� 
        ret = OCIAttrGet(param, OCI_DTYPE_PARAM, (void *)&colname, &size, OCI_ATTR_NAME, errhp);
        printf("%s\t", colname);
    }
    printf("\n");

    //�����α���ȡ��ϢNEXT 
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

//ִ�в�ѯҵ��
sword switch_select()
{
	char c_switch;
	int ret = OCI_ERROR;
    char sqlselect[MAX_SQL_LENS] = {0};
    text objptr[128];
    ub4 objp_len = 0;

    strcpy((char*)sqlselect, "SELECT * FROM ");
	echo_select_item();

	//ҵ����ת
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
        printf("������ѧ��id:\n");
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

        printf("�Ƿ�����ɸѡ����(Y/N):\n");

        c_switch = getchar();
        if (c_switch != '\n')
            swallow_char_until('\n');

        if (c_switch == 'Y' || c_switch == 'y')
        {
            printf("������ɸѡ����:\n");
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
        printf("ѡ���ѯ��:\n");
        ret = pick_table(sqlselect);
        if (OCI_SUCCESS != ret)
            break;
        while (1)
        {
            printf("�Ƿ����Ӳ�ѯ��(Y/N):\n");
            c_switch = getchar();
            if (c_switch != '\n')
                swallow_char_until('\n');

            if (c_switch == 'Y' || c_switch == 'y')
            {
                strcat(sqlselect, ",");
                printf("��ѡ���ѯ��");
                ret = pick_table(sqlselect);
                if (OCI_SUCCESS != ret)
                    break;
            }
            if (c_switch == 'N' || c_switch == 'n')
                break;
        }
        printf("��д��ɸѡ����(����֮����and����)\n");
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
        LOGOCI_ERROR("�Ƿ���������");
        return OCI_ERROR;
    }

    return ret;
}

//�ύ����
sword CommitOrNot()
{
    char c_switch;
	int ret = OCI_ERROR;

	printf("�Ƿ�ȷ���ύ(Y/N):\n");
    c_switch = getchar();

    if (c_switch == 'Y'|| c_switch == 'y')
    {
        ret = OCITransCommit(svchp, errhp, 0);
        if (OCI_SUCCESS != ret)
        {
        LOGOCI_ERROR("error : OCIStmtPrepare");
        return ret;
        }
        LOGOCI_NOTICE("�ɹ��ύ");
    }
    else
    {
        LOGOCI_NOTICE("�����ύ");
    }

    do{} while (getchar() != '\n');

	return ret;
}

//ִ��ָ��DDL
sword exec_DDL()
{
	int ret = OCI_ERROR;
	char sqlddl[MAX_SQL_LENS] = {0};
    text objptr[128];
    ub4 objp_len = 0;
	printf("������sql:\n");
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

//ִ��ָ��drop
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

//ִ�����ݵ���
sword exec_copy()
{
	int ret = OCI_ERROR;
    char sqlcopy[MAX_SQL_LENS] = {0};
    text objptr[128];
    ub4 objp_len = 0;
    
    strcpy((char *)sqlcopy, "copy ");
    printf("ѡ��Ҫ����ı�:\n");
    ret = pick_table(sqlcopy);
    if (OCI_SUCCESS != ret)
    {
        report_error();
        return ret;
    }

    strcat(sqlcopy, "from '");
    printf("�����뵼��ͬ��csv�ļ�ȫ·��:\n");
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

//ִ�в���ҵ��
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

	printf("������Ҫ����ñ��ֵ:\n");

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

//ִ��ɾ��ҵ��
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

	printf("�Ƿ�����ɸѡ����(Y/N):\n");

    c_switch = getchar();
    if (c_switch != '\n')
        swallow_char_until('\n');

    if (c_switch == 'Y' || c_switch == 'y')
    {
        printf("������ɸѡ����:\n");
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
        LOGOCI_WARRING("ɾ�� 0 ��");
    else
        report_error();

	return ret;
}

//ִ�и���ҵ��
sword exec_update()
{
	int ret = OCI_ERROR;
	/*Todo*/
    char sqlup[MAX_SQL_LENS] = {0};
    char objptr[128] = {'\0'};
    ub4 objp_len = 0;

    strcpy((char *)sqlup, "update ");
    printf("ѡ��Ҫ���ĵı�:\n");
    ret = pick_table(sqlup);
    strcat(sqlup, " set ");
    printf("����Ҫ���ĵ��ֶ�:\n");
    fgets(objptr, 127, stdin);
    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';

    strcat(sqlup, objptr);
    strcat(sqlup, " = '");
    printf("����Ҫ���ĵ�ֵ:\n");
    fgets(objptr, 127, stdin);
    objp_len = (ub4)strlen((char *)objptr);
    if (objp_len > 0 && objptr[objp_len - 1] == '\n')
        objptr[objp_len - 1] = '\0';
    strcat(sqlup, objptr);
    strcat(sqlup, "' where ");
    printf("��������:\n");
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

//���������
int main()
{
	text *DbName =(text*)"localhost:5432";//����Դ��
	text *username = (text *)"uxdb";//�û���
	text *password = (text *)"123456";//����
	int logged_on = FALSE;
	char c_switch;

	//��ʼ�����־��
	if (init_handles() != OCI_SUCCESS)
	{
		printf("FAILED: init_handles()\n");
		return finish_demo(logged_on);
	}
	
	//��¼�����ݿ����
	if (log_on(username, password, DbName) != OCI_SUCCESS)
	{
		printf("FAILED: log_on()\n");
		return finish_demo(logged_on);
	}	
    else
        logged_on = TRUE;

	//��ʼ�����
	if (OCIHandleAlloc((dvoid *)envhp, (dvoid **)&stmthp,
        (ub4)OCI_HTYPE_STMT, (CONST size_t)0, (dvoid **)0))
	{
		printf("FAILED: alloc statement handle\n");
		return finish_demo(logged_on);
	}

    // ҵ����ת
    do
    {
	    //��ӡ��ӭ����
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
            LOGOCI_NOTICE("����ҵ��");    
            break;

        default:
            LOGOCI_ERROR("�����������");
            break;
        }
    } while (c_switch != 'q');

    //�Ͽ����ӣ�������־��
	return finish_demo(logged_on);
}

