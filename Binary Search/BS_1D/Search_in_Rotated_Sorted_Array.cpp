class Solution {
public:
    int findPivot(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        if(start == end) return start;
        while(start < end) {
            int mid = start + (end-start)/2;

            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]) return mid;
            else if(mid-1 >= 0 && nums[mid] < nums[mid-1]) return mid-1;
            else if(nums[start] < nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return 0;
    }
    int findTarget(vector<int>& nums, int start, int end, int target) {
        while(start <= end) {
            int mid = start+(end-start)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        /*
        Example 1:

        Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4

        Example 2:

        Input: nums = [4,5,6,7,0,1,2], target = 3
        Output: -1

        Example 3:

        Input: nums = [1], target = 0
        Output: -1

        Example 4:

        Input: nums = [1,3], target = 3
        Output: 1

        */



        //first -> find pivot

        int pivot = findPivot(nums);
        int ans = -1;

        //now -> search where target preset either left or right

        if(nums[0] <= target && target <= nums[pivot]) {
            ans = findTarget(nums, 0, pivot, target);
        }
        else ans = findTarget(nums, pivot+1, nums.size()-1, target);

        return ans;
    }
};