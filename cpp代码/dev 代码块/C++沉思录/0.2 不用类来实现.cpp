#include<stdio.h>

void trace(char* s){
	printf("%s\n",s);
}

int main(){
	trace("begin main()\n");
	// main ��������
	trace("end main()\n"); 
}

