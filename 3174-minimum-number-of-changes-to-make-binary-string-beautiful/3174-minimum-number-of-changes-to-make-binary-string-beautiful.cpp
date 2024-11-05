class Solution {

public:

    int minChanges(string s) {

        int i = 0;

        int ans = 0;

        int prev = 0;

        int n = s.size();

        while(i<n){

            char c = s[i];

            int count = 0;

            while(i<n && s[i] == c){

                i++;

                count++;

            }

            if(count%2 == 1){

               prev = !prev;

            }

            ans += prev;

        }

        return ans;

    }

};