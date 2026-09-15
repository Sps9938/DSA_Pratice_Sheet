class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> ans;
        int last_value = arr[arr.size()-1];
        
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i] >= last_value) ans.push_back(arr[i]);
            
            last_value = max(last_value, arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};