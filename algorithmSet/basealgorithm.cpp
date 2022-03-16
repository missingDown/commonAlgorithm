#include "basealgorithm.h"
#include <string.h>
#include <stack>


BaseAlgorithm::BaseAlgorithm()
{

}

void BaseAlgorithm::bubbleSort(vector<int> &nums)
{
    //定义一个布尔变量hasChanged，用来标记每轮遍历中是否发生了交换
    bool hasChanged = true;
    //每轮遍历开始，将 hasChange 设置为 false
    for(int i=0;i<nums.size()-1 && hasChanged;i++){
        hasChanged = false;
        //进行两两比较，如果发现当前的数比下一个数还大，那么就交换这两个数，同时记录一下有交换发生
        for(int j=0;j<nums.size()-1-i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                hasChanged = true;
            }
        }
    }
}

void BaseAlgorithm::insertSort(vector<int> &nums)
{
    // 将数组的第一个元素当作已经排好序的，从第二个元素，即 i 从 1 开始遍历数组
    for(int i=1,j,current;i<nums.size();i++){
        // 外围循环开始，把当前 i 指向的值用 current 保存
        current = nums[i];
        // 指针 j 内循环，和 current 值比较，若 j 所指向的值比 current 值大，则该数右移一位
        for(j=i-1;j>=0&&nums[j]>current;j--){
            nums[j+1] = nums[j];
        }
        // 内循环结束，j+1 所指向的位置就是 current 值插入的位置
        nums[j+1] = current;
    }
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
