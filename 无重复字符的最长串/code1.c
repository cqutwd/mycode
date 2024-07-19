struct HashTable{
	char key;
	UT_hash_handle hh;
};
struct Hashtable* hashtable;
struct Hashtable* find(char ikey){
	struct HashTable* tmp;
	HASH_FIND_INT(hashtable,&ikey,tmp);
	return tmp;
}
void insert(char ikey){
	struct HashTable* tmp = malloc(sizeof(struct HashTable));
	tmp->key = ikey;
	HASH_ADD_INT(hashtable,ikey,tmp);
}
int lengthOfLongestSubsrting(char* s){
	hashtable = NULL;
	unsigned char length = sizeof(s) / sizeof(s[0]);
	int flag = 0;
	int result;
	struct HashTable* it = NULL;
	for(int i = 0;i < (int)length;i ++){
		it = find(s[i]);
		if(!it){
			flag ++;
			insert(s[i]);
		}else{
			hashtable = NULL;
			if(result < flag)
				retult = flag;
			flag = 1;
			insert(s[i]);
		}
	}
	if(result < flag)
		result = flag;
	return result;
}
