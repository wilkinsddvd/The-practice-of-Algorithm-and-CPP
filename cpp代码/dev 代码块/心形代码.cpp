#include<stdio.h>

int main(){
	int i,j;
	printf(
		"     ******       ******\n"
		"   *********     *********\n"
		"*************   ************\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<29;j++)
			printf("*");
		printf("\n");
	}	
	for(int i=0;i<7;i++){
		for(j=0;j<2*(i+1)-1;j++)
			printf(" ");
		for(j=0;j<27-i*4;j++)
			printf("*");
		printf("\n");
	}
	for(int i=0;i<14;i++){
		printf(" ");
	}
	printf("*\n");
	return 0;
} 
