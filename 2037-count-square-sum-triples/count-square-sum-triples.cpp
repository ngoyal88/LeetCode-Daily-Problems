class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        
        for (int c = 1; c <= n; ++c) {
            int target = c * c;
            int left = 1;
            int right = c - 1;
            
            while (left < right) {
                int sum = left * left + right * right;
                
                if (sum == target) {
                    count += 2;
                    left++;
                    right--;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        
        return count;
    }
};