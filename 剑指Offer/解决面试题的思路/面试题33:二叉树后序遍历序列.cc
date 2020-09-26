#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0) {
            return true;
        }
        int right =  postorder.size() - 1;
        int left = 0;
        return check(postorder, left, right); // 进行检查
    }

    bool check(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int last = postorder[right];
        int i = left;
        int middle =  -1;
        for(; i <= right-1; i++){
            if (postorder[i] <= last){
                middle = i;
            }else{
                break;
            }
        }
        for(; i <= right-1; i++){
            if (postorder[i] <= last){
                return false;
            }
        }
        if (middle == -1){
            return check(postorder, left, right-1);
        }
        return check(postorder, left, middle) && check(postorder, middle+1, right-1);
    }
};

int main(){
    vector<int> a = {1,3,2,6,5};
    Solution s;
    cout << s.verifyPostorder(a) << endl;
}