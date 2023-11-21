//链表
//类型定义
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//变量定义
LinkList L;
LNode* p, * s;
//重要操作
p = L;//p指向头结点
s = L->next;//s指向首元结点
p = p->next,//p指向下一结点


//链表初始化
Status InitList_L(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
//判断链表是否为空
int ListEmpty(LinkList L)
{
	if (L->next)//not empty
		return 0;
	else
		return 1;
}
//单链表的销毁
Status DestroyList(LinkList& L)
{
	Lnode* p;
	while (L) {
		P = L;
		L = L->next;
		delete p;
	}
}
//单链表清空，链表仍存在，但链表中无元素
Status ClearList(LinkList& L)//将L重置为空表
{
	Lnode* p, * q;//或LinkList p,q
	p = L->next;
	while (p) {  //没到表尾
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;//头节点指针域为空
	return OK;
}
//求单链表的表长 
//从首元结点开始，依次计数所有结点
int ListLength_L(LinkList L)//返回L中数据元素个数
{
	LinkList p;//Lnode *p;
	p = L->next;//p指向第一个结点
	i = 0;
	while (p) {//遍历单链表，统计结点数
		i++;
		p = p->next;
	}
	return i;
}
//单链表的取值 顺着链域next逐个结点往下搜索，直到搜索到第i个
//结点为止，因此链表不是随机存取结构
//从第一个结点L->next顺链扫描，p=L->next
Status GetElem_L(LinkList L, int i, ElemType& e) {
	p = L->next;j = 1;//初始化
	while (p && j < i) {//向后扫描，直到p指向第i个元素或p为空
		p = p->next;++j;
	}
	if (!p || j > i) return ERROR;//第i个元素不存在
	e = p->data;
	return OK;
}//GetElem_L
//单链表的查找
Lnode *LocateElem_L(LinkList L,ElemType& e) {
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}//复杂度O(n)
int LocateElem_L(LinkList L, Elemtype e) {
	p = L->next;j = 1;
	while(p &&p->data!=e)
	{
		p = p->next;j++;
	}
	if (p) return j;
	else return 0;
}
//链表的插入
//在L中第I个元素之前插入数据元素e
Status ListInsert_L(LinkList& L, int i, ElemType e) {
	p = L;j = 0;
	while (p && j < i - 1)
	{
		p = p->next;++j;//寻找第i-1个结点，p指向i-1结点
	}
	if (!p || j > i - 1)return ERROR;//i大于表长+1或者小于1插入位置非法
	s = new LNode;s->data = e;//生成新结点s，将结点s的数据域值为e
	s->next = p->next;//结点s插入L中
	p->next = s;
	return ok;
}//ListInsert_L
//删除第i个结点
Status ListRemove_L(LinkList& L, int i, ElemType) {
	p = L;j = 0;q;i;
	while (p && j < i - 1) { p = p->next;++j; }//寻找第i个节点，并令P指向其前驱
	if (!(p->next) || j > i - 1))return ERROR;//删除位置不合理
	q = p->next;//临时保存被删结点的地址已被释放
	p->next = q->next;//改变删除结点前驱结点的指针域
	e = q->data;//保存删除结点的数据域
	delete q;//释放删除结点的空间
	return OK;
}//ListDelete_L
//建立单链表，头插法
/*L = new LNode;L->next = NULL;
//L = (LinkList)malloc(sizeof(LNode));//c language
p = new LNode;p->data = an;
p->next = L->next;L->next = p;
p = new LNode; p->data = a(n - 1);
p->next = L->next;L->next = p;*/
void CreateList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = Null;
	for (i = n;i > 0;--i) {
		p = new LNode;//p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}//CreateList_H
//复杂度O（n）

//尾插法建立单链表
//正位序输入n个元素的值，建立带表头节点的单链表L
void CreateList_R(LinkList& L, int n) {
	L = new LNode;L->next = Null;
	r = L;//尾指针r指向头结点
	for (i = 0;i < n;++i) {
		p = new LNode;cin >> p->data;//生成新结点，输入元素值
		p->next = null;
		r->next = p;//插入到表尾
		r = p;//r指向新的尾结点
	}
}//CreateList_R
//复杂度O（n）

