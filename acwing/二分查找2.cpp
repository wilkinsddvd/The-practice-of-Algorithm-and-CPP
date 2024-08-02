int bsearch_2(int l,int r){
	while(l < r){
		int mid = l+r+1>>1;
		if(check(mid))l = mid;
		else r = mid-1;
	}
	return 1;
} 
