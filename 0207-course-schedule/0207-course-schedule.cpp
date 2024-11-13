class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>());
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        int completeCourses = 0;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                completeCourses++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int t = q.size();
            while(t--){
                int course = q.front();q.pop();
                for(auto it: adj[course]){
                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.push(it);
                        completeCourses++;
                    }
                }
            }
        }
        return completeCourses == numCourses;
    }
};


// Algorithm:

// take all the subjects first which has zero indegree

// reducde numCourse by no of them..

// now for each subject which is depend upon them rduce theiere indegree by 1

// if indegree begin zero it means 
// reduce numCouse again by 1 


// and the end if numCouse getting zero it means we can compleete all the coues..

// o(n);
// making adj o(m+n);
// O(V+E ); // where v is vertex and Eis deges..