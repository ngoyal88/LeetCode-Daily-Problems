class Solution {
public:
    bool possible(long long mid,int n,vector<int> & batteries){
        long long total = 0;
        for(long long it : batteries){
            total += min(it,mid);
        }
        return total >= (long long)n*mid;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total=0;
        for(auto &it : batteries)total += it;
        long long ans=0;
        long long lo = 0,hi = total/n;
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            if(possible(mid,n,batteries)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};