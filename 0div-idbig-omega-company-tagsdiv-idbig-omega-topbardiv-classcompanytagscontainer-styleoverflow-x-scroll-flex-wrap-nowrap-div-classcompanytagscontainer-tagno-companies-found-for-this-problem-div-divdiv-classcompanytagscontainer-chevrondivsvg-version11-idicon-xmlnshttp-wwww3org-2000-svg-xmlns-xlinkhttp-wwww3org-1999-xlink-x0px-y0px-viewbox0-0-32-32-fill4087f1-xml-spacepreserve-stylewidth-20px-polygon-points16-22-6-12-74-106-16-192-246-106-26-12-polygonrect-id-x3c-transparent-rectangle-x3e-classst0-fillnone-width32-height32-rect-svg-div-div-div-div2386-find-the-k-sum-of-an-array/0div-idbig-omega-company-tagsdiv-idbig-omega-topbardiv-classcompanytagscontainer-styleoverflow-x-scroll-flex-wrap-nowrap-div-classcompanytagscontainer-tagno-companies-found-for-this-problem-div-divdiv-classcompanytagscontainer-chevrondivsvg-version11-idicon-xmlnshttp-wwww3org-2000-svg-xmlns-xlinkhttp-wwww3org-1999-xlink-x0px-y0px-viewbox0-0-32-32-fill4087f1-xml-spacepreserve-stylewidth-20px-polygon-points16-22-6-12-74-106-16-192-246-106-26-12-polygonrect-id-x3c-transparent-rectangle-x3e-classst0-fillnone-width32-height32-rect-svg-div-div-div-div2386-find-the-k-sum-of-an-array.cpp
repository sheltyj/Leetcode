#define pi pair<long long,int>
class Solution {
public:
    
    long long kSum(vector<int>& nums, int k) {
        long long int maxSum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxSum+=max(0,nums[i]);
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        priority_queue<pi,vector<pi>,greater<pi>> minHeap;
        
        minHeap.push({nums[0],0});
        if(k==1) return maxSum;
        k--;
        long long  curr = nums[0];
        while(!minHeap.empty() && k--){
            pi currP = minHeap.top();
            minHeap.pop();
            curr = currP.first;
            int ind = currP.second;
            
            if(ind<n-1){
                minHeap.push({curr+nums[ind+1],ind+1});
                minHeap.push({curr-nums[ind]+nums[ind+1],ind+1});
            }
        
        }
        return maxSum - curr;  
    }
};