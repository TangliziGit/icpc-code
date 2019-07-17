#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==i) continue;

            if (nums[i]>=nums.size()) nums[i]=-1;
            else if (nums[i]>=0){
                swap(nums[nums[i]], nums[i]);
                i--;
            }
        }

        bool flg=false;
        for (int i=0; i<nums.size(); i++)
            if (nums[i]==-1) return i;
        return nums.size();
    }
};

int main(void){
    int n[9]={9,6,4,2,3,5,7,0,1};
    vector<int> num(n, n+9);
    Solution s;

    cout << s.missingNumber(num) << endl;

    return 0;
}
