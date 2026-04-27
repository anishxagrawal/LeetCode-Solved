class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        

        int n = nums.size();

        int left = 0;
        int right = n - 1;
        int lb = n, ub = n;


        while (left <= right) {

            int mid = left + (right - left) / 2;
            
            if (target <= nums[mid]){
                lb = mid;
                right = mid -1;
            }
            else left = mid + 1;
        }

        if (lb == n || target != nums[lb]) return {-1, -1};

        left = 0;
        right = n - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            
            if (target < nums[mid]){
                right = mid -1;
            }
            else left = mid + 1;
        }
        ub = left - 1;
        return {lb, ub};

    }
};