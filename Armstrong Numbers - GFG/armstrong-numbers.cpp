//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int sum=0;
        int r=0;
        int p=n;
        while(n>0)
        {
            r=n%10;
            n=n/10;
            sum=sum+pow(r,3);
            // cout<<sum<<endl;
        }
        if(sum==p){ return "Yes";}
        else
        {
        return "No";}
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends