class Solution {
public:
    int bestClosingTime(string customer) {
        int n = customer.size();
        vector<int> prefix(n+1,0),suffix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i];
            if(customer[i] == 'N')prefix[i+1]++; 
        }
        for(int i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1];
            if(customer[i] == 'Y') suffix[i]++;
        }
        int ans =0;
        int penalty = suffix[0];
        for(int i=1;i<=n;i++){
            int temp = prefix[i] + suffix[i];
            if(temp < penalty){
                penalty = temp;
                ans = i;
            }
        }
        return ans;
    }
};