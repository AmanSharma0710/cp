#include <bits/stdc++.h>
using namespace std;
// building suffix links using memoization
// you can use exit_links(nearest ending of string is a suffix of you) to speed up pushing info to suffixes
// clear for multiple testcases then add dummy node
const int K = 63; // to be changed to 52 if lower and upper (numbers?)
struct Vertex {
    int next[K];
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int cnt = 0 , h = 0;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int getCharIndex(char ch) {
    if(ch == '-')
        return 62;
    return (isdigit(ch) ? 52 + (ch - '0') : (islower(ch) ? ch - 'a' : 26 + ch - 'A'));
}
int add_string(string const& s) {
    int v = 0, height = 0;
    for (char ch : s) {
        int c = getCharIndex(ch);
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
        t[v].h = ++height;
    }
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = getCharIndex(ch);
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

void solve() {

    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        nodes[i] = add_string(s);
    }

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;

        int v = 0;
        for(char c : s) {
            v = go(v, c);
            t[v].cnt++;
        }
    }

    vector<int> pool((int)t.size());
    iota(pool.begin(), pool.end(), 0);

    sort(pool.begin(), pool.end(), [&](auto x, auto y) {
        return t[x].h > t[y].h;
    });

    for(auto v : pool) {
        t[get_link(v)].cnt += t[v].cnt;
    }

    for(int i = 0 ; i < n ; ++i) {
        cout << t[nodes[i]].cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}