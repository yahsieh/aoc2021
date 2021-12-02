#include <bits/stdc++.h>
using namespace std;

void part1() {
    int i, prev;
    bool first = true;
    uint64_t counter = 0;
    while (cin>>i) {
        cout << i << endl;
         if (i>prev)
            ++counter;
        prev = i;
    }
    cout << counter << endl;
}

void part2() {
    int i;
    list<int> prev;
    bool first = true;
    uint64_t ans = 0, cnt = 0;
    while (cin>>i) {
        prev.push_back(i);
        if (prev.size() > 4)
            prev.pop_front();
        if (cnt >= 3 && prev.back()>prev.front()) {
            ++ans;
        }
        ++cnt;
    }
    cout << ans << endl;
}

int main() {
    part2();
    return 0;
}