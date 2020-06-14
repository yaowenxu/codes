struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 判断一个二叉树是否是对称的；
class Solution {
public:
    bool trace(TreeNode *tl, TreeNode *tr){
        bool res = false;
        if ((tl==nullptr && tr == nullptr))
        {
            res = true;
        }
        if (tl==nullptr || tr == nullptr)
        {
            return res;
        }
        if (tl->val == tr->val)
        {
            res = true;
        }
        res = res && trace(tl->left, tr->right);
        res = res && trace(tl->right, tr->left); // 进行对称遍历；
        return res; // 返回最终结果；
    }
    // 判断树是否是对称的；
    bool isSymmetric(TreeNode* root) {
        return trace(root, root);
    }
};