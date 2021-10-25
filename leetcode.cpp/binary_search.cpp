#include"iostream"
#include"vector"

using namespace std;

int binary_search_non_recursive(vector<int> nums,int left,int right,int target) //nums已经按照升序排列,默认数组中有要查找的目标值
{
    while(left<right)
    {
        int mid=(left+right)/2;          //取到中间位置
        if(nums[mid]==target)            //如果中间值和目标值相等，直接返回
        {
            return mid;
        }
        else if(nums[mid]<target)        //如果目标值大于中间值，将left的值更改为mid，即在整个数组的右半部分查找
        {
            left=mid;
        }
        else if(nums[mid]>target)       //如果目标值小于中间值，将right的值更改为mid，即在整个数组的左半部分查找
        {
            right=mid;
        }
    }
    return left;
}
int binary_search_recursive(vector<int> nums,int left,int right,int target)
{
    if(left>right)
    {
        return -1;
    }
    int mid=(left+right)/2;
    if(target<nums[mid])
    {
        return binary_search_recursive(nums,left,mid-1,target);     //递归到数组的左半边查找
    }
    else if(target>nums[mid])
    {
        return binary_search_recursive(nums,mid+1,right,target);    //递归到数组的右半边查找
    }
    else
        return mid;
}