//线性表的初始化
//Status InitList_Sq(SqList& L)   构造一个空的顺序表L
/*{
	L.elem = new ElemTyoe[MaxSize];//为顺序表分配空间
	if (!L.elem)exit(OVERFLOW);//存储分配失败
	L.length = 0;//空表长度为0
	return OK;
}*/
//线性表的取值
/*
int GetElem(SqList L,int i, ElemType &e){
  if (i<1|i>L.length)
      return ERROR;//判断i值是否合理
  e =L.elem[i-1];//第i-1的单元存储着第i个数据
  return OK;
}

//顺序表上的按值查找
int LocateElem(SqList L,ElemType e)//L中查找e的数据元素，返回其序号
{
    for(i = 0;i<L.length;i++)
	    if(L.elem[i] == e) return i+1;//查找成功返回序号
	return 0;//查找失败，返回0
}
ASL复杂度（n+1）/2

//顺序表的插入
Status ListInsert_Sq(Sqlist&L,int i,ElemType e){
{
if(i<1||i>L.length+1)return ERROR;//i值不合法
if(L.length == MaxSize)return ERROR;//当前存储空间已满
for(j = L.length-1;j>=i-1;j--)
   L.elem[j+1] = L.elem[j];//插入位置及之后的元素后移
L.elem[i-1] = e;//将新元素e放入第i个位置
L-length++;表长增1
return OK
}//复杂度1/n+1（n+...+1+0)= n/2

//顺序表的删除
Status ListDelete Sq(SqList&L,int i)
{
if ((i<1)||(i>L.Length)) return ERROR;//i值不合法
    for(j = i;j<=L.length-1;j++)
L.elem[j-1] = L.elem[j];//将删除的元素之后的元素前移
L.length--;表长减一
return OK;
}复杂度1/n *(n-1)n/2 = n-1/2

