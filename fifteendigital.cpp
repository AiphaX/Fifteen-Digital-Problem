#include "fifteendigital.h"
#include "iostream"
#include "ctime"
#include <stdlib.h>

using namespace std;
char Goal[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int NodeSate = 0;

//FifteenDigital::FifteenDigital():
//{
    //QColor emptyclor = QColor::fromRgb(11,1,200,0);
    //ui->setupUi(this);
//}

//FifteenDigital::~FifteenDigital()
//{
    //delete ui;
//}

int FifteenDigital::CountOpen()
{
    int a =0;
    TreeNode *p;
    for(p = &OpenTable;p->OpenNext !=NULL;p=p->OpenNext)
    {
        a++;
    }
    return a;
}

int FifteenDigital::CountClose()
{
    int a =0;
    TreeNode *p;
    for(p = &CloseTable;p->CloseNext !=NULL;p=p->CloseNext)
    {
        a++;
    }
    return a;
}

int FifteenDigital::GetNodeSonNum(TreeNode *p)
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
    return a;
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
void FifteenDigital::run()
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
                cout << "open table number:" << FifteenDigital::CountOpen() << endl;   //显示open表的结点数量
                cout << "close table number:" << FifteenDigital::CountClose() << endl;  //显示close表的结点数量
                break;
            }
         }
        finish = clock();
        cout << "Algorithm run time: " << finish-start << endl; //显示运行时间
        // p->deepth;
        NodeSate = 1;
    }
}

// 搜索路径的前进后退按钮
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
        //FifteenDigital::ShowNode(p);
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
        //FifteenDigital::ShowNode(p);
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
}


void FifteenDigital::init()
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

    //FifteenDigital::ShowNode(&RootNode);

    //open表
    OpenTable.OpenNext = &RootNode;
    OpenTable.OpenPrevious = NULL;
    RootNode.OpenPrevious = &OpenTable;
    RootNode.OpenNext = NULL;
    //close表
    CloseTable.CloseNext = NULL;
    RootNode.CloseNext = NULL;

    BarValue = 0;
}
