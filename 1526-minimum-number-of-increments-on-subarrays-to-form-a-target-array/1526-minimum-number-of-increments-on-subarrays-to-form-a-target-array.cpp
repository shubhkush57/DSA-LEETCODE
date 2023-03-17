class Solution {
public:
   
    int minNumberOperations(vector<int>& target) {
//         int n = target.size();
//         // to rememove the equal things.......
//         vector<int>tar;
//         for(int i = 0;i<n;i++){
//             if( i == 0){
//                 tar.push_back(target[i]);
//             }
//             else if(target[i] != tar.back()){
//                 tar.push_back(target[i]);
//             }
//         }
//         // you have to just calcaulate the local maximam and then add it to the anser
//         // ans += (local  maxima )-(previous local minima);
//         n  = tar.size();
//         if(n == 1){
//             return target[0];
//         }
//         int prev_min = 0;
//         int ans = 0;
//         for(int i = 0;i<tar.size();i++){
//             if(i == 0){
//                 if(tar[i]>tar[i+1]){
//                     ans += tar[i]-prev_min;
//                 }
//             }
//             else if(i == n-1){
//                 if(tar[i] > tar[i-1]){
//                     ans += tar[i]-prev_min;
//                 }
//             }
//             else{
//                 if(tar[i]>tar[i-1] && tar[i]> tar[i+1]){
//                     ans += tar[i]-prev_min;
//                 }
//                 else if(tar[i] < tar[i-1] && tar[i] < tar[i+1]){
//                     prev_min = tar[i];
//                 }
               
//             }
//         }
        // second way of calculating the differnce between local maxima and local minia
        // instead of goind for direct diff we will go asceding diffence. 
        int n = target.size();
        int ans = target[0];
        for(int i = 1;i<n;i++){
            ans += max(0,target[i]-target[i-1]);
        }
        return ans;
    }
};