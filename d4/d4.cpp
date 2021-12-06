#include<bits/stdc++.h>
using namespace std;

class bingo {
public:
    int val[5][5];
    bool marked[5][5];
    unordered_map<int,pair<int,int>> ump;
    void print() {
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                cout << val[i][j] << (j==4?"\n": ", ");
        cout << endl;
    }
    void printMarked() {
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                cout << marked[i][j] << (j==4?"\n": ", ");
        cout << endl;
    }
    void mark(int a) {
        unordered_map<int,pair<int,int>>::iterator it = ump.find(a);
        if (it!=ump.end()) {
            marked[it->second.first][it->second.second] = true;
        }
    }
    bool checkWin() {
        for (int i=0;i<5;i++) {
            bool ans1 = marked[i][0];
            bool ans2 = marked[0][i];
            for (int j=1;j<5;j++) {
                ans1 &= marked[i][j];
                ans2 &= marked[j][i];
            }
            if (ans1 || ans2)
                return true;
        }
        return false;
    }
    void calcWin(int lastCalled) {
        int sumOfUnmarked = 0;
        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                if (!marked[i][j]) {
                    sumOfUnmarked += val[i][j];
                }
            }
        }
        cerr << "sum = " << sumOfUnmarked << ", last = "
             << lastCalled << " ans = " << sumOfUnmarked*lastCalled << endl;
        exit(0);
    }
    bingo() {
        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                val[i][j] = 0;
                marked[i][j] = false;
            }
        }
    }
};

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
    int tmp[5];
    vector<bingo> bv;
    while (cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>tmp[4]) {
        bingo b;
        for (int i=0;i<5;i++) {
            b.val[0][i] = tmp[i];
            b.ump[tmp[i]] = make_pair(0, i);
        }
        for (int i=1;i<5;i++) {
            cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>tmp[4];
            for (int j=0;j<5;j++) {
                b.val[i][j] = tmp[j];
                b.ump[tmp[j]] = make_pair(i, j);
            }
        }
        bv.push_back(b);
    }
    for (int i=0;i<5;i++) {
        for (int j=0;j<bv.size();j++) {
            bv[j].mark(v[i]);
        }
    }
    bool win = false;
    for (int i=0;i<bv.size();i++) {
        win = bv[i].checkWin();
        if (win) {
            bv[i].print();
            bv[i].printMarked();
        }
    }
    int cnt = 5;
    while (!win && cnt < v.size()) {
        for (int j=0;j<bv.size();j++) {
            bv[j].mark(v[cnt]);
        }
        for (int i=0;i<bv.size();i++) {
            win = bv[i].checkWin();
            if (win) {
                bv[i].print();
                bv[i].printMarked();
                bv[i].calcWin(v[cnt]);
                return;
            }
        }
        ++cnt;
    }
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
    int tmp[5];
    vector<bingo> bv;
    while (cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>tmp[4]) {
        bingo b;
        for (int i=0;i<5;i++) {
            b.val[0][i] = tmp[i];
            b.ump[tmp[i]] = make_pair(0, i);
        }
        for (int i=1;i<5;i++) {
            cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>tmp[4];
            for (int j=0;j<5;j++) {
                b.val[i][j] = tmp[j];
                b.ump[tmp[j]] = make_pair(i, j);
            }
        }
        bv.push_back(b);
    }
    for (int i=0;i<5;i++) {
        for (int j=0;j<bv.size();j++) {
            bv[j].mark(v[i]);
        }
    }
    for (int i=0;i<bv.size();i++) {
        int totalWin = 0;
        if (bv[i].checkWin()) {
            ++totalWin;
        }
        if (totalWin == bv.size()) {
            int k = 0;
            while (k < bv.size() && bv[k].checkWin())
                ++k;
            bv[k].calcWin(v[i]);
        }
    }
    int cnt = 5;
    while (cnt < v.size()) {
        for (int j=0;j<bv.size();j++) {
            bv[j].mark(v[cnt]);
        }
        int totalWin = 0;
        for (int i=0;i<bv.size();i++) {
            if (bv[i].checkWin()) {
                ++totalWin;
            }
        }
        if (totalWin == bv.size()-1) {
            int k = 0;
            while (k < bv.size() && bv[k].checkWin())
                ++k;
            cerr << "k=" << k << endl;
            ++cnt;
            while(cnt < v.size() && !bv[k].checkWin()) {
                bv[k].mark(v[cnt++]);
            }
            bv[k].print();
            bv[k].printMarked();
            bv[k].calcWin(v[cnt-1]);
        }
        ++cnt;
    }
}

int main() {
    part2();
    return 0;
}