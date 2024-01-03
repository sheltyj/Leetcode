class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> adjWeights;
        int n = weights.size();
        for(int i=1;i<n;i++){
            adjWeights.push_back(weights[i]+weights[i-1]);
        }
        sort(adjWeights.begin(), adjWeights.end());
        long long int ans =0;
        for(int i=0;i<k-1;i++){
            ans+= (adjWeights[n-2-i]-adjWeights[i]);
        }
        return ans;
    }
};