class Solution {
public:
    bool canShip(vector<int>& weights, int daily_capacity, int deadline) {

        int n = weights.size();
        int total_weight = 0;
        int days = 1;

        int i = 0;
        long long temp = 0;

        while (i < n) {
            
            temp = temp + weights[i];

            if (temp > daily_capacity){
                temp = 0;
                days++;
                i--;
            }
            i++;
        }
        if (days <= deadline) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int total_weight = 0;
        int max = INT_MIN;

        for (int i = 0; i < n; i++) {
            total_weight = total_weight + weights[i];
            if (weights[i] > max) max = weights[i];
        }

        int low = max; 
        int high = total_weight;
        int ans = 0;

        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if (canShip(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};