class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        long currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                currentNumber = currentNumber * 10 + (s[i] - '0');        
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if (operation == '+')
                    stack.push(currentNumber);
                else if (operation == '-')
                    stack.push(-currentNumber);
                else if (operation == '*'){
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * currentNumber);
                }
                else if (operation == '/'){
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / currentNumber);
                }
                operation = s[i];
                currentNumber = 0;
            }
        }
        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};