#include <bits/stdc++.h>
using namespace std;

uint64_t fish[9];

void print() {
    uint64_t ans = 0;
    for (int i=0;i<9;i++) {
        cout << fish[i] << (i==8?"\n":", ");
        ans += fish[i];
    }
    cout << "ans = " << ans << endl;
}

void move1() {
    uint64_t tmp = fish[0];
    for (int j=0;j<8;j++) {
        fish[j] = fish[j+1];
    }
    fish[8] = 0;
    if (tmp>0) {
        fish[8] = tmp;
        fish[6] += tmp;
    }
}

void move18() {
    for (int i=0;i<18;i++) {
        move1();
    }
}

void move80() {
    for (int i=0;i<80;i++) {
        move1();
    }
}

void move256() {
    for (int i=0;i<256;i++) {
        move1();
    }
}

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
    for (auto i: v) {
        ++fish[i];
    }
    move80();
    // move256();
    print();
}

int main() {
    part1();
    return 0;
}