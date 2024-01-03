class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int currSum = 0;
        unordered_map<int,int> store;
        
        store[0]++;
        int ans = 0;
        for(int i : nums){
            currSum+=i;
            int curr = currSum%k;
            if(currSum<0){
                curr = k-abs(currSum)%k;
                if(curr==k) curr=0;
            }
            ans+=store[curr];
            store[curr]++;
            
        }
        
        
        return ans;
    }
};