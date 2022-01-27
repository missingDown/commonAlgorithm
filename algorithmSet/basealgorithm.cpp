#include "basealgorithm.h"
#include <string.h>
#include <stack>


BaseAlgorithm::BaseAlgorithm()
{

}

void BaseAlgorithm::all_sort(vector<int> &a, int lo, int hi)
{
    //判断是否只剩下最后一个元素
    if (lo >= hi)
    {
        return;
    }

    // 从中间将数组分成两个部分
    int mid = lo + (hi - lo)/2;

    //分别递归地将左右两半排好序
    all_sort(a, lo, mid);
    all_sort(a, mid+1, hi);

    //将排好序的左右两半合并
    merge(a, lo, mid, hi);
}

void BaseAlgorithm::merge(vector<int> &nums, int lo, int mid, int hi)
{
    //复制一份原来的数组
    vector<int> copy(nums);

    //定义一个k指针表示从什么位置开始修改原来的数组，i指针表示左半边的起始位置，j指针表示右半边的起始位置
    int k = lo, i = lo, j = mid + 1;
    while (k<=hi) {
        if (i>mid)
        {
            nums[k++] = copy[j++];
        } else if (j>hi) {
            nums[k++] = copy[i++];
        } else if (copy[j]<copy[i]) {
            nums[k++] = copy[j++];
        } else {
            nums[k++] = copy[i++];
        }
    }
}

void BaseAlgorithm::quick_sort(int a[], int lo, int hi)
{
    //判断是否只剩下一个元素，是，则直接返回
    if(lo>=hi)
    {
        return;
    }

    int p = partition(a, lo, hi);//选取基准值，分成比基准值小和比基准值大的两部分
    quick_sort(a, lo, p-1);//左半部分继续排序拆分
    quick_sort(a, p+1, hi);//右半部分继续排序拆分
}

int BaseAlgorithm::partition(int a[], int lo, int hi)
{
    int pivotkey;
    pivotkey = a[lo];
    while (lo<hi) {
        while (lo<hi&&a[hi]>=pivotkey) {
            hi--;
        }

        a[lo] = a[hi];
        a[hi] = pivotkey;

        while (lo<hi&&a[lo]<=pivotkey) {
            lo++;
        }

        a[hi] = a[lo];
        a[lo] = pivotkey;
    }
    return lo;
}

void BaseAlgorithm::quickSort(int array[], int lo, int hi)
{
    if(lo>=hi) return ;

    stack<int> st; // 用栈保存每一个待排序子串的首尾元素下标
    int mid = partition(array, 0, hi);
    if(mid > 1){
        st.push(0);
        st.push(mid-1);
    }
    int len = hi - lo + 1;
    if(mid < len-2){
        st.push(mid + 1);
        st.push(len-1);
    }

    while(!st.empty()){
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        mid = partition(array, left, right);
        if(left < mid-1){
            st.push(left);
            st.push(mid-1);
        }
        if(right > mid+1){
            st.push(mid+1);
            st.push(right);
        }
    }
}
