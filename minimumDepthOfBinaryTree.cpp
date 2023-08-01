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
class Solution {
public:
    void solve(int height , TreeNode* root , int&mini){
        if(root==NULL){
            return;
        }
        if(root->left ==NULL &&  root->right==NULL){
            mini = min(mini , height);
            return;
        }
        solve(height+1 , root->left , mini);
        solve(height+1,  root->right,  mini);
    }
    int minDepth(TreeNode* root) {
        int mini = INT_MAX;
        if(root==NULL){
            return 0;
        }
        solve(1, root, mini);
        return mini;
    }
};
