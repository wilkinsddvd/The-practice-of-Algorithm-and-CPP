#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//����һ���ṹ��Student������ѧ�������ͳɼ�
struct Student{
	string name;
	int score;
	//Ĭ�Ϲ��캯��
	Student() {}
	//�вι��캯��
	Student(string n,int s):name(n),score(s) {}
};

//���ճɼ���������ıȽϺ���
bool cmp_score(Student x,Student y){
	return x.score > y.score; //�����һ��ѧ���ĳɼ����ڵڶ���ѧ�����򷵻�true�����򷵻�false
}

int main(){
	//����һ����������ѧ��������
	Student stu[3];
	string n;
	int s;
	//�ӱ�׼������������ÿ��ѧ���������ͳɼ������������stu������
	for(int i=0;i<3;i++){
		cin>>n>>s;
		stu[i] = Student(n,s);
	}
	
	//ʹ��sort�������ɼ��������򣬲����ֱ�Ϊ������ʼ��ַ�����������ַ���ȽϺ���
	sort(stu,stu+3,cmp_score);
	
	//���ճɼ��������ÿ��ѧ���������ͳɼ�
	for(int i=0;i<3;i++){
		cout<<stu[i].name<<" "<<stu[i].score<<endl;
	}
	
	return 0;
} 
