class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int> one,two;
        for(auto &it : nums){
            sum += it;
            if(it%3 == 1) one.push_back(it);
            else if(it%3 == 2) two.push_back(it);
        }
        if(sum % 3 == 0) return sum;

        sort(one.begin(),one.end()); 
        sort(two.begin(),two.end()); 

        int rem = sum%3;
        int ans=0;

        if(rem == 1){
            int remove1 = one.size() >= 1 ? one[0] : INT_MAX;
            int remove2 = two.size() >= 2 ? two[0]+two[1] : INT_MAX;
            ans = sum - min(remove1,remove2);
        }else{
            int remove1 = two.size() >= 1 ? two[0] : INT_MAX;
            int remove2 = one.size() >= 2 ? one[0]+one[1] : INT_MAX;
            ans = sum - min(remove1,remove2);
        }
        return ans<0 ? 0 : ans;
    }
};