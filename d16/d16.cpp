#include <bits/stdc++.h>
using namespace std;

#define DBG_FLAG 1
#define DBG(x) if(DBG_FLAG) {x}

string h2b(string s) {
    string ret = "";
    for (int i=0;i<s.size();i++) {
        int k;
        if (s[i]>='0' && s[i]<='9') {
            k = s[i]-'0';
        }
        else {
            k = s[i]-'A'+10;
        }
        char a = (k&1)+'0';
        k>>=1;
        char b = (k&1)+'0';
        k>>=1;
        char c = (k&1)+'0';
        k>>=1;
        char d = (k&1)+'0';
        k>>=1;
        ret += d;
        ret += c;
        ret += b;
        ret += a;
    }
    return ret;
}

class packet {
public:
    int ver;
    int type;
    int lengthType;
    int length;
    long long literal;
    vector<packet> sub;
};

long long calc(vector<packet> &v, int op) {
    long long ret;
    switch (op)
    {
    case 0:
        for (int i=0;i<v.size();i++) {
            
        }
        break;
    default:
        cerr << "unhandled type" << op << endl;
        exit(1);
    }
}

packet parse(string s) {
    packet ret;
    int packetVersion = stoi(s.substr(0, 3), 0, 2);
    int typeId = stoi(s.substr(3, 3), 0, 2);
    ret.ver = packetVersion;
    ret.type = typeId;
    DBG(cerr<<"ver="<<ret.ver<<",type="<<ret.type<<endl;)
    int cnt = 6;
    if (typeId==4) {
        string lit = "";
        while(s[cnt]=='1') {
            lit += s.substr(cnt+1, 4);
            cnt += 5;
        }
        lit += s.substr(cnt+1, 4);
        DBG(cerr<<"lit="<<lit<<endl;)
        ret.literal = stoll(lit, 0, 2);
        DBG(cerr<<"literal="<<ret.literal<<endl;)
        ret.length = cnt + 5;
    } else if (typeId!=4) {
        int lengthType = (s[6]=='1');
        ret.lengthType = lengthType;
        int L, mul, pos;
        if (lengthType==0) {
            // total length in bits of sub-packets
            L = stoi(s.substr(7, 15), 0, 2);
            DBG(cerr << "ltype=" << lengthType << ",L="<<L<<endl;)
            pos = 7+15;
            while(pos-22<L) {
                DBG(cerr<<"pos="<<pos<<endl;)
                ret.sub.push_back(parse(s.substr(pos)));
                pos += ret.sub.back().length;
            }
            if (pos-22!=L) {
                DBG(cerr<<"parse failed: length not matched\n";)
                exit(1);
            }
        } else {
            // number of sub-packets
            L = stoi(s.substr(7, 11), 0, 2);
            DBG(cerr << "ltype=" << lengthType << ",L="<<L<<endl;)
            pos = 7+11;
            for (int i=0;i<L;i++) {
                ret.sub.push_back(parse(s.substr(pos)));
                pos += ret.sub.back().length;
            }
        }
        ret.length = pos;
    }
    DBG(cerr << "packet length = " << ret.length << endl;)
    return ret;
}

int traverse(packet p) {
    stack<packet> stk;
    stk.push(p);
    int ret = 0;
    while(!stk.empty()) {
        packet top = stk.top();
        stk.pop();
        ret += top.ver;
        if (top.type!=4) {
            for (int i=0;i<top.sub.size();i++)
                stk.push(top.sub[i]);
        } else {
            // cout << top.literal << endl;
        }
    }
    return ret;
}

void part1() {
    string in, s;
    cin>>in;
    s = h2b(in);
    packet root = parse(s);
    cout << "total ver = "<< traverse(root) << endl;
}

int main() {
    part1();
    return 0;
}