#include "fifteendigital.h"
#include "node.h"
#include "math.h"
//结点初始化，构造函数
TreeNode::TreeNode()
{
    SonNode1 = NULL;
    SonNode2 = NULL;
    SonNode3 = NULL;
    SonNode4 = NULL;
    OpenNext = NULL;
    OpenPrevious =NULL;
    CloseNext = NULL;
    FatherNode = NULL;
    fn = 0;

}

//结点的析构函数
TreeNode::~TreeNode()
{
//    delete TreeNode;
}

//计算一个结点空位的位数
int FifteenDigital::CalEmptyPosition(TreeNode* p)
{
    int i=0,j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
           if(p->Number[i][j] == 0)
           {
               return (10*i+j);
           }
        }
    }
    return 0;
}

void FifteenDigital::CopyNumber(TreeNode* p,int a[4][4])
{
    for(int i = 0; i<4; i++)
        for(int j =0; j<4 ;j++)
            a[i][j] = p->Number[i][j];
}

//扩展某一个类型的子节点，空格上下移动
void FifteenDigital::ExtendSonNode(TreeNode* fatherNode, MoveType move)
{
    TreeNode *p = new TreeNode;
    p->FatherNode = fatherNode;
    int position = fatherNode->EmptyPosition;

    //复制数据
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            p->Number[i][j] = fatherNode->Number[i][j];

    if(move == UP)
    {
         fatherNode->SonNode1 = p;
         p->Number[position/10][position%10] = p->Number[position/10 - 1][position%10];
         p->Number[position/10 - 1][position%10] = 0;
         p->EmptyPosition = position - 10;   //更新空位的位置
    }
    else if(move == DOWN)
    {
        fatherNode->SonNode2 = p;
        p->Number[position/10][position%10] = p->Number[position/10 + 1][position%10];
        p->Number[position/10 + 1][position%10] = 0;
        p->EmptyPosition = position + 10;
    }
    else if(move == LEFT)
    {
        fatherNode->SonNode3 = p;
        p->Number[position/10][position%10] = p->Number[position/10][position%10 - 1];
        p->Number[position/10][position%10 - 1] = 0;
        p->EmptyPosition = position - 1;
    }
    else if(move == RIGHT)
    {
        fatherNode->SonNode4 = p;
        p->Number[position/10][position%10] = p->Number[position/10][position%10 + 1];
        p->Number[position/10][position%10 + 1] = 0;
        p->EmptyPosition = position + 1;
    }

    p->SonNode1 = NULL;
    p->SonNode2 = NULL;
    p->SonNode3 = NULL;
    p->SonNode4 = NULL;
    p->FatherNode = fatherNode;
    p->deepth = fatherNode->deepth + 1;
    p->OpenNext = NULL;
    p->CloseNext = NULL;
    p->fn = FifteenDigital::CalValueFun(p);
    //加入到open表中
    p->OpenNext = OpenTable.OpenNext;
    if(OpenTable.OpenNext != NULL)
    {
        OpenTable.OpenNext->OpenPrevious = p;
    }
    p->OpenPrevious = &OpenTable;
    OpenTable.OpenNext = p;
}

//扩展某个结点
void FifteenDigital::ExtendNode(TreeNode* p)
{
    int row = p->EmptyPosition/10;
    int column = p->EmptyPosition%10;
    int a[4][4];

    if(row>=1)    //可以向上移动
    {
       FifteenDigital::CopyNumber(p, a);
       a[row][column] = p->Number[row - 1][column];
       a[row - 1][column] = 0;
       if(FifteenDigital::FindSameNode(&RootNode, a) == 0)   //去搜索树中搜索没有一样的结点，可以扩展
       {
           FifteenDigital::ExtendSonNode(p,UP);
       }
       else
       {
           p->SonNode1 = NULL;
       }
    }
    else
    {
       p->SonNode1 = NULL;
    }

    if(row<=2)    //可以向下移动
    {
        FifteenDigital::CopyNumber(p, a);
        a[row][column] = p->Number[row + 1][column];
        a[row + 1][column] = 0;
        if(FifteenDigital::FindSameNode(&RootNode,a) == 0)  //去搜索树中搜索没有一样的结点，可以扩展
        {
            FifteenDigital::ExtendSonNode(p,DOWN);
        }
        else
        {
            p->SonNode2 = NULL;
        }
    }
    else
    {
        p->SonNode2 = NULL;
    }

    if(column>=1)    //可以向左移动
    {
        FifteenDigital::CopyNumber(p,a);
        a[row][column] = p->Number[row][column - 1];
        a[row][column - 1] = 0;
        if(FifteenDigital::FindSameNode(&RootNode,a) == 0)   //去搜索树中搜索没有一样的结点，可以扩展
        {
            FifteenDigital::ExtendSonNode(p,LEFT);
        }
        else
        {
            p->SonNode3 = NULL;
        }
    }
    else
    {
        p->SonNode3 = NULL;
    }

    if(column<=2)    //可以向右移动
    {
        FifteenDigital::CopyNumber(p,a);
        a[row][column] = p->Number[row][column + 1];
        a[row][column + 1] = 0;
        if(FifteenDigital::FindSameNode(&RootNode,a) == 0)   //去搜索树中搜索没有一样的结点，可以扩展
        {
            FifteenDigital::ExtendSonNode(p,RIGHT);
        }
        else
        {
            p->SonNode4 = NULL;
        }
    }
    else
    {
        p->SonNode4 = NULL;
    }

}

//从搜索树中找是否有相同的结点
int FifteenDigital::FindSameNode(TreeNode* p,int a[4][4])
{
    int result =0;
    if(p == NULL)
    {
        return 0;
    }
    result += FifteenDigital::FindSameNode(p->SonNode1,a);  //子结点1
    result += FifteenDigital::FindSameNode(p->SonNode2,a);  //子结点2
    result += FifteenDigital::FindSameNode(p->SonNode3,a);  //子结点3
    result += FifteenDigital::FindSameNode(p->SonNode4,a);  //子结点4
    int i = 0, j = 0;
    for(i = 0; i<4; i++)
    {
        for(j =0; j<4 ;j++)
        {
            if(p->Number[i][j] != a[i][j])
                return result;
        }
    }
    return (result+1);
}

//更新open表和close表
void FifteenDigital::RefreshOpenClose(TreeNode* p)
{
    //open
    p->OpenPrevious->OpenNext = p->OpenNext;
    if(p->OpenNext != NULL)
    {
        p->OpenNext->OpenPrevious = p->OpenPrevious;
    }
    p->OpenPrevious = NULL;
    p->OpenNext = NULL;

    //close
    p->CloseNext = CloseTable.CloseNext;
    CloseTable.CloseNext = p;
}

//①对open表进行排序
void FifteenDigital::SortOpenTable()
{
    TreeNode *MinNode,*temp,*p,*q;
    if(OpenTable.OpenNext != NULL)
    {
        MinNode=OpenTable.OpenNext;
        for(p = OpenTable.OpenNext; p->OpenNext!=NULL; p=p->OpenNext)
        {
            for(q=p; q->OpenNext!= NULL; q=q->OpenNext)
            {
                if(q->fn < MinNode->fn)
                {
                    MinNode = q;
                }
            }
            temp = q;
            q->OpenNext = p->OpenNext;
            q->OpenPrevious = p->OpenPrevious;
            p->OpenPrevious->OpenNext = q;
            if(p->OpenNext != NULL)
            {
                p->OpenNext->OpenPrevious = q;
            }

            p->OpenPrevious = temp->OpenPrevious;
            p->OpenNext = temp->OpenNext;
            temp->OpenPrevious->OpenNext = p;
            if(temp->OpenNext != NULL)
            {
                temp->OpenNext->OpenPrevious = p;
            }
            p=q;
        }
    }
}

//②找到Open表中fn最小的结点即可
TreeNode* FifteenDigital::SearchOpenTable()
{
    TreeNode *p,*MinNode;
    p = OpenTable.OpenNext;
    if(OpenTable.OpenNext != NULL && p != &RootNode)
    {
        MinNode = OpenTable.OpenNext;
        for(p = OpenTable.OpenNext; p->OpenNext!=NULL; p=p->OpenNext)
        {
            if(p->fn < MinNode->fn)     // || (p->fn == MinNode->fn && p->deepth > MinNode->deepth))
            {
                MinNode = p;
            }
        }
        return MinNode;
    }
    else
    {
        return p;
    }
}
