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
#define pi pair<int,int>
class Solution {
public:
    int ans = 0;
    pi dfs(TreeNode* root){
        if(!root->left && !root->right){
            return {root->val,root->val};
        }
        int currVal = root->val;
        int currDiff = 0;
        pi left = {currVal,currVal};
        pi right = {currVal,currVal};
        if(root->left){
            left = dfs(root->left);
        }
        if(root->right){
            right = dfs(root->right);
        }
        currDiff = max(currDiff, max(abs(currVal-left.first), abs(currVal-left.second)));
        currDiff = max(currDiff, max(abs(currVal-right.first), abs(currVal-right.second)));
        ans = max(ans,currDiff);
        return {min(currVal,min(left.first,right.first)),  max(currVal, max(left.second,right.second))};
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        dfs(root);
        return ans;
    }
};