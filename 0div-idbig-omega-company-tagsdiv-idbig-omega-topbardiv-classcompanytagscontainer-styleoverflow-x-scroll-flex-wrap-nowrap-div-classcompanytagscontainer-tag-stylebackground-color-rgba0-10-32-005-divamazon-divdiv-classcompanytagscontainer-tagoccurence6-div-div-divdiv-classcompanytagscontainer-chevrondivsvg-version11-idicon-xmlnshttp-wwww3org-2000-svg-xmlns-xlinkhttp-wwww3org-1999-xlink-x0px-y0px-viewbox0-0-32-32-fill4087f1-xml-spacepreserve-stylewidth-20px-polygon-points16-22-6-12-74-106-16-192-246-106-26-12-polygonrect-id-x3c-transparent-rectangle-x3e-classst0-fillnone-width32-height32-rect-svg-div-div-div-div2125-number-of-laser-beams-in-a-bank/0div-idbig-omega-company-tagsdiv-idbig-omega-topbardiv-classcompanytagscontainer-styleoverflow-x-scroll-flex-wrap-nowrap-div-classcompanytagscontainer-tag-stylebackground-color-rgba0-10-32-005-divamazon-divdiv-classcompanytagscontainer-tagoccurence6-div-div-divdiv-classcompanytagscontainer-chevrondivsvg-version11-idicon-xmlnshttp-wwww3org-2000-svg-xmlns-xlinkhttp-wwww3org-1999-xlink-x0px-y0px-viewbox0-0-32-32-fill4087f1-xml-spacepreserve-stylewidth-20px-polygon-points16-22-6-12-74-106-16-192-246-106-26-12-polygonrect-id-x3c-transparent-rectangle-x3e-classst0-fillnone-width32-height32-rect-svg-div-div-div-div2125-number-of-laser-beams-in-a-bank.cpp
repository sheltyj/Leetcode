class Solution {
public:
    int count1(string &s){
        int ans = 0;
        for(char ch : s){
            if(ch=='1') ans++;
        }
        return ans;
    }
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(string s : bank){
            int curr = count1(s);
            if(curr==0) continue;
            ans+= curr*prev;
            prev=curr;
        }
        return ans;
    }
    
};