#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int verNum, edgeNum;
    cin >> verNum >> edgeNum;

    map<string, int> outDegree; 
    for (int i = 0; i < verNum; i++) {
        string vertex;
        cin >> vertex;
        outDegree[vertex] = 0; 
    }

    for (int i = 0; i < edgeNum; i++) {
        string start, end;
        int weight;
        cin >> start >> end >> weight;
        outDegree[start]++; 
    }

    int zeroDegreeNum = 0;
    for (auto it = outDegree.begin(); it != outDegree.end(); it++) {
        if (it->second == 0) {
            zeroDegreeNum++;
        }
    }

    cout << zeroDegreeNum << endl;

    return 0;
}
