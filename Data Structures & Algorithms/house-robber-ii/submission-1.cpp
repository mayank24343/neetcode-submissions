class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        //may take 1st house but never last
        int p1 = nums[0], p2 = max(nums[0], nums[1]), curr = max(p1, p2);
        if (nums.size() == 2) return curr;
        for (int i = 2; i < nums.size() - 1; i++){
            curr = max(p1+nums[i], p2);
            p1 = p2;
            p2 = curr;
        }
        //may take last house but never first
        p1 = nums[1], p2 = max(nums[1], nums[2]);
        int curr2 = max(p1,p2);
        for (int i = 3; i < nums.size(); i++){
            curr2 = max(p1+nums[i], p2);
            p1 = p2;
            p2 = curr2;
        }

        return max(curr, curr2);
    }
};
