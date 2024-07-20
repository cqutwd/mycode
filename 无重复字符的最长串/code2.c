/**************************
此方法来自力扣：我自横刀向天笑
数组hash+双指针
比起我那个冗长的代码，这个代码
让我体会到了语言的简洁之美，看到这样的代码
时我真的很激动
激动之余也不免感叹这行代码的精妙
可以说是麻雀虽小五脏俱全啊
别看只有这么几行，里面绕的很
**************************/
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
