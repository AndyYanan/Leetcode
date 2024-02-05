class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> preSameCarIdx(256, -1); // A vector to store the previous occurrence index of each character in the string
        // Initialize all elements to -1, indicating that no character has occurred before.

        int len = s.size();
        int res = 0, start = -1; // res to store the length of the longest substring, and start to track the start index of the current substring.

        for (int i = 0; i < len; i++) {
            // If the current character has occurred before within the current substring (i.e., its previous occurrence index is greater than the start index),
            // update the start index to the previous occurrence index. This will shrink the current substring and eliminate the repeating character.
            if (preSameCarIdx[s[i]] > start) {
                start = preSameCarIdx[s[i]];
            }

            // Update the previous occurrence index of the current character to the current index.
            preSameCarIdx[s[i]] = i;

            // Update the length of the longest substring found so far by comparing it with the current length (i - start).
            res = max(res, i - start);
        }

        return res; // Return the length of the longest substring without repeating characters.



        
        
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
