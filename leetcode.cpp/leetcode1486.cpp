#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int count=1;
        int current=start;
        while(count<n)
        {
            int temp=start+2*count;
            current=temp^current;
            count++;
        }
        return current;
    }
};
int main()
{
    int n=10;
    int start=5;
    Solution s;
    int result=s.xorOperation(n,start);
    cout<<result<<endl;
    system("pause");
    return 0;
}