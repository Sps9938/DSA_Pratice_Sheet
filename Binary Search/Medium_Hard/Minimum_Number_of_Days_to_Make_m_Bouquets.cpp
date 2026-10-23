class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int flower = 0;
        int bouquet = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(day >= bloomDay[i]) flower++;
            else {
                bouquet += flower/k;
                if(bouquet >= m) return true;
                flower = 0;
            }
            
        }

        if(flower) {
            bouquet += flower/k;
            if(bouquet >= m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++) {
            high = max(high, bloomDay[i]);
            low = min(low, bloomDay[i]);
        }

        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isPossible(bloomDay, m, k, mid)) high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
};