Binary Search Template Analysis
Report Issue
 

Template Explanation:

99% of binary search problems that you see online will fall into 1 of these 3 templates. Some problems can be implemented using multiple templates, but as you practice more, you will notice that some templates are more suited for certain problems than others.

Note: The templates and their differences have been colored coded below.



These 3 templates differ by their:

left, mid, right index assignments
loop or recursive termination condition
necessity of post-processing
Templates 1 and 3 are the most commonly used and almost all binary search problems can be easily implemented in one of them. Template 2 is a bit more advanced and used for certain types of problems.

Each of these 3 provided templates provides a specific use case:

 
****************************************************************************************************************************************************************************
Template #1 (left <= right):

Most basic and elementary form of Binary Search
Search Condition can be determined without comparing to the element's neighbors (or use specific elements around it)
No post-processing required because at each step, you are checking to see if the element has been found. If you reach the end, then you know the element is not found

int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}

Distinguishing Syntax:

1. Initial Condition: left = 0, right = length-1
2. Termination: left > right
3. Searching Left: right = mid-1
4. Searching Right: left = mid+1
 
*****************************************************************************************************************************************************************************************************************
Template #2 (left < right):

An advanced way to implement Binary Search.
Search Condition needs to access the element's immediate right neighbor
Use the element's right neighbor to determine if the condition is met and decide whether to go left or right
Guarantees Search Space is at least 2 in size at each step
Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.

 int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left < right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(nums[left] == target) return left;
  return -1;
}

Distinguishing Syntax:

1. Initial Condition: left = 0, right = length - 1
2. Termination: left == right
3. Searching Left: right = mid
4. Searching Right: left = mid+1
 
**************************************************************************************************************************************************************************************************************************************
Template #3 (left + 1 < right):

An alternative way to implement Binary Search
Search Condition needs to access element's immediate left and right neighbors
Use element's neighbors to determine if the condition is met and decide whether to go left or right
Guarantees Search Space is at least 3 in size at each step
Post-processing required. Loop/Recursion ends when you have 2 elements left. Need to assess if the remaining elements meet the condition.

  int binarySearch(vector<int>& nums, int target){
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right){
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}

Distinguishing Syntax:

1. Initial Condition: left = 0, right = length-1
2. Termination: left + 1 == right
3. Searching Left: right = mid
4. Searching Right: left = mid
 
***************************************************************************************************************************************************************************************************************
Time and Space Complexity:

Runtime: O(log n) -- Logarithmic Time

Because Binary Search operates by applying a condition to the value in the middle of our search space and thus cutting the search space in half, in the worse case, we will have to make O(log n) comparisons, where n is the number of elements in our collection.

Why log n?

Binary search is performed by dividing the existing array in half.
So every time you a call the subroutine ( or complete one iteration ) the size reduced to half of the existing part.
First N become N/2, then it become N/4 and go on till it find the element or size become 1.
The maximum no of iterations is log N (base 2).
 

Space: O(1) -- Constant Space

Although Binary Search does require keeping track of 3 indices, the iterative solution does not typically require any other additional space and can be applied directly to the collection itself, therefore warrants O(1) or constant space.










---------------------------------------------------------------------------- Binary Search ------------------------------------------------------------------------------------------------------------------------------
/*
https://neetcode.io/problems/binary-search/question
Time complexity : O(logn)
Space Complexity : O(1)

Here as we have to search for the single element will use the first element here, whenever element will be found it must be the mid value.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {

        int left = 0;
        int right = nums.size()-1;

        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
            return mid;

            else if(nums[mid]<target)
            left = mid+1;

            else
            right = mid-1;
        }

        return -1;
        
    }
};



--------------------------------------------------------------------------------------------- search-2d-matrix ------------------------------------------------------------------------------------------------------------
/*
https://neetcode.io/problems/search-2d-matrix/question

Time Complexity: $O(\log(N \times M)
)$Why: You are treating the 2D matrix as a single, flattened 1D array of size $N \times M$ (where $N$ is the number of rows and $M$ is the number of columns). Because you divide 
the search space in half during every iteration of the while loop, it takes logarithmic time relative to the total number of elements.Note: This can also be written mathematically as $O(\log N + \log M)$.

Space Complexity: $O(1)
$Why: The algorithm only allocates a few integer variables (n, m, left, right, pvtindex, and pvtelement). You are modifying indices to map to the existing matrix rather than creating a
new 1D array in memory. The matrix is passed by reference, so no extra memory is consumed.

1. Here we are taking the 2d matrix as a single matrix hence foundind the mid value by [r/n][c%n] , where n is the number of columns

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        if(left == 0)
        return false;

        int m = matrix[0].size();

        int left = 0;
        int right = n*m -1;

        while(left<=right)
        {
            int pvtindex = (left+right)/2;
            int pvtelement = matrix[pvtindex/m][pvtindex%m];

            if(target == pvtelement)
            return true;

            else if (pvtelement<target)
            left = pvtindex+1;

            else
            right = pvtindex-1;


        }

        return false;
        
    }
};


------------------------------------------------------------------------------------------------------------- Koko Eating Bananas -----------------------------------------------------------------------------------------------------------
/*
https://neetcode.io/problems/eating-bananas/question

Complexity Analysis

Let n be the length of the input array piles and m be the maximum number of bananas in a single pile from piles.

Time complexity: O(n⋅logm)

The initial search space is from 1 to m, it takes logm comparisons to reduce the search space to 1.
For each eating speed middle, we traverse the array and calculate the overall time Koko spends, which takes O(n) for each traversal.
To sum up, the time complexity is O(n⋅logm).
Space complexity: O(1)

For each eating speed middle, we iterate over the array and calculate the total hours Koko spends, which costs constant space.
Therefore, the overall space complexity is O(1).

1. If Koko can eat all the piles with a speed of n, she can also finish the task with the speed of n+1.
With a larger eating speed, Koko will spend less or equal time on every pile. Thus, the overall time is guaranteed to be less than or equal to that of the speed n.

2. If Koko can't finish with a speed of n, then she can't finish with the speed of n−1 either.
With a smaller eating speed, Koko will spend more or equal time on every pile, thus the overall time will be greater than or equal to that of the speed n.


*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        // Initalize the left and right boundaries 
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            // Get the middle index between left and right boundary indexes.
            // hourSpent stands for the total hour Koko spends.
            int middle = (left + right) / 2;
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / middle).
            for (int pile : piles) {
                hourSpent += pile / middle + (pile % middle != 0);
            }

            // Check if middle is a workable speed, and cut the search space by half.
            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the minimum workable eating speed.
        return right;
    }
};
