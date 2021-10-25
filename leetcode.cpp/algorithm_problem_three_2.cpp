#include"iostream"
#include"vector"

using namespace std;

int solve(int n)
{
    int dp[11];
    dp[0]=0;
    dp[1]=10;
    dp[2]=81;                           //初始化
    int sum=dp[0]+dp[1]+dp[2];          //初始sum值
    for(int i=3;i<=n;i++)               //根据动态转移方程计算dp[i]
    {
        dp[i]=dp[i-1]*(11-i);
        sum+=dp[i];
    }
    return sum;                 
}
int main()
{
    cout<<"请输入整数n(<0<=n<10):";
    int n=0;
    cin>>n;
    while(n<0||n>=10)
    {
        cout<<"n的大小不符合规则，请再次输入：";        
        cin>>n;
    }
    int result=solve(n);            
    cout<<result<<endl;
    system("pause");
    return 0;
}