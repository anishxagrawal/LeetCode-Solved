class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // int n1 = nums1.size();
        // int n2 = nums2.size();

        // vector<int> res;

        // int index = -1;

        // for (int i = 0; i < n1; i++){
        //     for (int j = 0; j < n2; j++) {
        //         if (nums1[i] == nums2[j]){
        //             index = j;
        //             break;
        //         }
        //     }

        //     bool found = false;

        //     for (int i = index + 1; i < n2; i++){
        //         if (nums2[index] < nums2[i]) {
        //             res.push_back(nums2[i]);
        //             found = true;
        //             break;
        //         }
        //     } if (!found) res.push_back(-1);
        // }
        // return res;


        stack<int> stack;
        unordered_map<int, int> nge;

        for (int num : nums2) {
            while (!stack.empty() && num > stack.top()){
                nge[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }

        while (!stack.empty()) {
            nge[stack.top()] = -1;
            stack.pop();
        }

        vector<int> res;
        for(int x : nums1) {
            res.push_back(nge[x]);
        }
        return res;
    } 
};