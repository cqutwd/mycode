/**************************************
方法二：哈希表
方法一中在第一轮循环输入i后，在第二轮
循环中寻找target - i,时间复杂度为O（n）
利用哈希表能将此处的时间复杂度降为O(1)
来自力扣官方题解
**************************************/
struct HashTable{
	int key;
	int val;
	UT_hash_handle hh；//hash handle(哈希句柄)的缩写
};

struct HashTable* hashtable;

//寻找
struct HashTable* find(int ikey){
	struct HashTable* tmp;
	HASH_FIND_INT(hashtable,&ikey,tmp);

	return tmp;
}
//插入
void inserrt(int ikey,int ival){
	struct HashTable* it = find(ikey);
	if(it == NULL){
		struct HashTable* tmp = malloc(sizeof(struct HashTable));
		tmp->key = ikey,tmp->val = ival;
		HASH_FIND_INT(hashtable,key,tmp);
	}
	else{
		it->val = ival;
	}

}
int* twoSun(int* nums,int numsSize,int target,int* returnSize){
	hashtable = NULL;
	for(int i = 0;i < numsSize;i ++){
		struct HashTable* it = find(target - nums[i]);
		if(it != NULL){
			int * ret = malloc(sizeof(int) * 2);
			ret[0] = it->val,ret[1] = i;
			*returnSize = 2;
			return ret;
		}
	insert(nums[i],i);
	}
	*returnSize = 0;
	return NULL;
}
