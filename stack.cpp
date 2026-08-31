------------------------------------------------------------ Valid Paranthesis -----------------------------------------------------------------------------------------------------------
https://neetcode.io/problems/validate-parentheses/question
  
  /*
If there is any opening bracket, will push it into stack else for the closing bracket will check for the open bracket.

Complexity Analysis

Time Complexity: O(n). Single for loop used
Space Complexity: O(N). Stack space
*/

  #include <bits/stdc++.h>
using namespace std;

// Class containing the isValid method
class Solution {
public:
    // Function to check if the input string has valid parentheses
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets

        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);  // Push opening brackets to stack
            else {
                if (st.empty()) return false;  // No matching opening bracket
                char ch = st.top();
                st.pop();

                // Check for matching pair
                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();  // True if all brackets matched
    }
};

int main() {
    Solution sol;
    string s = "()[{}()]";

    if (sol.isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}


---------------------------------------------------------------------minimum-stack------------------------------------------------------------------------------------------
  1. Brute Force Approach 

/*
A stack of pairs is used, where each pair contains the element itself and the minimum element at the time the element was pushed onto the stack.

Complexity Analysis
Time Complexity: O(1) for all operations (push, pop, top, getMin) as they involve constant time operations on the stack.

Space Complexity: O(n) where n is the number of elements in the stack, as we store pairs of values (element and minimum) in the stack.
*/

#include <bits/stdc++.h>
using namespace std;

// Class to implement Minimum Stack
class MinStack {
private:
    // Initialize a stack
    stack <pair<int,int>> st;
    
public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }
        
        // Update the current minimum 
        int mini = min(getMin(), value);
        
        // Add the pair to the stack
        st.push({value, mini});
    }
    
    // Method to pop a value from stack
    void pop() {
        // Using in-built pop method
        st.pop(); 
    }
    
    // Method to get the top of stack
    int top() {
        // Return the top value
        return st.top().first;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return st.top().second;
    }
};

int main() {
    MinStack s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}


2. Optimal approach  :

/*
Use a stack to store elements and maintain a variable to keep track of the current minimum value.

It's optimal approach in such a way like in previous approach we have to store the min element through out the stack, hence the space taken will be O(n) for stack and O(n) for storing that element as well so O(2n)

Here in this we are storing the min in a variable which consist of O(1) space so space is basically O(n) only.


*/

#include <bits/stdc++.h>
using namespace std;

// Class to implement Minimum Stack
class MinStack {
private:
    // Initialize a stack
    stack <int> st;
    // To store the minimum value 
    int mini;
    
public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            //Update the minimum value
            mini = value;
            
            // Push current value as minimum
            st.push( value );
            return;
        }
        
        // If the value is greater than the minimum
        if(value > mini) {
            st.push(value);
        }
        else {
            // Add the modified value to stack : prev min  = 2*min - x
            st.push(2 * value - mini);
            // Update the minimum
            mini = value;
        }
    }
    
    // Method to pop a value from stack
    void pop() {
        // Base case
        if(st.empty()) return;
        
        // Get the top
        int x = st.top();
        st.pop(); // Pop operation
        
        // If the modified value was added to stack
        if(x < mini) {
            // Update the minimum : x = 2*new min-prev min
            mini = 2 * mini - x;
        }
    }
    
    // Method to get the top of stack
    int top() {
        // Base case
        if(st.empty()) return -1;
        
        // Get the top
        int x = st.top();
        
        // Returnn top if minimum is less than the top
        if(mini < x) return x;
        
        //Otherwise return mini
        return mini;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return mini;
    }
};

int main() {
    MinStack s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}


------------------------------------------------------------------ evaluate-reverse-polish-notation ---------------------------------------------------------------------------------
  /*
  T.C : o(N)
  S.C : O(N)
  */

  class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& c : tokens) {
            if (c == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b + a);
            } else if (c == "-") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b - a);
            } else if (c == "*") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b * a);
            } else if (c == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};


----------------------------------------------------------------------- Daily Temperature ----------------------------------------------------------------------------------------------------------
  /*
  https://neetcode.io/problems/daily-temperatures/question

  We have to find the next index which is bigger than the current index -> we keep pushing the index in stack as soon as we get the greater element than stack top element, we just store the top index and pop the 
  top elements and store the difference between the current and top index
  */

  class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
       int n = t.size();
       stack<int>st;
       vector<int>res(n,0);

       for(int i = 0 ; i<t.size() ; i++)
       {
         while(!st.empty() and t[i] > t[st.top()])
         {
            int idx = st.top();
            st.pop();
            res[idx] = i-idx;
         }
         st.push(i);
       }

       return res;
        
    }
};


------------------------------------------------------------------------------- Car Fleet ----------------------------------------------------------------------------------------------------------------

  /*
  https://neetcode.io/problems/car-fleet/question

  We have to think all which car will reach to the destination, at the end we have to calculate time and we have to check if we will choose the car which is taking less time than the most nearest car from the destination
  then will definitely going to bypass the car.

  Here we dont have to bypass so will first sort the cars on the basis of nearest position from the destinations then calculate the time which is taking more time will definetely not bypass.
  
  
  */

  class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n = position.size();
        vector<pair<int, int>>cars;

        for(int i = 0 ; i< n ; i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        stack<double>st;

        for(auto c : cars)
        {
            auto tp = c.first;
            auto ts = c.second;

            double timetaken = (double)(target-tp)/ts;

            if(st.empty() or timetaken > st.top())
            st.push(timetaken);
        }

        return st.size();


        
    }
};


----------------------------------------------------------------------------------- Largest Rectangle in Histogram ------------------------------------------------------------------------------------------------

  /*
  https://neetcode.io/problems/largest-rectangle-in-histogram/question

  1. For each element we have to keep finding the smaller elements from the left and right for the current one if any element in left or right is bigger than current then we have to pop.
  2. Then we have to find the width and then area.
  
  */

  class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {

        int n = heights.size();

        vector<int>left(n);
        vector<int>right(n);

        stack<int>st;

        for(int i = 0 ; i<n ; i++)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            st.pop();

            left[i]=st.empty()?-1:st.top();

            st.push(i);
        }

        while(!st.empty())
        st.pop();

        for(int i = n-1 ; i>=0 ; i--)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            st.pop();

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i = 0 ;i<n ; i++)
        {
            int width = right[i]-left[i]-1;
            ans=max(ans, width*heights[i]);
        }

        return ans;
        
    }
};

