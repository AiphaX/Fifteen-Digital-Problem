#ifndef FIFTEENDIGITAL_H
#define FIFTEENDIGITAL_H

#include "node.h"
#include "aisearch.h"

class FifteenDigital
{
public:
    ~FifteenDigital();
    FifteenDigital();

    //有关搜索树的函数
    void NodeInit();
    void ExtendNode(TreeNode* p);   //扩展结点的函数
    int CalValueFun(TreeNode* p);   //计算估值函数
    void RefreshOpenClose(TreeNode* p);     //更新open表和close表
    int CalEmptyPosition(TreeNode* p);    //返回结点空位置的行数和列数
    void ExtendSonNode(TreeNode* fatherNode,MoveType move);
    int FindSameNode(TreeNode* p,int a[4][4]);    //找搜索树中是否有相同的结点
    void CopyNumber(TreeNode* p,int a[4][4]);
    void SortOpenTable();
    TreeNode* SearchOpenTable();
    bool MatchNumber(int a[4][4]);
    int CountOpen();
    int CountClose();

    void run();
    void ShowNode(TreeNode *p);
    void init();
};

#endif // FIFTEENDIGITAL_H
