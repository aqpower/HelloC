/*
function:不使用
variable:
*/
#include "algorithm"
#include "cstring"
#include "iostream"
#include "stack"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

void calu(stack<double> &nums, stack<char> &op) {
    double b = nums.top();
    nums.pop();
    double a = nums.top();
    nums.pop();
    switch (op.top()) {
    case '+':
        nums.push(a + b);
        op.pop();
        break;
    case '-':
        nums.push(a - b);
        op.pop();
        break;
    case '*':
        nums.push(a * b);
        op.pop();
        break;
    case '/':
        nums.push(a / b);
        op.pop();
        break;
    }
}

double solve(string s) {
    stack<double> nums;
    stack<char> op;
    unordered_map<char, int> priority = {{'(', 0}, {'-', 1}, {'+', 1},
                                         {'*', 2}, {'/', 2}, {')', 3}};
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            double num = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i++] - '0';
            }
            nums.push(num);
            i--;
        } else {
            if (s[i] == '(') {
                op.push(s[i]);
            } else if (s[i] == ')') {
                while (nums.size() >= 2 && op.top() != '(') {
                    calu(nums, op);
                }
                op.pop();
            } else {
                while (nums.size() >= 2 && !op.empty() &&
                       priority[op.top()] >= priority[s[i]]) {
                    calu(nums, op);
                }
                op.push(s[i]);
            }
        }
    }
    while (nums.size() >= 2 && !op.empty()) {
        calu(nums, op);
    }
    return nums.top();
}

int main() {
    int t;
    string s;
    while (cin >> t && t != -1) {
        cin >> s;
        cout << solve(s) << endl;
    }
    system("pause");
    return 0;
}
