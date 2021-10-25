#include"iostream"
#include"vector"

using namespace std;

int numlist[3]={1,2,3};

void print_out()
{
    for(int i=0;i<3;i++)
    {
        cout<<numlist[i]<<",";
    }
    cout<<endl;
}
void swap(int i,int j)
{
    int temp=numlist[i];
    numlist[i]=numlist[j];
    numlist[j]=temp;
}
void Backtrack(int t,int total_num)
{
    if(t>=total_num)
    {
        print_out();
    }
    else
    {
        for(int i=t;i<total_num;i++)
        {
            swap(i,t);
            Backtrack(t+1,total_num);
            swap(i,t);
        }
    }
}
int main()
{
    Backtrack(0,3);
    system("pause");
    return 0;
}



