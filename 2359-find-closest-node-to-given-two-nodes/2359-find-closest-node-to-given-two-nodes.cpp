class Solution {
public:
    vector<int> pathre(vector<int>&edges,int node1){
        int n = edges.size();
        vector<int>vis(n,false);
        vector<int>path1;
        queue<int>q;
        vis[node1] = true;
        q.push(node1);
        while(!q.empty()){
            // now taking the value of the desired terms
            int f = q.front();q.pop();
            path1.push_back(f);
            if(edges[f] != -1 && vis[edges[f]] == false ){
                q.push(edges[f]);
                vis[edges[f]] = true;
            }
        }
        return path1;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // closestMeetingNode 
        int n = edges.size(); // no of nodes
        
        vector<int>path1 = pathre(edges,node1);
        vector<int>path2 = pathre(edges,node2);
        cout<<"resutl"<<endl;
        unordered_map<int,int>mp;
        for(int i = 0;i<path1.size();i++){
            cout<<path1[i]<<' ';
            mp[path1[i]] = i;
        }
        cout<<endl;
        int dis = INT_MAX;
        vector<pair<int,int>>dii;
        for(int i =0;i<path2.size();i++){
            cout<<path2[i]<<' ';
            if(mp.count(path2[i])){
                // converting this into the desired terms
                // maximum distance minimize
                int temp = max(i,mp[path2[i]]);
                dii.push_back({temp,path2[i]});
            }
        }
        cout<<endl;
        sort(dii.begin(),dii.end());
        int found = INT_MAX;
        if(dii.size() ==0){
            return -1;
        }
        int minid = dii[0].first;
        for(int i = 0;i<dii.size();i++){
            //now taking the value of hte miinimum dist
            if(dii[i].first == minid && found > dii[i].second){
                found = dii[i].second;
            }
        }
        return found;
        
    }
};