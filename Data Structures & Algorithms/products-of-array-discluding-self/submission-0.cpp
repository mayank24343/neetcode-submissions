class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_prod = 1, non_zero_prod = 1, zeros = 0;
        for (int i : nums){
            total_prod*= i;
            if (i == 0){
                zeros++;
            }
            else{
                non_zero_prod*= i;
            }
        }

        vector<int> ans(nums.size(), 0);
        if (zeros > 1) return ans;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                ans[i] = non_zero_prod;
            }
            else{
                ans[i] = total_prod/nums[i];
            }
        }

        return ans;
    }
};
