class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0)return n;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            auto it = upper_bound(nums.begin(),nums.end(),nums[i]);
            if(nums.end() - it >= k) ans++;
        }
        return ans;
    }
};