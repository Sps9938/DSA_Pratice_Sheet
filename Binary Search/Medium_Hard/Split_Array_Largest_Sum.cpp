class Solution {
public:
    int findTotalStudent(vector<int>& nums, int &k, long long &pages) {
        long long totalPage = 0;
        int studentNeeded = 1;
        for(int i=0; i<nums.size(); i++) {
            if(totalPage + nums[i] > pages) {
                studentNeeded++;
                totalPage = 0;
            }
            totalPage += nums[i];
        }
        
        return studentNeeded;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = 0;
        for(int i=0; i<nums.size(); i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }
        
        while(low <= high) {
            long long mid = low+(high-low)/2;
            int studentNeeded = findTotalStudent(nums, k, mid);
            if(studentNeeded <= k) high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
};