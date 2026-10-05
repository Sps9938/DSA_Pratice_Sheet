class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp;
        mp[0] = 1;
        int xr = 0;
        long count = 0;
        
        for(int i=0; i<arr.size(); i++){
            xr ^= arr[i];
            if(mp.find(xr^k) != mp.end()) count += mp[xr^k];
            mp[xr]++;
            
        }
        
        return count;
        
    }
};