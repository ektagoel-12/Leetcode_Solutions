# Brute Force
The condition is y*y<=x; We will search from 0,1,2....y and square each value to see if the condition is satisfied.
# Code
```
class Solution {
public:
    int mySqrt(int x) {
        long long y=0;
        while(y*y<=x)
        {
            y++;
        }
        return y-1;
    }
};
```
# Complexity
- Time complexity: O(√x))
- Space complexity: O(1)


# Optimal Approach
<!-- Describe your approach to solving the problem. -->
Instead of checking for all the elements we will use binary search for search . If the square of element is greater than required number than right part is discarded and we will search on left side or vice versa.

# Complexity
- Time complexity: O(log(√x)))
- Space complexity: O(1)

# Code
```
class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=INT_MAX,ans;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(mid*mid<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};
```
