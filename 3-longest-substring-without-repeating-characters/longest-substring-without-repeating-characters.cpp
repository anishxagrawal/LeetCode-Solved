class Solution {
public:

    bool uniqueChar(string s) {

        unordered_map<char, int> freq;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
            if (freq[s[i]] > 1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        
        int left = 0;
        int right = 0;

        string res;
        int ans = 0;
        int j = 0;

        while (right <= n - 1) {

        res = s.substr(left, right - left + 1);

            if (!uniqueChar(res)) {
                left++;
            }

            ans = right - left + 1;
            right++;
        }
        return ans;
    }
};