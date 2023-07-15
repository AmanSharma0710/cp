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


class Solution {
public:
    long long colosseum(int N,vector<int> A) {
        priority_queue<int,vi,greater<int>> minheap;
        priority_queue<int,vi,less<int>> maxheap;
        vector<long long> summax(N+1,0);
        vector<long long> summin(N+1,0);
        long long sum = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            minheap.push(A[i]);
        }
        summax[0] = sum;
        for(int i=0;i<N;i++){
            minheap.push(A[N+i]);
            sum += A[N+i];
            int minx = minheap.top();
            minheap.pop();
            sum -= minx;
            summax[i+1] = sum;
        }
        sum = 0;
        for(int i=0;i<N;i++){
            sum += A[2*N+i];
            maxheap.push(A[2*N+i]);
        }
        summin[N] = sum;
        for(int i=N-1;i>=0;i--){
            maxheap.push(A[N + i]);
            sum += A[N + i];
            int maxx = maxheap.top();
            maxheap.pop();
            sum -= maxx;
            summin[i] = sum;
        }
        long long ans = INT_MIN;
        for(int i=0;i<N;i++){
            ans = max(ans,summax[i]-summin[i]);
        }
        return ans;
   }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        Solution obj;
        int n;
        cin>>n;
        vector<int> a(3*n);
        rep(i,0,3*n){
            cin>>a[i];
        }
        cout<<obj.colosseum(n,a)<<endl;
    }
    return 0;
}
