class Solution {
public:
    unordered_map<string, string>mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int n=longUrl.length();
        string sub=longUrl.substr(n-5);
        string enc="https://tinyurl.com/"+to_string(n)+sub+to_string(sub.length());
        mp[enc]=longUrl;
        return enc;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));