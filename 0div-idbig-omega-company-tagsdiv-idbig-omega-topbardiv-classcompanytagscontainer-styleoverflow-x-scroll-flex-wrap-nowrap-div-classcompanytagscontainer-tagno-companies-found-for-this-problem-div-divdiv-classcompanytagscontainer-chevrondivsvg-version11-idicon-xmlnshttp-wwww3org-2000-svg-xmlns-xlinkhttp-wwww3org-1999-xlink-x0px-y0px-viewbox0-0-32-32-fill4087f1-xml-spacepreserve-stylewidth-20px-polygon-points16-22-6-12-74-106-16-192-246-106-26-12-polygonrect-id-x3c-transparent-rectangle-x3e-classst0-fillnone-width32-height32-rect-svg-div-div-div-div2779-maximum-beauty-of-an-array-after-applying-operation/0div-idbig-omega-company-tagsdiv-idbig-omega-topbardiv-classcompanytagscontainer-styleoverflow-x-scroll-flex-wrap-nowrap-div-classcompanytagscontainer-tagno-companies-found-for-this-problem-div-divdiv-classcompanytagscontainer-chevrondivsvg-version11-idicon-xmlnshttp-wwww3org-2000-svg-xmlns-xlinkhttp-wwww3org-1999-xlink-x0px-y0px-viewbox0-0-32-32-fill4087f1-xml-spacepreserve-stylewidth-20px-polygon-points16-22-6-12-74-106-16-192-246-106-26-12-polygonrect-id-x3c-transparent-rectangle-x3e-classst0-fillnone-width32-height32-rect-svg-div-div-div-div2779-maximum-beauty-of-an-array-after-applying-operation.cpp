class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int st = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            while(nums[st]+2*k<nums[i]) st++;
            ans = max(ans, i-st+1);
        }
        return ans;
        
    }
};