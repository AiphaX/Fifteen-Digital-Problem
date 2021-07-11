#include "fifteendigital.h"
#include "ui_fifteendigital.h"
#include "iostream"
#include "windows.h"
#include "ctime"
#include <stdlib.h>

using namespace std;
char Goal[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int NodeSate = 0;

FifteenDigital::FifteenDigital(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FifteenDigital)
{
    //QColor emptyclor = QColor::fromRgb(11,1,200,0);
    ui->setupUi(this);
}

FifteenDigital::~FifteenDigital()
{
    delete ui;

}

void FifteenDigital::ShowNode(TreeNode* p)
{
    if(p!=NULL)
    {
        if(p->Number[0][0] > 0)
            ui->Box01->setTextColor(RGB(0,0,255));
        else
            ui->Box01->setTextColor(RGB(0,255,0));
        ui->Box01->setText(QString::number(p->Number[0][0],10));
        if(p->Number[0][1] > 0)
            ui->Box02->setTextColor(RGB(0,0,255));
        else
            ui->Box02->setTextColor(RGB(0,255,0));
        ui->Box02->setText(QString::number(p->Number[0][1],10));
        if(p->Number[0][2] > 0)
            ui->Box03->setTextColor(RGB(0,0,255));
        else
            ui->Box03->setTextColor(RGB(0,255,0));
        ui->Box03->setText(QString::number(p->Number[0][2],10));
        if(p->Number[0][3] > 0)
            ui->Box04->setTextColor(RGB(0,0,255));
        else
            ui->Box04->setTextColor(RGB(0,255,0));
        ui->Box04->setText(QString::number(p->Number[0][3],10));
        if(p->Number[1][0] > 0)
            ui->Box05->setTextColor(RGB(0,0,255));
        else
            ui->Box05->setTextColor(RGB(0,255,0));
        ui->Box05->setText(QString::number(p->Number[1][0],10));
        if(p->Number[1][1] > 0)
            ui->Box06->setTextColor(RGB(0,0,255));
        else
            ui->Box06->setTextColor(RGB(0,255,0));
        ui->Box06->setText(QString::number(p->Number[1][1],10));
        if(p->Number[1][2] > 0)
            ui->Box07->setTextColor(RGB(0,0,255));
        else
            ui->Box07->setTextColor(RGB(0,255,0));
        ui->Box07->setText(QString::number(p->Number[1][2],10));
        if(p->Number[1][3] > 0)
            ui->Box08->setTextColor(RGB(0,0,255));
        else
            ui->Box08->setTextColor(RGB(0,255,0));
        ui->Box08->setText(QString::number(p->Number[1][3],10));
        if(p->Number[2][0] > 0)
            ui->Box09->setTextColor(RGB(0,0,255));
        else
            ui->Box09->setTextColor(RGB(0,255,0));
        ui->Box09->setText(QString::number(p->Number[2][0],10));
        if(p->Number[2][1] > 0)
            ui->Box10->setTextColor(RGB(0,0,255));
        else
            ui->Box10->setTextColor(RGB(0,255,0));
        ui->Box10->setText(QString::number(p->Number[2][1],10));
        if(p->Number[2][2] > 0)
            ui->Box11->setTextColor(RGB(0,0,255));
        else
            ui->Box11->setTextColor(RGB(0,255,0));
        ui->Box11->setText(QString::number(p->Number[2][2],10));
        if(p->Number[2][3] > 0)
            ui->Box12->setTextColor(RGB(0,0,255));
        else
            ui->Box12->setTextColor(RGB(0,255,0));
        ui->Box12->setText(QString::number(p->Number[2][3],10));
        if(p->Number[3][0] > 0)
            ui->Box13->setTextColor(RGB(0,0,255));
        else
            ui->Box13->setTextColor(RGB(0,255,0));
        ui->Box13->setText(QString::number(p->Number[3][0],10));
        if(p->Number[3][1] > 0)
            ui->Box14->setTextColor(RGB(0,0,255));
        else
            ui->Box14->setTextColor(RGB(0,255,0));
        ui->Box14->setText(QString::number(p->Number[3][1],10));
        if(p->Number[3][2] > 0)
            ui->Box15->setTextColor(RGB(0,0,255));
        else
            ui->Box15->setTextColor(RGB(0,255,0));
        ui->Box15->setText(QString::number(p->Number[3][2],10));
        if(p->Number[3][3] > 0)
            ui->Box16->setTextColor(RGB(0,0,255));
        else
            ui->Box16->setTextColor(RGB(0,255,0));
        ui->Box16->setText(QString::number(p->Number[3][3],10));
    }
}

void FifteenDigital::UiInit()
{
    ui->textBrowser1->setText(QString::number(0,10));
    ui->textBrowser2->setText(QString::number(0,10));
    ui->textBrowser3->setText(QString::number(0,10));
    ui->textBrowser4->setText(QString::number(0,10));
    ui->pushButton5->setStyleSheet("background:rgb(0,255,0)");
    ui->pushButton6->setStyleSheet("background:rgb(255,255,255)");
    ui->pushButton7->setStyleSheet("background:rgb(255,255,255)");
}

void FifteenDigital::CountOpen()
{
    int a =0;
    TreeNode *p;
    for(p = &OpenTable;p->OpenNext !=NULL;p=p->OpenNext)
    {
        a++;
    }
    ui->textBrowser1->setText(QString::number(a,10));
}

void FifteenDigital::CountClose()
{
    int a =0;
    TreeNode *p;
    for(p = &CloseTable;p->CloseNext !=NULL;p=p->CloseNext)
    {
        a++;
    }
    ui->textBrowser2->setText(QString::number(a,10));
}

void FifteenDigital::GetNodeSonNum(TreeNode *p)
{
    int a = 0;
    if(p->SonNode1 != NULL)
        a+=1;
    if(p->SonNode2 != NULL)
        a+=1;
    if(p->SonNode3 != NULL)
        a+=1;
    if(p->SonNode4 != NULL)
        a++;
    ui->textBrowser3->setText(QString::number(a,10));
}


bool FifteenDigital::MatchNumber(char a[4][4])
{
    int i =0,j = 0;
    for(i= 0;i<4;i++)
    {
        for(j=0;j <4;j++)
        {
            if(a[i][j] != Goal[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

//按键按下，这时候可以开始更改内容
void FifteenDigital::on_pushButton_clicked()
{
    TreeNode *p;
    clock_t start,finish;
    int time = 0;
    start = clock();
    if(NodeSate == 0)
    {
        while(1)   //进入
        {
            p = FifteenDigital::SearchOpenTable();   //找到当前搜索树中fn最小的结点
            FifteenDigital::ExtendNode(p);       //扩展该结点
            FifteenDigital::RefreshOpenClose(p);  //更新open表和close表
            time++;
            if(FifteenDigital::MatchNumber(p->Number) == true || time >100000)
            {    //当搜索到目标结点或者扩展次数超过10万次
                FinalNode = p;
                FifteenDigital::ShowNode(p);   //显示该结点的状态
                FifteenDigital::CountOpen();   //显示open表的结点数量
                FifteenDigital::CountClose();  //显示close表的结点数量
                ui->textBrowser4->setText(QString::number(p->deepth,10));
                break;
            }
         }
        finish = clock();
        ui->textBrowser3->setText(QString::number((finish-start),10)); //显示运行时间
        BarValue = p->deepth;
        ui->progressBar->setValue(100);
        NodeSate = 1;
    }
}

void FifteenDigital::on_pushButton2_clicked()
{
    if(FinalNode != NULL)
    {
        TreeNode *p = FinalNode;
        if(BarValue < FinalNode->deepth)
            BarValue++;
        while(1)
        {
            if( p->deepth  <= BarValue)
                break;
            p = p->FatherNode;
        }
        FifteenDigital::ShowNode(p);
        ui->progressBar->setValue(p->deepth *100 / FinalNode->deepth);
    }
}

void FifteenDigital::on_pushButton4_clicked()
{
    if(FinalNode != NULL)
    {
        TreeNode *p = FinalNode;
        if(BarValue > 0)
            BarValue--;
        while(1)
        {
            if(p->deepth  <= BarValue)
                break;
            p = p->FatherNode;
        }
        FifteenDigital::ShowNode(p);
        ui->progressBar->setValue(p->deepth *100 / FinalNode->deepth);
    }
}

void FifteenDigital::on_pushButton3_clicked()
{
    int row = 0,column = 0,a = 0,num = 0;
    if(NodeSate == 1)
        num = 60;
    else
        num = 30;

    for(int i = 0;i <num; i++)
    {
        row = RootNode.EmptyPosition/10;
        column = RootNode.EmptyPosition%10;
        a = rand()%4;
        if(row >= 1 && a == 0)   //向上移动
        {
            RootNode.Number[row][column] = RootNode.Number[row-1][column];
            RootNode.Number[row-1][column] = 0;
            RootNode.EmptyPosition -= 10;
        }
        else if(row <= 2 && a== 1)  //向下移动
        {
            RootNode.Number[row][column] = RootNode.Number[row+1][column];
            RootNode.Number[row+1][column] = 0;
            RootNode.EmptyPosition += 10;
        }
        else if(column >= 1 && a== 2)   //向左移动
        {
            RootNode.Number[row][column] = RootNode.Number[row][column-1];
            RootNode.Number[row][column-1] = 0;
            RootNode.EmptyPosition -= 1;
        }
        else if(column <= 2 && a== 3)  //向右移动
        {
            RootNode.Number[row][column] = RootNode.Number[row][column+1];
            RootNode.Number[row][column+1] = 0;
            RootNode.EmptyPosition += 1;
        }
    }

    FifteenDigital::ShowNode(&RootNode);
    NodeSate = 0;
    RootNode.OpenNext = NULL;
    RootNode.OpenPrevious = NULL;
    RootNode.CloseNext = NULL;
    RootNode.FatherNode = NULL;
    RootNode.deepth = 0;
    RootNode.EmptyPosition = FifteenDigital::CalEmptyPosition(&RootNode);
    RootNode.fn = FifteenDigital::CalValueFun(&RootNode);
    FinalNode = NULL;

    //open表
    OpenTable.OpenNext = &RootNode;
    RootNode.OpenPrevious = &OpenTable;
    OpenTable.OpenPrevious = NULL;
    //close表
    CloseTable.CloseNext = NULL;
    BarValue = 0;
    ui->progressBar->setValue(0);
}

void FifteenDigital::on_pushButton5_clicked()
{
    AlgorithmType = 1;
    ui->pushButton5->setStyleSheet("background:rgb(0,255,0)");
    ui->pushButton6->setStyleSheet("background:rgb(255,255,255)");
    ui->pushButton7->setStyleSheet("background:rgb(255,255,255)");
}

void FifteenDigital::on_pushButton6_clicked()
{
    AlgorithmType = 2;
    ui->pushButton5->setStyleSheet("background:rgb(255,255,255)");
    ui->pushButton6->setStyleSheet("background:rgb(0,255,0)");
    ui->pushButton7->setStyleSheet("background:rgb(255,255,255)");
}

void FifteenDigital::on_pushButton7_clicked()
{
    AlgorithmType = 3;
    ui->pushButton5->setStyleSheet("background:rgb(255,255,255)");
    ui->pushButton6->setStyleSheet("background:rgb(255,255,255)");
    ui->pushButton7->setStyleSheet("background:rgb(0,255,0)");
}

void FifteenDigital::on_pushButton_2_clicked()
{
    RootNode.Number[0][0]=11;
    RootNode.Number[0][1]=9;
    RootNode.Number[0][2]=4;
    RootNode.Number[0][3]=15;
    RootNode.Number[1][0]=1;
    RootNode.Number[1][1]=3;
    RootNode.Number[1][2]=0;
    RootNode.Number[1][3]=12;
    RootNode.Number[2][0]=7;
    RootNode.Number[2][1]=5;
    RootNode.Number[2][2]=8;
    RootNode.Number[2][3]=6;
    RootNode.Number[3][0]=13;
    RootNode.Number[3][1]=2;
    RootNode.Number[3][2]=10;
    RootNode.Number[3][3]=14;
    NodeSate = 0;

    RootNode.SonNode1 = NULL;
    RootNode.SonNode2 = NULL;
    RootNode.SonNode3 = NULL;
    RootNode.SonNode4 = NULL;

    RootNode.FatherNode = NULL;
    RootNode.deepth = 0;
    RootNode.EmptyPosition = FifteenDigital::CalEmptyPosition(&RootNode);
    RootNode.fn = FifteenDigital::CalValueFun(&RootNode);
    FinalNode = NULL;

    FifteenDigital::ShowNode(&RootNode);

    //open表
    OpenTable.OpenNext = &RootNode;
    OpenTable.OpenPrevious = NULL;
    RootNode.OpenPrevious = &OpenTable;
    RootNode.OpenNext = NULL;
    //close表
    CloseTable.CloseNext = NULL;
    RootNode.CloseNext = NULL;

    BarValue = 0;
    ui->progressBar->setValue(0);
}
