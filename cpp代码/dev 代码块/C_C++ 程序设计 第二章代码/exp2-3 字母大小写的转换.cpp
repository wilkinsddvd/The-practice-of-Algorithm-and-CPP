/*exp2-3 ��ĸ��Сд��ת��*/
#include<stdio.h>

int main(){
	char ch1,ch2;
	printf("Input a captital letter:");
	ch1 = getchar();
	// ת��ΪСд��ĸ +32 Сд��ĸ��ASCLL��� ��д��ĸ��ASCLL��С
	ch2 = ch1 + 32;
	printf("ASCLL of %c is %d\n",ch1,ch1);
	printf("ASCLL of %c is %d\n",ch2,ch2);
	return 0; 
}
