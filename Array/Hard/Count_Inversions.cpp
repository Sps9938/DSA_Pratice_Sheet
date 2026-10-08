class Solution {
  public:
  long long cnt = 0;
    void mergesort(vector<int> &arr, int s, int e, int mid){
        vector<int> temp;
        
        //compare
        int i=s;
        int j=mid+1;
        // int main_index = s;
        
        while(i <= mid && j <= e){
            if(arr[i] > arr[j]){
                temp.push_back(arr[j++]);
                cnt += mid - i + 1;
            }
            else {
                temp.push_back(arr[i++]);
            }
        }
        
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= e) temp.push_back(arr[j++]);
        
        for(int k = s; k <= e; k++) arr[k] = temp[k - s];
        
        
        
    }
    void solveUsingRecursion(vector<int> &arr, int s, int e){
        if(s >= e) return;
        
        int mid = s + (e-s)/2;
        solveUsingRecursion(arr, s, mid);
        solveUsingRecursion(arr, mid+1, e);
        
        mergesort(arr, s, e, mid);
        
    }
    int inversionCount(vector<int> &arr) {
        // code here
        int s = 0;
        int e = arr.size()-1;
        solveUsingRecursion(arr, s, e);
        
        return cnt;
    }
};