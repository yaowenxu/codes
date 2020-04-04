/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 16:57:14
 * LastEditTime: 2020-04-04 19:10:07
 * Description: 使用回溯法，求解矩阵中是否存在某个字符串；
 */
#include <vector>
#include <string>
#include <cstring>
using namespace std; 
class Solution {
public:
    // 判断是否已经找到了字符串
    bool findrest(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, int i, int j){
        int row = board.size(); // 数组的大小；
        int col = board[0].size(); // 找到当前数组的列数；
        char c = word[0];
        string substr = word;
        if(c != board[i][j]){
            return false;
        }
        substr = word.substr(1, word.size()-1); //找到字符串的子串；
        vis[i][j] = true;
        if (substr.size() == 0)
        {
            return true; //说明找到节点；
        }
        // 寻找下一节点；遍历上节点；
        if (i-1 >= 0 && !vis[i-1][j])
        {
            if (findrest(board, vis, substr,i-1, j))
            {
                return true; // 只有有函数范围状态；立刻使用多层return 返回调用栈底；通知调用函数找到符合的解；
            }
        }
        // 寻找下一节点；遍历左节点；
        if (j-1 >= 0 && !vis[i][j-1])
        {
            if (findrest(board, vis, substr,i, j-1))
            {
                return true;
            }
        }
        // 寻找下一节点；遍历下节点；
        if (i+1 < row && !vis[i+1][j])
        {
            if (findrest(board, vis, substr,i+1, j))
            {
                return true;
            }
        }
        // 寻找下一节点；遍历右节点；
        if (j+1 < col && !vis[i][j+1])
        {
            if (findrest(board, vis, substr,i, j+1))
            {
                return true;
            }
        }
        vis[i][j] = false; // 进行状态回溯；
        return false; // 如果上左下右；都找过了，还是没找到的话，就真的没有了；
    }
    // visit 表示一个数组是否被访问过；
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(); // 找到当前数组的大小；
        int col = board[0].size(); // 找到当前数组的列数；
        vector<vector<bool>> visit(row, vector<bool>(col, false)); // 进行初始化数组
        if(word.size() == 0){ // 如果当前字符串长度为0;则提前返回；
            return false;
        }
        // 第一层遍历；判断第一个字母是和矩阵中相等；如果相等在进行遍历；
        // 不然需要两个状态标记；
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (findrest(board, visit, word, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};