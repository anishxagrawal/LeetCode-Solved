class Solution {
public:

    int trap(vector<int>& height) {

        int water = 0;
        int n = height.size();

        if (n < 3) return 0;
    
        vector<int> nGe(n, -1), pGe(n, -1);

        pGe[0] = 0;
        for (int i = 1; i < n; i++) {
            pGe[i] = max(pGe[i - 1], height[i - 1]);
        }

        nGe[n-1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            nGe[i] = max(nGe[i + 1], height[i + 1]);
        }

        for (int i = 1; i < n - 1; i++){
            
            int temp = min(nGe[i], pGe[i]);
            if (temp > height[i])
                water = water + (temp - height[i]);
        }
        return water;
    }
};