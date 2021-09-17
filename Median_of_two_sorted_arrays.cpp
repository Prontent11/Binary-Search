class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
         if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low=0,high=n1;
        while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=((n1+n2)+1)/2-mid1;
        
          int max1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int max2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int min1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int min2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
            if(max1<=min2 and max2<=min1){
                if((n1+n2)% 2 == 1){
                return (double) max(max1,max2);
                }
                else{
                    return (double)(min(min1,min2) + max(max1,max2))/2;
                }
            }
            else if(max1>min2) high=mid1-1;
            else low=mid1+1;
        }
        return -1;
    }
    
};
