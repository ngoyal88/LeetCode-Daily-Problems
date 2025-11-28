class Solution {
public:
    int ans = 0,k;
    vector<vector<int>>  adj;
    int dfs(int node,int par,vector<int> &values){
        int sum = values[node];
        for(auto adjNode : adj[node]){
            if(adjNode != par){
                sum += dfs(adjNode,node,values);
            }
        }
        if(sum %k == 0)ans++;
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int K) {
        adj.resize(n);
        k = K;
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int t = dfs(0,-1,values);
        return ans;
    }
};