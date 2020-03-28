/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-28 22:03:37
 * LastEditTime: 2020-03-29 00:19:32
 * Description: 二叉树结构实现，深度优先搜索实现（递归-非递归），广度优先搜索实现；
 */

#include <iostream>
#include <queue>
#include <stack> // 使用栈来实现深度优先搜索
using namespace std;

struct node {
    int val;
    struct node* left; // 树的左孩子节点
    struct node* right; // 树的右孩子节点
    node(){
        left = nullptr;
        right = nullptr;
    }
};

// 此 标识树的根
struct node* root;

// 广度优先搜索
void BFS(struct node* root){
    queue<struct node*> que;
    que.push(root);
    while (!que.empty())
    {
        struct node *p = que.front();
        cout << p->val << " "; // 弹出元素并访问元素；
        que.pop();
        if (p->left != nullptr){
            que.push(p->left);
        }
        if (p->right != nullptr){
            que.push(p->right);
        }
    }
}

// 深度优先搜索递归实现
void DFS_preorder(struct node* root){
    if(root==nullptr){
        return; // 递归出口
    }
    cout << root->val << " ";
    DFS_preorder(root->left);
    DFS_preorder(root->right);
}

void DFS_inorder(struct node* root){
    if(root==nullptr){
        return; // 递归出口
    }
    DFS_inorder(root->left);
    cout << root->val << " ";
    DFS_inorder(root->right);
}

void DFS_postorder(struct node* root){
    if(root==nullptr){
        return; // 递归出口
    }
    DFS_postorder(root->left);
    DFS_postorder(root->right);
    cout << root->val << " ";
}

void DFS_preorder_stack(struct node* root){
    stack<struct node*>  nodestack;
    while( root!= nullptr || !nodestack.empty()){
        if (root== nullptr){
            root = nodestack.top();
            nodestack.pop();
        }else{
            cout << root->val << " ";
            nodestack.push(root->right);
            root =  root->left;
        }
    }
}

void DFS_inorder_stack(struct node* root){
    stack<struct node*> nodestack;
    while(root != nullptr || !nodestack.empty()){
        if (root ==  nullptr){
            root = nodestack.top();
            cout << root->val << " ";
            nodestack.pop();
            root = root->right;
        }else{
            nodestack.push(root);
            root = root->left;
        }
    }
}

void DFS_postorder_stack(struct node* root){
    stack<struct node*> nodestack;
    struct node* pre =  root;
    while(root != nullptr){
        while (root->left != nullptr)
        {
            nodestack.push(root);
            root = root->left;
        }
        while(root!= nullptr && (root->right == nullptr || root->right == pre)){
            // 当节点没有右孩子或者右孩子被刚刚访问过，则方位该节点；
            cout << root->val << " ";
            pre = root;
            if (nodestack.empty()){
                return;
            }
            root = nodestack.top();
            nodestack.pop();
        }
        nodestack.push(root);
        root = root->right;
    }
}

int main(){
    cout << "二叉树实现：" << endl;
    // 创建一颗完全二叉树；0，1，2，3，4，5，6，7，8，9，
    struct node n0; n0.val = 0;
    struct node n1; n1.val = 1;
    struct node n2; n2.val = 2;
    struct node n3; n3.val = 3;
    struct node n4; n4.val = 4;
    struct node n5; n5.val = 5;
    struct node n6; n6.val = 6;
    struct node n7; n7.val = 7;
    struct node n8; n8.val = 8;
    struct node n9; n9.val = 9;
    root = &n0;
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    n2.left = &n5; n2.right = &n6;
    n3.left = &n7; n3.right = &n8;
    n4.left = &n9;
    BFS(root); // 广度优先搜索；
    cout << endl;
    DFS_preorder(root); // 深度优先搜索，先序遍历递归实现；
    cout << endl;
    DFS_inorder(root); // 深度优先搜索，中序遍历递归实现；
    cout << endl;
    DFS_postorder(root); // 深度优先搜索，后序遍历递归实现；
    cout << endl;
    DFS_preorder_stack(root); // 深度优先搜索先序遍历，栈实现;
    cout << endl;
    DFS_inorder_stack(root); // 深度优先搜索中序遍历，栈实现;
    cout << endl;
    DFS_postorder_stack(root); // 深度优先搜索后序遍历，栈实现；
    cout << endl;
    return 0;
}