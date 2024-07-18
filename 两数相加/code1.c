/*********************************
两数相加：
方法一：递归
此处只是提供一个思路，正确性没有验证
代码中的错误我难得改了：
当l1和l2都为NULL时再判断一次flag是否需要进位
还有很多需要优化的地方，比如当l1和l2长度不同时
可以用三目运算符来赋0，flag也可以直接用/来得到
不用判断。
1.创建一个存放结果的线性表
2.申明一个变量flag记录上一位的进位
3.递归
*********************************/
int flag = 0;
struct ListNode* Res = (struct ListNode*)malloc(sizeof(struct ListNode));
struct ListNode* t = Res;
struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){
	if(l1 == NULL && l2 == NULL)//递归结束标志
		return Res;
	struct ListNode* p = malloc(sizeof(struct ListNode));
	p->next = NULL;
	p->val = l1->val + l2->val + flag;//结果存入链表
	if(p->val >= 10){
		flag = 1;
		p->val %= 10;
	}else{
		flag = 0;
	}
	t->next = p;//尾插法顺序一致
	t = p;
	return addTwoNumbers(l1->next,l2->next);//开始递归
}
