class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i : nums) freq[i]++;
        int ans = 0;
        for(auto p : freq){
            if(p.second==1) return -1;
            else{
                ans+=p.second/3;
                if(p.second%3!=0) ans++;
            }
        }
        return ans;
    }
};