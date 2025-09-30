#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        long result = 0;    // current result
        int sign = 1;       // current sign (+1 or -1)
        stack<int> stk;     // to store (previous result, previous sign)
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                long num = 0;
                // build full number (can have multiple digits)
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // step back because for loop will increment
                result += sign * num;
            }
            else if (c == '+') {
                sign = 1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '(') {
                // Push current result and sign
                stk.push(result);
                stk.push(sign);
                // Reset for new sub-expression
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
        }
        
        return result;
    }
};
