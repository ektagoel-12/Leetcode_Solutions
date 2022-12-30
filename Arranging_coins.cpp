# Brute Force
We will search from 0,1,2....n each representing the row. If the row number is less or equal to the number of coins then the row will be incremented and we will subtract the required coins from the total number of coins. This will stop when the row number will become greater than avaible number of coins.
# Code
```
class Solution {
public:
    int arrangeCoins(int n) {
        int rows=0;
        int i=1;
        while(i<=n)
        {
            n-=i;
            rows++;
            i++;
        }
        return rows;
    }
};
```
# Complexity
- Time complexity: O(n))
- Space complexity: O(1)


# Optimal Approach
<!-- Describe your approach to solving the problem. -->
Instead of checking for all the numbers upto n, we will use binary search. At each iteration, we will find the total number of coins that are needed upto that row. For eg:Upto 4th row total number of coins required are`1+2+3+4` which can be calculated from the formula `n(n+1)/2 = 4(4+1)/2`.It that sum is equal to number of coins then return the number else if that is greater than coins then right part is discarded and we will search on left side and vice versa.

# Complexity
- Time complexity: O(log(n)))
- Space complexity: O(1)

# Code
```
class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        int low=0,high=n;
        while(low<=high)
        {
            long long  mid=low+(high-low)/2;
            long long  x=( mid *(mid+1) ) / 2;
            if(x==n) return mid;
            else if(x>n)
            {
                high=mid-1;
            }
            else 
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};
```
