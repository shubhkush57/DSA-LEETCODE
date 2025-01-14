class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        vector<int>c;
        map<int,set<int>>mp;
        set<int>st;
        for(int i = 0;i<n;i++){
            st.insert(A[i]);
            int count = 0;
            for(int j = 0;j<=i;j++){
                if(st.count(B[j])){
                    count++;
                }
                
            }
            c.push_back(count);
        }
        // set<int>s;
        // for(int i = 0;i<n;i++){
        //     s.insert(A[i]);
        //     mp[i]= s;
        // }
        // int count = 0;
        // for(int i = 0;i<n;i++){
        //     if(mp[i].count(B[i])){
        //         count++;
        //     }
        //     c.push_back(count);
        // }
        
        return c;
    }
}; 