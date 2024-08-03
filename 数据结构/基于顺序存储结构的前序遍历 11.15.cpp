#include <iostream>
#include <vector>

using namespace std;

void preorderTraversal(vector<char>& tree, int index) {
    if (index >= tree.size() || tree[index] == '#') {
        return;
    }
    
    cout << tree[index] << " ";
    
    preorderTraversal(tree, 2 * index + 1); 
    preorderTraversal(tree, 2 * index + 2); 
}

int main() {
    string input;
    cin >> input;
    
    vector<char> tree;
    for (int i = 0; i < input.size(); i++) {
        tree.push_back(input[i]);
    }
    
    if (tree.empty() || tree[0] == '#') {
        cout << "Empty" << endl;
    } else {
        preorderTraversal(tree, 0);
        cout << endl;
    }
    
    return 0;
}
