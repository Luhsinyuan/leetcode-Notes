#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(),A.end());
        vector<int> B;
        int overflow=0;
        int bitNum=0;
        int n=1;
        while(K/n>0)
        {
            bitNum++;
            B.push_back(K%10);
            K=K/10;
        }
        int maxsize=min(A.size(),B.size());
        vector<int> C(max(A.size(),B.size()));
        for(int i=0;i<maxsize;i++)
        {
           int temp=overflow+A[i]+B[i]>=10?1:0;
           C[i]=(overflow+A[i]+B[i])%10;
           overflow=temp;
        }
        if(A.size()>B.size())
        {
                for(int i=maxsize;i<A.size();i++)
                {
                    int temp=overflow+A[i]>=10?1:0;
                    C[i]=(overflow+A[i])%10;
                    overflow=temp;  
                }
        }
        else if(A.size()<B.size())
        {
                for(int i=maxsize;i<B.size();i++)
                {
                    int temp=overflow+B[i]>=10?1:0;
                    C[i]=(overflow+B[i])%10;
                    overflow=temp;   
                }
        }
        if(overflow)
        {
            C.push_back(1);
        }
        reverse(C.begin(),C.end());
        return C;
    }
};
int main()
{
    vector<int> A={9,9,9,9,9,9,9,9,9,9,9,9};
    int K=1;
    Solution s;
    vector<int> nums(s.addToArrayForm(A,K));
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<endl;
    }
    system("pause");
    return 0;
}