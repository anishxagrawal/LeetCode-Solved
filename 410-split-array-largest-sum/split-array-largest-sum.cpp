class Solution {
public:
    int countSubArrays(vector<int>nums, int maxSum) {

        int n = nums.size();
        int count = 1;
        int currSum = 0;

        for (int i = 0; i < n; i++) {
            if (currSum + nums[i] <= maxSum){
                currSum += nums[i];
            }
            else {
                count ++;
                currSum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // required = number of subarrays needed if max allowed sum = mid
            int required = countSubArrays(nums, mid);
            
            if (required <= k) {
                ans = mid; 
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};