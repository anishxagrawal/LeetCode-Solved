class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if (nums.size() == 1 && nums[0] == k)
            return 1;

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int sum = nums[i];

            if (sum == k) count++;

            for (int j = i + 1; j < n; j++) {
                sum = sum + nums[j];    
                if (sum == k) count++;
            }
        }
        return count;
    }
};