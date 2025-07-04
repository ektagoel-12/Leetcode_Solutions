class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto &itr:strs){
            string temp=itr;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(itr);
        }
        for(auto &x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};