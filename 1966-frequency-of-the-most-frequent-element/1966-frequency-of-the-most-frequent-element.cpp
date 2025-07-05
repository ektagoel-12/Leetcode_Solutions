class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         sort(begin(nums), end(nums));
        long i = 0, j = 0, N = nums.size(), sum = 0;
        for (; j < N; ++j) {
            sum += nums[j];
            if ((j - i + 1) * nums[j] - sum > k) sum -= nums[i++];
        }
        return j - i;
    }
};