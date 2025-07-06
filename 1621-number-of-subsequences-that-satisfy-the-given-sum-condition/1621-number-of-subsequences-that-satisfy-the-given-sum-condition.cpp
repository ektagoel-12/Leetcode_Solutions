class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,n=nums.size(),res=0,mod=1e9+7;
        int r=n-1;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2) % mod;
        }
        while(l<=r){
            if(nums[r]+nums[l]<=target){
                res=(res+ power[r-l]) % mod;
                l++;
            }
            else r--;
        }
        return res;
    }
};