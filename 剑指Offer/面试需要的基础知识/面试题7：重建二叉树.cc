/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-03 11:50:41
 * LastEditTime: 2020-04-03 12:12:14
 * Description: 根据前序遍历和中序遍历，构建二叉树；
 */
#include <vector>
using namespace std;

// 二叉树节点结构，用于恢复二叉树；
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 注意递归函数主体，递归函数参数和递归程序出口的选择；
class Solution {
public:
    TreeNode* construct(vector<int>& pre, int prel, int prer,vector<int> &in, int inl, int inr){
        if (prer < prel) // 递归出口；
        {
            return nullptr;
        }
        int root = pre[prel]; //中序遍历第一个节点
        TreeNode *p = new TreeNode(root);
        // 寻找中序遍历节点的根节点
        int cnt = 0;
        for (int i = inl; i <= inr; i++)
        {
            if (in[i] == root)
            {
                break;
            }
            cnt++;
        }
        // 构建左树节点；
        TreeNode* left = construct(pre, prel+1, prel+cnt, in, inl, inl+cnt-1);
        //  构建右树节点；
        TreeNode* right = construct(pre, prel+cnt+1, prer, in, inl+cnt+1, inr);
        p->left = left;
        p->right = right;
        return p;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1); //构建二叉树
    }
};