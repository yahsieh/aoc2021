#include <bits/stdc++.h>
using namespace std;

#define A 0b0000001
#define B 0b0000010
#define C 0b0000100
#define D 0b0001000
#define E 0b0010000
#define F 0b0100000
#define G 0b1000000

#define ZERO A|B|C|E|F|G


void part1() {
    vector<string> v;
    string s;
    while(cin>>s) {
        for (int i=0;i<9;i++)
            cin>>s;
        cin>>s; // |
        for (int i=0;i<4;i++) {
            cin>>s;
            v.push_back(s);
        }
    }
    int cnt = 0;
    for (auto i: v) {
        if (i.size()==2 || i.size()==3 || i.size()==4 || i.size()==7)
            ++cnt;
    }
    cout << cnt << endl;
}

int mp[7];

void updateMapping(vector<string> &v) {
    string one, two, three, four, five, six, seven, eight, nine;
    vector<string> tv[8];
    for (auto i: v) {
        if (i.size()==2)
            one = i;
        else if (i.size()==3)
            seven = i;
        else if (i.size()==2)
            four = i;
        else if (i.size()==2)
            eight = i;
        else {
            tv[i.size()].push_back(i);
        }
    }
    // 1, 4, 5, 6, 7, 8
    char a = seven[seven.find_first_not_of(one)];
    mp[a-'a'] = A;
    for (int i=0;i<3;i++) {
        if (tv[6][i].find(one[0])==string::npos
            || tv[6][i].find(one[1])==string::npos)
            six = tv[6][i];
    }
    char c = eight[eight.find_first_not_of(six)];
    mp[c-'a'] = C;
    for (int i=0;i<3;i++) {
        if (tv[5][i].find(c)==string::npos)
            five = tv[5][i];
    }
    char e = six[six.find_first_not_of(five)];
    mp[e-'a'] = E;
}

void part2() {
    vector<string> v1, v2;
    string s;
    while(cin>>s) {
        v1.push_back(s);
        for (int i=0;i<9;i++) {
            v1.push_back(s);
        }
        cin>>s; // |
        for (int i=0;i<4;i++) {
            cin>>s;
            v2.push_back(s);
        }
    }
    int cnt = 0;
    cout << cnt << endl;
}

int main() {
    part1();
    return 0;
}