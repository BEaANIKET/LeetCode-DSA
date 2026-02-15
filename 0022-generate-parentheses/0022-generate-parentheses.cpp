class Solution {
public:

    vector<string> ans;

    void solve(int n , string s, int open, int close){
        if(open + close == n*2){
            ans.push_back(s);
            s = "";
            return ;
        }

        if(open > close){
            s.push_back(')');
            solve(n, s, open, close+1);
            s.pop_back();
        }

        if(s.empty() || open < n){
            s.push_back('(');
            solve(n, s, open+1, close);
            s.pop_back();
        }

        return ;
        
    }

    vector<string> generateParenthesis(int n) {
        solve(n, "", 0, 0);
        return ans;
    }
};