class Solution {
public:
    int finddayNeeded(vector<int>& weights, int days, int capacity) {
        // if(weights[0] > capacity) return false;
        int sum = 0;
        int dayNeeded = 1;
        for(int i= 0; i<weights.size(); i++) {
            if(sum+weights[i] > capacity) {
                sum = 0;
                dayNeeded++;
            }
            sum += weights[i];
        }
        return dayNeeded;    
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        if(days > weights.size()) return -1;
        
        int sum = 0;
        for(int i=0; i<weights.size(); i++) {
            sum += weights[i];
        }
        int high = sum;
        int low = *max_element(weights.begin(), weights.end());

        while(low <= high) {
            int mid = low+(high-low)/2;
            int dayNeeded = finddayNeeded(weights, days, mid);
            if(dayNeeded <= days) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};