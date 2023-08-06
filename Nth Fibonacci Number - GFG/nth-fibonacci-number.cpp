//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1000000007;
  int recur(int n,vector<int>&dp)
  {
      if(n<=1) return n;
      if(dp[n]!=-1)
      {
          return dp[n];
      }
      else
      return dp[n]=(recur(n-1,dp)+recur(n-2,dp))%mod;
  }
    int nthFibonacci(int n){
        vector<int>dp(n+1,-1);
       return recur(n,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends