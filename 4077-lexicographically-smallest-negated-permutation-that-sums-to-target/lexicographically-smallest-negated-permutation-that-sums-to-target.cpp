class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum = 1LL*n*(n+1)/2;
        if(llabs(target) > sum || (sum-target)%2 == 1) return {};
        vector<int> ans;
        if(target == sum){
            for(int i=1;i<=n;i++) ans.push_back(i);
            return ans;
        } 

        long long Diff = (sum - target);
        for(int i=n;i>0;i--){
            if(Diff >= 2*i){
                Diff-=(2*i);
                ans.push_back(-i);
            } 
            else{
                ans.push_back(i);
            }
        }    
        sort(ans.begin(),ans.end());
        return ans;
    }
};