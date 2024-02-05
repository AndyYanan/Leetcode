class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {0}; // Initialize an array to store the count of each character ('a' to 'z') in the string
        
        // Step 1: Count the occurrences of each character in the input string
        for (int i = 0; i < s.size(); ++i){
            cnt[s[i] - 'a']++;
        }      

        int maxCount = INT_MIN, letter = 0;
        // Step 2: Find the character with the maximum count in the input string
        for (int i = 0; i < 26; ++i){
            if (cnt[i] > maxCount){
                maxCount = cnt[i];
                letter = i;
            }
        }

        // Step 3: Check if the maximum count exceeds half the size of the string + 1
        if (maxCount > (s.size() + 1) / 2){
            return ""; // It's impossible to reorganize the string, so return an empty string
        }

        string res = s;
        int idx = 0;
        // Step 4: Reorganize the string by placing the character with the maximum count at even indices first
        while (cnt[letter] > 0){
            res[idx] = letter + 'a';
            idx += 2;
            cnt[letter]--;
        }

        // Step 5: Place the remaining characters at odd indices in the string
        for (int j = 0; j < 26; j++){
            while (cnt[j]){
                if (idx >= s.size()){
                    idx = 1; // Wrap around to odd indices if we reach the end of the string
                }
                res[idx] = j + 'a';
                cnt[j]--;
                idx += 2;
            }
        }

        return res; // Return the reorganized string
    }
};
