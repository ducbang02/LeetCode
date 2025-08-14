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


//Recusion: Time O(n), space O(n)
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return nullptr;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);
    return root;
}

//BFS: Time O(n), space O(n)
TreeNode* invertTreeBFS(TreeNode* root){
    if(!root) return nullptr;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* p = q.front();
        cout<<q.front()->val<<" ";
        q.pop();

        swap(p->left, p->right);

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

//BFS: Time O(n), space O(n)
TreeNode* invertTreeDFS(TreeNode* root) {
    if (root == nullptr) return nullptr;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        // cout << node->val << " ";
        swap(node->left, node->right);

        // Push phải trước để trái được xử lý trước
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return root;
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

    cout << "Duyet cay theo chieu rong: ";
    printBFS(root); // Output mong doi: 1 2 3 4 5 6
    TreeNode* root2 = invertTreeDFS(root);
    printBFS(root2);

    // Giải phóng bộ nhớ (nếu muốn làm gọn hơn thì viết hàm deleteTree)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
