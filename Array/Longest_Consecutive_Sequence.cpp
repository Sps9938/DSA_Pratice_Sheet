class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
       unordered_set<int> st(nums.begin(), nums.end());
       int max_len = 0;

       for(auto &num: st){
            if(st.contains(num-1))
                continue; //sequence is not start 
            int curr_len = 1;
            int curr_value = num;

            while(st.contains(curr_value+1)){
                curr_len += 1;
                curr_value += 1;
            }

            max_len = max(max_len, curr_len);
        }

       return max_len;
    }
};