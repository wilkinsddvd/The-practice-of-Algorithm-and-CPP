#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//定义一个结构体Student，包括学生姓名和成绩
struct Student{
	string name;
	int score;
	//默认构造函数
	Student() {}
	//有参构造函数
	Student(string n,int s):name(n),score(s) {}
};

//按照成绩降序排序的比较函数
bool cmp_score(Student x,Student y){
	return x.score > y.score; //如果第一个学生的成绩大于第二个学生，则返回true，否则返回false
}

int main(){
	//定义一个包含三个学生的数组
	Student stu[3];
	string n;
	int s;
	//从标准输入流中输入每个学生的姓名和成绩，并将其存入stu数组中
	for(int i=0;i<3;i++){
		cin>>n>>s;
		stu[i] = Student(n,s);
	}
	
	//使用sort函数按成绩降序排序，参数分别为数组起始地址、数组结束地址、比较函数
	sort(stu,stu+3,cmp_score);
	
	//按照成绩降序输出每个学生的姓名和成绩
	for(int i=0;i<3;i++){
		cout<<stu[i].name<<" "<<stu[i].score<<endl;
	}
	
	return 0;
} 
