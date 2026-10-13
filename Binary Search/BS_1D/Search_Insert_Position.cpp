class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int ans = -1;
        int s = 0;
        int e = n-1;
        while(s <= e) {
            int mid = s + (e - s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                ans = mid + 1;
                s = mid + 1;
            }
            else e = mid - 1;
        }

        if(ans == -1 && nums[n-1] < target) return n;
        if(ans == -1 && nums[0] > target) return 0;
        return ans; 

    }
};