class Solution {
private:
    // String containing all the characters used for generating the short URL code
    string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    // Two unordered maps to store the mappings between original URLs and their corresponding short codes
    unordered_map<string, string> url2code, code2url;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        
        // Generate a unique short code for the long URL
        while (url2code.find(longUrl) == url2code.end()) {
            // Shuffle the characters in the alphabets string to create a random short code
            random_shuffle(alphabets.begin(), alphabets.end());
            
            // Take the first 6 characters of the shuffled alphabets as the short code
            code = alphabets.substr(0, 6);
            
            // Check if the generated short code is already in use, if not, associate it with the long URL
            if (code2url.find(code) == code2url.end()) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        
        // Return the shortened URL with the short code appended to the base URL
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // Find the last occurrence of '/' in the short URL to extract the short code
        int p = shortUrl.rfind("/");
        
        // Retrieve the original URL using the short code from the code2url map
        return code2url[shortUrl.substr(p + 1)];
    }
};
