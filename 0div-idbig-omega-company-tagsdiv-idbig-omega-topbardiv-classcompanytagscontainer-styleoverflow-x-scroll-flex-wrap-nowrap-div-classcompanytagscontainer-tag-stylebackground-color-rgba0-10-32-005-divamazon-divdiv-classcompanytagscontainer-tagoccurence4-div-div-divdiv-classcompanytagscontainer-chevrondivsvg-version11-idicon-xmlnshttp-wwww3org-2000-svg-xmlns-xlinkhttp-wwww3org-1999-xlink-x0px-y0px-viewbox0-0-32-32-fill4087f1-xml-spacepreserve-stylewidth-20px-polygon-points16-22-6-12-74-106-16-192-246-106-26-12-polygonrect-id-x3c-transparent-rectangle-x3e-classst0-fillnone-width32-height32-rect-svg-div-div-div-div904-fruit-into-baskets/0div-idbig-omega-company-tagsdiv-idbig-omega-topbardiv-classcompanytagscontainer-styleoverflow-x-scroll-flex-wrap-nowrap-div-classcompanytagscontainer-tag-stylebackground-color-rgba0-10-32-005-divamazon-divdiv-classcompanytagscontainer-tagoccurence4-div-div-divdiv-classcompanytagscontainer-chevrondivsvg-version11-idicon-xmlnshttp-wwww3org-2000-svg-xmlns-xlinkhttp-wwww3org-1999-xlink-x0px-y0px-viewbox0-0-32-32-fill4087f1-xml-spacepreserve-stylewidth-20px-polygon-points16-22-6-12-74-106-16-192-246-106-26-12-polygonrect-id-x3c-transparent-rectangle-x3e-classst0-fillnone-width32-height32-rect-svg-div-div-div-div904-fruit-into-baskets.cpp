class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> freq(n,0);
        int count =0;
        int left = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(++freq[fruits[i]]==1) count++;
            while(count>2){
                if(--freq[fruits[left++]]==0)count--;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};