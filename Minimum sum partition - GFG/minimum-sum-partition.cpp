//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	     int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
         vector<bool>prev(sum+1,0),curr(sum+1,0);
        prev[0]=true,curr[0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool not_take=prev[target];
                bool take=false;
                if(target>=arr[ind])
                {
                    take=prev[target-arr[ind]];
                }
                curr[target]=take || not_take;
            }
            prev=curr;
        }
        for(int i=0;i<=sum;i++)
        {
            if(prev[i]==true)
            {
                int s2=sum-i;
                mini=min(mini,abs(i-s2));
            }
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends