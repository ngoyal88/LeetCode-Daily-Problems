class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });

        int cnt =0;
        int last = INT_MIN;
        for(auto &p : pairs){
            if(p[0] > last){
                cnt++;
                last = p[1];
            }
        }
        return cnt;
    }
};