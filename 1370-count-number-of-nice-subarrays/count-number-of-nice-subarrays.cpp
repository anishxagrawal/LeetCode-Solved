class Solution {
public:
    int countAtmost(vector<int>& nums, int k){

        int n = nums.size();    
        int left = 0; 
        int count = 0;

        int oddCount = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2 == 1) oddCount++;

            while (oddCount > k){
                if (nums[left] % 2 == 1) 
                    oddCount--;

                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return countAtmost(nums, k) - countAtmost(nums, k - 1);
    }
};