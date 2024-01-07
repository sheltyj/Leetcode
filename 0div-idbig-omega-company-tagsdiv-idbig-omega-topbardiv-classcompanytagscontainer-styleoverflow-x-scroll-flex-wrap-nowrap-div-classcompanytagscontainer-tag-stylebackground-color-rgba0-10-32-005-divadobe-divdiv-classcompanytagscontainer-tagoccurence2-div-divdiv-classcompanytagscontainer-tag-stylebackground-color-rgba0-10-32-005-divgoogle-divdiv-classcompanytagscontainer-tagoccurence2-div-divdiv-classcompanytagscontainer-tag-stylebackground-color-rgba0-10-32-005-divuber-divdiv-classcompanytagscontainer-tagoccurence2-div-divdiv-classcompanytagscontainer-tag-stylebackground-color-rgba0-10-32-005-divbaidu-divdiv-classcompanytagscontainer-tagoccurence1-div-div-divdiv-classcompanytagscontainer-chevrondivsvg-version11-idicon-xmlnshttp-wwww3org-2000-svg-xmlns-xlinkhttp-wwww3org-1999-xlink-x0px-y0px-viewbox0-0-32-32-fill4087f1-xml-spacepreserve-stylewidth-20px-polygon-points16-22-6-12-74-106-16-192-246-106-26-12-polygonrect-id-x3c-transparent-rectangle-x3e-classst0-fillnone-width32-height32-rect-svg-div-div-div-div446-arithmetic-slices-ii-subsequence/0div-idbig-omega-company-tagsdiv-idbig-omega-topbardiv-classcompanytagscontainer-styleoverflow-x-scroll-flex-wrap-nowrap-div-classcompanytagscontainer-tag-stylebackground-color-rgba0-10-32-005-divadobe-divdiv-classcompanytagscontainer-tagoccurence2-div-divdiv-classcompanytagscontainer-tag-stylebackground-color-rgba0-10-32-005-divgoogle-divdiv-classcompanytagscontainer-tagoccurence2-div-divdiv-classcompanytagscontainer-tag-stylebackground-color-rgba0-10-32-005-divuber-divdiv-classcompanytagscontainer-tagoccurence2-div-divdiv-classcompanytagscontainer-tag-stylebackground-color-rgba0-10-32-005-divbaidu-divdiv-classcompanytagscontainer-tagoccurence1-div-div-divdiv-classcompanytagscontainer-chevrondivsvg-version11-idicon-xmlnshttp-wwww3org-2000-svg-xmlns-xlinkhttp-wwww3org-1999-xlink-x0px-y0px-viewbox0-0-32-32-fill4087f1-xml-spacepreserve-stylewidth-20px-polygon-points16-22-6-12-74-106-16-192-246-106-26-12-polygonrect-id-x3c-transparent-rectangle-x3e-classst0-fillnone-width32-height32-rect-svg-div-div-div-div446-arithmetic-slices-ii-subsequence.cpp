class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<long long int, int> store[n][4];
        
        for(int i=1;i<n;i++){
            long long int curr = nums[i];
            long long int diff = curr - nums[i-1];
            store[i][2][diff]++;
            for(auto p : store[i-1][2]){
                store[i][2][diff+p.first]+=p.second;
            }
        }
        int ans = 0;
        
        for(int i=2;i<n;i++){
            long long int curr= nums[i];
            for(int j=1;j<i;j++){
                long long int diff = curr-nums[j];
                int inc = store[j][2][diff]+store[j][3][diff];
                ans+=inc;
                store[i][3][diff]+=inc;
            }                                    
                                               
        }
                                      return ans;
        
  
            
        
        
            
        
    }
};