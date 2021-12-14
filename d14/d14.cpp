#include <bits/stdc++.h>
using namespace std;

void part1() {
    string poly, tmp;
    cin>>poly;
    unordered_map<string, char> mp;
    char a, b, c;
    scanf("\n");
    while (scanf("%c%c -> %c\n", &a, &b, &c)==3) {
        string s = "";
        s += a;
        s += b;
        mp[s] = c;
    }
    for (int k=0;k<10;k++) {
        cerr << "k=" << k << endl;
        for (int i = poly.size()-2;i>=0;--i) {
            string f = poly.substr(i, 2);
            if (mp.find(f)!=mp.end()) {
                poly.insert(poly.begin()+i+1, mp[f]);
            }
        }
    }
    uint64_t cnt[26] = {};
    for (int i=0;i<poly.size();i++) {
        cnt[poly[i]-'A']++;
    }
    int mn = 0, mx = 0;
    while (cnt[mn]==0)
        ++mn;
    for (int i=1;i<26;i++) {
        if (cnt[i]>0 && cnt[i]<cnt[mn]) {
            mn = i;
        }
        if (cnt[i]>cnt[mx])
            mx = i;
    }
    cout << cnt[mx] << " - " << cnt[mn] << " = " << cnt[mx]-cnt[mn] << endl;
}

int main() {
    part1();
    return 0;
}