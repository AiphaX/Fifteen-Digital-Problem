#include "fifteendigital.h"
#include "node.h"
#include <iostream>

using namespace std;
 TreeNode RootNode;
 TreeNode OpenTable;
 TreeNode CloseTable;
 TreeNode *FinalNode;
 int AlgorithmType = 1;

int main()
{
    cout << "Program is running" << endl;
     FifteenDigital w;
     w.init();
     w.run();
}
