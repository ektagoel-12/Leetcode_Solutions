//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int recur(vector<vector<int>>& points, int n,int last,vector<vector<int>>&dp)
    {
        int maxi=0;
        if(n==0) 
        {
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    maxi=max(maxi,points[0][i]);
                }
            }
            return dp[n][last]=maxi;
        }
        if(dp[n][last]!=-1) return dp[n][last];
        int point=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                point=points[n][i]+recur(points,n-1,i,dp);
            }
            maxi=max(maxi,point);
        }
        return dp[n][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return recur(points,n-1,3,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends