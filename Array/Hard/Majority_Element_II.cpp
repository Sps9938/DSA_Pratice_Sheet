class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cn1 = 0;
        int cn2 = 0;
        int e1 = INT_MIN;
        int e2 = INT_MIN;

        for(auto &num: nums){
            if(cn1 == 0 && e2 != num){
                e1 = num;
                cn1 = 1;
            }
            else if(cn2 == 0 && e1 != num){
                e2 = num;
                cn2 = 1;
            }
            else if(e1 == num) cn1++;
            else if(e2 == num) cn2++;
            else{
                cn1--;
                cn2--;
            }
        }

        cn1 = 0;
        cn2 = 0;
        for(auto &num: nums){
            if(num == e1) cn1++;
            if(num == e2) cn2++;
        }

        vector<int> ans;
        int t = nums.size()/3;
        if(cn1 > t) ans.push_back(e1);
        if(cn2 > t) ans.push_back(e2);
        return ans;
    }
};