//Optimal Approach
//Time Complexity: O(log(min(n,m))), Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int left = (n1+n2+1)/2;
        int low = 0;
        int high = n1;

        while(low <= high) {
            int md1 = (low+high)/2;
            int md2 = left-md1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(md1-1 >= 0) l1 = nums1[md1-1];
            if(md2-1 >= 0) l2 = nums2[md2-1];
            if(md1 < n1) r1 = nums1[md1];
            if(md2 < n2) r2 = nums2[md2];

            if(l1 <= r2 && l2 <= r1) {
                if((n1+n2) & 1) return (double)max(l1,l2);
                else return ((double)max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1 > r2) high = md1-1;
            else low = md1+1;

        }

        return 0;
    }
};

//Better Approach
//Time Complexity: O(n) + O(m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        double ans = 0;
        int pos = 0;
        int i=0, j=0;
        if(n & 1) {
            pos = n/2;
            int count = -1;
            while(i < nums1.size() && j < nums2.size()) {
                if(nums1[i] < nums2[j]) {
                    count++;
                    if(count == pos) return (double)(nums1[i]);
                    i++;
                }
                else{
                    count++;
                    if(count == pos) return (double)(nums2[j]);
                    j++;
                }
            }

            while(i < nums1.size()){
                count++;
                if(count == pos) return ans = (double)(nums1[i]);
                i++; 
            }
            while(j < nums2.size()){
                count++;
                if(count == pos) return ans = (double)(nums2[j]);
                j++;
            }


        }
        else{
            int pos1 = n/2;
            int pos2 = pos1-1;
            double md1 = 0;
            double md2 = 0;
            int count = -1;
            while(i < nums1.size() && j < nums2.size()) {
                if(nums1[i] < nums2[j]) {
                    count++;
                    if(count == pos2) {
                        md1 = nums1[i];

                    }
                    if(count == pos1) {
                        md2 = nums1[i];
                    }
                    i++;
                }
                else{
                    count++;
                    if(count == pos2) {
                        md1 = nums2[j];

                    }
                    if(count == pos1) {
                        md2 = nums2[j];
                    }
                    j++;
                }
            }

            while(i < nums1.size()){
                count++;
                if(count == pos2) {
                        md1 = nums1[i];

                    }
                if(count == pos1) {
                    md2 = nums1[i];
                }
                i++; 
            }
            while(j < nums2.size()){
                count++;
                if(count == pos2) {
                        md1 = nums2[j];

                    }
                if(count == pos1) {
                    md2 = nums2[j];
                }
                j++;
            }

            return ((double)md1 + (double)md2)/2.0;
        }

        return ans;
    }
};

//Brute Force Approach
//Time Complexity: O(n) + O(m), Space Complexity: O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0, j=0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) arr.push_back(nums1[i++]);
            else arr.push_back(nums2[j++]);
        }
        while(i < nums1.size()) arr.push_back(nums1[i++]);
        while(j < nums2.size()) arr.push_back(nums2[j++]);

        int n = arr.size();
        double ans = 0;
        if(n & 1) {
            int pos = (n-1)/2;
            ans = (double)(arr[pos]);

        }
        else{
            int pos1 = n/2;
            int pos2 = pos1-1;
            ans = ((double)arr[pos1]+(double)arr[pos2])/2.0;
        }
        // cout<<"size of merged arrary: "<<n<<endl;
        return ans;
    }
};