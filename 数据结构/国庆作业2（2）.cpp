#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isMatch(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty() || !isMatch(st.top(), c)) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    bool res = isValid(s);
    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
