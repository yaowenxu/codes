#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            // 进行广度优先遍历；
            TreeNode* p = que.front();
            que.pop();
            if (p!=nullptr)
            {
                res.push_back(p->val);
                que.push(p->left);
                que.push(p->right);
            }
        }
        return res;
    }
};