class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        vector<bool> ans;
        for(auto &it : nums){
            num = ((num << 1) | it) % 5;
            ans.push_back(num == 0);
        }
        return ans;
    }
};