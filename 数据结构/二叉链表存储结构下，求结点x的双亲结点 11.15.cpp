#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

bool find_parent(TreeNode* root, char x, char& parent) {
    if (root == NULL) {
        return false;
    }
    if ((root->left != NULL && root->left->val == x) || (root->right != NULL && root->right->val == x)) {
        parent = root->val;
        return true;
    }
    bool found = find_parent(root->left, x, parent);
    if (found) {
        return true;
    }
    found = find_parent(root->right, x, parent);
    return found;
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
    char x;
    cin >> x;
    char parent;
    bool found = find_parent(root, x, parent);
    if (found) {
        cout << parent << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
