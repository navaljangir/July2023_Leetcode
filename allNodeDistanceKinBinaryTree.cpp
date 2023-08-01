/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        unordered_map<TreeNode* , TreeNode*> parent;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0 ;i<n;i++){
                TreeNode* front = q.front();
                 q.pop();
                 if(front->left){
                     q.push(front->left);
                     parent[front->left]=front;
                 }
                 if(front->right){
                     q.push(front->right);
                     parent[front->right]=front;
                 }
            }
        }
        unordered_map<TreeNode* , bool > visited;
        q.push(target);
        while(k>0 && !q.empty()){
            int n = q.size();
            for(int i =0 ; i<n ;i++){
                TreeNode* front = q.front();
                q.pop();
                visited[front]=true;
                if(front->left && visited[front->left]==false){
                    q.push(front->left);
                }
                if(front->right && visited[front->right]==false){
                    q.push(front->right);
                }
                if(parent[front] && visited[parent[front]]==false){
                    q.push(parent[front]);
                }
            }
            k--;
        }
        vector<int> v;
        while(!q.empty()){
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
};
