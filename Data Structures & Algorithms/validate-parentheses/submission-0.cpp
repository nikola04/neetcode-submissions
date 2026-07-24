class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for (char& c : s) {
            if (c == ')') {
                if (stck.empty() || stck.top() != '(')
                    return false;
                stck.pop();
            }
            else if (c == '}') {
                if (stck.empty() || stck.top() != '{')
                    return false;
                stck.pop();
            }
            else if (c == ']') {
                if (stck.empty() || stck.top() != '[')
                    return false;
                stck.pop();
            }
            else stck.push(c);
        }

        return stck.empty();
    }
};
