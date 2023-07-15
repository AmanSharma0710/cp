#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

int power(int x, unsigned int y, int p){
    int res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1){
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int a, int p){
    return power(a, p - 2, p);
}

vector<int> factorial;

int nCr(int n, int r, int p){
    return (((factorial[n] * modInverse(factorial[r], p)) % p) * modInverse(factorial[n - r], p) % p) % p;
}

signed main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    factorial.assign(100005, 1);
    for(int i = 1; i < 100005; i++){
        factorial[i] = (factorial[i - 1] * i) % 1000000007;
    }
    int n = t+1;
    int r = 0;
    int res = 0;
    while(r <= n){
       res = (res + nCr(n, r, MOD) )% MOD;
       n--;
       r++;
    }
    cout << res << endl;
    return 0;
}