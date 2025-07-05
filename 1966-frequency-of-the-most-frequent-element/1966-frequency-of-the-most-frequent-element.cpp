class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long left=0,n=nums.size(),ans=0,sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(nums[right]* (right-left+1)> sum+k) sum-=nums[left++];
            ans=max(right-left+1,ans);
        }
        return ans;
    }
};