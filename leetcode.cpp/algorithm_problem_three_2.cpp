#include"iostream"
#include"vector"

using namespace std;

int solve(int n)
{
    int dp[11];
    dp[0]=0;
    dp[1]=10;
    dp[2]=81;                           //��ʼ��
    int sum=dp[0]+dp[1]+dp[2];          //��ʼsumֵ
    for(int i=3;i<=n;i++)               //���ݶ�̬ת�Ʒ��̼���dp[i]
    {
        dp[i]=dp[i-1]*(11-i);
        sum+=dp[i];
    }
    return sum;                 
}
int main()
{
    cout<<"����������n(<0<=n<10):";
    int n=0;
    cin>>n;
    while(n<0||n>=10)
    {
        cout<<"n�Ĵ�С�����Ϲ������ٴ����룺";        
        cin>>n;
    }
    int result=solve(n);            
    cout<<result<<endl;
    system("pause");
    return 0;
}