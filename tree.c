#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef char ElemType;



//二叉树的存储结构——顺序结构
/*
typedef struct
{
	ElemType data[MAXSIZE];
	int n; //二叉树的结点个数
} SqBiTree;
*/
//顺序结构的二叉树存在一个问题：当树的深度较大时，数组中会有大量的空位，造成空间浪费。不经常使用。

//二叉树的存储结构——链式结构
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild; //左右孩子指针
} BiTNode, * BiTree;

char str[] = "ABDH#K###E##CFI###G#J##"; //二叉树的前序遍历序列，#表示空结点
int index = 0; //全局变量，记录当前访问的字符在str中的位置

//创建二叉树
void CreateBiTree(BiTree* T)
{
	char ch = str[index++]; //获取当前字符并将index加1
	if (ch == '#')
	{
		*T = NULL; //如果是#，表示空结点，设置*T为NULL
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode)); //分配内存
		(*T)->data = ch; //设置结点数据
		CreateBiTree(&(*T)->lchild); //递归创建左子树
		CreateBiTree(&(*T)->rchild); //递归创建右子树
	}
}


//二叉树的遍历--前序遍历
void PreOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		printf("%c ", T->data); //访问根结点
		PreOrderTraverse(T->lchild); //前序遍历左子树
		PreOrderTraverse(T->rchild); //前序遍历右子树
	}
}

//二叉树的遍历--中序遍历
void InOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild); //中序遍历左子树
		printf("%c ", T->data); //访问根结点
		InOrderTraverse(T->rchild); //中序遍历右子树
	}
}

//二叉树的遍历--后序遍历
void PostOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		PostOrderTraverse(T->lchild); //后序遍历左子树
		PostOrderTraverse(T->rchild); //后序遍历右子树
		printf("%c ", T->data); //访问根结点
	}
}





//main函数测试

int main()
{
	BiTree T;
	CreateBiTree(&T); //创建二叉树
	printf("前序遍历: ");
	PreOrderTraverse(T); //前序遍历
	printf("\n中序遍历: ");
	InOrderTraverse(T); //中序遍历
	printf("\n后序遍历: ");
	PostOrderTraverse(T); //后序遍历
	printf("\n");
	return 0;
}






