class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> que;
        vector<long long int> cumSum(n+1,0);
        cumSum[0] = 0;
        for(int i=1;i<=n;i++){
            cumSum[i] = cumSum[i-1] + nums[i-1];
        }
        que.push_back(0);
        int ans = n+1;
        for(int i=1;i<=n;i++){
            while(!que.empty() && cumSum[que.back()]>cumSum[i]){
                que.pop_back();
            }
            while(!que.empty() && cumSum[i]-cumSum[que.front()]>=k){
                ans = min(i-que.front(), ans);
                que.pop_front();
            }
            que.push_back(i);
        }
        return ans==n+1?-1 : ans;
        
    }
};