int bsearch_1(int l,int r){
	while(l < r){
		int mid = l+r>>1;
		if(check(mid ))r = mid;
		else l = mid+1;
	}
	return l;
} 
