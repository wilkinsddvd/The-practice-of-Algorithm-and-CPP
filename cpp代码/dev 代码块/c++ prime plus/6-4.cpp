#include<iostream>
using namespace std;

int main(){
	cout << "This program may reformat your hard disk\n" << "abd destroy all your data.\n";
	cout << "Do you wish to continue?<y/n> \n";
	char ch;
	cin >> ch;
	if(ch == 'y' || ch == 'Y'){
		cout << "You ware warned!\a\a\n";
	}else if(ch == 'n' || ch == 'N'){
		cout << "A wish continue ... bye\b";
	}else{
		cout << "That wasn't a y or n! Apparently you ";
		cout << "can't follow\n";
		cout << "instructions, so I'll trash your disk anyway.\a\a\a\n";
	}
	return 0;
}
