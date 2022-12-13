bool cmp(pair<string, int>& a,pair<string, int>& b)
{
        if(a.second == b.second){

            int val = a.first.compare(b.first);

            if(val<0) return a.second;
            else b.second;
        }
    return a.second > b.second;
}

vector<string> frequentWords(vector<string>& words , int k) {
	unordered_map<string, int> mp;
	for(auto i : words) {
		mp[i]++;
	}
	vector<pair<string,int>>temp;

	for(auto it: mp) {
		temp.push_back(it);
	}

	sort(temp.begin(), temp.end(), cmp);
	vector<string> result;
	for(int i=0; i<k; i++) {
		result.push_back(temp[i].first);
	}

	return result;
}