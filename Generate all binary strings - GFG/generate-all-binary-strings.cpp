//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generate(string ds,int num)
    {
        if(ds.size()==num)
        {
            cout<<ds<<" ";
            return;
        }
        generate(ds+='0',num);
        ds.pop_back();
        if(ds.size()==0||(ds.size()>0&& ds.back()!='1'))
        {
            generate(ds+'1',num);
            ds.pop_back();
        }
        
    }
    void generateBinaryStrings(int num){
        //Write your code
        string ds="";
        generate(ds,num);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends