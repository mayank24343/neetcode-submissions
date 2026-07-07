class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;

        while (low <= high){
            mid = low + (high-low)/2;
            //cout << mid << endl;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] >= nums[low]){
                if (target >= nums[low] && target < nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if (nums[mid] <= nums[high]){
                if (target <= nums[high] && target > nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};
