#include <bits/stdc++.h>
using namespace std;

void part1() {
    string s;
    cin>>s;
    vector<int> v;
    size_t pos = 0;
    do {
        string ns = s.substr(pos);
        v.push_back(stoi(ns));
        pos = s.find_first_of(",\n", pos+1);
        pos = s.find_first_not_of(",\n", pos);
    } while (pos!=string::npos);
    sort(v.begin(), v.end());
    int median = v[v.size()/2];
    int ans = 0;
    for (auto i: v) {
        ans += (median>i?median-i:i-median);
    }
    cout << "ans = " << ans << endl;
}

void part2() {
    string s;
    cin>>s;
    vector<int> v;
    size_t pos = 0;
    do {
        string ns = s.substr(pos);
        v.push_back(stoi(ns));
        pos = s.find_first_of(",\n", pos+1);
        pos = s.find_first_not_of(",\n", pos);
    } while (pos!=string::npos);
    double avg = 0;
    for (auto i: v) {
        avg += i;
    }
    avg /= v.size();
    int c = ceil(avg);
    int f = floor(avg);
    int ans = 0;
    for (auto i: v) {
        int a = abs((int)c-i);
        ans += a*(a+1)/2;
    }
    cout << "ceil ans = " << ans << endl;
    ans = 0;
    for (auto i: v) {
        int a = abs((int)f-i);
        ans += a*(a+1)/2;
    }
    cout << "floor ans = " << ans << endl;
}

int main() {
    part2();
    return 0;
}