// ���� vector was not declared in this scope 
// vairable or field merge declared void
// PII was not declared in this scope
// segs was not declared in this scope
void merge(vector<PII> &segs)
{
	vector<PII> res;
	
	sort(segs.begin(),segs.end());
	
	int st = -2e9,ed = -2e9;
	for(auto seg:segs)
		if(ed < seg.first)
		{
			if(st != -2e9) res.push_back({st,ed});
			st = seg.first,ed = seg.second;
		}
		else ed = max(ed,seg.second);
	if(st != -2e9) res.push_back({st,ed});
	segs = res;
}

