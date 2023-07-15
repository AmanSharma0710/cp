#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}




signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int c;
    cin>>c;
    //0..n-1    numbers
    //n..2n-1   0..n-1
    //2n..3n-1  mask
    //3n        0
    //3n+1      2
    //3n+2..4n+1  F[i]*(mask)
    //4n+2..5n+1  i*(mask)
    //5n+2..6n+1  0 0 0 0 difference 0 0 0
    //6n+2..7n+1  cumulative sum
    //7n+2        cumulative sum *2
    //7n+3        cumulative sum > 0
    //7n+4        answer
    if(c==1){
        cout<<(6*n+5)<<endl;
        for(int i=0; i<n; i++){
            cout<<"put "<<i<<endl;
        }
        for(int i=0; i<n; i++){
            cout<<"compare "<<(i+n)<<" "<<(i)<<endl;
        }
        int idx0 = 3*n, idx2 = 3*n+1;
        cout<<"put 0"<<endl;
        cout<<"put 2"<<endl;
        for(int i=0; i<n; i++){
            cout<<"multiply "<<i<<" "<<(i+2*n)<<endl;
        }
        for(int i=0; i<n; i++){
            cout<<"multiply "<<(n+i)<<" "<<(i+2*n)<<endl;
        }
        for(int i=0; i<n; i++){
            cout<<"subtract "<<(3*n+2+i)<<" "<<(4*n+2+i)<<endl;
        }
        int idx = 6*n+2;
        cout<<"add "<<(5*n+2)<<" "<<idx0<<endl;
        for(int i=1; i<n; i++){
            cout<<"add "<<idx++<<" "<<(i+5*n+2)<<endl;
        }
        cout<<"multiply "<<idx2<<" "<<(7*n+1)<<endl;
        cout<<"compare "<<idx0<<" "<<(7*n+1)<<endl;
        cout<<"subtract "<<(7*n+2)<<" "<<(7*n+3)<<endl;
        return 0;
    }



    cout<<((n*(n-1)) + 1)<<endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout<<"compare "<<i<<" "<<j<<endl;
        }
    }
    int idx = n, idx2 = n + (n*(n-1))/2;
    cout<<"put "<<(n*(n-1))/2<<endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout<<"subtract "<<idx2++<<" "<<idx<<endl;
            idx++;
        }
    }
    return 0;
}
