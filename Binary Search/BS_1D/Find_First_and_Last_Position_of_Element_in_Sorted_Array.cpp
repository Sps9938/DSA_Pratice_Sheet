class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int left = -1;
        int right = -1;

        // for find first position

        while(s <= e) {
            int mid = s+(e-s)/2;

            if(nums[mid] == target) {
                left = mid;
                e = mid-1;
            }
            else if(nums[mid] < target) s = mid+1;
            else e = mid-1;

        }
        // for find last position
        s = 0;
        e = nums.size()-1;
        while(s <= e) {
            int mid = s+(e-s)/2;

            if(nums[mid] == target) {
                right = mid;
                s = mid+1;
            }
            else if(nums[mid] < target) s = mid+1;
            else e = mid-1;

        }

        return {left, right};
    }
};