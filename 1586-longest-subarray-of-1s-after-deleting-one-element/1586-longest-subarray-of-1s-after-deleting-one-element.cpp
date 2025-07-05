class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int i=0,j=0,n=nums.size(),ans=0,cnt=0;
       for(j=0;j<n;j++){
        if(nums[j]==0) cnt+=1;
        if(cnt>1) {
            if(nums[i++]==0){
                cnt--;
            }
        }
    }
    return j-i-1;
    }
};