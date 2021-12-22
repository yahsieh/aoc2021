#include <bits/stdc++.h>
using namespace std;
#define SHIFT 131072
#define MAX 262144

void part1() {
    char buf[10];
    bool arr[101][101][101]={};
    int x1,x2,y1,y2,z1,z2;
    while (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d\n", buf, &x1, &x2, &y1, &y2, &z1, &z2)==7) {
        // fprintf(stderr, "(%d,%d,%d,%d,%d,%d)\n", x1, x2, y1, y2, z1, z2);
        if (x1<-50) x1=-50;
        if (x2>50) x2=50;
        if (y1<-50) y1=-50;
        if (y2>50) y2=50;
        if (z1<-50) z1=-50;
        if (z2>50) z2=50;
        if (x1>x2 || y1>y2 || z1>z2) {
            // fprintf(stderr, "(%d,%d,%d,%d,%d,%d)\n", x1, x2, y1, y2, z1, z2);
            continue;
        }
        for (int i=x1;i<=x2;i++)
            for (int j=y1;j<=y2;j++)
                for (int k=z1;k<=z2;k++)
                    arr[i+50][j+50][k+50] = (strcmp(buf, "on") == 0);
    }
    int cnt = 0;
    for (int i=0;i<=100;i++)
        for (int j=0;j<=100;j++)
            for (int k=0;k<=100;k++)
                cnt += arr[i][j][k];
    cout << "ans = " << cnt << endl;
}

class Node {
    int64_t l, r;
    Node *left, *right;
    Node () {
        l=r=mark=0;
        left=nullptr;
        right=nullptr;
    }
    Node (int _l, int _r) {
        l=_l,r=_r;
    }
};

void part2() {
    char buf[10];
    int x1,x2,y1,y2,z1,z2;
    while (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d\n", buf, &x1, &x2, &y1, &y2, &z1, &z2)==7) {
    }
}

int main() {
    part2();
    return 0;
}
