#ifndef NODE_H
#define NODE_H

class TreeNode
{
public:
    ~TreeNode();
    TreeNode();

    int deepth;   //该结点的深度
    int fn;       //该结点的估值函数值
    int EmptyPosition;    //结点空位的位置
    int Number[4][4];    //代表这个结点数码的状态
    TreeNode* FatherNode;  //父结点
    TreeNode* SonNode1;
    TreeNode* SonNode2;
    TreeNode* SonNode3;
    TreeNode* SonNode4;  //一个结点可能会有4个子节点
    TreeNode* OpenNext;
    TreeNode* OpenPrevious;
    TreeNode* CloseNext;

};

enum MoveType
{
    UP=1,DOWN=2,LEFT=3,RIGHT=4
};

extern TreeNode RootNode;
extern TreeNode OpenTable;
extern TreeNode CloseTable;
extern TreeNode *FinalNode;
extern int AlgorithmType;

#endif // NODE_H

