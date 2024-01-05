class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sortedSeq;
        for(int i : nums){
            int len = sortedSeq.size();
            if(len==0 || sortedSeq[len-1]<i){
                sortedSeq.push_back(i);
            }else{
                int upper = lower_bound(sortedSeq.begin(), sortedSeq.end(),i)-sortedSeq.begin();
                if(upper<len) sortedSeq[upper] = i;
            }
        }
        return sortedSeq.size();
    }
};