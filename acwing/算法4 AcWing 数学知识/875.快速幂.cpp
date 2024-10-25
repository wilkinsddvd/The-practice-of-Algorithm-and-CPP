 #include<bits/stdc++.h> //头文件，包含常用的STL类，如vector、queue等，以及一些常用的函数，如sort、reverse等

using namespace std; //使用std命名空间

typedef long long ll; //给long long类型定义别名为ll 

int q_pow(int a, int b, int p){ //定义快速幂的函数，返回值类型为int，接受3个参数：底数a，指数b，模数p
    int res = 1%p; //结果初始化为1
    while(b){ //当指数b不为0时
        if(b & 1) //判断指数b的二进制位是否为1，如果是，则res乘以底数a取模模数p，否则不操作
            res = (ll)res * a % p;
            b >>=1; //将指数右移1位，相当于除以2
            a = (ll)a*a%p; //将底数a平方取模模数p
    }
    return res; //返回结果
}

int main(){
    int n; //定义一个变量n，表示测试数据组数
    cin>>n; //输入测试数据组数

    while(n--){ //循环执行测试数据的处理
        int a,b,p; //定义变量a、b、p，表示底数、指数、模数
        cin>>a>>b>>p; //输入底数、指数、模数
        cout<<(q_pow(a,b,p))<<endl; //输出快速幂的结果
    }
    return 0; //结束程序
} 
