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
    const int MOD = 1e9+7;
    long long total = 0;
    long long ans = 0;
    int getTotal(TreeNode* root){
        if(!root) return 0;
        return root->val + getTotal(root->right) + getTotal(root->left);
    }
    long long dfs(TreeNode* node){
        if(!node)return 0;

        long long right = dfs(node->right);
        long long left = dfs(node->left);

        long long sub = left + right + node->val;
        long long prod = sub * (total-sub);

        ans = max(ans,prod);
        return sub;
    }
    int maxProduct(TreeNode* root) {
     total = getTotal(root);
     long long temp = dfs(root);
     return ans%MOD;
    }
};