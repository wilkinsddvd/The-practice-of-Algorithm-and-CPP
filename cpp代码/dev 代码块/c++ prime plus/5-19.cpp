#include<iostream>

using namespace std;

int main(void){
	int ch,count = 0;
	
	while((ch = cin.get()) != EOF){
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " characters read\n";
	return 0;
}
