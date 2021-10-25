#include"iostream"
#include"vector"

using namespace std;

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        if(!nums.empty())
        {
            sum.push_back(nums[0]);
        }
        for(int i=1;i<nums.size();i++)
        {
            sum.push_back(sum[i-1]+nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            cout<<sum[i]<<endl;
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        return sum[right];
        else
        return sum[right]-sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main()
{  
    vector<int> num={-2, 0, 3, -5, 2, -1};
    NumArray* obj=new NumArray(num);
    int sum=obj->sumRange(0,2);
    cout<<sum<<endl;
    system("pause");
    return 0;
}