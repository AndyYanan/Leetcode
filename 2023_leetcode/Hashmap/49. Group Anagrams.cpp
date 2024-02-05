class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create an unordered map to store anagrams as keys and their corresponding strings as values
        unordered_map<string, vector<string>> mp;
        
        // Temporary string to store sorted versions of strings from the input vector
        string temp = "";
        
        // Get the total number of strings in the input vector
        int len = strs.size();
        
        // Loop through each string in the input vector
        for (int i = 0; i < len; ++i) {
            // Make a copy of the current string
            temp = strs[i];
            
            // Sort the characters of the string in lexicographical order
            sort(temp.begin(), temp.end());
            
            // Add the sorted string as a key to the map and push the original unsorted string as its value
            mp[temp].push_back(strs[i]);
        }
        
        // Create a vector to store the final result
        vector<vector<string>> res;
        
        // Loop through each element in the map
        for (auto& ele : mp) {
            // Push the group of anagrams (values of the map) into the result vector
            res.push_back(ele.second);
        }
        
        // Return the result containing groups of anagrams
        return res;
    }
};
