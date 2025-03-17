#include<stdio.h> 
#include<string.h>

typedef struct{
	char num[20];
	char name[20];
	char stuclass[20];
	float math;
	float english;
	float cyuyan;
}student;

student stu[1000];
int stu_number = 0;

void inputdata(student dat[]){
	printf("����ѧ��ѧ��:");
	scanf("%s",&dat[stu_number].num);
	printf("����ѧ������:");
	scanf("%s",&dat[stu_number].name);
	printf("����ѧ���༶:");
	scanf("%s",&dat[stu_number].stuclass);
	printf("����ѧ����ѧ�ɼ�:");
	scanf("%f",&dat[stu_number].math);
	printf("����ѧ��Ӣ��ɼ�:");
	scanf("%f",&dat[stu_number].english);
	printf("����ѧ��C���Գɼ�:");
	scanf("%f",&dat[stu_number].cyuyan);	  
	stu_number++;
	printf("¼��ɹ�!\n\n"); 
}

void show_student(student dat[]){
	for(int i=0;i<stu_number;i++){
		printf("\n");
		printf("ѧ��: %s\n",dat[i].num);
		printf("����: %s\n",dat[i].name);
		printf("�༶: %s\n",dat[i].stuclass);
		printf("��ѧ: %.2f\n",dat[i].math);
		printf("Ӣ��: %.2f\n",dat[i].english);
		printf("C����: %.2f\n\n",dat[i].cyuyan);
	}
}

void research(student dat[]){
	char stud[20] = {0};
	printf("����ѧ������:");
	scanf("%s",&stud);
	for(int i=0;i<stu_number;i++){
		if(strcmp(dat[i].name,stud)== 0){
			printf("\n");
			printf("ѧ��: %s\n",dat[i].num);
			printf("����: %s\n",dat[i].name);
			printf("�༶: %s\n",dat[i].stuclass);
			printf("��ѧ: %.2f\n",dat[i].math);
			printf("Ӣ��: %.2f\n",dat[i].english);
			printf("C����: %.2f\n\n",dat[i].cyuyan);
			return ;	
		}

	}
	printf("δ�ҵ�ѧ��\n");
}

void delete_stu(student dat[]){
	char stud[20] = {0};
	printf("����Ҫɾ����ѧ��ѧ��");
	scanf("%s",&stud);
	for(int i=0;i<stu_number;i++){
		if(strcmp(dat[i].num,stud)== 0){
			for(int t=i;i<stu_number-1;t++){
				dat[t] = dat[t+1];
			}
			stu_number--;
			return ;	
		}

	}
	printf("ɾ���ɹ�\n");
}

	
void xiugai(student dat[]){
	char stud[20] = {0};
	printf("����Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s",&stud);
	for(int i=0;i<stu_number;i++){
		if(strcmp(dat[i].num,stud)== 0){
		printf("����ѧ��ѧ��:");
		scanf("%s",&dat[i].num);
		printf("����ѧ������:");
		scanf("%s",&dat[i].name);
		printf("����ѧ���༶:");
		scanf("%s",&dat[i].stuclass);
		printf("����ѧ����ѧ�ɼ�:");
		scanf("%f",&dat[i].math);
		printf("����ѧ��Ӣ��ɼ�:");
		scanf("%f",&dat[i].english);
		printf("����ѧ��C���Գɼ�:");
		scanf("%f",&dat[i].cyuyan);	  
		stu_number++;
		printf("¼��ɹ�!\n\n"); 
			return ;	
		}

	}
	printf("�޸ĳɹ�\n");
}


int main(){
	int chose = 0;
	printf("          ѧ������ϵͳ\n");
	while(1){
		printf("1.¼��ѧ����Ϣ\n");
		printf("2.��ʾ����ѧ����Ϣ\n");	
		printf("3.����ѧ����Ϣ\n");
		printf("4.ɾ��ѧ����Ϣ\n");
		printf("5.�޸�ѧ����Ϣ\n");
		printf("6.�˳�ϵͳ\n");
		printf("������ָ��:\n");
		scanf("%d",&chose);
		switch(chose){
			case 1: inputdata(stu);	break;
			case 2: show_student(stu);break;
			case 3: research(stu);break;
			case 4: delete_stu(stu);break;
			case 5: xiugai(stu);break;
			case 6: printf("����ָ��"); return 0; break;
		}		
	} 

}
