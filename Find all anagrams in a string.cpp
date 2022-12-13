vector<int> findAnagrams(string s, string p)
{
	unordered_map<char, int> mp;
	for(int i=0; i<p.size(); i++) {
		mp[p[i]]++;
	}
	int start = 0, end = 0, char_matched = 0;
	vector<int> result;
	for(; end < s.size(); end++) {
		char end_char = s[end];
		if(mp.find(end_char) != mp.end()) {
			mp[end_char]--;
			if(mp[end_char] == 0) {
				char_matched++;
			}
		}
		if(char_matched == mp.size()) {
			result.push_back(start);
		}
		if(end >= p.size() - 1) {
			char start_char = s[start++];
			if(mp.find(start_char) != mp.end()) {
				if(mp[start_char] == 0) {
					char_matched--;
				}
				mp[start_char]++;
			}
		}
	}
	return result;
}