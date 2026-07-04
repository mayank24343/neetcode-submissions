class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> numbers = unordered_set(nums.begin(), nums.end());
        int mx = 1;
        int num, cnt;
        for (int i : nums){
            if (numbers.count(i-1)) continue;
            num = i;
            cnt = 1;
            while (numbers.count(num+1)){
                num++;
                cnt++;
            }
            mx = max(mx, cnt);
        }

        return mx;
    }
};
