class Solution {
public:
    long long cnt = 0;
    void mergeSort(vector<int>& nums, int s, int e, int mid){
        vector<int> temp;

        int i = s;
        int j = mid+1;

        while(i <= mid && j <= e){
            if(nums[i] > (long long) 2 * nums[j]){
                cnt += mid - i + 1;
                j++;
            }
            else i++;
        }

        i = s;
        j = mid+1;

        while(i <= mid && j <= e){
            if(nums[i] > nums[j]){
                temp.push_back(nums[j++]);
            }
            else temp.push_back(nums[i++]);
        }

        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= e) temp.push_back(nums[j++]);

        for(int k = s; k <= e; k++){
            nums[k] = temp[k - s];
        }
    }
    void solveUsingDevideAndConquer(vector<int>& nums, int s, int e){
        if(s >= e) return;

        int mid = s +  (e - s)/2;

        solveUsingDevideAndConquer(nums, s, mid);
        solveUsingDevideAndConquer(nums, mid+1, e);

        mergeSort(nums, s, e, mid);
    }
    int reversePairs(vector<int>& nums) {
        solveUsingDevideAndConquer(nums, 0, nums.size()-1);
        
        return cnt;
    }
};