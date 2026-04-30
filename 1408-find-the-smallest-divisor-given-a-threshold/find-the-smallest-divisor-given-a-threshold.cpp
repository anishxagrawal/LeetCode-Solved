class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int max = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > max) max = nums[i];
        }

        int left = 1;
        int right = max;
        int ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            int sum = 0;

            for (int i = 0; i < n; i++) {
                int temp = (nums[i] + mid - 1) / mid;
                sum = sum + temp;
            }

            if (sum <= threshold) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};