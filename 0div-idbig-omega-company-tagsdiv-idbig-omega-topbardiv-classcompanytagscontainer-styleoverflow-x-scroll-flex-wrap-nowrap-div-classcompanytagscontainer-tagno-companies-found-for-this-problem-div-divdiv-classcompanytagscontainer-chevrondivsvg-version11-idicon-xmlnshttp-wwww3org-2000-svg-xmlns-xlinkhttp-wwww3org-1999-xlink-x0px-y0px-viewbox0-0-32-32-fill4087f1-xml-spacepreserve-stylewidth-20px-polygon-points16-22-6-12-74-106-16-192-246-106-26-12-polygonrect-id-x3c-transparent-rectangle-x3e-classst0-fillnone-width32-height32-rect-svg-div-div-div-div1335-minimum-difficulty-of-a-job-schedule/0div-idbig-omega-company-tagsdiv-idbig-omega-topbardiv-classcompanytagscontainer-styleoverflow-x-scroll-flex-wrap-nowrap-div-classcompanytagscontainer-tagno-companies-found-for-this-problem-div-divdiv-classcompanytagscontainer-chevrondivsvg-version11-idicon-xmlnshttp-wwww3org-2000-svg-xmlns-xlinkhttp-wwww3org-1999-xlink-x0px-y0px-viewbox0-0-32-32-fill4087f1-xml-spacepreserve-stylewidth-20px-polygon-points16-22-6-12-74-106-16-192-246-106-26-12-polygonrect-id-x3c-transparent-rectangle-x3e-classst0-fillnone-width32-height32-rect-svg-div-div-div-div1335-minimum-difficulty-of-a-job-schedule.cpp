class Solution {
public:
    vector<vector<vector<int>>> dp;
    int util(vector<int>& jobs, int d, int ind, int maxEle){
        int n = jobs.size();
        
        if(ind==n && d==0) return maxEle;
        if(ind==n && d!=0) return INT_MAX;
        if(ind<n && d==0) return INT_MAX;
        
        if(dp[ind][maxEle][d]!=-1) return dp[ind][maxEle][d];
        
        
        int sameDay = util(jobs,d,ind+1,max(maxEle,jobs[ind]));
        
        int diffDay = util(jobs,d-1,ind+1,0);
        if(diffDay!=INT_MAX){
            diffDay+=max(maxEle,jobs[ind]);
        }
        int ans = min(sameDay,diffDay); 
        
        return dp[ind][maxEle][d] = ans;
        
        
        
    }
    int minDifficulty(vector<int>& jobs, int d) {
        if(jobs.size()<d) return -1;
        dp.resize(jobs.size(), vector<vector<int>>(1001,vector<int>(d+1,-1)));
        return util(jobs,d,0,0);

    }
};