// 判断树的子结构 
struct TreeNode { 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 要进行两次遍历来进行计算最终的结果值；
class Solution {
public:
    // 匹配树；要以B树为模板
    bool matchABtree(TreeNode* A, TreeNode* B){
        bool res = false;
        if (A == nullptr)
        {
            return res;
        }
        if (A->val == B->val) // 利用短路计算；
        {
            res =  true;
        }
        if (B->left!=nullptr)
        {
            res = res && matchABtree(A->left, B->left); // 进行匹配左树
        }
        if (B->right!=nullptr){
            res = res && matchABtree(A->right, B->right); // 进行匹配右树
        }
        // 返回最终结果；
        return res;
    }
    // 递归遍历树；
    bool searchBrootINAtree(TreeNode* A, TreeNode* B){
        bool res = false;
        if (A == nullptr)
        {
            return false;
        }
        if (A->val == B->val)
        {
            res = matchABtree(A, B); // 进行匹配树；
        }
        res = res || searchBrootINAtree(A->left, B);
        res = res || searchBrootINAtree(A->right, B);
        return res; // 返回最后的结果；
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A==nullptr || B == nullptr)
        {
            return false;
        }
        return searchBrootINAtree(A, B); // 在A树中搜索B树；
    }
};