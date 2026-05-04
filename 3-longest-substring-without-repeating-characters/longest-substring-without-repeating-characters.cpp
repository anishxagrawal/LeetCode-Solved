class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<char, int> freq;

        while (right < n) {

            freq[s[right]]++;

            if (freq[s[right]] > 1) {
                while (freq[s[right]] != 1) {
                    freq[s[left]]--;
                    left++;
                    
                }
            }
            ans = max (ans, right - left + 1);
            right++;
        }
        return ans;
        
    }
};