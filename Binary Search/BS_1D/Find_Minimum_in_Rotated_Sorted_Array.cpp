class Solution {
public:
    int findPivot(vector<int>& nums, int start, int end) {
        if(start == end) return start;

        while(start < end) {
            int mid = start+(end-start)/2;

            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]) return mid;
            else if(mid-1 >=0 && nums[mid] < nums[mid-1]) return mid-1;
            else if(nums[start] < nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int start = 0;
        int end = nums.size()-1;

        int pivot = findPivot(nums, start, end);
        if(pivot == -1) return nums[0];

        return min(nums[0], nums[pivot+1]);
    }
};