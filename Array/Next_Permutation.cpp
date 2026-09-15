class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1. breaking point
        int br_index = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                br_index = i;
                break;
            }
        }

        if(br_index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //2. least greater value to breaking point value

        for(int i=n-1; i>br_index; i--){
            if(nums[br_index] < nums[i]){
                swap(nums[br_index], nums[i]);
                break;
            }
        }


        //3. reverse rest element
        reverse(nums.begin() + br_index+1, nums.end());
        
    }
};