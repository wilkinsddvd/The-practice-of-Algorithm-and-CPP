#include<stdio.h>
static int noisy = 1;

void trace(char* s){
	if(noisy)	
		printf("%s\n",s);
}

void trace_on(){
	noisy = 1;
}

void trace_off(){
	noisy = 0;
}

int main(){
	trace("begin main()\n");
	// main ��������
	trace("end main()\n"); 
} 
