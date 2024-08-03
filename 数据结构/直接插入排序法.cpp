#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findSmallestK(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    vector<int> result(arr.begin(), arr.begin() + k);
    return result;
}

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }
    int k;
    cin >> k;

    vector<int> smallestK = findSmallestK(arr, k);
    for (int i = 0; i < smallestK.size(); i++) {
        cout << smallestK[i] << " ";
    }

    return 0;
}
