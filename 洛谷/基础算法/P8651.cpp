#include <bits/stdc++.h>
using namespace std;

int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};//ÿ������ 

bool isrun(int x){//�ж����� 
	if(x%4) return false;
	else{
		if(x%100) return true;
		else{
			if(x%400) return false;
			else return true;
		}
	}
} 

int a,b,c;

bool isok(int y,int m,int d){//�ж�������� 
	int p=y%100;
	if(p==a && m==b && d==c) return true;
	if(p==c && m==a && d==b) return true;
	if(p==c && m==b && d==a) return true;
	return false;
}

void print(int y,int m,int d){//��� 
	cout<<y<<"-";
	if(m<=9) cout<<"0";
	cout<<m<<"-";
	if(d<=9) cout<<"0";
	cout<<d<<endl;
}

int main(){
	char ch;//�ָ��� 
	cin>>a>>ch>>b>>ch>>c;
    //scanf("%d/%d/%d",&a,&b,&c);
    for(int i=1960; i<=2059; i++){//��
    	if(isrun(i)) d[2]++;//���� 2 ���� 29 �죬����ƽ���� 1 �� 
        for(int j=1; j<=12; j++){//��
            for(int k=1; k<=d[j]; k++){//��
                if(isok(i,j,k)){
                	print(i,j,k);
                	//printf("%d-%02d-%02d\n",i,j,k);
				}
            }
        }
    }
    return 0;
}
