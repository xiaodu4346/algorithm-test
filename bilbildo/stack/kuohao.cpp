/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
    public:
        bool isValid(string s) {
            stack<char> cs;
            for (char h : s) {
                if (h=='('|| h=='[' || h=='{') {
                    //入栈
                    cs.push(h);
                }
                else{
                    if (cs.empty()) {
                        return false;
                    }
                    char cmp= cs.top();
                        //出栈
                        cs.pop();
                    if (cmp == '('&& h !=')'
                    || cmp == '['&& h !=']'
                    || cmp == '{'&& h !='}')
                    {
                        return false;
                    }
                }
            }
            return cs.empty();
        }
    };
    // @lc code=end
    
    