class TopVotedCandidate {
public:
    unordered_map<int,int>mp;
    vector<int>tm;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        // at the time 
        int n = persons.size();
        unordered_map<int,pair<int,int>>remp;
        for(int i = 0;i<n;i++){
            // mp[times[i]][persons[i]].first++;
            // mp[times[i]][persons[i]].second = i;
            remp[persons[i]].first++;
            remp[persons[i]].second = i;
            
            
            int mini = 0;
            int person = -1;
            int prev = 0;
            for(auto it: remp){
                if(it.second.first >mini){
                    person = it.first;
                    mini = it.second.first;
                    prev = it.second.second;
                }
                else if(it.second.first == mini && prev < it.second.second){
                    person = it.first;
                    mini = it.second.first;
                    prev = it.second.second;
                }
            } 
            
            
            mp[times[i]] = person;
        }
        tm = times;
    }
    
    int q(int t) {
        // at time t who was leading the election
        int start = 0;
        int end = mp.size()-1;
        int time = 0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(tm[mid]<=t){
                time = tm[mid];
                start= mid+1;
            }
            else{
                end = mid-1;
            }
        }
        // you got time
        
        return mp[time];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */