class Solution {
public:
    int minimumFlips(int n) {
        int ans=0;
        string bit;
        while(n){
            int d = n&1;
            bit += (d + '0');
            n>>=1;
        } 
        string rev = bit;
        reverse(rev.begin(),rev.end());
        for(int i=0;i<bit.size();i++){
            if(bit[i]!= rev[i]) ans++;
        }
        return ans;
    }
};