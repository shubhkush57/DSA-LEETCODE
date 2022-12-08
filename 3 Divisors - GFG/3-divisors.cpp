//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void SieveOfEratosthenes(int n)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        // Print all prime numbers
        for (int p = 2; p <= n; p++)
            if (prime[p])
                cout << p << " ";
    }
    bool isPrime(long long n)
    {
        // Corner case
        if (n <= 1)
            return false;
        // Check from 2 to square root of n
        for (long long i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<long long>m(1000001,0);
        vector<int>ans;
        // m[0] = 0;
        // for(long long i = 2;i<1000001;i++){
        //     // it should be prime
        //     if(isPrime(i)){
        //         m[i-1] = 1;
        //     }
        //     m[i-1] += m[i-2];
        // }
        
        int n = 1000001;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        // Print all prime numbers
        for (int p = 2; p <= n; p++){
            if (prime[p])
                m[p-1] = 1;
            m[p-1] += m[p-2];
        }
        
        // now to calculate the prime numbers
        for(int i = 0;i<q;i++){
            long long t = query[i];
            long long temp = sqrt(t);
            // cout<<temp<<endl;
            ans.push_back(m[temp-1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends