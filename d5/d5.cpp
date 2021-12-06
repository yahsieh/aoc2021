#include <bits/stdc++.h>
using namespace std;

#define LEN 1001

int diagram[LEN][LEN];

void print() {
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            cout << diagram[i][j] << (j==9?"\n":"");
        }
    }
    cout << endl;
}

int mx, my;
void calc() {
    int ans = 0;
    for (int i=0;i<=my;i++) {
        for (int j=0;j<=mx;j++) {
            ans += (diagram[i][j]>=2);
        }
    }
    cout << "ans = " << ans << endl;
}

void part1() {
    int a, b, c, d;
    while (scanf("%d,%d -> %d,%d", &a ,&b ,&c ,&d) != EOF) {
        int tmpx = max(a, c);
        if (tmpx>mx)
            mx=tmpx;
        int tmpy = max(b, d);
        if (tmpy>my)
            my=tmpy;
        if (a==c) {
            int l = min(b, d), r = b+d-l;
            for (int i=l;i<=r;i++) {
                ++diagram[i][a];
            }
        } else if (b==d) {
            int l = min(a, c), r = a+c-l;
            for (int i=l;i<=r;i++) {
                ++diagram[d][i];
            }
        }
    }
    // print();
    calc();
}

void part2() {
    int a, b, c, d;
    while (scanf("%d,%d -> %d,%d", &a ,&b ,&c ,&d) != EOF) {
        int tmpx = max(a, c);
        if (tmpx>mx)
            mx=tmpx;
        int tmpy = max(b, d);
        if (tmpy>my)
            my=tmpy;
        if (a==c) {
            int l = min(b, d), r = b+d-l;
            for (int i=l;i<=r;i++) {
                ++diagram[i][a];
            }
        } else if (b==d) {
            int l = min(a, c), r = a+c-l;
            for (int i=l;i<=r;i++) {
                ++diagram[d][i];
            }
        } else {
            int l, r, y1, y2;
            if (a < c) {
                l = a, y1 = b;
                r = c, y2 = d;
            } else {
                l = c, y1 = d;
                r = a, y2 = b;
            }
            int k = y1 < y2 ? 1 : -1;
            int tmpy = y1;
            for (int i=l;i<=r;i++) {
                ++diagram[tmpy][i];
                tmpy += k;
            }
        }
    }
    print();
    calc();
}

int main() {
    part2();
    return 0;
}