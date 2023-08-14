//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool recur(vector<int>arr,int sum,int idx,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(idx==0) return (arr[0]==sum);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool not_take=recur(arr,sum,idx-1,dp);
        bool take=false;
        if(sum>=arr[idx])
        {
            take=recur(arr,sum-arr[idx],idx-1,dp);
        }
        return dp[idx][sum]=take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return recur(arr,sum,arr.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends