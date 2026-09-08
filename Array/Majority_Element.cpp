class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m_element = 0;
        int count = 0;

        int n = nums.size();

        for(int i=0; i<n; i++){
            if(count == 0){
                m_element = nums[i];
                count = 1;
            }
            else if(m_element == nums[i]) count++;
            else count--;
        }

        return m_element;

        // if(count != 0) return m_element;
        // return -1;
    }
};
/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        int x = nums.size()/2;
        for(auto me: hash){
            if(me.second > x) return me.first;
        }
        return -1;
    }
};

*/

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
*/