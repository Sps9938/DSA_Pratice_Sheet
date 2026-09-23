class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        // code here
    //selection sort -> let choose every indes as min_index and compare with other
    // index if smaller then swap them
    
    for(int i=0; i<arr.size(); i++) { 
            int min_index = i;
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j] < arr[min_index]) swap(arr[j], arr[min_index]);
            }
        }
    }
};