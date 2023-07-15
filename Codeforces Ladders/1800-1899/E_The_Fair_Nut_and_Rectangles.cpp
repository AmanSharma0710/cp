#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Line {
	mutable int m, c, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const int inf = LLONG_MAX;
	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->m == y->m) x->p = x->c > y->c ? inf : -inf;
		else x->p = div(y->c - x->c, x->m - y->m);
		return x->p >= y->p;
	}
	void add(int m, int c) {
		auto z = insert({m, c, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.c;
	}
};

signed main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, pair<int, int> > > aa(n); //use this instead of pair<pair<int, int>, int> to avoid TLE
	for(int i = 0; i < n; i++){
		cin >> aa[i].first >> aa[i].second.first >> aa[i].second.second;
	}
	sort(aa.begin(), aa.end());
	LineContainer lc;
	lc.add(0, 0);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x = aa[i].first;
		int y = aa[i].second.first;
		int a = aa[i].second.second;
		int f = lc.query(y);
		f += x * y - a;
		lc.add(-x, f);
		ans = max(ans, f);
	}
	cout << ans << '\n';
}