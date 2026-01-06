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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = INT_MIN;
        int res = 1,level=1;
        while(!q.empty()){
            int n = q.size();
            int cost = 0;
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();            
                if(node->right != NULL ) q.push(node->right);
                if(node->left != NULL ) q.push(node->left);
                cost += node->val;
            }
            if(cost > ans){
               res = level;
               ans = cost;
            }
            level++;
        }
        return res;
    }
};