class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int res = 0, left = 0;
        vector<int> dic(256, -1);
        for(int right = 0; right < len; right++){
            if(dic[s[right]] >= left){
                left = dic[s[right]] + 1;
            }
            dic[s[right]] = right;
            res = max(res, right-left+1);
        } 
        return res;

        
        
        /*
        int len = s.size();
        int start_idx = 0, res = 0;
        unordered_map<char, int> mp(0); // Hashmap to store the count of characters in the current substring
        // Here, the count for each character is initialized to 0.

        for (int i = 0; i < len; ++i) {
            mp[s[i]]++; // Increment the count for the current character in the hashmap

            // If the count of the current character becomes more than 1, it means we have a repeating character
            // in the current substring. In this case, we need to shrink the substring from the start to eliminate
            // the repeated character and find a new valid substring.
            while (mp[s[i]] > 1) {
                mp[s[start_idx]]--; // Decrement the count for the character at the start of the current substring
                start_idx++; // Move the start index of the substring forward to shrink it
            }

            // Update the maximum length of the substring found so far
            res = max(res, i - start_idx + 1);
        }

        return res; // Return the length of the longest substring without repeating characters
        */
    }
};
