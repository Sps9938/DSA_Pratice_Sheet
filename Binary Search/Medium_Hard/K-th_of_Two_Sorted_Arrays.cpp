//Optimized approach
//Time Complexity: O(log(min(n,m))), Space Complexity: O(1)
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
       int n1 = a.size();
       int n2 = b.size();
       if(n1 > n2) return kthElement(b, a, k);

       int left = k;
       int low = max(0, k-n2);
       int high = min(k, n1);

       while(low <= high) {
           int md1 = (low+high)/2;
           int md2 = left-md1;

           int l1 = INT_MIN;
           int l2 = INT_MIN;
           int r1 = INT_MAX;
           int r2 = INT_MAX;

           if(md1-1 >= 0) l1 = a[md1-1];
           if(md2-1 >= 0) l2 = b[md2-1];
           if(md1 < n1) r1 = a[md1];
           if(md2 < n2) r2 = b[md2];

           if(l1 <= r2 && l2 <= r1) return max(l1, l2);
           if(l1 > r2) high = md1-1;
           else low = md1+1;

       }
        return -1;
    }
};
//Better approach 
//Time Complexity: O(n) + O(m), Space Complexity: O(1)
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i=0,j=0,actualIndex = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] <= b[j]){
                actualIndex++;
                if(actualIndex == k) return a[i];
                i++;
            }
            else{
                actualIndex++;
                if(actualIndex == k) return b[j];
                j++;
            }
        }
        
        while(i < a.size()){
            actualIndex++;
            if(actualIndex == k) return a[i];
            i++;
        }
        while(j < b.size()) {
            actualIndex++;
            if(actualIndex == k) return b[j];
            j++;
        }
        
        return -1;
        
    }
};