#include <iostream>
#include <string>
using namespace std;
int bs(string s, string t) {
	int i = 0, j = 0;
	int count = 0;
	while (s[i] != '\0') {//������Ϊ������Ϊ�㣬��һֱ����ƥ��ֱ��������ͷ��
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
		if (t[j] == '\0') {
			count++;
			//i++;���������ģʽ��ͷ��������û�е�ͷ�������ִ��ѭ��
			//������i+���������Ծ
			j = 0;
		}
	}
	if (s[i] == '\0') return count;
	else return 0;
}
int main()
{
	string s;
	string t;
	int n;
	getline(cin, s);
	getline(cin, t);
	cout << bs(s, t);
}
