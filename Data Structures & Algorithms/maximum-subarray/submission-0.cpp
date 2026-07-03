class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int curr = 0;
        for (int i = 0; i < nums.size(); i++){
            curr += nums[i];
            mx = max(curr,mx);
            if (curr < 0) {
                curr = 0;
            }
        }

        return mx;
    }
};
