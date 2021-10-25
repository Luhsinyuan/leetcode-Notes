#include"iostream"
#include"vector"

using namespace std;

int binary_search_non_recursive(vector<int> nums,int left,int right,int target) //nums�Ѿ�������������,Ĭ����������Ҫ���ҵ�Ŀ��ֵ
{
    while(left<right)
    {
        int mid=(left+right)/2;          //ȡ���м�λ��
        if(nums[mid]==target)            //����м�ֵ��Ŀ��ֵ��ȣ�ֱ�ӷ���
        {
            return mid;
        }
        else if(nums[mid]<target)        //���Ŀ��ֵ�����м�ֵ����left��ֵ����Ϊmid����������������Ұ벿�ֲ���
        {
            left=mid;
        }
        else if(nums[mid]>target)       //���Ŀ��ֵС���м�ֵ����right��ֵ����Ϊmid�����������������벿�ֲ���
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
        return binary_search_recursive(nums,left,mid-1,target);     //�ݹ鵽��������߲���
    }
    else if(target>nums[mid])
    {
        return binary_search_recursive(nums,mid+1,right,target);    //�ݹ鵽������Ұ�߲���
    }
    else
        return mid;
}