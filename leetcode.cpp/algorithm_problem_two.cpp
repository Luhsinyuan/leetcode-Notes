#include"iostream" 
#include"vector"
#include"string"

using namespace std;

int main(){
	string c1,c2;
	int origin[1000];											//存储初始密码和目标密码的数字版
	int target[1000];
	cin>>c1>>c2;
    int len=c1.size();

	//将所有初始密码和目标密码的字符转变为数字，同时往后移一位，方便处理
    for(int i=0;i<len;i++)
    {
        origin[i+1]=c1[i]-'0';									//初始密码									
        target[i+1]=c2[i]-'0';									//目标密码
    }
    
	
	//初始化
	int dp[1000][10][10];										//用于存储所有所有状态
	for (int i = 0; i <= len; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				dp[i][j][k] = INT32_MAX;									//初始化，由于是取最小值，因此初始化为最大值
			}															
		}
	}							
		
        //对初始的前两位密码进行初始化
	dp[0][origin[1]][origin[2]] = 0;
		
		
		
		for (int i = 0; i < len; i++){										//三层循环枚举i,j,k
			for (int j = 0; j < 10; j++){
				for (int k = 0; k < 10; k++){
					if (dp[i][j][k] < INT32_MAX){                           //对于初始值不是最大值的值进行操作

						int up = (target[i + 1] - j + 10) % 10;             //对于第i+i位是j而言，需要up次向上的拨动才能复位

						int down = (j - target[i + 1] + 10) % 10;           //同理，需要down次向下的波动可以复位

						for (int l = 0; l <= up; l++){                      //枚举每一次向上拨动

							for (int m = 0; m <= l; m++){                   //对于第i+1位，向上拨动了l次，那么第i+2位一定拨动了小于等于l次，枚举这m次拨动 
								//动态转移方程，k是i+1位的数字，k+l%10是第i+2位拨动后的数字，(origin[i+3]+m)%10是第i+3位拨动后的数字
                                //dp数组的定义是：第i+1位前都归位后，第i+2位是k+l%10,第i+3位是origin[i+3]+m%10的最小转动次数 
								//这个状态转移方程是指，i+1位之前都复位，第i+2位是(k + l) % 10，第i+3位是origin[i + 3] + m) % 10的最小操作次数是本身的操作次数和前i位复位完毕，i+1位是j，i+3位是k加上
								//向上转动的次数
								dp[i + 1][(k + l) % 10][(origin[i + 3] + m) % 10] = min(dp[i + 1][(k + l) % 10][(origin[i + 3] + m) % 10], dp[i][j][k] + up);
							}
						}
						for (int l = 0; l <= down; l++){                    //同理，枚举每一次向下拨动
							for (int m = 0; m <= l; m++){
								dp[i + 1][(k - l + 10) % 10][(origin[i + 3] - m + 10) % 10] = min(dp[i + 1][(k - l + 10) % 10][(origin[i + 3] - m + 10) % 10], dp[i][j][k] + down);
							}
						}
					}
				}
			}
		}


		int result = INT32_MAX;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				result = min(result, dp[len][i][j]);                             //找到所有使前slen位密码全部复位的拨动步数最小的一个
		cout<<result<<endl;
		system("pause");
		return 0;
	}

