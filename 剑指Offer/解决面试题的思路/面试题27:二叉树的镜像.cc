struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 进行镜像二叉树；
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        TreeNode* tmp;
        if (root==nullptr)
        {
            return nullptr;
        }
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};