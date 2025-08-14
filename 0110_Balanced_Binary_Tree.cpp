#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Recursion: Time O(n), space O(n)
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int leftHeigh = maxDepth(root->left);
    int rightHeigh = maxDepth(root->right);
    return 1 + max(leftHeigh, rightHeigh);
}

//Recusion: Time O(n^2), space O(n);
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    
    int rightHeight = maxDepth(root->left) - 1;
    int lefttHeight = maxDepth(root->right) - 1;
    cout<<rightHeight - lefttHeight<<" ";
    if(abs(rightHeight - lefttHeight) > 1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

// Hàm in cây theo chiều rộng (BFS)
void printBFS(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout<<"\n";
}

// Hàm main để thử
int main() {
    /*
            1
          /  \
         2    3
        / \  / \
       4   5 6  7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    root->right->right->right->right = new TreeNode(9);

    cout << "Duyet cay theo chieu rong: ";
    printBFS(root); // Output mong doi: 1 2 3 4 5 6

    cout<<isBalanced(root);

    // Giải phóng bộ nhớ (nếu muốn làm gọn hơn thì viết hàm deleteTree)
    delete root->right->right->right->right;
    delete root->right->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
