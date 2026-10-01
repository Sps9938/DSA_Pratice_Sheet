class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int maxi = 0;
        unordered_map<int, int> hash;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            
            if(sum == 0) maxi = max(maxi, i+1);
            else if(hash.find(sum) != hash.end()){
                maxi = max(maxi, i-hash[sum]);
            }
            else hash[sum] = i;
        }
        
        return maxi;
    }
};