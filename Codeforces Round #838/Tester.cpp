#include<bits/stdc++.h>
using namespace std;

vector<int> gl;

int getNum(vector<int>& v)
{
    int n = v.size();
    srand(time(NULL));
    int index = rand() % n;
    int num = v[index];
    swap(v[index], v[n - 1]);
    v.pop_back();
    return num;
}
 
void generateRandom(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
 
    while (v.size()) {
        gl.push_back(getNum(v));
    }
}

int rand(int a, int b){
    return a + (rand() % (b-a+1));
}


signed main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = rand(1, 10);
    cout<<t<<endl;
    while(t--){
        int n = rand(2, 10);
        gl.assign(0, 0);
        generateRandom(n);
        for(int i=0; i<n; i++){
            cerr<<gl[i]<<" ";
        }
        cerr<<endl;
        cout<<n<<endl;
        for(int i=0; i<2*n; i++){
            char s;
            cin>>s;
            if(s=='?'){
                int a, b;
                cin>>a>>b;
                cout<<__gcd(gl[a-1], gl[b-1])<<endl;
            }
            else{
                int a, b;
                cin>>a>>b;
                if(gl[a-1]==0 || gl[b-1]==0){
                    cout<<1<<endl;
                    break;
                }
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    return 0;
}
