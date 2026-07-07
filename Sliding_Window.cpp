--------------------------------------------------------- Buy and sell stock ---------------------------------------------------------------------------------------------------------
/*
https://neetcode.io/problems/buy-and-sell-crypto/question

1. For maximum profit,we will buy for once, and then keep checking for the minimum values in the whole array and find the max value.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {

     int mina = prices[0];
     int maxa = 0;

     for(int i = 1 ; i<prices.size(); i++)
     {
        if(prices[i]<mina)
        mina = prices[i];

        maxa = max(maxa, prices[i]-mina);

     }

     return maxa;


        
    }
};


------------------------------------------------------------------- longest-substring-without-duplicates ----------------------------------------------------------------------------------------------------

https://neetcode.io/problems/longest-substring-without-duplicates/question

Brute force : 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> charSet;
            for (int j = i; j < s.size(); j++) {
                if (charSet.find(s[j]) != charSet.end()) {
                    break;
                }
                charSet.insert(s[j]);
            }
            res = max(res, (int)charSet.size());
        }
        return res;
    }
};

Time & Space Complexity : 

Time : O(n*m)
Space : O(m)

*********************************************************************************************************************************************************

Sliding Window :

Time & Space Complexity : 

Time: O(n)
Space: O(m) //basically size of the window.

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       int n = s.length();
       unordered_set<int>st;

       int l = 0;
       int res = 0;

       for(int r = 0; r<n ; r++)
       {

         while(st.find(s[r])!=st.end())
         {
         st.erase(s[l]);
         l++;
         }

         st.insert(s[r]);
         res = max(res, r-l+1);

       }

       return res;
    }
};

------------------------------------------------------------------------------- longest-repeating-substring-with-replacement ------------------------------------------------------------------------

https://neetcode.io/problems/longest-repeating-substring-with-replacement/question

1. Main idea here is till how much index we can go along with addtion of k that is the distance (r-l+1) = maxf(maximum repeat character) + k

Time Complextity : O(n)
Space : O(m) , m is total number of unique characters.

class Solution {
public:
    int characterReplacement(string s, int k) 
    {

        int res = 0;
        unordered_map<char,int>mp;

        int l = 0, maxf = 0;

        for(int r = 0 ; r<s.length(); r++)
        {

         //checking for the maximum frequency
           mp[s[r]]++;
           maxf = max(maxf, mp[s[r]]);

           while((r-l+1)-maxf > k)
           {
            mp[s[l]]--;
            l++;
           }

           res = max(res, r-l+1);
        }

        return res;
        
    }
};


----------------------------------------------------------------------- Minimum Window Substring ----------------------------------------------------------------------------------------------------------------------------------------------------
https://takeuforward.org/data-structure/minimum-window-substring
    
1. Brute Force Approach :

/*
To check if a substring is valid, we need to compare the frequency of each character in the substring with the required frequency from the target string. If the current substring satisfies the condition, we update the minimum length and store the substring. After checking all possible substrings, the one with the minimum valid length will be the answer. This approach is inefficient for large strings.
Generate all possible substrings of the source string.
For each substring, count the characters and compare the frequency with that of the target string.
If the substring satisfies the required frequency for all characters, check if its length is smaller than the current minimum.
If yes, update the minimum window and store the current substring as the result.
After all substrings are checked, return the minimum valid substring. If no such substring is found, return an empty string.

Complexity Analysis

Time Complexity: O(n² * m), where n is the length of the source string and m is the length of the target. We examine all possible substrings starting from each index, and for each, we verify whether it contains all target characters, which takes O(m) time.

Space Complexity: O(m), since we use frequency maps to store character counts from the target string and the current window.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if the current window contains all characters of the target
    bool containsAll(unordered_map<char, int>& windowFreq, unordered_map<char, int>& targetFreq) {
        // Loop through each character in the target frequency map
        for (auto& entry : targetFreq) {
            // If current window has less frequency of any character, return false
            if (windowFreq[entry.first] < entry.second) return false;
        }
        // All characters matched
        return true;
    }

    // Function to find the minimum window substring that contains all characters of t
    string minWindow(string s, string t) {
        // Frequency map to count occurrences of characters in target string
        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        // Store the minimum window length found and the resulting substring
        int minLen = INT_MAX;
        string result = "";

        // Loop through all possible starting points in s
        for (int i = 0; i < s.size(); i++) {
            // Frequency map for the current window starting at i
            unordered_map<char, int> windowFreq;

            // Try to expand the window to the right
            for (int j = i; j < s.size(); j++) {
                // Add character to current window frequency
                windowFreq[s[j]]++;

                // Check if this window contains all characters of t
                if (containsAll(windowFreq, targetFreq)) {
                    // If smaller than previous result, update
                    if ((j - i + 1) < minLen) {
                        minLen = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                    break; // No need to expand this window anymore
                }
            }
        }

        // Return the final result substring
        return result;
    }
};

// Driver code
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    // Create an object of Solution class
    Solution sol;

    // Call the method and print result
    cout << sol.minWindow(s, t) << endl;  // Output: "BANC"
    return 0;
}





2. Sliding Window pattern : 

/*
To solve this problem efficiently, we can use the sliding window technique. Instead of checking all substrings , we can maintain a dynamic window that expands to include characters until all required characters from the target are present. Once we have a valid window, we then try to shrink it from the left to find the minimum length window that still satisfies the condition. This way, we avoid unnecessary work and make the algorithm significantly faster than brute force. This is a standard pattern for substring problems involving frequency checks or "contains all" constraints.
Use a frequency map to record the count of each character in the target string.
Track how many characters are still needed using a counter.
Use two pointers (left and right) to define the sliding window over the source string.
Move the right pointer to expand the window and include valid characters.
When all characters are found, move the left pointer to shrink the window and update the minimum result.
Continue this process until the right pointer reaches the end of the string.
Return the smallest valid window found, or an empty string if no such window exists.

Time Complexity: O(n + m), where n is the length of string s and m is the length of string t. We traverse the string s once using the sliding window and use hash maps for constant-time access.

Space Complexity: O(m), where m is the number of unique characters in t. We store frequencies for target characters and the current window.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum window in s that contains all characters of t
    string minWindow(string s, string t) {
        // Frequency map to store required characters from target string
        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        // Total unique characters required to match
        int required = targetFreq.size();

        // Sliding window pointers
        int left = 0, right = 0;

        // Counter to track how many unique characters in window match target
        int formed = 0;

        // Frequency map for characters in the current window
        unordered_map<char, int> windowFreq;

        // Track the minimum window length and its starting index
        int minLen = INT_MAX;
        int minLeft = 0;

        // Expand the window by moving right pointer
        while (right < s.size()) {
            // Add the current character into window
            char c = s[right];
            windowFreq[c]++;

            // If current character is in target and frequency matches, increase formed
            if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Try shrinking the window from the left
            while (left <= right && formed == required) {
                // Update the minimum window if this is smaller
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Remove the left character from window
                char leftChar = s[left];
                windowFreq[leftChar]--;

                // If leftChar is part of target and falls below required count, decrease formed
                if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }

                // Move the left pointer forward
                left++;
            }

            // Expand the window to the right
            right++;
        }

        // Return the minimum window substring, or empty if not found
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

// Driver Code
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout << sol.minWindow(s, t) << endl; // Output: "BANC"
    return 0;
}


-------------------------------------------------------------------------- Sliding window maximum ------------------------------------------------------------------------------------------------------

    https://takeuforward.org/data-structure/sliding-window-maximum

    1. Brute Force Approach
/*
Just run the two loops for k size and keep pushing the maximum elements.
Time Complexity: O(n * k) Each of the (n - k + 1) windows is scanned completely to find its maximum. In worst-case, each window of size k requires O(k) operations.

Space Complexity: O(1) We are only using output list which does not count as extra space in space complexity analysis. No additional data structures used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return max of each sliding window of size k
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Result vector to store maximum of each window
        vector<int> result;

        // Loop through the array till the window can slide
        for (int i = 0; i <= nums.size() - k; i++) {
            // Initialize max element as the first element of the window
            int maxVal = nums[i];

            // Traverse through the current window of size k
            for (int j = i; j < i + k; j++) {
                // Update maxVal if a larger value is found
                maxVal = max(maxVal, nums[j]);
            }

            // Append the max of this window to the result
            result.push_back(maxVal);
        }

        // Return the final result
        return result;
    }
};

// Driver code
int main() {
    Solution obj;

    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(arr, k);

    // Print the result
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}

2. Optimal Solution

/*
The real concern is only when the outgoing element was the maximum. To optimize, we use a double-ended queue (deque) to maintain elements in a way that always keeps track of the current maximum efficiently. 
When a new element enters, we push it to the back of the deque, but before that, we remove all smaller elements from the back since they're not useful anymore. Also, if the element at the front is outside the
window's range, we remove it. This ensures that the element at the front of the deque always represents the maximum of the current window.

Time Complexity: O(n) Each element is pushed and popped from the deque at most once, so overall traversal is linear.

Space Complexity: O(k) Deque stores at most k elements at any time, one for each index in the window.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the max of each sliding window of size k
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque to store indices of useful elements in the current window
        deque<int> dq;

        // Result vector to store the maximums
        vector<int> result;

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from the front if they are out of this window's range
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all elements from the back that are smaller than current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // Once the first window is completed, add front element to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        // Return the final result
        return result;
    }
};

// Driver code
int main() {
    Solution obj;

    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(arr, k);

    // Print the result
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}


