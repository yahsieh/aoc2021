#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

void part1() {
    string s;
    int a;
    pair<int,int> p;
    p.x = p.y = 0;
    while (cin>>s>>a) {
        if (s=="forward") {
            p.x += a;
        } else if (s=="down") {
            p.y += a;
        } else if (s=="up") {
            p.y -= a;
        } else {
            // shouldn't happen
        }
    }
    cout << "("<< p.x << ", "<<p.y << "), ans = "<<p.x*p.y << endl;
}

void part2() {
    string s;
    int a;
    pair<int,int> p;
    p.x = p.y = 0;
    int aim = 0;
    while (cin>>s>>a) {
        if (s=="forward") {
            p.x += a;
            p.y += aim*a;
        } else if (s=="down") {
            aim += a;
        } else if (s=="up") {
            aim -= a;
        } else {
            // shouldn't happen
        }
    }
    cout << "("<< p.x << ", "<<p.y << "), ans = "<<p.x*p.y << endl;
}


int main() {
    part2();
    return 0;
}