class Solution {
public:
    void helper(vector<int>& candidates, int target,vector<int>&ds,int idx,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                helper(candidates,target-candidates[i],ds,i+1,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        helper(candidates,target,ds,0,ans);
        return ans;
    }
};