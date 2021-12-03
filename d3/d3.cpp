#include <bits/stdc++.h>
using namespace std;

void part1() {
    int arr[20] = {};
    int cnt = 0;
    string s;
    int sz;
    while (cin>>s) {
        sz = s.size();
        for (int i=0;i<sz;i++)
            arr[i] += s[i]-'0';
        ++cnt;
    }
    for (int i=0;i<sz;i++) {
        if (arr[i] >= cnt/2) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
    int gamma = 0, epsilon = 0, mul = 1;
    for (int i=sz-1;i>=0;--i) {
        gamma += arr[i]*mul;
        epsilon += (!arr[i])*mul;
        mul*=2;
    }
    cout << gamma << ", " << epsilon << ", " << gamma*epsilon << endl;
}


int calcOxy(vector<string> tmp) {
    vector<string> v0, v1;
    int cnt = 0, sz = tmp[0].size();
    while (tmp.size()>1) {
        for (int i=0;i<tmp.size();i++) {
            if (cnt>=sz) {
                exit(1);
            }
            if (tmp[i][cnt]=='0')
                v0.push_back(tmp[i]);
            else
                v1.push_back(tmp[i]);
        }
        tmp.clear();
        if (v0.size()>v1.size()) {
            tmp = v0;
        } else if (v0.size()<v1.size()) {
            tmp = v1;
        } else {
            // v0.size == v1.size
            // oxy do 1, co2 do 0
            tmp = v1;
        }
        v0.clear();
        v1.clear();
        ++cnt;
    }
    int oxy = 0, mul = 1;
    for (int i=tmp[0].size()-1;i>=0;i--) {
        if ((char)tmp[0][i] == '1')
            oxy += mul;
        mul *= 2;
    }
    return oxy;
}

int calcCO2(vector<string> tmp) {
    vector<string> v0, v1;
    int cnt = 0, sz = tmp[0].size();
    while (tmp.size()>1) {
        for (int i=0;i<tmp.size();i++) {
            if (cnt>=sz) {
                exit(1);
            }
            if (tmp[i][cnt]=='0')
                v0.push_back(tmp[i]);
            else
                v1.push_back(tmp[i]);
        }
        tmp.clear();
        if (v0.size()<v1.size()) {
            tmp = v0;
        } else if (v0.size()>v1.size()) {
            tmp = v1;
        } else {
            // v0.size == v1.size
            // oxy do 1, co2 do 0
            tmp = v0;
        }
        v0.clear();
        v1.clear();
        ++cnt;
    }
    int co2 = 0, mul = 1;
    for (int i=tmp[0].size()-1;i>=0;i--) {
        if ((char)tmp[0][i] == '1')
            co2 += mul;
        mul *= 2;
    }
    return co2;
}

void part2() {
    int arr[20] = {};
    int cnt = 0;
    string s;
    vector<string> tmp;
    while (cin>>s) {
        tmp.push_back(s);
    }
    int oxy = calcOxy(tmp);
    int co2 = calcCO2(tmp);
    cout << oxy << ", " << co2 << ", " << oxy*co2 << endl;
}

int main() {
    part2();
    return 0;
}