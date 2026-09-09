class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_index = 0;
        int curr_sum = 0;
        int max_subarray = INT_MIN;

        while(curr_index < nums.size()){
            curr_sum = max(nums[curr_index], curr_sum + nums[curr_index]);
            
            max_subarray = max(curr_sum, max_subarray);
            curr_index++;
             
        }

        return max_subarray;

    }
};