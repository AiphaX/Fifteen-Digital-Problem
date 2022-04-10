#include "fifteendigital.h"
#include "iostream"
#include "ctime"

using namespace std;
int Goal[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int NodeSate = 0;

FifteenDigital::FifteenDigital()
{
}

FifteenDigital::~FifteenDigital()
{
}

void FifteenDigital::init()
{
    int data[4][4] = {
        {11, 9, 4, 15},
        {1, 3, 0, 12},
        {7, 5, 8, 6},
        {13, 2, 10, 14}
    };
    for(int i=0; i < 4;i++)
        for(int j=0; j <4 ;j++)
            RootNode.Number[i][j]=data[i][j];

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

    cout << "init status:" << endl;
    FifteenDigital::ShowNode(&RootNode);

    //open表
    OpenTable.OpenNext = &RootNode;
    OpenTable.OpenPrevious = NULL;
    RootNode.OpenPrevious = &OpenTable;
    RootNode.OpenNext = NULL;
    //close表
    CloseTable.CloseNext = NULL;
    RootNode.CloseNext = NULL;
}

int FifteenDigital::CountOpen()
{
    int num =0;
    TreeNode *p;
    for(p = &OpenTable;p->OpenNext !=NULL;p=p->OpenNext)
    {
        num++;
    }
    return num;
}

int FifteenDigital::CountClose()
{
    int num =0;
    TreeNode *p;
    for(p = &CloseTable;p->CloseNext !=NULL;p=p->CloseNext)
    {
        num++;
    }
    return num;
}

void FifteenDigital::ShowNode(TreeNode* p)
{
    for(int i = 0;i < 4; i++) {
        for (int j = 0; j < 4; j++){
            cout << p->Number[i][j] << "\t";
        }
        cout << endl;
    }
}

bool FifteenDigital::MatchNumber(int a[4][4])
{
    int i = 0, j = 0;
    for(i = 0;i < 4;i++){
        for(j = 0;j < 4;j++){
            if(a[i][j] != Goal[i][j]){
                return false;
            }
        }
    }
    return true;
}

//main step
void FifteenDigital::run()
{
    TreeNode *p;
    clock_t start_t,finish_t;
    int search_times = 0;
    int node_deepth = p->deepth;
    start_t = clock();
    if(NodeSate == 0){
        while(1){
            p = FifteenDigital::SearchOpenTable();   //找到当前搜索树中fn最小的结点
            FifteenDigital::ExtendNode(p);       //扩展该结点
            FifteenDigital::RefreshOpenClose(p);  //更新open表和close表
            search_times++;
            if(p->deepth > node_deepth) {
                node_deepth = p->deepth;
                cout << "step " << p->deepth << endl;
                FifteenDigital::ShowNode(p);
            }
            if(FifteenDigital::MatchNumber(p->Number) || search_times >100000)
            {    //当搜索到目标结点或者扩展次数超过10万次
                FinalNode = p;
                cout << endl << "search times: " << search_times << endl;
                cout << "move steps: " << p->deepth << endl;
                cout << "open table number:" << FifteenDigital::CountOpen() << endl;   //显示open表的结点数量
                cout << "close table number:" << FifteenDigital::CountClose() << endl;  //显示close表的结点数量
                break;
            }
         }
        finish_t = clock();
        cout << "Algorithm run time: " << double(finish_t - start_t)/CLOCKS_PER_SEC << " s" << endl; //显示运行时间
        NodeSate = 1;
    }
}
