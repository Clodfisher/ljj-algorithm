#include<stdio.h>
#include<stdlib.h>

typedef	int S32;
typedef char CHAR;
typedef void VOID;
typedef int BOOL;
typedef struct testNode
{
	CHAR ucData;
	struct testNode *pstNext;
}TESTNODE;

#define	TRUE  		1
#define FALSE 		0
#define RET_OK	 	0
#define RET_ERROR 	-1

S32	linkInsert(TESTNODE **ppstHead, CHAR ucData);
S32	linkCreate(TESTNODE **ppstHead, CHAR *acTestData, S32 iLen);
VOID linkPrint(TESTNODE *pstHead);
BOOL isHuiwen(TESTNODE *pstHead);
TESTNODE* linkFindByIdx(TESTNODE *pstHead, S32 iIndex);
S32 linkCreateSycleByIdx(TESTNODE **ppstHead, CHAR *acTestData, S32 iLen, S32 iLinkIdx);
BOOL isLinkSycle(TESTNODE *pstHead);
TESTNODE *linkMerge(TESTNODE	*pstFistHead, TESTNODE *pstSecondHead);
VOID linkFindMiddleNode(TESTNODE *pstHead);

S32 main(S32 argc, CHAR *argv[])
{
	CHAR 		atestData1[] = {'a', 'c','e'};
	CHAR		atestData[] = {'a', 'b', 'c'};
	CHAR        atestData2[] = {'a', 'b', 'c'};
	CHAR		atestData3[] = {'a'};
	S32			iRet = RET_ERROR;
	S32			iLen = 0;
	S32			iLoop = 0;
	BOOL		bHuiwen = FALSE;
	TESTNODE	*pstFirstHead = NULL;
	TESTNODE	*pstSecondHead = NULL;
	TESTNODE	*pstTargetHead = NULL;

	iLen = sizeof(atestData)/sizeof(CHAR);
	linkCreate(&pstFirstHead, atestData, iLen);
	linkPrint(pstFirstHead);
	
	linkFindMiddleNode(pstFirstHead);

	return iRet;
}

//查找链表中间节点，两个指针，后指针为中间节点
VOID linkFindMiddleNode(TESTNODE *pstHead)
{
	TESTNODE	*pstFirst = pstHead;
	TESTNODE	*pstSec	  = pstHead;

	while (NULL != pstFirst->pstNext && NULL != pstFirst->pstNext->pstNext)
	{
		pstFirst = pstFirst->pstNext->pstNext;
		pstSec	 = pstSec->pstNext;
	}

	printf("middle node is %c.\n", pstSec->ucData);

	return;

}
//删除链表倒数第n个节点，思路是2个指针，前一个指针先走n步
S32	linkDelete(TESTNODE	**ppstHead, S32      n)
{
	TESTNODE	*pstFirstHead = *ppstHead;
	TESTNODE	*pstTarget	  = NULL;
	TESTNODE	*pstPreNode   = NULL;
	S32			i             = 0;

	//前指针先走n步NULL == pstFirstHead->pstNext，表示pstFirstHead以及是最后一个节点了
	while (NULL != pstFirstHead->pstNext && i < n)
	{
		pstFirstHead = pstFirstHead->pstNext;
		i++;
	}
	
	if (NULL == pstFirstHead->pstNext)
	{
	
		//遍历到最后且第一个节点需要删除
		if (i == n)
		{
			pstTarget = *ppstHead;
			*ppstHead = pstTarget->pstNext;
			free(pstTarget);
			return RET_OK;
		}
		else //i输入不对
		{
			printf("i(%d) < n(%d)\n", i, n);
			return RET_ERROR;
		}
	}

	
	//后指针定位到要删除掉节点
	pstTarget = *ppstHead;
	//NULL == pstFirstHead->pstNext,代表pstFistHead已经是最后一个节点
	while (NULL != pstFirstHead->pstNext)
	{
		pstPreNode 		= pstTarget;
		pstFirstHead 	= pstFirstHead->pstNext;
		pstTarget 		= pstTarget->pstNext;	
	}

	pstPreNode->pstNext = pstTarget->pstNext;
	free(pstTarget);

	return RET_OK;
	
}

//两个有序链表合并，思路是选择第一个元素小的链表作为master链表
TESTNODE *linkMerge(TESTNODE	*pstFistHead, TESTNODE *pstSecondHead)
{
	TESTNODE	*pstMaster 		= NULL;
	TESTNODE	*pstSlave  		= NULL;
	TESTNODE	*pstPreNode 	= NULL;
	TESTNODE	*pstInsertNode  = NULL;
	TESTNODE	*pstTargetHead  = NULL;

	if  (pstFistHead->ucData <= pstSecondHead->ucData)
	{
		pstMaster = pstFistHead;
		pstSlave  = pstSecondHead;
	}
	else
	{
		pstMaster = pstSecondHead;
		pstSlave  = pstFistHead;
	}

	pstTargetHead = pstMaster;

	while (NULL != pstMaster && NULL != pstSlave)
	{
		if (pstMaster->ucData <= pstSlave->ucData)
		{
			pstPreNode = pstMaster;
			pstMaster  = pstMaster->pstNext;
		}
		else
		{
			pstInsertNode          = pstSlave;
			pstSlave               = pstSlave->pstNext;
			pstInsertNode->pstNext = pstMaster;
			pstPreNode->pstNext    = pstInsertNode;
			pstPreNode             = pstInsertNode;
		}
	}

	if ( NULL != pstSlave)
	{
		pstPreNode->pstNext = pstSlave;
	}

	return pstTargetHead;

}

//在链表尾插入一个节点
S32	linkInsert(TESTNODE **ppstHead, CHAR ucData)
{
	TESTNODE	*pstNewNode = NULL;
	TESTNODE	*pstTmpNode	= NULL;

	pstNewNode = (TESTNODE *)malloc(sizeof(TESTNODE));
	if	(NULL==pstNewNode)
	{
		printf("malloc new node failed.\n");
		return RET_ERROR;
	}
	pstNewNode->ucData  = ucData;
	pstNewNode->pstNext = NULL;
	
	pstTmpNode = *ppstHead;
	if (NULL == pstTmpNode)
	{
		*ppstHead = pstNewNode;
		return RET_OK;
	}

	while (NULL != pstTmpNode->pstNext)
	{
		pstTmpNode = pstTmpNode->pstNext;
	}

	pstTmpNode->pstNext = pstNewNode;

	return RET_OK;
}

//根据数组创建链表
S32	linkCreate(TESTNODE **ppstHead, CHAR *acTestData, S32 iLen)
{
	S32 	i 	 = 0;
	S32		iRet = RET_ERROR; 
	for (; i < iLen; i++)
	{
		iRet = linkInsert(ppstHead, acTestData[i]);
		if (RET_ERROR == iRet)
		{
			return iRet;
		}
	}
}

//查找链表第i个节点
TESTNODE* linkFindByIdx(TESTNODE *pstHead, S32 iIndex)
{
	S32  		iSearchIdx = 0;
	TESTNODE	*pstTarget = NULL;
	
	while (NULL != pstHead && iSearchIdx < iIndex)
	{
		pstHead = pstHead->pstNext;
		iSearchIdx++;
	}
	if (NULL != pstHead && iSearchIdx == iIndex)
	{
		pstTarget = pstHead;
	}

	return pstTarget;

}
/* 创建单链表环
   iLindIdx表示最后一个节点指向第几个元素，从0开始
*/
S32 linkCreateSycleByIdx(TESTNODE **ppstHead, CHAR *acTestData, S32 iLen, S32 iLinkIdx)
{
	S32	iRet;
	S32 iTmpLen = 0;
	S32 iIdx = 0;
	TESTNODE *pstTargetNode = NULL;
	TESTNODE *pstCurNode = NULL;
	
	iRet = linkCreate(ppstHead, acTestData, iLen);
	if	(RET_ERROR == iRet)
	{
		return iRet;
	}

	pstCurNode = *ppstHead;
	pstTargetNode = linkFindByIdx(pstCurNode, iLinkIdx);
	if (NULL == pstTargetNode)
	{
		printf("find target failed.\n");
		return RET_ERROR;
	}

	while(NULL != pstCurNode->pstNext)
	{
		pstCurNode = pstCurNode->pstNext;
	}

	pstCurNode->pstNext = pstTargetNode;

	iTmpLen = iLen + iLinkIdx;
	pstCurNode = *ppstHead;
	for (iIdx=0; iIdx< iTmpLen; iIdx++)
	{
		printf("%c ", pstCurNode->ucData);
		pstCurNode = pstCurNode->pstNext;
	}

	printf("\n");

	return RET_OK;

}

/* 判定链表中是否存在环 
   第1层循环遍历每个链表，终止条件是pNext == NULL
   第2层循环遍历当前节点所有前面的节点，包括自己，查看是否pNext是否等于某个地址
*/

BOOL isLinkSycle(TESTNODE *pstHead)
{
	TESTNODE	*pstCurNode;
	TESTNODE	*pstNextNode;
	TESTNODE	*pstCheckNode;

	pstCurNode = pstHead;
	while (NULL!= pstCurNode)
	{
		pstNextNode = pstCurNode->pstNext;
		/* 最后一个节点指向自身 */
		if (pstNextNode == pstCurNode)
		{
			printf("find cycle pre(%p,%c) next(%p,%c).\n", pstCurNode, pstCurNode->ucData,
					pstNextNode,pstNextNode->ucData);
			return TRUE;
		}
		
		pstCheckNode = pstHead;
		while( pstCheckNode != pstCurNode )
		{
			if  (pstCheckNode == pstNextNode)
			{
				printf("find cycle pre(%p,%c) next(%p,%c).\n", pstCheckNode, pstCheckNode->ucData,
					pstCurNode,pstCurNode->ucData);
				return TRUE;
			}

			pstCheckNode = pstCheckNode->pstNext;
		}
		
		pstCurNode = pstNextNode;

	}

	return FALSE;
	

}
//链表打印
VOID linkPrint(TESTNODE *pstHead)
{
	while (NULL != pstHead)
	{
		printf("%c ", pstHead->ucData);
		pstHead = pstHead->pstNext;
	}
	printf("\n");

	return;
}
//判定单链表是否是回文，快慢指针，慢指针翻转
BOOL isHuiwen(TESTNODE *pstHead)
{
	TESTNODE	*pstFirstNode 	= NULL;
	TESTNODE	*pstSencondNode = NULL;
	TESTNODE	*pstPreNode		= NULL;
	TESTNODE	*pstNextNode	= NULL;
	TESTNODE	*pstRecoveryPreNode = NULL;
	TESTNODE	*pstRecoveryNode	= NULL;
	BOOL		bIsHuiwen = TRUE;

	/*链表为NULL或只有一个节点不是回文*/
	if	(NULL == pstHead || NULL == pstHead->pstNext)
	{
		printf("link is not huiwen.\n");
		return RET_ERROR;
	}

	pstFirstNode = pstHead;
	pstSencondNode = pstHead;
	 
	while (	NULL != pstFirstNode->pstNext
		 && NULL != pstFirstNode->pstNext->pstNext )
	{
		pstFirstNode 			= pstFirstNode->pstNext->pstNext;

		pstNextNode 			= pstSencondNode->pstNext;
		pstSencondNode->pstNext = pstPreNode;
		pstPreNode 				= pstSencondNode;
		pstSencondNode 			= pstNextNode;				
	}

	/*遍历结束后，快指针赋值为慢指针下一个节点*/
	pstNextNode = pstFirstNode->pstNext;
    pstFirstNode = pstSencondNode->pstNext;
	/*ababa,pstRecoveryPreNode为a，慢指针赋值为前一个指针*/
	if (NULL == pstNextNode)
	{
		pstRecoveryPreNode 	= pstSencondNode;
		pstSencondNode 		= pstPreNode;
	}
	/*abba, pstRecoveryPreNode为b，慢指针改变指向*/
	else if (NULL == pstNextNode->pstNext)
	{
		pstRecoveryPreNode		= pstFirstNode;
		pstSencondNode->pstNext = pstPreNode;
	}

	pstRecoveryNode = pstSencondNode;

	/*遍历判定是否回文*/
	while (NULL != pstFirstNode)
	{
		if (pstFirstNode->ucData != pstSencondNode->ucData)	
		{
			printf("%c %c not huiwen.\n", pstFirstNode->ucData, pstSencondNode->ucData);
			bIsHuiwen = FALSE;
			break;
		}
		pstFirstNode = pstFirstNode->pstNext;
		pstSencondNode = pstSencondNode->pstNext;
	}

   /* 恢复链表 */
	while (NULL != pstRecoveryNode)
	{
		pstNextNode = pstRecoveryNode->pstNext;
		pstRecoveryNode->pstNext = pstRecoveryPreNode;
		pstRecoveryPreNode = pstRecoveryNode;
		pstRecoveryNode = pstNextNode;
	}
	
	return bIsHuiwen;
	
}

