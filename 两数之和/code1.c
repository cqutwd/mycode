/************************************
 穷举法
 将数组中的所有两两组合分别相加所得
 结果与target比较
 将下标记录在ret中返回
************************************/
int* twoSum(int* nums,int numsSize,int target,int*returnSize)
{
	for(int i = 0;i < numsSize;i ++)
		for(int j = i +  1;j < numsSize;j ++)
		{
			if(nums[i] + nums[j] == target)
			{
				int* ret = malloc(sizeof(int) * 2);
				ret[0] = i,ret[1] = j;
				*returnSize = 2;
				return ret;
			}
		}
	*returnSize = 0;
	return NULL;
}
