class Solution {
public:
    // prime factors..
    set<int> primF(int n){
        set<int>ans;
        if(n <=1){
            return ans;
        }
        if(n%2 == 0){
            ans.insert(2);
             while(n%2 == 0){
                // cout<<2<<" ";
                n = n/2;
            }
        }
       
        for(int i = 3;i<= sqrt(n);i = i+2){
            // ans.insert(i);
            if(n%i == 0){
                ans.insert(i);
                    while(n%i == 0){
                    // cout<<i<<' ';
                    n = n/i;
                    }
            }
            
        }
        if(n>2){
            // cout<<<<" ";
            ans.insert(n);
        }
        return ans;
    }
    void makeSet(vector<int>&parent){
        int n = parent.size();
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        return;
    }
    bool isDisjoint(vector<int>&parent,int node1,int node2){
        int p1 = findParent(parent,node1);
        int p2 = findParent(parent,node2);
        return p1 != p2;
    }
    int findParent(vector<int>&parent,int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]);
    }
    void unionFind(vector<int>&parent,vector<int>&rank,int u,int v){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u]<rank[v]){
            rank[u]++;
            parent[u] =v;
        }
        else{
            rank[v]++;
            parent[v] = u;
        }
        
        return;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        // union Find Question......
        // every node should be connected into one component...
        // then ok otherwise false..
        // we take an index find it's prime factors...
        // go and find the prime factor 2 
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        makeSet(parent);
        for(int i = 0;i<n;i++){
            // for(auto it: mp){
            //     cout<<it.first<<' '<<it.second<<endl;
            // }
            // cout<<endl;
            // cout<<endl;
            set<int>st = primF(nums[i]);
            // int p = findParent(parent,i);
            for(auto it: st){
                // cout<<it<<' ';
                if(mp.count(it)){
                    // cout<<"HERE"<<endl;
                    // int node = mp[it];
                    // cout<<node<<' ';
                    unionFind(parent,rank,mp[it],i);
                    // mp[it] = p;
                    // cout<<parent[i]<<endl;
                }
                // int p = findParent(parent,i);
                mp[it] = i;
            }
            // cout<<endl;

        }
        for(int i =1;i<n;i++){
            // cout<<findParent(parent,i)<<' ';
            if(isDisjoint(parent,i,i-1)){
                // cout<<i<<endl;
                return false;
            }
        }
        return true;

    }
};