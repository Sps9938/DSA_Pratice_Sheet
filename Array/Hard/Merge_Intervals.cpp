class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(auto &num: intervals){
            if(end >= num[0]) {
                end = max(end, num[1]);
            }
            else{
                ans.push_back({start, end});
                start = num[0];
                end = num[1];
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};