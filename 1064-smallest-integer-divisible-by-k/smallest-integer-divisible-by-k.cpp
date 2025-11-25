class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0) return -1;
        long long n = 1;
        for(int i=1;;i++){
            if(n%k == 0) return i;
            n = (n*10+1)%k;
        }
        return -1;
    }
};