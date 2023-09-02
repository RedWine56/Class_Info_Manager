#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"

unsigned int stunum;

int main()
{
	//创建头节点
	Node* head = (Node*)malloc(sizeof(Node));
	//Node* head = (Node*)malloc(sizeof(Node*));
	head->next = NULL;
	init(head);//初始化程序

	int flag = 1;
	while (flag)
	{
		//展示菜单
		menu();

		//选择操作
		int choice;
		scanf("%d", &choice);
		getchar();

		//对应功能实现
		switch (choice)
		{
		case 1://查看
			print_all(head);
			break;
		case 2://搜索
			find(head);
			break;
		case 3://添加
			add(head);
			break;
		case 4://删除
			delete(head);
			break;
		case 5://修改
			modify(head);
			break;
		case 6://统计
			stat(head);
			break;
		case 7://清屏
			system("cls");
			break;
		case 8://退出
			flag = 0;
			printf("已退出系统。\n");
			break;
		default:
			if (choice != 7)
				printf("无效选项，请重新输入。\n");
			break;
		}
	}
	return 0;
}


//展示菜单
void menu()
{
	printf("**********************\t\n");
	printf("***学生信息管理系统***\t\n");
	printf("**********************\t\n");
	printf("****1.显示学生信息****\t\n");
	printf("****2.搜索学生信息****\t\n");
	printf("****3.添加学生信息****\t\n");
	printf("****4.删除学生信息****\t\n");
	printf("****5.修改学生信息****\t\n");
	printf("****6.统计学生成绩****\t\n");
	printf("****7.清空当前页面****\t\n");
	printf("****8.退出管理系统****\t\n");
	printf("**********************\t\n");
	printf("输入对应数字以选择操作\t\n");
	printf("**********************\t\n");
}

//1.查看
void print_all(Node* head)
{
	stunum = count_(head);
	printf("\n");
	if (stunum == 0)
	{
		printf("当前系统中无学生信息！\n\n");
	}
	else
	{
		printf("当前共有%d名学生。\n", stunum);
		Node* move = head->next;//初始化move为数据首节点
		printf("性别\t姓名\t\t学号\t\t高数\t大物\t大英\n");
		while (move != NULL)
		{
			printf("%s\t%s\t\t%lu\t", move->student.gender,
				move->student.name, move->student.num);//打印姓别，姓名,学号
			for (int i = 0; i < 3; i++)
			{
				printf("%d\t", move->student.score[i]);
			}//打印三门成绩
			printf("\n");
			//移动到下一节点
			move = move->next;
		}
	}
	printf("\n");
	system("pause");
	printf("\n");
}
void print_one(Node* goal)
{
	printf("性别\t姓名\t\t学号\t\t高数\t大物\t大英\n");
	printf("%s\t%s\t\t%lu\t", goal->student.gender,
		goal->student.name, goal->student.num);//打印姓别，姓名,学号
	for (int i = 0; i < 3; i++)
	{
		printf("%d\t", goal->student.score[i]);
	}//打印三门成绩
	printf("\n");
}
void print_sorted(Node* goal,int a) 
{
	printf("%s\t\t%lu\t", 
	goal->student.name, goal->student.num);//打印姓名,学号
	printf("%d\t\n", goal->student.score[a-1]);//打印分数
}

//2.搜索
void find(Node* head)
{
out:
	printf("\n");
	printf("当前操作：搜索学生信息。\n");
	printf("请选择搜索方式：\n");
	printf("1.按学号查找\n");
	printf("2.按姓名查找\n");
	printf("或者按其他任意键退出搜索。\n");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
	{//按学号查找
		find_num(head);
		goto out;
		break;
	}
	case 2://按姓名查找
		find_name(head);
		goto out;
		break;
	default:
		printf("已退出搜索。");
		system("pause");
		printf("\n");
		break;
	}
}
//按学号查找
Node* find_num(Node* head)
{
	Node* move = (Node*)malloc(sizeof(Node*));
	move = head->next;
	printf("请输入目标学生的学号：");
	unsigned long goal_num;
	scanf("%lu", &goal_num);
	printf("\n");
	while (move != NULL)
	{
		if (goal_num == move->student.num)
		{
			printf("为您找到以下结果：\n");
			print_one(move);
			system("pause");
			printf("\n");
			return move;
		}
		move = move->next;
	}
	printf("查无此人。\n");
	system("pause");
	return NULL;
}
//按姓名查找
Node* find_name(Node* head)
{
	Node* move = (Node*)malloc(sizeof(Node*));
	move = head->next;
	printf("请输入目标学生的姓名：");
	char goal_name[20];
	scanf("%s", &goal_name);
	while (move != NULL)
	{
		if (strcmp(goal_name, move->student.name) == 0)
		{
			printf("为您找到以下结果：\n");
			print_one(move);
			system("pause");
			return move;
		}
		move = move->next;
	}
	printf("查无此人。\n");
	system("pause");
	return NULL;
}

//3.添加
void add(Node* head)
{
	printf("当前操作：添加学生信息。\n");
	printf("请输入要添加的学生人数：");
	int h;
	scanf("%d", &h);
	getchar();
	for (int j = 1; j <= h; j++)
	{
		printf("\n");
		printf("当前正在添加第%d位学生的信息\n", j);
		//创建新的学生信息节点
		Node* new = (Node*)malloc(sizeof(Node));
		new->next = NULL;
		printf("请输入学生的性别：");
		char *str1 = "男";
		char *str2 = "女";
	//gender_in:
		scanf("%s", new->student.gender);
		//// ||  !(strcmp(new->student.gender, str2))
		//if ( !(strcmp(new->student.gender, str1)))
		//{
		//	printf("输入无效，请重新输入:");
		//	goto gender_in;
		//}
		printf("请输入学生的姓名：");
		scanf("%s", new->student.name);
		printf("请输入学生的学号：");
	out:
		scanf("%d", &new->student.num);
		if (!check_num(new->student.num,head))
		{
			printf("学号已存在，请重新输入:\n");
			goto out;
		}
		printf("请输入学生的三门成绩，依次为高数、大物、大英,中间以空格分隔：\n");
		for (int i = 0; i < 3; i++)
			scanf("%d", &new->student.score[i]);

		Node* move = head;//创建用于链接数据的移动节点
		while (move->next != NULL)
		{
			move = move->next;
		}

		//将新节点链接到move的后面
		move->next = new;
		save(head);
		printf("添加成功！\n");
	}
	system("pause");
}

//4.删除
void delete(Node* head)
{
	printf("当前操作：删除学生信息。\n请输入目标学生的学号：");
	unsigned long goal_num;
	scanf("%lu", &goal_num);
	printf("\n");
	Node* move = head;
	Node* goal = move->next;
	while (goal != NULL)
	{
		if (goal->student.num==goal_num)
		{
			printf("为你找到以下结果：\n");
			print_one(goal);
			system("pause");
			printf("\n");
			printf("是否确认删除该学生的信息？\n1.确认\n2.取消\n");
			int a;
			scanf("%d", &a);
			if (a == 1)
			{
				Node* temp = goal;
				goal = goal->next;
				move->next = NULL;
				free(temp);
				temp = NULL;
				move->next = goal;
				save(head);
				printf("\n删除成功！");
				system("pause");
			}
			else
			{
				printf("\n操作已取消。");
				system("pause");
			}
			return;
		}
		move = goal;
		goal = goal->next;
	}
	printf("查无此人。\n");
	system("pause");
}

//5.修改
void modify(Node* head)
{
	printf("\n");
	printf("当前操作：修改学生信息。\n");
	Node* goal = find_num(head);
	if (goal != NULL)
	{
		modify_which(goal);
		save(head);
	}
	
}
//修改具体的项目
void modify_which(Node* goal)
{
	int flag = 1;
	while (flag)
	{
		printf("请输入数字来选择要修改的项目：\n");
		printf("1.性别\n2.姓名\n3.学号\n4.高数成绩\n5.大物成绩\n6.大英成绩\n0.退出\n");
		int a;
		scanf("%d", &a);
		printf("\n");
		switch (a)
		{
			case 1:
			{
				printf("请输入修改后的性别：");
				scanf("%s", goal->student.gender);
				printf("修改完成！");
				system("pause");
				break;
			}
			case 2:
			{
				printf("请输入修改后的姓名：");
				scanf("%s", goal->student.name);
				printf("修改完成！");
				system("pause");
				break;
			}
			case 3:
			{
				printf("请输入修改后的学号：");
				scanf("%lu", &goal->student.num);
				printf("修改完成！");
				system("pause");
				break;
			}
			case 4:
			{
				printf("请输入修改后的高数成绩：");
				scanf("%d", &goal->student.score[0]);
				printf("修改完成！");
				system("pause");
				break;
			}
			case 5:
			{
				printf("请输入修改后的大物成绩：");
				scanf("%d", &goal->student.score[1]);
				printf("修改完成！");
				system("pause");
				break;
			}
			case 6:
			{
				printf("请输入修改后的大英成绩：");
				scanf("%d", &goal->student.score[2]);
				printf("修改完成！");
				system("pause");
				break;
			}
			case 0:
				flag = 0;
				printf("已退出修改。");
				system("pause");
				break;
		}
		printf("\n");
	}
}


//6.统计
void stat(Node* head)
{
	stunum = count_(head);
	int a;
	printf("请选择要统计的科目：\n1.高数\n2.大物\n3.大英\n或输入其他数字以退出统计。\n");
	scanf("%d", &a);
	printf("\n");
	if (a < 4)
	{
		if (a == 1)
		{
			printf("当前统计的科目为高数。\n\n");
		}
		else if (a == 2)
		{
			printf("当前统计的科目为大物。\n\n");
		}
		else
		{
			printf("当前统计的科目为大英。\n\n");
		}
		float avg = average_(head, a);
		int max = max_stat(head,a);
		int min = min_stat(head, a);
		printf("最高分:%d\t\t",max);printf("最低分:%d\n",min);
		printf("平均分：%.2f\t\t",avg);printf("极差：%d\n",max-min);
		printf("方差:%.2f\n",var_stat(head,a,avg));
		printf("\n");

		int good = good_stat(head, a);
		int bad = bad_stat(head, a);
		printf("总人数：%d\n",stunum);
		printf("优秀人数：%d\t\t",good);printf("挂科人数：%d\n",bad);
		printf("优秀率：%.2f%%\t\t", (good*1.0) / (stunum * 1.0)*100);
		printf("挂科率：%.2f%%\n", (bad * 1.0) /(stunum*1.0)*100);
		printf("\n");
		
		Node** sorted = sort_score(head, a);
		int i; 
		printf("排名如下：\n");
		printf("姓名\t\t学号\t\t");
		switch (a)
		{
			case 1:
				printf("高数\n");
				break;
			case 2:
				printf("大物\n");
				break;
			case 3:
				printf("大英\n");
				break;
		}

		for (i = 0; i < stunum; i++)
		{
			print_sorted(sorted[i],a);
		}//按分数排序输出

		//for (i = 0; i < stunum; i++)
		//{
		//	free(sorted[i]);
		//}//释放申请的内存（？）
	}
	else
	{
		printf("已退出统计。");
	}
	printf("\n");
	system("pause");
	printf("\n");
}

//保存文件
void save(Node* head)
{
	FILE* file = fopen("./stu.info", "w");
	Node* move = head->next;
	while (move != NULL)
	{
		if (fwrite(&move->student, sizeof(stu), 1, file) != 1)
		{
			printf("保存失败。\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

//程序启动时，先读取之前保存的数据
void init(Node* head)
{
	FILE* file = fopen("stu.info", "r");
	if (!file)
	{
		printf("当前无学生信息文件，跳过读取。\n");
		return;
	}
	printf("读取学生信息文件成功！\n");
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	Node* move = head;
	while (fread(&temp->student, sizeof(stu), 1, file) == 1)
	{//将文件中的学生信息读取到内存中
		move->next = temp;
		move = temp;
		temp = (Node*)malloc(sizeof(Node));
		temp->next = NULL;
	};
	free(temp);
	fclose(file);
}

//统计有多少学生
int count_(Node* head)
{
	int count = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		count++;
		move = move->next;
	}
	return count;
}

//检查学号唯一性
int check_num(unsigned long goal_num,Node* head)
{
	Node* move = head;
	while (move != NULL)
	{
		if (move->student.num == goal_num)
		{
			return 0;
		}
		move = move->next;
	}
	return 1;
}

//统计平均分
float average_(Node* head, int a)
{
	/*1.高数2.大物3.大英*/
	float avg=0;
	float sum = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		sum += move->student.score[a - 1];
		move = move->next;
	}
	avg = sum / (stunum * 1.0);
	return avg;
}

//统计最高分
int max_stat(Node* head, int a)
{
	Node* move = head->next;
	int max = 0;
	while (move != NULL)
	{
		if (max < move->student.score[a - 1])
		{
			max = move->student.score[a - 1];
		}
		move = move->next;
	}
	return max;
}

//统计最低分
int min_stat(Node* head, int a)
{
	Node* move = head->next;
	int min = 999;
	while (move != NULL)
	{
		if (move->student.score[a - 1] < min)
		{
			min = move->student.score[a - 1];
		}
		move = move->next;
	}
	return min;
}

//统计方差
float var_stat(Node* head, int a,float avg)
{
	stunum = count_(head);
	float var = 0;
	float sum = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		sum += pow(move->student.score[a-1]-avg, 2);
		move = move->next;
	}
	var = sum / (stunum * 1.0);
	return var;
}

//排序
Node** sort_score(Node* head, int a)
{
	stunum = count_(head);
	Node** sorted=(Node**)malloc(sizeof(Node*)*stunum);
	Node* move = head->next;
	
	int i,j;
	for (i = 0; i < stunum; i++)
	{
		sorted[i] = move;
		move = move->next;
	}
	
	for (i = 0; i < stunum; i++)
	{
		for (j = 0; j < stunum - i - 1; j++)
		{
			if (sorted[j]->student.score[a-1] < sorted[j + 1]->student.score[a - 1])
			{
				Node* temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}//冒泡排序
	return sorted;
}

//统计优秀人数
int good_stat(Node* head, int a)
{
	int sum = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.score[a - 1] > 89)//>=90分为优秀
		{
			sum++;
		}
		move = move->next;
	}
	return sum;
}

//统计挂科人数
int bad_stat(Node* head, int a)
{
	int sum = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.score[a - 1] <60)//<60分挂科
		{
			sum++;
		}
		move = move->next;
	}
	return sum;
}
