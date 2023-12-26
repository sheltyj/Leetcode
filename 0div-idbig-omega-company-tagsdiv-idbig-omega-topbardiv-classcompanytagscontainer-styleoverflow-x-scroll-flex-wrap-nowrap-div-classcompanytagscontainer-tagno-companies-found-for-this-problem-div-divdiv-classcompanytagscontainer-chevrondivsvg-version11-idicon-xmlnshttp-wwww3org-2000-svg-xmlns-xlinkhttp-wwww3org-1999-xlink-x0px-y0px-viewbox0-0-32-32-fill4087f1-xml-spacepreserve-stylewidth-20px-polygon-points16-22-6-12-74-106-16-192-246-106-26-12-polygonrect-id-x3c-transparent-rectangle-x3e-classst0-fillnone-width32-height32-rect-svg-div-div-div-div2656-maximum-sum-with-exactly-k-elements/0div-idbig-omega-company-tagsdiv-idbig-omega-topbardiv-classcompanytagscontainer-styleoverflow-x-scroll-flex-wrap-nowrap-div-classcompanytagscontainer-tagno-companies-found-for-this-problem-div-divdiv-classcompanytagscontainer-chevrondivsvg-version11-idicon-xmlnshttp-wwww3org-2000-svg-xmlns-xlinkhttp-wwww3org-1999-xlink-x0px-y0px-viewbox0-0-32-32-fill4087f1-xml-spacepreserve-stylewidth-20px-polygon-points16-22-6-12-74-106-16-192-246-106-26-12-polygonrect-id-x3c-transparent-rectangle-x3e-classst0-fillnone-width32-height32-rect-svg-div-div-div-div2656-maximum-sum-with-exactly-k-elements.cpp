class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxEle = 0;
        for(int i : nums){
            maxEle = max(maxEle, i);
        }
        
        return ((k*(k-1))/2) + maxEle*k;
        
    }
};