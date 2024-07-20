/*************************
 * 最大连续1的个数
 * 太简单了 就没用hash
 * 直接就计数了
 * 就一个三目运算符值得关注
*************************/
int findMaxConsecutiveOnes(int* nums,int numsSize){
	int max = 0;
	int flag = 0;
	int i = 0;
	while(i < numsSize){
		if(nums[i]){
			flag ++;
		}else{
			flag = 0;
		}
		max = max < flag?flag:max;
		i ++;
	}
	return max;
}
