#include<stdio.h>

class Trace{
	public:
		void print(char* s){
			printf("%s",s);
		} 
};

int main(){
	Trace t;
	t.print("begin main()\n");
	// main函数的主体
	t.print("end main()\n"); 
} 
