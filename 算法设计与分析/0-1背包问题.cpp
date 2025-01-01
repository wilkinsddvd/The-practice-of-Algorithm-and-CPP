#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int dp[MAX];
int w[MAX], v[MAX], choose[MAX][MAX];
struct node{
    int id;
    int weight;
    int value;
}a[MAX];

int main(){
    int N, V;
    cin >> N >> V; 
    
    for(int i = 1; i <= N; i++){
        cin >> a[i].weight >> a[i].value;
        a[i].id = i;
    }
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= V; j++){
            dp[j] = 0;
            choose[i][j] = 0; 
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = V; j >= a[i].weight; j--){
            if(dp[j] < dp[j - a[i].weight] + a[i].value){
                dp[j] = dp[j - a[i].weight] + a[i].value;
                choose[i][j] = 1; 
            }else{
                choose[i][j] = 0; 
            }
        }
    }

    cout << dp[V] << endl;
    

    for(int i = N; i >= 1; i--){
        if(choose[i][V] == 1){
            cout << a[i].id << " ";
            V = V - a[i].weight; 
        }
    }
    
    return 0;
}
// 测试样例
//In: 
//5 10
//2 6
//2 3
//6 5
//5 4
//4 6
//Out: 
//15
//5 2 1 // 被装入背包的物品 
