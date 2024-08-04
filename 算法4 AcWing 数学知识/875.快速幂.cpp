 #include<bits/stdc++.h> //ͷ�ļ����������õ�STL�࣬��vector��queue�ȣ��Լ�һЩ���õĺ�������sort��reverse��

using namespace std; //ʹ��std�����ռ�

typedef long long ll; //��long long���Ͷ������Ϊll 

int q_pow(int a, int b, int p){ //��������ݵĺ���������ֵ����Ϊint������3������������a��ָ��b��ģ��p
    int res = 1%p; //�����ʼ��Ϊ1
    while(b){ //��ָ��b��Ϊ0ʱ
        if(b & 1) //�ж�ָ��b�Ķ�����λ�Ƿ�Ϊ1������ǣ���res���Ե���aȡģģ��p�����򲻲���
            res = (ll)res * a % p;
            b >>=1; //��ָ������1λ���൱�ڳ���2
            a = (ll)a*a%p; //������aƽ��ȡģģ��p
    }
    return res; //���ؽ��
}

int main(){
    int n; //����һ������n����ʾ������������
    cin>>n; //���������������

    while(n--){ //ѭ��ִ�в������ݵĴ���
        int a,b,p; //�������a��b��p����ʾ������ָ����ģ��
        cin>>a>>b>>p; //���������ָ����ģ��
        cout<<(q_pow(a,b,p))<<endl; //��������ݵĽ��
    }
    return 0; //��������
} 
