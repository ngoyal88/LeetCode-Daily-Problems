class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int &num : nums){
            num %=3;
            ans += min(num-0,3-num);
        }
        return ans;
    }
};