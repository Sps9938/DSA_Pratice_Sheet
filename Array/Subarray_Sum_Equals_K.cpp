class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int total = 0;

        for(auto &num: nums){
            total += num;
            if(mp.contains(total-k)) count += mp[total-k];

            mp[total]++;
        }
        return count;
    }
};