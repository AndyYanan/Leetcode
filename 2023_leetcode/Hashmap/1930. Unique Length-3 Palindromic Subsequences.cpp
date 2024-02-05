class Solution{
public:
	int countPalindromicSubsequence(string s){
		vector<int> min_pos(26, -1);
		vector<int> max_pos(26, -1);
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			if(min_pos[c - 'a'] == -1) min_pos[c - 'a'] = i;
			else max_pos[c - 'a'] = i; 
		}
		int res = 0;
		for(int char_idx = 0; char_idx < 26; char_idx++){
			if(min_pos[char_idx] == -1 || max_pos[char_idx] == -1) continue;
			unordered_set<char> unique_palin;
			for(int i = min_pos[char_idx] + 1; i < max_pos[char_idx]; i++){
				unique_palin.insert(s[i]);
			}
			res += unique_palin.size();
		}
		return res;
	}	
};