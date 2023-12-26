class Solution {
public:
   
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int maxSum1=0;
        int maxSum2=0;
        int totSum1=0;
        int totSum2=0;
        int currSum1=0;
        int currSum2=0;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            totSum1+=nums1[i];
            totSum2+=nums2[i];
            
            currSum1+=(nums2[i]-nums1[i]);
            currSum2+=(nums1[i]-nums2[i]);
            
            
            currSum1 = max(currSum1,0);
            currSum2= max(currSum2,0);
            
            maxSum1 = max(maxSum1, currSum1);
            maxSum2 = max(maxSum2, currSum2);
        }
        return max(totSum1+maxSum1, totSum2+maxSum2);
    }
};