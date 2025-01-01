#include<bits/stdc++.h>
using namespace std;

// �ϲ��������������麯��
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1; // ���������С
    int n2 = r - m;     // ���������С

    // ������ʱ����
    vector<int> L(n1), R(n2);

    // �������ݵ���ʱ����
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // �ϲ���ʱ�����ԭ����
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

    // ����L[]��ʣ��Ԫ��
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ����R[]��ʣ��Ԫ��
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l��������Ч���ֵĿ�ʼ����
// r��������Ч���ֵĽ�������
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // ͬһ�����м�λ��
        int m = l + (r - l) / 2;
 
        // �ݹ����������
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // �ϲ�����õ�����
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    arr.resize(n); // ��ʼ������Ĵ�С
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1); // �����������������
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
