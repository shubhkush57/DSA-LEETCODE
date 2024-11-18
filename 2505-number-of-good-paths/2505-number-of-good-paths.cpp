class UnionFind{
private:
    vector<int>parent,rank;
public:
    UnionFind(int n){
        parent.clear();
        parent.resize(n);
        rank.clear();rank.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]);
    }
    void makeUnion(int node1,int node2){
        node1 = findParent(node1);
        node2 = findParent(node2);
        if(node1 == node2){
            return;
        }
        else if(rank[node1]<rank[node2]){
            rank[node2]++;
            parent[node1] = node2;
        }
        else{
            rank[node1]++;
            parent[node2] = node1;
        }
        return;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // first we will make adjList.
        int n = vals.size();
        vector<vector<int>>adj(n,vector<int>());
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        map<int,vector<int>>mp; // having the same value nodes..
        for(int i = 0;i<n;i++){
            mp[vals[i]].push_back(i);
        }
        int ans = 0;
        UnionFind dsu(n);
        for(auto &[value,nodes]: mp){
            for(auto node: nodes){
                // we will start going to make it's dsu which are not it's smaller size...
                for(auto neighbors: adj[node]){
                    // now take those nodes whose values are less than me...
                    if(vals[neighbors]<= value){
                        dsu.makeUnion(neighbors,node);
                    }
                }
            }
            unordered_map<int,int>groupSize;
            for(auto node: nodes){
                groupSize[dsu.findParent(node)]++;
            }
            for(auto it: groupSize){
                ans += ((it.second+1)*(it.second))/2;
            }
        }
        
       // whose parent is whose...
        return ans;
    }
};