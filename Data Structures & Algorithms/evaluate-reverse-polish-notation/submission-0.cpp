class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;

        for (const auto& t : tokens) {
            if (t == "+") {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();

                s.push(t2 + t1);
            } else if(t == "-") {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();

                s.push(t2 - t1);
            } else if(t == "*") {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();

                s.push(t2 * t1);
            } else if( t == "/") {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();

                s.push(t2 / t1);
            } else {
                s.push(std::stoi(t));
            }
        }

        return s.top();
    }
};
