#define pi pair<int,int>
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        
        vector<pi> freqPair;
        for(auto p : freq) freqPair.push_back({p.second,p.first});
        sort(freqPair.begin(), freqPair.end());
        
        int n = freqPair.size();
        
        int len = freqPair[n-1].first;
        vector<vector<int>> ans(len);
        for(int i=0;i<len;i++){
            vector<int> curr;
            for(int j=n-1;j>=0;j-- ){
                if(freqPair[j].first==0) break;
                curr.push_back(freqPair[j].second);
                freqPair[j].first--;
            }
            ans[i]=curr;
        }
        return ans;
        
    }
};