class Solution {
public:
    long long MOD = 1000000007;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n-3; i++){
            
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j=i+1; j<n-2; j++){
                
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                int l = n-1;

                while(k < l){
                    long long sum = nums[i]%MOD + nums[j]%MOD + nums[k]%MOD + nums[l]%MOD;
                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                    }
                }
            }
        }

        return ans;

    }
};