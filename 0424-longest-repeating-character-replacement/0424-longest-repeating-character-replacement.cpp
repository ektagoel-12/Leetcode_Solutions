class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int left=0,right=0;
        int maxLen=0;
        while(right<s.length()){
            mp[s[right]]++;
            int freq=0;
            for(auto itr:mp){
                freq=max(freq,itr.second);
            }
            if((right-left+1 )- freq<=k){
                maxLen=max(maxLen,right-left+1);
            }
            else{
                while((right-left+1 )- freq>k){
                        mp[s[left]]--;
                        left++;
                }
            }
            right++;
        }
        return maxLen;
    }
};