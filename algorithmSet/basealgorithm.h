#ifndef BASEALGORITHM_H
#define BASEALGORITHM_H

#include <vector>

using namespace std;


class BaseAlgorithm
{
public:
    BaseAlgorithm();

    //冒泡排序 时间复杂度：O(n^2) 空间复杂度：O(1)
    static void bubbleSort(vector<int> &nums);

    //插入排序 时间复杂度：O(n^2) 空间复杂度：O(1)
    static void insertSort(vector<int> &nums);

    //归并排序 时间复杂度：O(nlogn) 空间复杂度：O(n)
    static void all_sort(vector<int> &a, int lo, int hi);
    static void merge(vector<int> &nums, int lo, int mid, int hi);

    //快速排序 时间复杂度：O(nlogn) 空间复杂度：O(logn)
    static void quick_sort(int a[], int lo, int hi);
    static int partition(int a[], int lo, int hi);
    //非递归快速排序
    static void quickSort(int array[], int lo, int hi);
};

#endif // BASEALGORITHM_H
