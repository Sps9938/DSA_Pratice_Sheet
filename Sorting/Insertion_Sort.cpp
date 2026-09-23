class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        //insertion sort -> let assume each index as key(small value) and 
        //then compare its to index-1 can we get greater if then store it with index+1
        //because index+1 always gives you a small value
        int n = arr.size();
        for(int i=1; i<n; ++i){
            int key = arr[i];
            int j = i-1;
            while(j >= 0 && key < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}; 