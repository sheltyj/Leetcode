class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool fun(vector<int> &nums, int k, int mask, int sum, int currSum, int i){
        if(currSum==sum && k==1) return true;
        if(i==nums.size())return false;
        if(k==0) return false;
        
        if(dp[mask][k]!=-1) return dp[mask][k];
        
        if(currSum==sum){
            //cout<<sum<<endl;
            //cout<<k<<endl;
            // for(int i=0;i<nums.size();i++){
            //     if(vis[i])cout<<nums[i]<<" ";
            // }
            // cout<<endl;
            return dp[mask][k] =  fun(nums,k-1,mask,sum,0,0);
        }
        bool taken = false;
        int currMask = (1<<i);
        if((currMask&mask)==0 && currSum+nums[i]<=sum){
            taken = fun(nums,k, (mask|currMask),sum,currSum+nums[i],i+1);
        }
        bool notTaken = fun(nums,k,mask,sum,currSum,i+1);
        return dp[mask][k] = taken || notTaken;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int mask = 1<<n;
        dp.resize(mask+1,vector<int>(k+1,-1));
        int sum = 0;
        for(int i : nums) sum+=i;
        if(sum%k!=0) return false;
        vector<bool> vis(nums.size(),false);
        return   fun(nums,k,0,sum/k,0,0);   
    }
};