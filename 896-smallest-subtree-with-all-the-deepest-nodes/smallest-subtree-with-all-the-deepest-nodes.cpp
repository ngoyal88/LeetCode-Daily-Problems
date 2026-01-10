/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        q.push(root);
        vector<TreeNode*> last;

        while (!q.empty()) {
            int n = q.size();
            last.clear();

            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                last.push_back(node);

                if (node->right != NULL) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
                if (node->left != NULL) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
            }
        }

        unordered_set<TreeNode*> st(last.begin(),last.end());
        while(st.size() > 1){
            unordered_set<TreeNode*> next;
            for(auto node : st){
                next.insert(parent[node]);
            }
            st = next;
        }
        return *st.begin();
    }
};