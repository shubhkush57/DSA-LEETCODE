class Solution {
public:
    static bool comp1(pair<int,vector<int>>&p1,pair<int,vector<int>>&p2){
        return p1.second[0] == 3;
    }
    
    void makeset(vector<int>&parent){
        int n = parent.size();
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        return;
    }
    int findParent(int node,vector<int>&parent){
        if(node == parent[node]){
            return node;
        } 
        return parent[node] = findParent(parent[node],parent);
    }
    void unionF(int node1,int node2,vector<int>&parent,vector<int>&rank){
        node1 = findParent(node1,parent);
        node2 = findParent(node2,parent);
        if(rank[node1] < rank[node2]){
            parent[node1]= node2;
            // rank[node2]++;
        }
        else if(rank[node2]<rank[node1]){
            parent[node2] = node1;
            // rank[node1]++;

        }
        else{
            parent[node2] = node1;
            rank[node1]++;
        }
        return;
    }
    int finP(int node,vector<int>&parent){
        if(node == parent[node]){
            return node;
        }
        return finP(parent[node],parent);
    }
    bool isDisjoint(int node1,int node2,vector<int>&parent){
        int p1 = findParent(node1,parent);
        int p2 = findParent(node2,parent);
        return (p1 != p2);
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // we will be making a mst for alice 
        // adn mst for bob then we will be remving the conmmon edges int boht of them and -1
        // map<int,vector<pair<int,int>>>mp;
        int m = edges.size();
        // for(int i = 0;i<m;i++){
        //     mp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        //     mp[edges[i][2]].push_back({edges[i][0],edges[i][1]});
        // }
        vector<pair<int,vector<int>>>al;
        for(int i = 0;i<m;i++){
            // if(edges[i][0] != 2){
                al.push_back({i,edges[i]});
            // }
        }
        // vector<pair<int,vector<int>>>bo;

        // for(int i = 0;i<m;i++){
        //     if(edges[i][0] != 1){
        //         bo.push_back({i,edges[i]});
        //     }
        // }
        
        // vector<int>alice(m,false);
        // vector<int>bob(m,false);
        // for alice
        // sort(al.begin(),al.end(),comp1);
        // // sort(bo.begin(),bo.end(),comp1);
        // for(int i = 0;i<al.size();i++){
        //     cout<<al[i].first<<' '<<al[i].second[0]<<' '<<al[i].second[1]<<' '<<al[i].second[2]<<endl;
        // }
        // cout<<endl;
        //  for(int i = 0;i<bo.size();i++){
        //     cout<<bo[i].first<<' '<<bo[i].second[0]<<' '<<bo[i].second[1]<<' '<<bo[i].second[2]<<endl;
        // }
        vector<int>parent3(n+1);
        vector<int>rank(n+1,0);
        makeset(parent3);
        // vector<int>parent1(n+1);
        // vector<int>rank1(n+1,0);
        // makeset(parent1);
        // int n1 = al.size();
        // cout<<n1<<endl;
        int count3 = 0;
        int count2 = 0;
        int count1 = 0;
        for(int i = 0;i<al.size();i++){
            if( al[i].second[0]== 3 && isDisjoint(al[i].second[1],al[i].second[2],parent3)){
                // alice[al[i].first] = true;
                // bob[al[i].first] = true;
                count3++;
                unionF(al[i].second[1],al[i].second[2],parent3,rank);
            }
           
            
        }
        vector<int>temp= parent3;
         for(int i = 0;i<al.size();i++){
            if( al[i].second[0]== 1 && isDisjoint(al[i].second[1],al[i].second[2],parent3)){
                // alice[al[i].first] = true;
                // bob[al[i].first] = true;
                count1++;
                unionF(al[i].second[1],al[i].second[2],parent3,rank);
            }
            
        }
        parent3 = temp;
         for(int i = 0;i<al.size();i++){
            if( al[i].second[0]== 2 && isDisjoint(al[i].second[1],al[i].second[2],parent3)){
                // alice[al[i].first] = true;
                // bob[al[i].first] = true;
                count2++;
                unionF(al[i].second[1],al[i].second[2],parent3,rank);
            }
            
        }
//         for(int i = 0;i<bo.size();i++){
//             if(isDisjoint(bo[i].second[1],bo[i].second[2],parent1)){
//                 bob[bo[i].first] = true;
//                 unionF(bo[i].second[1],bo[i].second[2],parent1,rank1);
//             }
//         }
//         int overall_parent = parent[1];
//         cout<<overall_parent<<endl;
//         for(int i = 2;i<n+1;i++){
//             cout<<parent[i]<<endl;
//             if(parent[i]  != overall_parent){
//                 return -1;
//             }
//         }
//         // cout<<endl;
//          overall_parent = parent1[1];
//                 // cout<<overall_parent<<endl;

//         for(int i = 2;i<n+1;i++){
//             // cout<<parent[i]<<endl;
//             if(parent1[i]  != overall_parent){
//                 return -1;
//             }
//         }
        // if(st1.size() != n || st.size() != n){
        //     return -1;
        // }
        // instead of this i have to only check if i am abe to go all nodes or not by that 
        //nodes
//         int ans = 0;
//         for(int i =0;i<m;i++){
//             cout<<alice[i]<<' '<<bob[i]<<endl;
            
//             // if(alice[i] && bob[i]){
//             //     ans++;
//             // }
//             if(alice[i] == false && bob[i] == false){
//                 ans++;
//             }
//         }
        // cout<<count1<<' '<<count2<<' '<<count3<<endl;
        if(count3+count1 != n-1 || count3+count2 != n-1){
            return -1;
        }
        return m-(count3+count1+count2);
        // return -1;
    }
};