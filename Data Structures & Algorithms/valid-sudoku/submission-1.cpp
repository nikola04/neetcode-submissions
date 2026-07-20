class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (char c : board[i]) {
                if (c == '.') continue;
                int n = c - '0';
                if (s.find(n) != s.end())
                    return false;
                s.insert(n);
            }
        }

        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = 0; j < n; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                int n = c - '0';
                if (s.find(n) != s.end())
                    return false;
                s.insert(n);
            }
        }

        map<int, set<int>> ms;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                int n = c - '0';

                int idx = (i / 3) * 3 + (j / 3);
                set<int>& s = ms[idx];

                if (s.find(n) != s.end())
                    return false;
                s.insert(n);
            }
        }

        return true;
    }
};
