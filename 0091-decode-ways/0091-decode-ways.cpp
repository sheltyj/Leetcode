class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0]=='0') return 0;
        int prev1 = 1;
        int prev2 = 1;

        for(int i=1;i<n;i++){
            int singleNum = s[i]-'0';
            int doubleNum = 10*(s[i-1]-'0') + (s[i]-'0');
            int curr = 0;
            if(singleNum>0) curr+=prev1;
            if(doubleNum<=26 && doubleNum>=10) curr+=prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};