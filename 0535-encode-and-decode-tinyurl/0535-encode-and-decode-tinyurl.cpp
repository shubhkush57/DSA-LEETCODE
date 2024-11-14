class Solution {
public:

    // Encodes a URL to a shortened URL.

    // we need to desing the shortes url.. of size 6
    int codeLength = 6;
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTWXYZ1234567890.-";
    string baseURL = "https://tinyurl.com/";
    unordered_map<string,string>memeory;
    string encode(string longUrl) {
        string encodedString = "";
        for(int i = 0;i<codeLength;i++){
            encodedString.push_back(characters[rand()%characters.size()]);
        }
        while(memeory.count(encodedString) == true){
            for(int i = 0;i<codeLength;i++){
                encodedString[i] += characters[rand()%characters.size()];
            }
        }
        memeory[encodedString] = longUrl;
        return  baseURL+encodedString;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string encoded_string = "";
        int n = shortUrl.size();
        int count = 0;
        int i = 0;
        for(;i<n;i++){
            if(shortUrl[i] == '/'){
                count++;
                if(count == 3){
                    i++;
                    break;
                }
            }
        }
        while(i<n){
            encoded_string.push_back(shortUrl[i]);
            i++;
        }
        return memeory[encoded_string];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));