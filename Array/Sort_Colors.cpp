class Solution {
public:
    void sortColors(vector<int>& nums) {
        int R = 0;//0
        int W = 0;//1
        int B = 0;//2

        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 0) R++;
            else if(nums[i] == 1) W++;
            else B++;
        }

        int index = 0;
        while(R--) nums[index++] = 0;
        while(W--) nums[index++] = 1;
        while(B--) nums[index++] = 2;
    }
};