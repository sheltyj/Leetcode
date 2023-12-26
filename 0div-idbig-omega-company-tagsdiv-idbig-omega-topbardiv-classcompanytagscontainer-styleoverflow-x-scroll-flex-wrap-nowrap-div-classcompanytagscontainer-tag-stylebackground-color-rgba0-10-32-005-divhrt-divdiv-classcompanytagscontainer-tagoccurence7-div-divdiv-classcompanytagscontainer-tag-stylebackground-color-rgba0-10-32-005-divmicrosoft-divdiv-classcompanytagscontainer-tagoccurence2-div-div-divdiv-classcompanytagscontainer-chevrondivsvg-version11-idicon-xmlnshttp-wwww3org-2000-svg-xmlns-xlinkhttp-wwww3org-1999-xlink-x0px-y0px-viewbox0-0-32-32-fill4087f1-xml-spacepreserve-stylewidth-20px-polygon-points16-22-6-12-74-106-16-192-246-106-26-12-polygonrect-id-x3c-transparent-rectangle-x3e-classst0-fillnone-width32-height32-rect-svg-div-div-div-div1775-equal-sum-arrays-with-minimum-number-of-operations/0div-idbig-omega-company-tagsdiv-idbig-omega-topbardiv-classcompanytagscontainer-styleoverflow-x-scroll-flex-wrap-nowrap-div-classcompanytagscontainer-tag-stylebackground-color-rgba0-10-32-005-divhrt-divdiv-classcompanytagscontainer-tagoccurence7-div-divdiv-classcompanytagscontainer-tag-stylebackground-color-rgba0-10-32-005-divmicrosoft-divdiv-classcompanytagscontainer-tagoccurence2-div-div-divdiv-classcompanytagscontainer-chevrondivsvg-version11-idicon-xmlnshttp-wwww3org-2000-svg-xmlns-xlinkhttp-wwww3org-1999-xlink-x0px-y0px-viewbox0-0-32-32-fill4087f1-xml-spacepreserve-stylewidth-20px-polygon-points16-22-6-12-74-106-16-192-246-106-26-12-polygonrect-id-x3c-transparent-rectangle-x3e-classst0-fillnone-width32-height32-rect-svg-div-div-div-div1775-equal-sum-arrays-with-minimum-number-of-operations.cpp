class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0;
        int sum2=0;
        vector<int> freq1(7,0);
        vector<int> freq2(7,0);
        for(int i : nums1){
            sum1+=i;
            freq1[i]++;
        } 
        for(int i : nums2) {
            sum2+=i;
            freq2[i]++;
        }
        if(sum1==sum2) return 0;
        
        if(sum1>sum2){
            swap(freq1,freq2);
        }
        int diff = abs(sum1-sum2);
        
        int ans = 0;
        int left = 1, right =6;
        while(left<=6 && right>=1){
            int leftFreq = freq1[left];
            int rightFreq = freq2[right];
            int impact = 6-left;
            int totFreq = leftFreq+rightFreq;
            
            if(totFreq*impact<diff){
                diff-=totFreq*impact;
                left++;
                right--;
                ans+=totFreq;
            }
            else{
                ans+=diff/impact;
                if(diff%impact!=0) ans++;
                return ans;
            }
        }
        return diff<=0 ? ans : -1;
        
        
    }
};