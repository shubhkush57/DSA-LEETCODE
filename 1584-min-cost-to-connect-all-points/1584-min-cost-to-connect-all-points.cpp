class Solution {
public:
    void makeset(vector<int>&parent,vector<int>&rank){
        int n = parent.size();
        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        return;
    }
    int findParent(vector<int>&parent,int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]) ;
    }
    bool isDisjoint(int node1,int node2,vector<int>&parent){
        int p1 = findParent(parent,node1);
        int p2 = findParent(parent,node2);
        return !(p1 == p2);
    }
    void unionF(int u,int v,vector<int>&parent,vector<int>&rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u]<rank[v]){
            parent[u] = v;
            rank[u]++;
        }
        else if(rank[u]>rank[v]){
            parent[v] = u;
            rank[v]++;
        }
        else{
            parent[v] = u;
            rank[v]++;
        }
        return;
    }
    int kruskal(vector<int>&parent,vector<int>&rank,vector<vector<int>>&points,vector<vector<int>>&v){
        int ans = 0;
        int n = v.size();
        // cout<<n<<endl;
        for(int i = 0;i<n;i++){
            int w = v[i][0];
            int n1 = v[i][1];
            int n2 = v[i][2];
            if(isDisjoint(n1,n2,parent)){
                // cout<<n1<<' '<<n2<<endl;
                ans += w;
                unionF(n1,n2,parent,rank);
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // we will be applying disjoint set union concept.
        // connected undirected graph
        // there is not difference {w,u,v} and {w,v,u}
        vector<vector<int>>v;
        int n = points.size();
        cout<<n<<endl;
        for(int i = 0;i<n;i++){
            int xi = points[i][0];
            int yi = points[i][1];
            for(int j = i+1;j<n;j++){
                int xj = points[j][0];
                int yj = points[j][1];
                int w = abs(xi-xj)+abs(yi-yj);
                v.push_back({w,i,j});
                // v.push_back({w,j,i});
                // i and j are node here
            }
        }
        // now we have 
        sort(v.begin(),v.end());
        // for(auto it: v){
        //     cout<<it[0]<<' '<<it[1]<<' '<<it[2]<<endl;
        // }
        vector<int>parent(n);
        vector<int>rank(n);
        makeset(parent,rank);
        int miniCost = kruskal(parent,rank,points,v);
        return miniCost;
    }
};