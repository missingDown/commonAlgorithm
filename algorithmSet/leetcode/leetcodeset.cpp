#include "leetcodeset.h"

LeetcodeSet::LeetcodeSet()
{

}

int LeetcodeSet::maxProfir(const vector<int> &prices)
{
    int maxProfir = 0;
    for(int i=1; i < prices.size(); i++){
        if(prices[i]>prices[i-1]){
            maxProfir += prices[i] - prices[i-1];
        }
    }
    return maxProfir;
}
