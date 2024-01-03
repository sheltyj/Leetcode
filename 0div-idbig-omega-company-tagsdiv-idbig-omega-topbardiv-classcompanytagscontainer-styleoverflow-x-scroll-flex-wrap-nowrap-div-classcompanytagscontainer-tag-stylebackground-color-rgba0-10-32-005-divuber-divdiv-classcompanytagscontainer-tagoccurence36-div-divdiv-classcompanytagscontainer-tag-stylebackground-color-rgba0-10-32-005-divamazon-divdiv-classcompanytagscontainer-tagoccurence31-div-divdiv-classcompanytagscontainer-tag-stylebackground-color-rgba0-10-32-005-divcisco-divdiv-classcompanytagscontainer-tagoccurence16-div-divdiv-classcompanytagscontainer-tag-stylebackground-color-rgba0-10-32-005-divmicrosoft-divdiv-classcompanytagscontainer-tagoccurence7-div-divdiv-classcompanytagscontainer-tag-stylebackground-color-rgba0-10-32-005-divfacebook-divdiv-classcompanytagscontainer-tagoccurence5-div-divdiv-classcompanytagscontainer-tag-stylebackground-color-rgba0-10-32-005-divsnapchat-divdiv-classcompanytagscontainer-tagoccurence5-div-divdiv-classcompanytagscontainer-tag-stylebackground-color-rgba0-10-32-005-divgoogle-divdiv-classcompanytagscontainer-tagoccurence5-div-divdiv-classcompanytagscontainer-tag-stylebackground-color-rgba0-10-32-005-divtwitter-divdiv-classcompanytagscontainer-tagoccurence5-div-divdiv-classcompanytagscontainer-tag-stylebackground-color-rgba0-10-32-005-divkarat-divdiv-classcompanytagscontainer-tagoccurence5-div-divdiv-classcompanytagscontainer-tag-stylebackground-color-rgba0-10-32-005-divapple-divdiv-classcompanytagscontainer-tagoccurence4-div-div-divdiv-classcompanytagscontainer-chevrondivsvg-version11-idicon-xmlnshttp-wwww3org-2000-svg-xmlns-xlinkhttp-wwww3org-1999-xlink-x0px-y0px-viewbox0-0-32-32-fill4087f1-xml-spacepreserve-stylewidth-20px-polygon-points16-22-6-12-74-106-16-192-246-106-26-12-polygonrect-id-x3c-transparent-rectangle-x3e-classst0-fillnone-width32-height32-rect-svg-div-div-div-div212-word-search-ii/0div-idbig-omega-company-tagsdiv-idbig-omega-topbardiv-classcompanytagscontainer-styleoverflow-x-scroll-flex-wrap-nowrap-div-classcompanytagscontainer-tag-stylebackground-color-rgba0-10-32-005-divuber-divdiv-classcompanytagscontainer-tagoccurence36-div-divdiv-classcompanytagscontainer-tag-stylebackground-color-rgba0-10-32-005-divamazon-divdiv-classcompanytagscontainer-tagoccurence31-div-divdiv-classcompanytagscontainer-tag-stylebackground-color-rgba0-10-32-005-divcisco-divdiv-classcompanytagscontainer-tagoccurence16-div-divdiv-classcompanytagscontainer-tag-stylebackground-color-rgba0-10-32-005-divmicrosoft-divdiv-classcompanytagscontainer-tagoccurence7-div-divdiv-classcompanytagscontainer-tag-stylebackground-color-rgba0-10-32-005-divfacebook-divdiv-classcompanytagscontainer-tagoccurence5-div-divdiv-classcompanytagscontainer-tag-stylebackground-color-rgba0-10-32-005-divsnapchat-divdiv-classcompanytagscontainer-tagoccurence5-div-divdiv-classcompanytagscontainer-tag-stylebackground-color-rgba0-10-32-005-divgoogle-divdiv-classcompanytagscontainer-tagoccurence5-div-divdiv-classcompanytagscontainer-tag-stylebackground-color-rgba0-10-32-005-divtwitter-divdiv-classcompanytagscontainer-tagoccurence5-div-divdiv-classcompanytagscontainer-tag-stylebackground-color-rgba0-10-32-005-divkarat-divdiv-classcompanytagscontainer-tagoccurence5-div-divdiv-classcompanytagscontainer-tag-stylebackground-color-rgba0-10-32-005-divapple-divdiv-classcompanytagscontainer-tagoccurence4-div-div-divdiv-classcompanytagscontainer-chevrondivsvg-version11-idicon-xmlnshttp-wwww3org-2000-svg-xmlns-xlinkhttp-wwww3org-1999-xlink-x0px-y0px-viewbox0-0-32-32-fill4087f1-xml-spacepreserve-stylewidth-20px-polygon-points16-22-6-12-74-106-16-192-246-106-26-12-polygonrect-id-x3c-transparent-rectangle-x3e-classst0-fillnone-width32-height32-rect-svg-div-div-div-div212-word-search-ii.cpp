class Node{
    public:
        vector<Node*> nextNodes;
        string word;
        Node(){
            nextNodes.resize(26,NULL);
            word = "";
        }
    
        void insert(string &s){
            int n = s.size();
            Node* currNode = this;
            for(int i=0;i<n;i++){
                int nextInd = s[i]-'a';
                if(currNode->nextNodes[nextInd]==NULL){
                    currNode->nextNodes[nextInd] = new Node();
                }
                currNode = currNode->nextNodes[nextInd];
            }
            currNode->word = s;
        }
};



int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

class Solution {
public:
    
    vector<string> ans;
    void solve(vector<vector<char>> &board, int row, int col, Node* node){
        int n = board.size();
        int m = board[0].size();
        
        char currChar = board[row][col];
        int ind = currChar-'a';
        if(node->nextNodes[ind]==NULL) return;
        
        if(node->nextNodes[ind]->word!=""){
            ans.push_back(node->nextNodes[ind]->word);
            node->nextNodes[ind]->word="";
        }
        board[row][col] = '$';
        for(int i=0;i<4;i++){
            int adjRow = row+dx[i];
            int adjCol = col+dy[i];
            if(adjRow>=0 && adjRow<n && adjCol>=0 && adjCol<m && board[adjRow][adjCol]!='$'){
                solve(board, adjRow, adjCol, node->nextNodes[ind]);
            }
        }
        board[row][col] = currChar;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Node* node = new Node();
        for(auto s : words){
            node->insert(s);
        }
        ans.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(board,i,j,node);
            }
        }
        return ans;
    }
};