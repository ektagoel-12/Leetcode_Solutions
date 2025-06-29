class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds,int idx){
        if(idx>=nums.size()) {ans.push_back(ds); return;}
        ds.push_back(nums[idx]);
        helper(nums,ans,ds,idx+1);
        ds.pop_back();
        helper(nums,ans,ds,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(nums,ans,ds,0);
        return ans;
    }
};