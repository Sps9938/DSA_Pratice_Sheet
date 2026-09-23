class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        //bubble sort -> n-1 time iterate
        //each time j and j+1 if getting smaller then swap
        int n = arr.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<n-1; j++){
                if(arr[j+1] < arr[j]) swap(arr[j+1], arr[j]);
            }
        }
    }
};