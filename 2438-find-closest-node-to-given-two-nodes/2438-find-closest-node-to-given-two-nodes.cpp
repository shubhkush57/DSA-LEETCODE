class Solution {
public:
    #define pp pair<int,int>
    vector<int> minDis(vector<vector<int>>&adj,int node){
        int n = adj.size();
        vector<int>dis(n,INT_MAX);
        dis[node] = 0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,node});
        while(!pq.empty()){
            pp f = pq.top();pq.pop();
            int d = f.first;
            node = f.second;
            for(auto it: adj[node]){
                int newnode = it;
                int newdis = d+1;
                if(dis[newnode]> newdis){
                    dis[newnode] = newdis;
                    pq.push({newdis,newnode});
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // apply disjkistra's...
        int n = edges.size();
        vector<vector<int>>adj(n,vector<int>());
        for(int i = 0;i<n;i++){
            if(edges[i] !=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int> disNode1 = minDis(adj,node1);
        vector<int> disNode2 = minDis(adj,node2);
        int maxDis = INT_MAX;
        int node = -1;
        for(int i = 0;i<n;i++){
            if(maxDis>max(disNode1[i],disNode2[i])){
                node = i;
                maxDis = max(disNode1[i],disNode2[i]);
            }
        }
        return node;
    }
};