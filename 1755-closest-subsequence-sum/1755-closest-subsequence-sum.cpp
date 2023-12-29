class Solution {
public:
    vector<int> combs;
    
    void util(vector<int>&nums, int currInd, int currSum, int en){
        if(currInd==en+1){
            combs.push_back(currSum);
            return;
        }
        util(nums,currInd+1,currSum+nums[currInd],en);
        util(nums,currInd+1,currSum,en);
    }
    vector<int> getAllComb(vector<int> &nums, int st, int en){
        combs.clear();
        util(nums,st,0,en);
        return combs;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        if(n==1) return min(abs(nums[0]-goal), abs(goal));
        int mid = n/2;
        vector<int> comb1 = getAllComb(nums,0,mid-1);
        vector<int> comb2 = getAllComb(nums,mid,n-1);
        sort(comb2.begin(), comb2.end());
        
        int ans = INT_MAX;
        int n2 = comb2.size();
        
        for(int i : comb1){
            int upper = upper_bound(comb2.begin(), comb2.end(), goal-i)-comb2.begin();
            int prev = upper-1;
            
            int diff1 = INT_MAX;
            int diff2 = INT_MAX;
            
            if(upper>=0 && upper<n2){
                diff1 = abs(goal-(comb2[upper]+i));
            }
            if(prev>=0 && prev<n2){
                diff2 = abs(goal-(comb2[prev]+i));
            }
            
            int curr = min(diff1,diff2);
            ans = min(ans,curr);
         
        }  
        return ans;
    }
};



    
    
    
    