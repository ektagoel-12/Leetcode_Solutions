//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool recur(int i,int n,vector<int>arr,int k,int sum)
    {
        if(i==n)
        {
            if(sum==k)return true;
            else return false;
        }
        // ds.push_back(arr[i]);
        if(sum>k) return false;
        sum+=arr[i];
        if(recur(i+1,n,arr,k,sum)) return true;
        sum-=arr[i];
        if(recur(i+1,n,arr,k,sum)) return true;
        return false;
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        // vector<int>ds;
        return recur(0,n,arr,k,0);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends