int firstUniqueInteger(vector<int> &v) {
	unordered_map<int,int> mp;
	for(int i=0; i<v.size(); i++) {
		mp[v[i]]++;
	}
	for(int i=0; i<v.size(); i++) {
		if(mp[v[i]] == 1) {
			return v[i];
		}
	}
	return -1;
}