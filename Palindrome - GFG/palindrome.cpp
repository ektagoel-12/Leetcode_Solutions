//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		long long int rem=0;
        long long int p=abs(n);
        while(p>0)
        {
            rem=rem*10+p%10;
            p=p/10;
        }
        if(rem==abs(n))
        {
            return "Yes";
        }
        return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends