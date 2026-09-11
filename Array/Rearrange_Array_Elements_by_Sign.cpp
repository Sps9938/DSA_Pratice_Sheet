class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans(nums.size());

        int ps_index = 0;
        int neg_index = 1;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(ps_index < n && nums[i] > 0){
                ans[ps_index] = nums[i];
                ps_index += 2;
            }
            else if(neg_index < n && nums[i] < 0) {
                ans[neg_index] = nums[i];
                neg_index += 2;
            }
        }

        return ans;
    }
};