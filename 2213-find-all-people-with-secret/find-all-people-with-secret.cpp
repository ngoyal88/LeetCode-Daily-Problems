class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first) {
        vector<int> ans;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : meetings){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        vector<int> time(n,INT_MAX);
        time[0] = 0;
        time[first] = 0;

        q.push({0,0});
        q.push({first,0});

        while(!q.empty()){
            auto [u,t] = q.top();
            q.pop();

            if (t > time[u]) continue;

            for(auto &[v,t2] : adj[u]){
                if(t2 >= t && time[v] > t2){
                    time[v] = t2;
                    q.push({v,t2});
                }
            }
        }


        for(int i=0;i<n;i++){
            if(time[i] != INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};