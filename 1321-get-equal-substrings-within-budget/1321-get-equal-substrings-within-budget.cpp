class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0,r=0,ans=0,sum=0;
        for(r=0;r<s.length();r++){
            sum+= abs(s[r]-t[r]);
            while(sum>maxCost){
                sum-=abs(s[l]- t[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;

    }
};