class Solution {
public:

 void findParenthesis(int open , int close , string &op , vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }

        if(open != 0){
            op += "(";
            findParenthesis(open-1 , close , op , ans);
            op.pop_back();
        }

        if(close>open){
            op += ")";
            findParenthesis(open , close-1 , op , ans);
            op.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
         int open = n;
       int close = n;
       string op = "";
       vector<string> ans;
       findParenthesis(open , close , op , ans);
       return ans;
    }
};