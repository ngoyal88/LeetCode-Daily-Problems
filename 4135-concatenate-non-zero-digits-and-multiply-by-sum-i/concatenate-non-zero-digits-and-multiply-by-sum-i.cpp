class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        long long sum=0;
        long long x=0;
        sum = (s[0] - '0');
        x = (s[0] - '0');
        for(int i=1;i<s.size();i++){
            if(s[i]!= '0'){
                int d = s[i]-'0';
                sum += d;
                x = x*10+d;
            }
        }
        return  x*sum;        
    }
};