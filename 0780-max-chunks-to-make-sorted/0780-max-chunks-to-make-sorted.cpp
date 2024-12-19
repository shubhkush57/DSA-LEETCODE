class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<bool>vis(n,false);
        // int ans = 0;
        // int search = n-1;
        // int i = n-1;
        // while(i>=0){
        //     if(search >=0 && vis[search] == true){
        //         search = search -1;
        //     }
        //     while(i>=0 && arr[i] != search){
        //         if(vis[arr[i]] == true)return 1;
        //         vis[arr[i]] = true;
        //         i--;
        //     }
        //     if(i>=0 && arr[i] == search){
        //         vis[arr[i]] = true;
        //         for(int k = i;k<n;k++){
        //             if(vis[k] == false){
        //                 return ans+1;
        //             }
        //         }
        //         i--;
        //         search = search-1;
        //         ans++;
        //     }
        // }
        // int i = n-1,j = n-1;
        // while(i>=0){
        //     if(arr[i] == j){
        //         for(int k = i;k<=j;k++){
        //             if(vis[k] == false){
        //                 ans = ans+1;
        //                 return ans;
        //             }
        //         }
        //         vis[j] = true;
        //         ans++;
        //         j = i-1;
        //     }
        //     else{
        //         vis[arr[i]] = true;
        //     }
        //     i--;
        // }
        int ans =0;
        int search = n-1;
        int i = n-1;
        while(i>=0){
            if(arr[i] == search){
                vis[arr[i]] = true;
                bool flag = false;
                for(int k = i;k<n;k++){
                    if(vis[k] == false){
                        search = k;
                        flag = true;
                        break;
                    };
                }
                i--;
                if(flag == false){
                    ans++;
                    search = i;
                }
                // i = i-1;
                // search = i;
                
            }
            else{
                vis[arr[i]] = true;
                i--;
            }
        }
        return ans;
    }
};