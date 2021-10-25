#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int total_weight=0;
        int left=INT_FAST64_MIN;
        for(int i=0;i<weights.size();i++)
        {
            total_weight+=weights[i];
            if(weights[i]>left)
            {
                left=weights[i];
            }
        }
        int right=total_weight;
        while(left<right)
        {
            int mid=(left+right)/2;
            int day_need=1;
            int temp=0;
            for(int weight:weights)
            {
                if(temp<=mid&&temp+weight>mid)
                {
                    day_need++;
                    temp=weight;
                }
                else
                {
                    temp+=weight;
                }
            }
            if(day_need<=D)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
int main()
{
    vector<int> numlist={1,2,3,4,5,6,7,8,9,10};
    Solution s;
    int result=s.shipWithinDays(numlist,5);
    cout<<result<<endl;
    system("pause");
    return 0;
}