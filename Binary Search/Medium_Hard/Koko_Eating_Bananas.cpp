class Solution {
public:
    int findTotalTime(vector<int>& piles, int k) {
        int total_time = 0;
        for(int i=0; i<piles.size(); i++) {
            total_time += ceil((double)piles[i]/k);
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = INT_MIN;
        long long sum = 0;
        for(int i=0; i<piles.size(); i++) {
            high = max(high, piles[i]);
            sum += piles[i];
        }
        int low = ceil((double)sum/h);
        int ans = high;

        while(low <= high) {
            int mid = low+(high-low)/2;
            int total_time = findTotalTime(piles, mid);
            if(total_time <= h) {
                high = mid-1;
            }
            else low = mid+1;   
        }

        return low;

    }
};