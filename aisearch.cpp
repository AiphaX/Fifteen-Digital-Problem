
#include "fifteendigital.h"
#include "node.h"
#include "aisearch.h"
#include "math.h"

//使用1倍曼哈顿距离，扩展结点19719个，41层
//使用2倍曼哈顿距离，不满足A*算法，扩展结点3769个
//使用1.5倍曼哈顿距离，扩展结点1246个，41层
//使用1.33倍曼哈顿距离，扩展结点3074个，41层

//计算结点的评估函数
int FifteenDigital::CalValueFun(TreeNode *p)
{
    int fn = 0,RealRow = 0,RealColumn = 0;
    int w = 0;
    for(int i = 0;i < 4 ;i++)
    {
        for(int j = 0;j< 4 ;j++)
        {
            RealRow = (p->Number[i][j] -1)/4;  //实际的行数,0,1,2,3行
            RealColumn = (p->Number[i][j] -1)%4;  //实际的行数
            if(p->Number[i][j] > 0)   //去掉那个没有数字的位置
            {
                fn += ((abs(RealRow - i) + abs(RealColumn - j)));
            }
            else if((i == 0 || j == 0))
            {
                w += 2;   //A算法，扩展结点604个.43层
            }
        }
    }
    if(AlgorithmType == 1)
    {
        ;      //使用曼哈顿距离,A*算法
    }
    else if(AlgorithmType == 2)
    {
        fn = fn * 3 /2;
    }
    else if(AlgorithmType == 3)
    {
        fn = fn * 3 /2 + w;
    }

    return (fn+p->deepth);
}
