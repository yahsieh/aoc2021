#include <bits/stdc++.h>
using namespace std;

#define DBG_FLAG 1
#define DBG(x) if(DBG_FLAG) {x}

bool isOpen(char c) {
    return c == '[' || c=='{' || c=='(' || c=='<';
}

bool isClose(char c) {
    return c == ']' || c=='}' || c==')' || c=='>';
}

bool match(char l, char r) {
    if (l=='[')
        return r==']';
    if (l=='{')
        return r=='}';
    if (l=='(')
        return r==')';
    if (l=='<')
        return r=='>';
    return false;
}

int64_t calc(char c) {
    if (c==')')
        return 3;
    else if (c==']')
        return 57;
    else if (c=='}')
        return 1197;
    else if (c=='>')
        return 25137;
    return 0;
}

int64_t calc2(char c) {
    if (c=='(')
        return 1;
    else if (c=='[')
        return 2;
    else if (c=='{')
        return 3;
    else if (c=='<')
        return 4;
    return 0;

}

void part1() {
    vector<string> v, corrupted;
    string s;
    stack<char> stk;
    int64_t point = 0;
    while (cin>>s) {
        bool isCorrupt = false;
        char c;
        if (isClose(s[0])) {
            // corrupt
            isCorrupt = true;
            c = s[0];
        }
        stk.push(s[0]);
        for (int i=1;i<s.size();i++) {
            if (isOpen(s[i]))
                stk.push(s[i]);
            else {
                if (!stk.empty()) {
                    char topC = stk.top();
                    if (match(topC, s[i]))
                        stk.pop();
                    else {
                        // corrupt
                        isCorrupt = true;
                        c = s[i];
                        break;
                    }
                } else {
                    // corrupt
                    isCorrupt = true;
                    c = s[i];
                    break;
                }
            }
        }
        if (isCorrupt) {
            point += calc(c);
        }
        else if (!stk.empty()) {
            // incomplete
        }
    }
    cout << "ans = " << point << endl;
}

void part2() {
    vector<string> v, corrupted;
    vector<int64_t> score;
    string s;
    stack<char> stk;
    int64_t point = 0;
    while (cin>>s) {
        char c;
        if (isClose(s[0])) {
            // corrupt
        }
        stk.push(s[0]);
        for (int i=1;i<s.size();i++) {
            if (isOpen(s[i]))
                stk.push(s[i]);
            else {
                if (!stk.empty()) {
                    char topC = stk.top();
                    if (match(topC, s[i]))
                        stk.pop();
                    else {
                        // corrupt
                        while(!stk.empty())
                            stk.pop();
                        break;
                    }
                } else {
                    // corrupt
                    while(!stk.empty())
                        stk.pop();
                    break;
                }
            }
        }
        if (!stk.empty()) {
            // incomplete
            int64_t cnt = 0;
            while (!stk.empty()) {
                char c1 = stk.top();
                stk.pop();
                DBG(cerr<<c1;)
                cnt *= 5;
                cnt += calc2(c1);
            }
            DBG(cerr<<endl;)
            score.push_back(cnt);
        }
    }
    sort(score.begin(), score.end());
    for (auto i: score) {
        cerr << i << endl;
    }
    cout << "ans = " << score[score.size()/2] << endl;
}
int main() {
    part2();
    return 0;
}