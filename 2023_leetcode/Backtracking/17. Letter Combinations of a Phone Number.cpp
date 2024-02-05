class Solution {
public:
    vector<string> res;     // Stores the resulting combinations
    string tmpStr;          // Temporarily holds a combination being constructed
    
    vector<string> letterCombinations(string digits) {
        vector<string> dic{{"0"}, {"1"}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
        
        if (digits.empty()) {
            return {}; // Return an empty vector if input is empty
        }
        
        dfsCombine(dic, digits, 0); // Start DFS combination generation
        return res; // Return the resulting combinations
    }
    
    // Recursive DFS combination generation function
    void dfsCombine(vector<string> dic, string digits, int startIdx) {
        if (startIdx == digits.size()) {
            res.push_back(tmpStr); // Store the complete combination
            return;
        }
        
        string val = dic[digits[startIdx] - '0']; // Get the string corresponding to the digit
        for (int i = 0; i < val.size(); ++i) {
            tmpStr.push_back(val[i]); // Append the character to the temporary combination
            dfsCombine(dic, digits, startIdx + 1); // Recursively generate remaining combinations 
            tmpStr.pop_back(); // Backtrack: remove the last character for next iteration
        }
    }
};
