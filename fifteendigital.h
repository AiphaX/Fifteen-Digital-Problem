#ifndef FIFTEENDIGITAL_H
#define FIFTEENDIGITAL_H

#include "node.h"
#include "aisearch.h"

//namespace Ui {
//class FifteenDigital;
//class TreeNode;
//}

class FifteenDigital
{
public:
    explicit FifteenDigital();
    //变量
    int BarValue;

    //有关搜索树的函数
    void NodeInit();
    void ExtendNode(TreeNode* p);   //扩展结点的函数
    int CalValueFun(TreeNode* p);   //计算估值函数
    void RefreshOpenClose(TreeNode* p);     //更新open表和close表
    int CalEmptyPosition(TreeNode* p);    //返回结点空位置的行数和列数
    void ExtendSonNode(TreeNode* fatherNode,MoveType move);
    int FindSameNode(TreeNode* p,char a[4][4]);    //找搜索树中是否有相同的结点
    void CopyNumber(TreeNode* p,char a[4][4]);
    void SortOpenTable();
    TreeNode* SearchOpenTable();
    bool MatchNumber(char a[4][4]);
    int CountOpen();
    int CountClose();
    int GetNodeSonNum(TreeNode* p);

    ~FifteenDigital();

    void run();

    void on_pushButton2_clicked();

    void on_pushButton4_clicked();

    void on_pushButton3_clicked();

    void init();
};

#endif // FIFTEENDIGITAL_H
