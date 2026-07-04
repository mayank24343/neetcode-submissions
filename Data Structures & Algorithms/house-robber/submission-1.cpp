class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int p1 = nums[0], p2 = max(nums[1], nums[0]), curr;
        for (int i = 2; i < n; i++){
            curr = max(p1+nums[i], p2);
            //cout << curr << endl;
            p1 = p2;
            p2 = curr;
        }

        return curr;
    }
};
