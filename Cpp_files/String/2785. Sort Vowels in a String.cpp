    class Solution {
    public:
        string sortVowels(string s) {
            /*
                Time complexity: O(nlogn)
                Step 1: Sorting vowels - O(nlogn)
                Step 2: Constructing answer string - O(n)
                Step 3: Joining characters - O(n)

                Space complexity: O(n)
                Sorted vowels list - O(n)
                Answer string - O(n)
            */
            // Step 1: Collect vowels and sort them in descending order
            vector<char> vowels;
            string str = "aeiouAEIOU";
            for (char c : s) {
                if (str.find(c) != string::npos) {
                    vowels.push_back(c);
                }
            }
            sort(vowels.begin(), vowels.end(), greater<char>()); // big to small 

            // Step 2: Construct the answer string by replacing vowels in sorted order
            string result;
            for (char c : s) {
                if (str.find(c) != string::npos) {
                    result += vowels.back();
                    vowels.pop_back();
                } else {
                    result += c;
                }
            }

            // Step 3: Return the final string
            return result;        
        }
    };