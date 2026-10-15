#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
            break;
        }
        }
        if (j == -1) return;
    for (int i=j+1;i<nums.size();i++){
        if (nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
    }
};
int main(){
    Solution s;
    vector<int> nums={0,1,0,3,5};
    s.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<"/n";
    }
    return 0;
}
