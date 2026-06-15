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


------------------------------------------------------------- Subarray Sum Equals K -----------------------------------------------------------------------------------------------------------

    /*
    https://leetcode.com/problems/subarray-sum-equals-k/description/

    Key observations : As we check for the subarray sum, we check for (sum-k) same to count the number uisng map.

    Complexity
Time complexity:
O(n)
Space complexity:
O(n)
    */



    class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {

        unordered_map<int, int>mp;

        mp[0] = 1;
        int sum = 0;
        int count = 0;

        for(auto &n : nums)
        {
            sum += n;

            //count the (sum-k) using map.
           count+= mp[sum-k];


           mp[sum]++; 
        }

        return count;
        
    }
};



----------------------------------- Spiral Matrix --------------------------------------------------------------
    /*
    Revise during the practice : https://leetcode.com/problems/spiral-matrix/description/
    */


    ----------------------------- Rotate Image ---------------------------------------------------
    /*
    https://leetcode.com/problems/rotate-image/
    */


    ------------------------------------------------------- Two Sum ----------------------------------------------------------------------------------------------------
    /*
    https://leetcode.com/problems/two-sum/description/

    Complexity  :

    Time Complexity : O (n)
    Space Complexity : O(n)
    
    */

    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i = 0 ; i<n ; i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                return {i, mp[target-nums[i]]};
            }


            mp[nums[i]] = i;
        }
       
       return {};
        
    }
};


--------------------------------------------------------- Valid Anagram ----------------------------------------------------------------------------------------------
    /*
    https://leetcode.com/problems/valid-anagram/description/

    Complexity Analysis
Time complexity: O(n).
Time complexity is O(n) because accessing the counter table is a constant time operation.

Space complexity: O(1).
Although we do use extra space, the space complexity is O(1) because the table's size stays constant no matter how large n is.
    
    */

    class Solution {
public:
    bool isAnagram(string s, string t) 
    {

        if(s.length() != t.length())
        return false;

        vector<int>freq(26);

        for(int i = 0 ; i<s.length() ; i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(auto x : freq)
        {
            if(x != 0)
            return false;
        }

        return true;
        
    }
};



------------------------------------------------------- Group Anagrams --------------------------------------------------------------------------------------------------------------------
    /*
    https://leetcode.com/problems/group-anagrams/editorial/

    Complexity Analysis

Time Complexity: O(NKlogK), where N is the length of strs, and K is the maximum length of a string in strs. The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(KlogK) time.

Space Complexity: O(NK), the total information content stored in ans.
    */

    class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {

        vector<vector<string>>ans;

        unordered_map<string, vector<string>>mp;

        for(auto x : strs)
        {
            string temp = x;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(x);
        }


        for(auto x : mp)
        {

            ans.push_back(x.second);
        }

        return ans;
        
    }
};


--------------------------------------------------------------------------- Top K Frequent Elements --------------------------------------------------------------------------------------------------------------

    /*
    https://leetcode.com/problems/top-k-frequent-elements/description/

    Complexity Analysis

Time complexity : O(N+Nlogk) if k<N and O(1) in the particular case of N=k. That ensures time complexity to be better than O(NlogN).

Space complexity : O(N+k) to store the hash map with not more N elements and a heap with k elements.
    */

    class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {

        unordered_map<int, int>mp;

        for(auto x : nums)
        {
            mp[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;

        for(auto x : mp)
        {

            pq.push({x.second, x.first});

            if(pq.size()>k)
            pq.pop();
        }

        vector<int>ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        
    }
};

-------------------------------------------------------- Product of Array Except Self -----------------------------------------------------------------------------------------------
    /*
    https://leetcode.com/problems/product-of-array-except-self/description/

    Complexity analysis

Time complexity : O(N) where N represents the number of elements in the input array. We use one iteration to construct the array L, one to update the array answer.
Space complexity : O(1) since don't use any additional array for our computations. The problem statement mentions that using the answer array doesn't add to the space complexity.
    */

    class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // The length of the input array
        int length = nums.size();

        // The answer vector to be returned
        vector<int> answer(length);

        // answer[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the
        // left, so answer[0] would be 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            // answer[i - 1] already contains the product of elements to the
            // left of 'i - 1' Simply multiplying it with nums[i - 1] would give
            // the product of all elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to
        // the right, so R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // For the index 'i', R would contain the
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
        }

        return answer;
    }
};


----------------------------------------------------------------------- longest-consecutive-sequence ------------------------------------------------------------------------------------------------
    /*
    https://leetcode.com/problems/longest-consecutive-sequence/submissions/1920169745/
    
    Complexity Analysis :

    Time : O(n)
    Space : O(n)
    
    */

    class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for (int i=0;i<n;i++){
            int x=nums[i];
            s.insert(x);
        }
        int ans=0;
        for (auto &x:s){
            int len=0;
            if (!s.count(x-1)){
                int y=x;
                while(s.count(y)){
                    len++;
                    y++;
                }
            }
            ans=max(ans,len);
        }
        return ans;
    }
};




    



    
