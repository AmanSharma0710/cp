class DSU{
    public:
    int n;
    vector<int> parent, rank;
    DSU(int n): n(n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    ~DSU(){
        parent.clear();
        rank.clear();
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1]>rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s1] = s2;
                rank[s2]++;
            }
        }
    }
};