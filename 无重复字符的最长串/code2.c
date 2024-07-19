int lengthOfLongestSubstring(char* s){
	//ASCII:max127
	int hash[127] = {0};
	int left = 0;
	int right = 0;
	int max = 0;
	while(s[right]){
		if(hash[s[right]] && left < hash[s[right]]){
			left = hash[s[right]];
		}
		hash[s[right]] = right + 1;
		max = max < right - left + 1?right - left + 1:max;
		right ++;
	}
	return max;

}
