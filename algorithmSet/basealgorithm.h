#ifndef BASEALGORITHM_H
#define BASEALGORITHM_H

#include <vector>

using namespace std;


class BaseAlgorithm
{
public:
    BaseAlgorithm();

    //归并排序
    void all_sort(vector<int> &a, int lo, int hi);
    void merge(vector<int> &nums, int lo, int mid, int hi);

    //快速排序
    void quick_sort(int a[], int lo, int hi);
    int partition(int a[], int lo, int hi);
    //非递归快速排序
    void quickSort(int array[], int lo, int hi);
};

#endif // BASEALGORITHM_H
