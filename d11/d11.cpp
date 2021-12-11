#include <bits/stdc++.h>
using namespace std;
vector<string> v;
bool flashed[30][30];
int x, y;
int cnt;

void flash(int, int);
void inc(int, int);

void print() {
    for (int i=0;i<x;i++) {
        for (int j=0;j<y;j++) {
            cout << v[i][j] << (j==y-1?"\n":", ");
        }
    }
    cout << "-----------\n";
}

bool check() {
    char ret = '0';
    for (int i=0;i<x;i++) {
        for (int j=0;j<y;j++) {
            ret |= v[i][j];
        }
    }
    return ret == '0';
}

void update() {
    for (int i=0;i<30;i++)
        memset(flashed[i], 0 , sizeof(flashed[i]));
    for (int i=0;i<x;i++) {
        for (int j=0;j<y;j++) {
            inc(i, j);
        }
    }
    // print();
}

void inc(int a, int b) {
    if (flashed[a][b])
        return;
    else {
        v[a][b]++;
        if (v[a][b]>'9') {
            flashed[a][b] = true;
            v[a][b] = '0';
            flash(a,b);
        }
    }
}

void flash(int a, int b) {
    ++cnt;
    if (a-1>=0) {
        inc(a-1, b);
        if (b-1>=0)
            inc(a-1, b-1);
        if (b+1<y)
            inc(a-1, b+1);
    }
    if (b-1>=0)
        inc(a, b-1);
    if (a+1<x) {
        inc(a+1, b);
        if (b-1>=0)
            inc(a+1, b-1);
        if (b+1<y)
            inc(a+1,b+1);
    }
    if (b+1<y)
        inc(a, b+1);
}

void part1() {
    string s;
    while (cin>>s)
        v.push_back(s);
    x = v.size();
    y = v[0].size();
    for (int i=0;i<100;i++)
        update();
    print();
    cout << "cnt="<<cnt<<endl;
}

void part2() {
    string s;
    while (cin>>s)
        v.push_back(s);
    x = v.size();
    y = v[0].size();
    uint64_t ans = 0;
    while(!check()) {
        update();
        ++ans;
    }
    print();
    cout << "ans="<<ans<<endl;
}


int main() {
    part2();
    return 0;
}