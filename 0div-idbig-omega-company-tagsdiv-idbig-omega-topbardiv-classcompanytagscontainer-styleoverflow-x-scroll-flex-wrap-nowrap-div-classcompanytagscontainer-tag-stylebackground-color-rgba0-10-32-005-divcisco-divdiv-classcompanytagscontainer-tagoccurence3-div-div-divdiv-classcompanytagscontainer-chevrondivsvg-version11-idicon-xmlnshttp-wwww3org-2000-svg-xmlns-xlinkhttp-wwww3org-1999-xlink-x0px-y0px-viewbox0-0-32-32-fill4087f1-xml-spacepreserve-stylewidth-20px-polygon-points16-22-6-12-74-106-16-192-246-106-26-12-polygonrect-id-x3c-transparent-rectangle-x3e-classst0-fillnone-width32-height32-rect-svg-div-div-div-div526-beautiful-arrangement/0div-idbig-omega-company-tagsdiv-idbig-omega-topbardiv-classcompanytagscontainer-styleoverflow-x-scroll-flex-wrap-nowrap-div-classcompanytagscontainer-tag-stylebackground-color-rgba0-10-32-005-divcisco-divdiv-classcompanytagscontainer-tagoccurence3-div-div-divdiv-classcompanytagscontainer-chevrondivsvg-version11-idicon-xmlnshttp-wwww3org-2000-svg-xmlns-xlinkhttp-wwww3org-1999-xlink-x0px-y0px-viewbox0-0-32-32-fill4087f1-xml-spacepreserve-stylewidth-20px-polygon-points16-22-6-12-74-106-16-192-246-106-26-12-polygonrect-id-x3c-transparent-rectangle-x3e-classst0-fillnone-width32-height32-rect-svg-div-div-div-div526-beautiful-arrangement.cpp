
class Solution {
public:
    int ans=0;
    int countArrangement(int n) {
        //if(n==1) return 1;
        
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        dfs(nums,0);
        return ans;
    }
    void dfs(vector<int>& nums,int ind){
        if(ind==nums.size()){
            ans++;
            return;
        }
       
        for(int i=ind;i<nums.size();i++){
            if(nums[i]%(ind+1)==0 || (ind+1)%nums[i]==0){
                swap(nums[i],nums[ind]);
                dfs(nums,ind+1);
                swap(nums[i],nums[ind]);
            }
        }
    }
};