#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

int calculate_depth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = calculate_depth(root->left);
    int right_depth = calculate_depth(root->right);
    return max(left_depth, right_depth) + 1;
}

TreeNode* build_tree(string& preorder, int& index) {
    if (index == preorder.size()) {
        return NULL;
    }
    char val = preorder[index++];
    if (val == '#') {
        return NULL;
    }
    TreeNode* root = new TreeNode(val);
    root->left = build_tree(preorder, index);
    root->right = build_tree(preorder, index);
    return root;
}

int main() {
    string preorder;
    cin >> preorder;
    int index = 0;
    TreeNode* root = build_tree(preorder, index);
    int depth = calculate_depth(root);
    cout << depth << endl;
    return 0;
}
