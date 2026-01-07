class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        if(s== t)return 0;
        int n = s.size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                if(s[i] == '0') a++;
                if(s[i] == '1') b++;
            }
        }
        long long ans=0;
        int pairs = min(a,b);
        int r = a-pairs+b-pairs;
        long long cost1 = min(2*flipCost, swapCost);
        long long cost2 = min(2*flipCost, swapCost+crossCost);
        if(r%2 == 1){ ans += flipCost;} 
        r/=2;
        ans+=(cost1*pairs);
        ans+=(cost2*r);
        return ans;
    }
};