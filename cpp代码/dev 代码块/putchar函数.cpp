#include<stdio.h>

int main(){
	double double_E = 31415.926; 
	string_D = "Hello";
	float float_f = 4.0f;
	char char_c = 's';
	char ch;
	int int_B = -1,int_A = 1;
	ch = getchar();
	putchar(ch);
	printf("\n");
	printf("%e",double_E); // ���ָ����ʽ��ʵ�� ���ֲ���Ĭ��6λС��
	
	printf("\n");
	
	printf("%g",float_f); // ���f��e��ʽ�������Ƚ϶̵�һ�� ������������0 
	
	printf("\n");
	
	printf("%c",char_c);// %c ���һ���ַ�
	
	printf("\n");
	
	printf("%u",int_B);// %u ���ʮ�����޷������� 
	
	printf("\n");
	
	printf("%d %i",int_B,int_A); // %d %i �������������
	
	printf("\n");
	
	printf("%o",int_B);
	
	printf("\n");
	
	printf("%x",int_B); 
	
	printf("\n");
	
	printf("%6.2f %f",float_f,float_f);
	
	printf("%s",string_D);
	return 0;
}
