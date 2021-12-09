#include <bits/stdc++.h>
using namespace std;

bool check(char target, vector<char> v) {
    // cerr << "target = " << target << endl;
    bool ret = true;
    for (int i=0;i<v.size();i++) {
        // cerr << v[i] << (i==v.size()-1?"\n":", ");
        ret &= target < v[i];
    }
    return ret;
}

bool visited[101][101];
int x, y;
vector<string> v;

void part1() {
    string s;
    vector<char> ans;
    while (cin>>s)
        v.push_back(s);
    for (int i=0;i<v.size();i++) {
        for (int j=0;j<v[i].size();j++) {
            vector<char> arg;
            if (i-1>=0)
                arg.push_back(v[i-1][j]);
            if (j-1>=0)
                arg.push_back(v[i][j-1]);
            if (i+1<v.size())
                arg.push_back(v[i+1][j]);
            if (j+1<v[i].size())
                arg.push_back(v[i][j+1]);
            if (check(v[i][j], arg)) {
                ans.push_back(v[i][j]);
            }
        }
    }
    uint64_t r = 0;
    for (int i=0;i<ans.size();i++) {
        cerr << ans[i] << endl;
        r += (ans[i]-'0');
    }
    r += ans.size();
    cout << r << endl;
}

int expand(int i, int j) {
    int ret = 0;
    if (visited[i][j] || v[i][j] == '9')
        return 0;
    else {
        visited[i][j] = true;
        ret = 1;
        if (i-1>=0)
            ret += expand(i-1, j);
        if (j-1>=0)
            ret += expand(i, j-1);
        if (i+1<x)
            ret += expand(i+1, j);
        if (j+1<y)
            ret += expand(i, j+1);
    }
    return ret;
}

void part2() {
    string s;
    priority_queue<int> pq;
    while (cin>>s)
        v.push_back(s);
    x = v.size();
    y = v[0].size();
    for (int i=0;i<v.size();i++) {
        for (int j=0;j<v[i].size();j++) {
            vector<char> arg;
            if (i-1>=0)
                arg.push_back(v[i-1][j]);
            if (j-1>=0)
                arg.push_back(v[i][j-1]);
            if (i+1<v.size())
                arg.push_back(v[i+1][j]);
            if (j+1<v[i].size())
                arg.push_back(v[i][j+1]);
            if (check(v[i][j], arg)) {
                pq.push(expand(i,j));
            }
        }
    }
    int a, b, c;
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    c = pq.top();
    pq.pop();
    cout << "(" << a<< ", " << b << ", " << c << ") "<< a*b*c << endl;
}

int main() {
    part2();
    return 0;
}