class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day){
        
        int n = bloomDay.size();
        int count = 0;
        int number_of_bouquet = 0;

        for (int i = 0; i < n; i++){
            if (bloomDay[i] <= day){
                count++;
                if(count == k){
                    number_of_bouquet++;
                    count = 0;
                }
            }
            else count = 0;
        }
        if (number_of_bouquet >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        long long temp =(long long) m * k;

        if (n < temp) return -1;

        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;

        while (left <= right){
            int mid = left + (right - left) / 2;

            if (canMake(bloomDay, m, k, mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};