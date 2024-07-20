/********************************
方法一：哈希表+移动窗口
遍历字符串，每遍历一个字符就在哈希表
中寻找重复，如果没有就压入哈希表
flag++
如果哈希表中存在，则将flag的值与ret
比较赋值，flag = 1.这里就有bug
直接将窗口起始点移至当前遍历的位置
而不是第一个重复字符的位置，导致ret
的值大概率比正确值小这个bug用双指针
能解决
测试中还有bug
就是ret的值大的离谱
********************************/
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
