#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;
class Block {
private:
	int start_place;			//起始地址
	int length;					//内存块长度
	int task_num;				//分配任务号，-1表示未被分配
    int total_order;            //该块的总体编号
public:
	Block(int start, int size, int num,int order=0)
	{
		start_place = start;
		length = size;
		task_num = num;
        total_order=order;
	}
    int get_total_order()
    {
        return total_order;
    }
    void set_total_order(int order)
    {
        total_order=order;
        return;
    }
	int get_start_place()
	{
		return start_place;
	}
	int get_length()
	{
		return length;
	}
	int get_task_num()
	{
		return task_num;
	}
	void set_start_place(int start)
	{
		start_place = start;
		return;
	}
	void set_length(int size)
	{
		length = size;
		return;
	}
	void set_task_num(int num)
	{
		task_num = num;
		return;
	}
};
class Task {
private:
	int task_num;
	bool is_proposer;
	int size;
public:
	Task(int num, bool proposer, int length)
	{
		task_num = num;
		is_proposer = proposer;
		size = length;
	}
	int grt_task_num()
	{
		return task_num;
	}
	bool get_is_proposer()
	{
		return is_proposer;
	}
	int get_size()
	{
		return size;
	}
	void set_task_num(int num)
	{
		task_num = num;
		return;
	}
	void set_is_proposer(bool proposer)
	{
		is_proposer = proposer;
		return;
	}
	void set_size(int length)
	{
		size = length;
		return;
	}
};

bool cmp1(Block* block1, Block* block2)
{
	return block1->get_start_place() < block2->get_start_place();
}
bool cmp2(Block* block1, Block* block2)
{
	return block1->get_length() < block2->get_length();
}
void Task_init(vector<Task*>& task_list)
{
	task_list.push_back(new Task(1, true, 130));
	task_list.push_back(new Task(2, true, 60));
	task_list.push_back(new Task(3, true, 100));
	task_list.push_back(new Task(2, false, 60));
	task_list.push_back(new Task(4, true, 200));
	task_list.push_back(new Task(3, false, 100));
	task_list.push_back(new Task(1, false, 130));
	task_list.push_back(new Task(5, true, 140));
	task_list.push_back(new Task(6, true, 60));
	task_list.push_back(new Task(7, true, 50));
	task_list.push_back(new Task(6, false, 60));
}
void proposer_BB(int choose,Task*& task,vector<Block*>& total_list)
{
    vector<Block*> free_block;
    for(int i=0;i<total_list.size();i++)
    {
        if(total_list[i]->get_task_num()==-1)
        {
            free_block.push_back(total_list[i]);
            total_list.erase(total_list.begin()+i);
        }
    }
    if(choose==1)
        sort(free_block.begin(),free_block.end(),cmp1);
    else
        sort(free_block.begin(),free_block.end(),cmp2);
    
	for (int i = 0; i < free_block.size(); i++)
	{
		Block* block = free_block[i];
		if (task->get_size() < block->get_length())
		{
			total_list.push_back(new Block(block->get_start_place(), task->get_size(), task->grt_task_num()));
			block->set_start_place(block->get_start_place()+task->get_size());
			block->set_length(block->get_length() - task->get_size());
			break;
		}
		else if (task->get_size() == block->get_length())
		{
			free_block.erase(free_block.begin() + i);
			block->set_task_num(task->grt_task_num());
			total_list.push_back(block);
			break;
		}
	}
    total_list.insert(total_list.end(),free_block.begin(),free_block.end());
    sort(total_list.begin(),total_list.end(),cmp1);
    cout<<"申请时：*************************"<<endl;
    cout<<"起始处"<<"\t"<<"长度"<<"\t"<<"任务号"<<"\t"<<"总排序"<<endl;
    for(int i=0;i<total_list.size();i++)
    {
        total_list[i]->set_total_order(i+1);
        cout<<total_list[i]->get_start_place()<<"\t"<<total_list[i]->get_length()<<"\t"<<total_list[i]->get_task_num()<<"\t"<<total_list[i]->get_total_order()<<endl;
    }
}
void free(int choose,Task* task,vector<Block*>& total_list)
{
    sort(total_list.begin(),total_list.end(),cmp1);
    int start_address=0;
    int size=0;
    cout<<"释放前：***********"<<endl;
    cout<<"起始处"<<"\t"<<"长度"<<"\t"<<"任务号"<<"\t"<<"总排序"<<endl;
    for(int i=0;i<total_list.size();i++)
    {
        total_list[i]->set_total_order(i+1);
        cout<<total_list[i]->get_start_place()<<"\t"<<total_list[i]->get_length()<<"\t"<<total_list[i]->get_task_num()<<"\t"<<total_list[i]->get_total_order()<<endl;
    }
    int order=0;
	for (int i = 0; i < total_list.size(); i++)
	{
		Block* block = total_list[i];
		if (block->get_task_num() == task->grt_task_num())
		{
            start_address=block->get_start_place();
            size=block->get_length();
            order=block->get_total_order();
			break;
		}
	}
    if(order==total_list.size())                                              //如果释放最后一块
    {
        if(total_list[total_list.size()-2]->get_task_num()==-1)                     //倒数第二块是空闲
        {
            total_list[total_list.size()-2]->set_length(total_list[total_list.size()-1]->get_length()+size);
            total_list.erase(total_list.begin()+order);
        }
    }
    else if(order==1)                                   //如果释放第一块
    {
        if(total_list[1]->get_task_num()==-1)                 //第二块是空闲
        {
            total_list[1]->set_start_place(start_address);
            total_list[1]->set_length(total_list[1]->get_length()+size);
            total_list.erase(total_list.begin());
            /*cout<<total_list[0]<<endl;
            cout<<total_list[1]<<endl;
            cout<<total_list[2]<<endl;
            cout<<"TEST:////////////////////////"<<endl;
            vector<Block*>::iterator it=total_list.begin();
            while(it!=total_list.end())
            {
                cout<<*it<<endl;
                it++;
            }
            for(int i=0;i<total_list.size();i++)
            {
                total_list[i]->set_total_order(i+1);
                cout<<total_list[i]->get_start_place()<<"\t"<<total_list[i]->get_length()<<"\t"<<total_list[i]->get_task_num()<<"\t"<<total_list[i]->get_total_order()<<endl;
            }*/
        }
    }
    else
    {
        if(total_list[order-2]->get_task_num()==-1&&total_list[order]->get_task_num()==-1)          //上下都是空闲
        {
            total_list[order-2]->set_length(total_list[order-2]->get_length()+total_list[order-1]->get_length()+total_list[order]->get_length());
            total_list.erase(total_list.begin()+order-1);                                       
            total_list.erase(total_list.begin()+order);   
                                            
        }
        else if(total_list[order-2]->get_task_num()==-1&&total_list[order]->get_task_num()!=-1) //上边是空闲
        {
            total_list[order-2]->set_length(total_list[order-2]->get_length()+total_list[order-1]->get_length());
            total_list.erase(total_list.begin()+order-1);
        }
        else if(total_list[order-2]->get_task_num()!=-1&&total_list[order]->get_task_num()==-1) //下边是空闲
        {
            total_list[order-1]->set_length(total_list[order-1]->get_length()+total_list[order]->get_length());
            total_list.erase(total_list.begin()+order);
        }
        else
        {
            total_list[order-1]->set_task_num(-1);
        }
    }
    cout<<"释放后：*************************"<<endl;
    cout<<"起始处"<<"\t"<<"长度"<<"\t"<<"任务号"<<"\t"<<"总排序"<<endl;
    int num=total_list.size();      
    for(int i=0;i<total_list.size();i++)
    {
        total_list[i]->set_total_order(i+1);
        cout<<total_list[i]->get_start_place()<<"\t"<<total_list[i]->get_length()<<"\t"<<total_list[i]->get_task_num()<<"\t"<<total_list[i]->get_total_order()<<endl;
    }
}
int main()
{
	vector<Task*> task_list;
	Task_init(task_list);
	vector<Block*> free_block;
	vector<Block*> occupied_block;
    vector<Block*> total_list;
    total_list.push_back(new Block(0, 640, -1,1));
	free_block.push_back(new Block(0, 640, -1,1));
	cout << "动态分区存储管理，请输入算法：" << endl;
	cout << "1.首次适应算法" << endl;
	cout << "2.最佳适应算法" << endl;
	int choose = 0;
	cin >> choose;
	cout << task_list.size() << endl;
	for (int i = 0; i < task_list.size(); i++)
	{
		Task* task = task_list[i];
		if (task->get_is_proposer() == true)
		{
			proposer_BB(choose, task,total_list);
		}
		else
		{
			free(choose,task,total_list);
		}
	}
    system("pause");
    return 0;
}