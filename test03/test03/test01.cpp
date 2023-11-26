//循环链表
//尾指针循环链表合并
//Tb表头连接到Ta表尾，释放Tb表头结点，修改指针，p存表头结点
LinkList Connect(LinkList Ta, LinkList Tb) {
	//假设两个非空的单循环链表
	p = Ta->next;//p存表头结点
	Ta->next = Tb->next->next;//Tb表头连接Ta表尾
	delete Tb->next;//释放Tb表头结点
	Tb->next = p;//修改指针
	return Tb;
}
//双向链表
typedef struct DulNode {
	Elemtype data;
	struct DulNode* prior, * next;
}DulNode,*DuLinkList;

//双向链表的插入
void ListInsert_Dul(DuLinkList& L, int i, ElemType e)
{
	if (!(p = GetElemP_Dul(L, i))) return ERROR;
	s = new DuLNode;
	s->date = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}//ListInsert_Dul

//双向链表的删除
void ListDelete_Dul(Dulink& L, Int i, ElemType& e) 
{//删除带头结点的双向循环链表L的第i个元素并用e返回
	if (!(p = GetElemP_Dul(L, i))) return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}//ListDelete_DuL

//线性表的合并
void union(List& La, List Lb) {
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for (i = 1;i < Lb_len;i++)
	{
		GetElem(Lb, i, e);
		if (!LocateElem(La, e)) ListInsert(&La, ++La_len, e);
	}
}//时间复杂度O(ListLength(La)*ListLength(Lb))

//有序表的合并顺序表
void MergeList_Sq(SqList LA, SqList LB, SqList& LC) {
	pa = LA.elem;
	pb = LB.elem;//指针pa和pb的初值分别指向表内第一个元素
	LC.length = LA.length + LB.length;//信标长度为带合并两表长度之和
	LC.elem = new ElemType[LC.length];//为合并后的新表分配一个数组空间
	pc = LC.elem;//指针pc指向新表的第一个元素
	pa_last = LA.elem + LA.length - 1;//指针pa_last指向LA表的最后一个元素
	pb_last = LB.elem + LB.length - 1;//指针pb_last指向LB表的最后一个元素
	while (pa <= pa_last && pb <= pb_last) {//两个表都非空
		if (*pa <= *pb)*pc++ = *pa++;//依次摘取两表中值较小的结点
		else*pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;//LB表已到达表尾，将LA中剩余元素加入LC
	while (pb <= pb_last) *pc++ = *pb++;//LA表已到达表尾，将LA中剩余元素加入LC
}//MergeList_Sq
//时间复杂度O(ListLength(La)+ListLength(Lb))
//空间复杂度O(ListLength(La)+ListLength(Lb))

//有序表的合并 链表的合并
void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc) {
	pa = La->next;
	pb = Lb->next;
	pc = Lc = La;//用La的头结点作为Lc的头结点
	while (pa && pb) {
		if (pa->data <= pb->data) { pc->next = pa;pc = pa;pa = pa->next; }
		else { pc->next = pb, pc = pb;pb = pb->next; }
	}
	pc->next = pa ? pa : pb;//插入剩余段
	delete Lb;//释放Lb的头结点
}
//时间复杂度O(ListLength(La)+ListLength(Lb))
//空间复杂度O（1）

//一元多项式的运算，实现两个多项式加减乘运算
//稀疏多项式相加，链式存储结构
typedef struct PNode {
	float coef;
	int expn;
	struct PNode* next;
}PNode,*Polynomial;

void CreatPolyn(Polynomial& P, int n) {
	输入m项的系数和指数，建立表示多项式的有序链表P
	P = new PNode;
	P->next = NULL;//先建立一个带头结点的单链表
	for (i = 1;i <= n;++i) {//依次输入n个非0项
		s = new PNode;//生成新结点
		cin >> s->coef >> s->expn;//输入系数和指数
		pre = P;//保存q的前驱，初值为头结点
		q = P->next;//q初始化，指向首元结点
		while (q && q->expn < s->expn) {//找到第一个大于输入项指数的项*q
			pre = q;
			q = q->next;
		}
		s->next = q;//将输入项s插入到q和其前驱结点pre之间
		pre->next = s;
	}
}

//图书管理系统
struct Book {
	char id[20];
	char name[50];
	int price;
};
typedef struct {
	Book* elem;
	int length;
}SqList;
typedef struct LNode {
	Book data;
	struct LNode* next;
}LNode,*LinkList;