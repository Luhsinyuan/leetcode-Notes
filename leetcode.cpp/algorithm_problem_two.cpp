#include"iostream" 
#include"vector"
#include"string"

using namespace std;

int main(){
	string c1,c2;
	int origin[1000];											//�洢��ʼ�����Ŀ����������ְ�
	int target[1000];
	cin>>c1>>c2;
    int len=c1.size();

	//�����г�ʼ�����Ŀ��������ַ�ת��Ϊ���֣�ͬʱ������һλ�����㴦��
    for(int i=0;i<len;i++)
    {
        origin[i+1]=c1[i]-'0';									//��ʼ����									
        target[i+1]=c2[i]-'0';									//Ŀ������
    }
    
	
	//��ʼ��
	int dp[1000][10][10];										//���ڴ洢��������״̬
	for (int i = 0; i <= len; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				dp[i][j][k] = INT32_MAX;									//��ʼ����������ȡ��Сֵ����˳�ʼ��Ϊ���ֵ
			}															
		}
	}							
		
        //�Գ�ʼ��ǰ��λ������г�ʼ��
	dp[0][origin[1]][origin[2]] = 0;
		
		
		
		for (int i = 0; i < len; i++){										//����ѭ��ö��i,j,k
			for (int j = 0; j < 10; j++){
				for (int k = 0; k < 10; k++){
					if (dp[i][j][k] < INT32_MAX){                           //���ڳ�ʼֵ�������ֵ��ֵ���в���

						int up = (target[i + 1] - j + 10) % 10;             //���ڵ�i+iλ��j���ԣ���Ҫup�����ϵĲ������ܸ�λ

						int down = (j - target[i + 1] + 10) % 10;           //ͬ����Ҫdown�����µĲ������Ը�λ

						for (int l = 0; l <= up; l++){                      //ö��ÿһ�����ϲ���

							for (int m = 0; m <= l; m++){                   //���ڵ�i+1λ�����ϲ�����l�Σ���ô��i+2λһ��������С�ڵ���l�Σ�ö����m�β��� 
								//��̬ת�Ʒ��̣�k��i+1λ�����֣�k+l%10�ǵ�i+2λ����������֣�(origin[i+3]+m)%10�ǵ�i+3λ�����������
                                //dp����Ķ����ǣ���i+1λǰ����λ�󣬵�i+2λ��k+l%10,��i+3λ��origin[i+3]+m%10����Сת������ 
								//���״̬ת�Ʒ�����ָ��i+1λ֮ǰ����λ����i+2λ��(k + l) % 10����i+3λ��origin[i + 3] + m) % 10����С���������Ǳ���Ĳ���������ǰiλ��λ��ϣ�i+1λ��j��i+3λ��k����
								//����ת���Ĵ���
								dp[i + 1][(k + l) % 10][(origin[i + 3] + m) % 10] = min(dp[i + 1][(k + l) % 10][(origin[i + 3] + m) % 10], dp[i][j][k] + up);
							}
						}
						for (int l = 0; l <= down; l++){                    //ͬ��ö��ÿһ�����²���
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
				result = min(result, dp[len][i][j]);                             //�ҵ�����ʹǰslenλ����ȫ����λ�Ĳ���������С��һ��
		cout<<result<<endl;
		system("pause");
		return 0;
	}

