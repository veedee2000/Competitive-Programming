class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ans = "";
        return ans = longUrl + longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string ans = "";
        for(int i = 0;i < shortUrl.size() / 2;i++){
            ans += shortUrl[i];
        }
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
