class Solution {
public:

    int peakCol(vector<vector<int>>& mat, int col){
        int n = mat.size();
        int max = INT_MIN;
        int max_row_index = -1;

        for (int i = 0; i < n; i++) {
            if (mat[i][col] > max) {
                max = mat[i][col];
                max_row_index = i;
            }
        }
        return max_row_index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0;
        int right = cols - 1;

        vector<int> ans;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            int peak_row = peakCol(mat, mid);

            int curr = mat[peak_row][mid];
            int leftVal  = (mid - 1 >= 0) ? mat[peak_row][mid - 1] : INT_MIN;
            int rightVal = (mid + 1 < cols) ? mat[peak_row][mid + 1] : INT_MIN;

            if (mid == 0 && curr > rightVal){ 
                return {peak_row, mid}; 
            } 
            else if (mid == cols - 1 && curr > leftVal){ 
                return {peak_row, mid}; 
            } 
            else if (curr > rightVal && curr > leftVal){ 
                return {peak_row, mid}; 
            } 
            else if (curr < leftVal) right = mid - 1;
            else if (curr < rightVal) left = mid + 1;
        }
        return ans;
    }
};