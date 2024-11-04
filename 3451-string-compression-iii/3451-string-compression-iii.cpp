class Solution {

public:

    string compressedString(string word) {

        int n= word.size();

        string ans = "";

        int i = 0;

        while(i<n){

            int count = 0;

            char fi = word[i];

            while(i<n && fi == word[i] && count <9){

                count++;

                i++;

            }

            ans.push_back('0'+count);

            ans.push_back(fi);

        }

        return ans;

    }

};