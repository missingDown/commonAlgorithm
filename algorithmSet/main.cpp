#include <iostream>
#include "leetcode/leetcodeset.h"

using namespace std;

int main()
{
    LeetcodeSet leetcodeSet;
    vector<int> data = {1,2,3,4,5};
    int result = leetcodeSet.maxProfir(data);
    cout << result << endl;
    return 0;
}
