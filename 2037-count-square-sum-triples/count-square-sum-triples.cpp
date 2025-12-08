class Solution {
public:
    int sqrt(int n){
        int lo = 0,hi = n;
        while(lo <= hi){
            long long mid = (lo + hi) / 2;
            long long sq = mid * mid;
            if(sq == n) return mid;
            if(sq > n) hi = mid-1;
            else lo = mid+1;
        }
        return -1;
    }
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int c = (i*i) + (j*j);
                c = sqrt(c); 
                if(c!= -1 && c <= n)ans++;
            }
        }
        return ans;
    }
};