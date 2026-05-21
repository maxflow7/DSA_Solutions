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



****************** square of sorted array **********************************************
    https://leetcode.com/problems/squares-of-a-sorted-array/\
/*
1. As we have to sort the square array in descending order, we have to check for the abs value of left and right index.
2. Then accordingly for which the value is greater, we have to udpate the array accordingly.
3. It's good to start from the end of index, as the array is already in ascending order.

*/
    

    class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
       int n = nums.size();

       int left = 0;
       int right = n-1;

       vector<int>ans(n);

       for(int i = n-1; i>=0 ; i--)
       {

        int square = 0;

        if(abs(nums[left]) < abs(nums[right]))
        {
            square = nums[right];
            right--;
        }
        else
        {
            square =nums[left];
            left++;
        }

        ans[i] = square*square;

       }

       return ans;
    }
};


********************** Majority Element **************************************
/*

https://leetcode.com/problems/majority-element/editorial/

1. One way -> we can just sort the array and the middle element will return the majority element.

Time complexity : 0(nlogn)
Space Complexity : O(1)

2. Use Boyer Moore Majority Element  :

The algorithm is based on the idea that if an element occurs more than N/2 times, then all the remaining elements
together must occur less than N/2 times.

Time Complexity : O(n)
Space Complexity : O(1)
    */

    ----------------------------- Sorting -----------------------------------------------------------------
    class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

--------------------Boyer Moore Majority Voting Algorithm-------------------------------------------------------

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};



    
