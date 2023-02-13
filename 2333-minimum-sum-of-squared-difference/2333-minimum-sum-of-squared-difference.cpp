class Solution {
public:
    #define int2 long long
    #define pp pair<int2,int2>
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<pp>pq; // maxheap
        int2 n = nums1.size();
        unordered_map<int2,int2>mp;
        for(int i = 0;i<n;i++){
            if(nums1[i] > nums2[i]){
                // pq.push(nums1[i]-nums2[i]);
                mp[nums1[i]-nums2[i]]++;
            }
            else if(nums2[i] > nums1[i]){
                // pq.push(nums2[i]-nums1[i]);
                mp[nums2[i]-nums1[i]]++;
            }
        }
        for(auto it: mp){
            pq.push({it.first,it.second});
        }
        // while(pq.empty() == false){
        //     cout<<pq.top().first<<' '<<pq.top().second<<endl;
        //     pq.pop();
        // }
        int2 sum = 0L;
        int2 times = k1+k2;
        while(times>0 && !pq.empty()){
            int2 top_ele = pq.top().first;
            int2 to_times = pq.top().second;
            pq.pop();
            int2 re = min(times,to_times);
            
            to_times = to_times-re;
            int2 val = top_ele;
            int2 re_times = to_times;
            // if(to_times != 0){
            //     pq.push({top_ele, to_times});
            // }
            times = times-re;
            top_ele = top_ele-1;
            if(top_ele != 0){
                pq.push({top_ele,re});
            }
            if(!pq.empty()){
                pp fst = pq.top();
                pq.pop();
                if(!pq.empty()){
                     pp sec = pq.top();
                        if(sec.first == fst.first){
                            pq.pop();
                            pq.push({fst.first,sec.second+fst.second});
                        }
                        else{
                            pq.push(fst);
                        }
                }
                else{
                    pq.push(fst);
                }
            }
            if(re_times != 0){
                pq.push({val,re_times});
            }
            // int2 re = min(times,top_ele);
            // if(pq.empty()){
            //     top_ele = top_ele-re;
            //     times = times-re;
            //     if(top_ele != 0){
            //         pq.push(top_ele);
            //     }
            // }
            // else{
            //     int2 sec = pq.top();
            //     int2 diff = top_ele-sec;
            //     if(diff != 0)
            //     re = min(re,diff);
            //     top_ele = top_ele-re;
            //     times = times-re;
            //     if(top_ele != 0){
            //         pq.push(top_ele);
            //     }
            // }
            
        }
        while(!pq.empty()){
            
            pp re= pq.top();
            // cout<<re.first<<' '<<re.second<<endl;
            int2 des= re.first*re.first;
            des = des*re.second;
            sum += des;
            pq.pop();
        }
        return sum;
        
    }
};