class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2 == 0 || k%5 == 0)return -1;
        int ans = 0;
        int rem = 1;
        while(rem != 0 ){
            rem = (rem*10 + 1) % k;
            ans++;
        }
        return ans+1;
    }
};