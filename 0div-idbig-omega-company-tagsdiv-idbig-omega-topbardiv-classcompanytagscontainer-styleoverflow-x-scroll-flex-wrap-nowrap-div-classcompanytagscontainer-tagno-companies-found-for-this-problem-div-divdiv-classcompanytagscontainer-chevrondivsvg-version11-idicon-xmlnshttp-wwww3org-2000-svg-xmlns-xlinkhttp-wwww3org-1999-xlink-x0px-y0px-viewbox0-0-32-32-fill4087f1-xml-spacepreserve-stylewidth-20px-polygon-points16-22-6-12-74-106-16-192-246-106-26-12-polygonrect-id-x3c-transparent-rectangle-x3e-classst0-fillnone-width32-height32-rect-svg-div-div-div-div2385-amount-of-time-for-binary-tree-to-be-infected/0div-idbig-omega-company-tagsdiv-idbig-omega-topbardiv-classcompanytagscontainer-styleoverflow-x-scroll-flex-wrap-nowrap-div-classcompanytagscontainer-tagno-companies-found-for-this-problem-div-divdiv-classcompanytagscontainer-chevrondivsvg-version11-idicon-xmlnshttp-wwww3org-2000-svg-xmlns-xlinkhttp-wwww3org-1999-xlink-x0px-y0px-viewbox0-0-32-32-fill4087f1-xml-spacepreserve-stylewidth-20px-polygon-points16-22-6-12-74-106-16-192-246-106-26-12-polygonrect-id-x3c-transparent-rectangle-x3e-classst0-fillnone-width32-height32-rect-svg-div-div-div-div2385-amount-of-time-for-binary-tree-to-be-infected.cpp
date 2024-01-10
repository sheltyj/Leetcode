/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define pi pair<int,bool>
class Solution {
public:
    int ans = -1;
    pi dfs(TreeNode* root , int start){
        if(!root) return {0,false};
        pi left = dfs(root->left,start);
        pi right = dfs(root->right,start);
        
        if(left.second || right.second){
            ans = max(ans, left.first+right.first);
            if(left.second) return {left.first+1,true};
            else return {right.first+1,true};
        }else if(root->val==start){
            ans = max(ans,max(left.first,right.first));
            return {1,true};
        }
        return {max(left.first,right.first)+1,false};   
    }
    int amountOfTime(TreeNode* root, int start) {
        ans = -1;
        pi p= dfs(root,start);
        return ans;
        
    }
};