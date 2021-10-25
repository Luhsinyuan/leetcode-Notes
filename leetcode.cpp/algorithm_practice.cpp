#include"iostream"
#include"vector"

using namespace std;

int num[3];
bool is_visited[3]={false,false,false};
void backtrack(int bit_num,int total_num)
{
    if(bit_num>=total_num)
    {
        for(int i=0;i<3;i++)
        {
            cout<<num[i];
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<total_num;i++)
    {
        if(is_visited[i]==false)
        {
            num[bit_num]=i;
            is_visited[i]=true;
            backtrack(bit_num+1,total_num);
            is_visited[i]=false;
        }
        
    }
}
int main()
{
    for(int i=0;i<3;i++)
    {
        num[i]=i;
    }
    backtrack(0,3);
    system("pause");
    return 0;
}