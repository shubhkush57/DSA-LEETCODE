class Solution {
public:
    #define int2 long long
    #define pp pair<int,char>
    string reorganizeString(string s) {
       unordered_map<char,int2>mp;
       for(auto it: s)mp[it]++;
       priority_queue<pp>pq;
       for(auto it: mp){
        pq.push({it.second,it.first});
       }
       string ans = "";
        while(pq.size()>1){
            auto firstChar = pq.top();pq.pop();
            auto secondChar = pq.top();pq.pop();
            ans.push_back(firstChar.second),ans.push_back(secondChar.second);
            if(firstChar.first-1>0){
                pq.push({firstChar.first-1,firstChar.second});
            }
            if(secondChar.first-1>0){
                pq.push({secondChar.first-1,secondChar.second});
            }
        }
        if(pq.size() ==1){
            auto ele = pq.top();pq.pop();
            if(ele.first>1)return "";
            if(ans.size()>0 &&ele.second == ans.back())return "";
            ans.push_back(ele.second);
        }




       return ans;
    }
};