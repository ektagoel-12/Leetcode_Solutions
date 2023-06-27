//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int arrSum(vector<int>arr)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
    void recurSum(vector<int>arr,int N,vector<int>&ans,vector<int>ds,int idx)
    {
        if(idx>=N)
        {
            ans.push_back(arrSum(ds));
            return;
        }
        ds.push_back(arr[idx]);
        recurSum(arr,N,ans,ds,idx+1);
        ds.pop_back();
        recurSum(arr,N,ans,ds,idx+1);                 
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        vector<int>ds;
        recurSum(arr,N,ans,ds,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends