class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days) {

        int n = weights.size();
        int days_used = 1;
        int current_load = 0;

        for (int w : weights){
            
            if (current_load + w <= capacity) 
                current_load += w;

            else {
                days_used++;
                current_load = w;
            }
        }
        return days_used <= days;
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