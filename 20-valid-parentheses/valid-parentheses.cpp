class Solution {
public:
    bool isValid(string s) {
        stack<char> open;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                open.push(s[i]);

            else {
                if(open.empty()) return false;

                char c = open.top();
                open.pop();

                if ((s[i] == ')' && c != '(') ||
                    (s[i] == ']' && c != '[') ||
                    (s[i] == '}' && c != '{')) return false;
            }
        }

        return open.empty();
    }
};