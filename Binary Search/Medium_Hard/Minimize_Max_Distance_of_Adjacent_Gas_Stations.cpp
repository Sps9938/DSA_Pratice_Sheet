

//Better Solution
//Time Complexity: O(nlogn) + O(klogn), Space Complexity: O(n)
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        /*
            stations[] = [1, 13, 17, 23]
            k = 5
        */
        int n = stations.size();
        // double ans = 1000000;
        vector<int> howManyStations(n-1, 0);
        priority_queue<pair<double, int>> pq;
        
        for(int i=0; i<n-1; i++) {
            pq.push({stations[i+1]-stations[i], i});
        }
        
        for(int gasStations=1; gasStations<=k; gasStations++) {
            
            auto top = pq.top();
            pq.pop();
            
            int maxInd = top.second;
            howManyStations[maxInd]++;
            
            double diff = stations[maxInd+1]-stations[maxInd];
            double currentGap = (double)diff/(double)(howManyStations[maxInd]+1);
            
            pq.push({currentGap, maxInd});
            
        }
        
       
        return pq.top().first;
    }
};

//Brute Force Approach
//Time Complexity: O(n*k) + O(n), Space Complexity: O(n)
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        /*
            stations[] = [1, 13, 17, 23]
            k = 5
        */
        int n = stations.size();
        // double ans = 1000000;
        vector<int> howManyStations(n-1, 0);
        for(int gasStations=0; gasStations<k; gasStations++) {
            double maxGap = -1;
            int maxInd = -1;
            for(int i=0; i<n-1; i++) {
                double diff = stations[i+1]-stations[i];
                double currentGap = (double)diff/((double)howManyStations[i]+1);
                if(currentGap > maxGap) {
                    maxGap = currentGap;
                    maxInd = i;
                    // ans = min(ans, maxGap);
                }
            }
            
            howManyStations[maxInd]++;
            
        }
        
        double ans = -1;
        for(int i=0; i<n-1; i++) {
            double diff = stations[i+1]-stations[i];
            double currentGap = (double)diff/((double)howManyStations[i]+1);
            ans = max(currentGap, ans);
        }
        
        return ans;
    }
};