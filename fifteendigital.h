#ifndef FIFTEENDIGITAL_H
#define FIFTEENDIGITAL_H

#include <QMainWindow>
#include "node.h"
#include "aisearch.h"

namespace Ui {
class FifteenDigital;
//class TreeNode;
}

class FifteenDigital : public QMainWindow
{
    Q_OBJECT

public:
    explicit FifteenDigital(QWidget *parent = 0);
    //变量
    int BarValue = 0;

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
    void CountOpen();
    void CountClose();
    void GetNodeSonNum(TreeNode* p);

    //有关图形界面的函数
    void ShowNode(TreeNode* p);
    void UiInit();

    ~FifteenDigital();

private slots:
    void on_pushButton_clicked();

    void on_pushButton2_clicked();

    void on_pushButton4_clicked();

    void on_pushButton3_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FifteenDigital *ui;
};

#endif // FIFTEENDIGITAL_H
