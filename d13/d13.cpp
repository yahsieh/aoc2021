#include <bits/stdc++.h>
using namespace std;

bool arr[2000][2000];

int count(int maxx, int maxy) {
    int cnt = 0;
    for (int j=0;j<=maxy;j++) {
        for (int i=0;i<=maxx;i++) {
            cnt += arr[j][i];
        }
    }
    return cnt;
}


void print(int maxx, int maxy) {
    int cnt = 0;
    for (int j=0;j<=maxy;j++) {
        for (int i=0;i<=maxx;i++) {
            cerr << (arr[j][i]==1?"#":".") << (i==maxx?"\n":"");
            cnt += arr[j][i]==1;
        }
    }
    cout << "ans = " << cnt << endl;
    cout << endl;
}
void fold(int axis, int pos, int maxx, int maxy) {
    if (axis == 1) {
        // fold horizontal
        int diff = 1;
        while (pos+diff<=maxy && pos-diff>=0) {
            for (int i=0;i<=maxx;i++) {
                arr[pos-diff][i] |= arr[pos+diff][i];
            }
            ++diff;
        }
    } else {
        // fold horizontal
        int diff = 1;
        while (pos+diff<=maxx && pos-diff>=0) {
            for (int i=0;i<=maxy;i++) {
                arr[i][pos-diff] |= arr[i][pos+diff];
            }
            ++diff;
        }
    }
}

void part2() {
    int a, b, d, maxx=0, maxy=0;
    char c;
    vector<pair<int,int>> v;
    while (scanf("%d,%d", &a, &b)==2) {
        // cerr << a << ", " << b << endl;
        arr[b][a] = true;
        if (a>maxx)
            maxx=a;
        if (b>maxy)
            maxy=b;
    }
    while (scanf("fold along %c=%d\n", &c, &d)==2) {
        // cerr << "fold (" << c << ", " << d << ")\n";
        v.push_back(make_pair((int)(c=='y'), d));
    }
    // print(maxx, maxy);
    for (int i=0;i<v.size();i++) {
        fold(v[i].first, v[i].second, maxx, maxy);
        if (v[i].first)
            maxy = v[i].second-1;
        else
            maxx = v[i].second-1;
    }
    print(maxx, maxy);
}

int main() {
    part2();
    return 0;
}