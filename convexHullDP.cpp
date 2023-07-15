struct Line {
	mutable int m, c, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    /*
        Used to optimize DP transitions of the form:
        dp[i] = min(dp[j] + b[j] * a[i]) for j < i
    */

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
	int query(int x) {  //gives the maximum value of y for a given x
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.c;
	}
};