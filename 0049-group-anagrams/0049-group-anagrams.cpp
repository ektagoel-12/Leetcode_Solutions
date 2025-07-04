class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.size()!=t.size()) return false;
        int arr[26]={};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<bool>flag(strs.size(),false);
        for(int i=0;i<strs.size();i++){
            if(flag[i]!=true){
                vector<string>ds;
                ds.push_back(strs[i]);
                for(int j=i+1;j<strs.size();j++){
                    if(isAnagram(strs[i],strs[j])){
                        ds.push_back(strs[j]);
                        flag[j]=true;
                    }
                }
                ans.push_back(ds);
            }
        }
        return ans;
    }
};