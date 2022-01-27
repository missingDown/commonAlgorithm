#include <iostream>
#include "leetcode/leetcodeset.h"
#include "basealgorithm.h"

using namespace std;

int main()
{
//    LeetcodeSet leetcodeSet;
//    vector<int> data = {1,2,3,4,5};
//    int result = leetcodeSet.maxProfir(data);
//    cout << result << endl;

//    vector<int> p = {2, 1, 7, 9, 5, 8};
//    int len = p.size();
//    BaseAlgorithm().all_sort(p, 0, len-1);
//    for (int i = 0;i<len;i++)
//    {
//        cout << p[i] << endl;
//    }

    int p[] = {2, 1, 7, 9, 5, 8};
    int len = sizeof (p)/sizeof (p[0]);
    BaseAlgorithm().quickSort(p,0,len-1);
    for (int i = 0;i<len;i++)
    {
        cout << p[i] << endl;
    }
    return 0;
}
