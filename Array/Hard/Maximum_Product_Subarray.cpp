class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        /* Dry -> run
        [2,3,-2,4]
        [-2,0,-1]
        [-3,-1,-1]
        [-3,0,1,-2]
        [7,-2,-4]
        [7,-2,5,-4]
        [2,-5,-2,-4,3]
        [2,-5,-2,-4,-6,3]
        [2,-5,-2,8,-4,-6,3]
        */

        int prefix = 1;
        int suffix = 1;
        int n = nums.size();
        int max_product = INT_MIN;  

        for(int i=0; i<n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-1-i];

            max_product = max(max_product, max(prefix, suffix));
        }


        return max_product;
    }
};