/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-29 11:46:51
 * LastEditTime: 2019-08-29 11:48:20
 * Description: 合并二叉树
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
  
class Solution {
public:
    void trace(TreeNode* t1, TreeNode* t2){
        if(t1==nullptr && t2 == nullptr){
            return;
        }
        if(t1!=nullptr && t2 == nullptr){
            return;
        }
        if(t1!=nullptr && t2 != nullptr){
            t1->val =  t1->val + t2->val;
            if(t1->left == nullptr && t2->left != nullptr){
                t1->left = t2->left;
                t2->left = nullptr;
            }
            if(t1->right == nullptr && t2->right != nullptr){
                t1->right =  t2->right;
                t2->right = nullptr;
            }
        }
        trace(t1->left, t2->left); // 使用递归实现的深度优先搜索
        trace(t1->right, t2->right);
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr && t2!=nullptr){
            return t2;
        }
        trace(t1, t2);
        return t1;
    }
};