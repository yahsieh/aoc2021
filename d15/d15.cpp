#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define DBG_FLAG 1
#define DBG(x) if(DBG_FLAG) {x}

void part1() {
    string s;
    int x, y=0;
    int dp[600] = {};
    bool init = true;
    while (cin>>s) {
        x = s.size();
        for (int i=0;i<s.size();i++) {
            if (init && i==0) {
                dp[0] = 0;
            } else {
                int left = (i>0?dp[i-1]:INT_MAX);
                int up = (init?INT_MAX:dp[i]);
                dp[i] = min(left,up) + (s[i]-'0');
            }

        }
        if(init) init=false;
        // for (int i=0;i<x;i++) {
        //     cout << dp[i] << (i==x-1?"\n":", ");
        // }
    }
    for (int i=0;i<x;i++) {
        cout << dp[i] << (i==x-1?"\n":", ");
    }
}

int getNum(char c, int inc=0) {
    int ret = c-'0'+inc;
    if (ret > 9) {
        ret %= 9;
        ret = (ret==0?9:ret);
    }
    return ret;
}

void part2() {
    string s;
    int x;
    int dp[1000] = {};
    bool init = true;
    vector<string> v;
    while (cin>>s) {
        v.push_back(s);
    }
    int sz = s.size();
    x = s.size() * 5;
    for (int l=0;l<5;l++) {
        for (int j=0;j<v.size();j++) {
            for (int k=0;k<5;k++) {
                for (int i=0;i<s.size();i++) {
                    if (init && i+k*sz==0) {
                        dp[0] = 0;
                        DBG(
                        cerr << "0";
                        )
                    } else {
                        int left = (i+k*sz>0?dp[i+k*sz-1]:INT_MAX);
                        int up = (init?INT_MAX:dp[i+k*sz]);
                        // cerr << "(" << left << ", " << up << ")\n";
                        dp[i+k*sz] = min(left,up) + getNum(v[j][i], k+l);
                        DBG(
                        cerr << getNum(v[j][i], k+l);
                        )
                    }
                }
            }
            if(init) init=false;
            DBG(
            cerr << endl;
            )
            // for (int i=0;i<x;i++) {
            //     cerr << dp[i] << (i==x-1?"\n":", ");
            // }
        }
    }
    // for (int i=0;i<x;i++) {
    //     cout << dp[i] << (i==x-1?"\n":", ");
    // }
}

int main() {
    part1();
    return 0;
}