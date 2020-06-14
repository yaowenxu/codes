#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 进行分行打印；
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int linenum = 1; // 表示树的每层的节点数；
        queue<TreeNode*> que; 
        que.push(root);
        int cnt = 0;
        vector<int> tmp;
        int vis = 0;
        while (!que.empty())
        {
            // 进行广度优先遍历；
            TreeNode* p = que.front();
            que.pop();
            cnt++;
            if (p!=nullptr)
            {
                vis++; // 被访问的节点的个数；
                if (cnt <= linenum)
                {
                    tmp.push_back(p->val);
                }
                que.push(p->left);
                que.push(p->right);
            }
            if (cnt==linenum)
            {
                cnt = 0;
                linenum = 2*vis; // 下一层需要计算的节点是上一层访问过的节点的两倍；
                vis = 0;
                vector<int> toswap;
                toswap.swap(tmp);
                if (!toswap.empty())
                {
                    res.push_back(toswap);
                }
            }
        }
        return res;
    }
};