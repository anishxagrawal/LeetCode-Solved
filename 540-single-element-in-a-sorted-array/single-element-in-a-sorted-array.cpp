class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1])
                    left = mid + 1;
                else right = mid;
            }

            if (mid % 2 != 0){
                if (nums[mid - 1] == nums[mid])
                    left = mid + 1;                    
                else right = mid;

            }
        }
        return nums[left];
    }
};