class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        return v1[2]<v2[2];
    }
    void makeSet(vector<int>&parent){
        int n = parent.size();
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        return;
    }
    int findParent(vector<int>&parent,int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]);
    }
    bool isDisjoint(vector<int>&parent,int node1,int node2){
        int p1 = findParent(parent,node1);
        int p2 = findParent(parent,node2);
        return p1 != p2;
    }
    void unionF(vector<int>&parent,vector<int>&rank,int u,int v){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[v]++;
        }
        else if(rank[u] <rank[v]){
            parent[u] = v;
        }
        else{
            parent[v] = u;
        }
        return;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // indices of teh edges;
        vector<int>critical;
        vector<int>pseduo;
        vector<vector<int>>ans;
        int e = edges.size();
        for(int i = 0;i<e;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),comp);
        // let's have this mst weight w
        int w = 0;
        vector<int>parent(n);
        vector<int>rank(n,0);
        makeSet(parent);
        for(int i = 0;i<e;i++){
            int wi = edges[i][2];
            int ai = edges[i][0];
            int bi = edges[i][1];
            if(isDisjoint(parent,ai,bi)){
                w += wi;
                unionF(parent,rank,ai,bi);
            }
        }
        // so w is the minimum tree with
        for(int i = 0;i<e;i++){
            int indx = edges[i][3];
            // build mst without it..
            vector<int>parenti(n);
            vector<int>ranki(n,0);
            makeSet(parenti);
            int w1 = 0;
            for(int j = 0;j<e;j++){
                if(j != i){
                    int wi = edges[j][2];
                    int ai = edges[j][0];
                    int bi = edges[j][1];
                    if(isDisjoint(parenti,ai,bi)){
                        w1 += wi;
                        unionF(parenti,ranki,ai,bi);
                    }
                }
            }
            if(w1 != w){
                // it means it is critical edges...
                critical.push_back(indx);
            }
            else{
                // it means some of the mst don't have this edge...
                // but may have .. so if i start building mst from this edge and found the wi equal to w then it is p critial edges..
                int w2 = 0;
                int wi = edges[i][2];
                int ai = edges[i][0];
                int bi = edges[i][1];
                vector<int>parentj(n);
                vector<int>rankj(n,0);
                makeSet(parentj);
                w2 += wi;
                unionF(parentj,rankj,ai,bi);
                for(int j = 0;j<e;j++){
                    if(j != i){
                        wi = edges[j][2];
                        ai = edges[j][0];
                        bi = edges[j][1];
                        if(isDisjoint(parentj,ai,bi)){
                            w2 += wi;
                            unionF(parentj,rankj,ai,bi);
                        }
                    }
                }
                if(w2 == w){
                    pseduo.push_back(indx);
                }
            }
        }
        ans.push_back(critical);
        ans.push_back(pseduo);
        return ans;
    }
};