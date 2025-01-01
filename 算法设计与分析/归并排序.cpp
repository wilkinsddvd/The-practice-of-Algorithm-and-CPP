#include<bits/stdc++.h>
using namespace std;

// 合并两个有序子数组函数
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1; // 左子数组大小
    int n2 = r - m;     // 右子数组大小

    // 创建临时数组
    vector<int> L(n1), R(n2);

    // 拷贝数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组回原数组
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝L[]的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝R[]的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l是数组有效部分的开始索引
// r是数组有效部分的结束索引
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // 同一组找中间位置
        int m = l + (r - l) / 2;
 
        // 递归地排序两半
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // 合并排序好的两半
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    arr.resize(n); // 初始化数组的大小
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1); // 传递整个数组和索引
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
