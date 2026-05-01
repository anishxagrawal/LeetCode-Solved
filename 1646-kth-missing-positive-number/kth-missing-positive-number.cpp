class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            int no_of_missing_elements = arr[mid] - (mid + 1);

            if (no_of_missing_elements < k)
                left = mid + 1;

            else if (no_of_missing_elements >= k){
                right = mid - 1;
            }
        }
        return left + k;
    }
};
