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

-------------------------------------- Best Time to Buy and Sell Stock -------------------------------------------------------------------------------------------------------------------


    /*
    As we have to find the profit for single day then the price of that day must be smaller price till today or the not then we can check it for selling it.

    Complexity Analysis
Time complexity: O(n). Only a single pass is needed.

Space complexity: O(1). Only two variables are used.
    
    */


    class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};


-------------------------------------------- Two sum ------------------------------------------------------------------------------------------------------------
    /*
   1. Using brute force approach.
   2. Using unordered map (because it takes 0(1) time for the insertion.

   Complexity Analysis

Time complexity: O(n).
We traverse the list containing n elements only once. Each lookup in the table costs only O(1) time.

Space complexity: O(n).
The extra space required depends on the number of items stored in the hash table, which stores at most n elements.
    
    */

    class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};

------------------------------------ Two Sum 2nd ---------------------------------------------------------------------------------------------------------------------------

    /*
    As it is already sorted in increasing order then we will take advantage of this and use the two pointer approach.

    Complexity Analysis

Time complexity: O(n).
The input array is traversed at most once. Thus the time complexity is O(n).

Space complexity: O(1).
We only use additional space to store two indices and the sum, so the space complexity is O(1).
    */

    class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];

            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        // In case there is no solution, return {-1, -1}.
        return {-1, -1};
    }
};


------------------------------------------------------ 3 SUM--------------------------------------------------------------------------------------
    https://leetcode.com/problems/3sum/

    /*
       C++
for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
The condition nums[i] <= 0 is a massive time-saver.

Since the array is sorted, the numbers go from smallest to largest. nums[i] represents the smallest number of your current triplet.

If nums[i] is positive (greater than 0), it is mathematically impossible to find two other numbers to its right that will sum up to 0, because everything to its right is also positive.

Therefore, as soon as nums[i] becomes greater than 0, the loop completely stops, saving unnecessary checks.


Complexity Analysis

Time Complexity: O(n 
2
 ). twoSumII is O(n), and we call it n times.

Sorting the array takes O(nlogn), so overall complexity is O(nlogn+n 
2
 ). This is asymptotically equivalent to O(n 
2
 ).

Space Complexity: from O(logn) to O(n), depending on the implementation of the sorting algorithm. For the purpose of complexity analysis, we ignore the memory required for the output.
    
    */

    class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSumII(nums, i, res);
            }
        return res;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                res.push_back({nums[i], nums[lo++], nums[hi--]});
                while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
            }
        }
    }
};

------------------------------------------ Maximum subarray --------------------------------------------------------------------------------------------------------------------------

    /*
    https://leetcode.com/problems/maximum-subarray/

    Complexity Analysis

Time complexity: O(N), where N is the length of nums.

We iterate through every element of nums exactly once.

Space complexity: O(1)

No matter how long the input is, we are only ever using 2 variables: currentSubarray and maxSubarray.
    
    */


    class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.size(); i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            currentSubarray = max(nums[i], currentSubarray + nums[i]);
            maxSubarray = max(maxSubarray, currentSubarray);
        }
        return maxSubarray;
    }
};



    



    
