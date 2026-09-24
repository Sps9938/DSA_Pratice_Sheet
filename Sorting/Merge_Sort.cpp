class Solution {
  public:
    void merging(vector<int>& arr, int l, int r, int mid){
        int leftsize = mid-l+1;
        int rightsize = r-mid;
        
        vector<int> left(leftsize);
        vector<int> right(rightsize);
        int k = l;
        
        for(int i=0; i<leftsize; i++){
            left[i] = arr[k++];
        }
        
        k = mid+1;
        
        for(int i=0; i<rightsize; i++){
            right[i] = arr[k++];
        }
        
        int leftindex = 0;
        int rightindex = 0;
        int mainindex = l;
        
        while(leftindex<leftsize && rightindex<rightsize){
            if(left[leftindex] < right[rightindex]){
                arr[mainindex++] = left[leftindex++];
            }
            else{
                arr[mainindex++] = right[rightindex++];
            }
        }
        
        while(leftindex<leftsize){
            arr[mainindex++] = left[leftindex++];
        }
        
        while(rightindex<rightsize){
            arr[mainindex++] = right[rightindex++];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l == r) return;
        
        int mid = (l+r)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merging(arr, l, r, mid);
        
        
    }
};