class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int l=0,r=0,ans=0,prod=1;
        for(r=0;r<nums.size();r++){
            prod*=nums[r];
            while(l<=r && prod>=k){
                prod/=nums[l++];
            }
                ans+=r-l+1;
        }
        return ans;
    }
};