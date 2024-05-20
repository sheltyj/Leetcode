vector<int>ind(26,27);
 bool myCompare(char a,char b){
   return ind[a-'a']<ind[b-'a'];
 }

class Solution {
public:
    string customSortString(string order, string s) {

        for(int i=0;i<order.size();i++){
            ind[order[i]-'a']=i;
        }
        sort(s.begin(),s.end(),myCompare);
        return s;
    }
};
