class Solution {
public:
    long long reverse(int n){
        int ans=0;
        while(n>0){
            ans = ans*10;
            ans += (n%10);
            n/=10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n- (int)reverse(n));
    }
};