1. Move zeroes :https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      if(nums.size()==0 or nums.size()==1)
        return ;
       int i = 0,j = 0;
        while(j<nums.size()){
            if(nums[j]==0)
                j++;
            else{
                swap(nums[i],nums[j]);
            i++;
                j++;
            }
        }
    }
};
