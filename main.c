#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"

unsigned int stunum;

int main()
{
	//����ͷ�ڵ�
	Node* head = (Node*)malloc(sizeof(Node));
	//Node* head = (Node*)malloc(sizeof(Node*));
	head->next = NULL;
	init(head);//��ʼ������

	int flag = 1;
	while (flag)
	{
		//չʾ�˵�
		menu();

		//ѡ�����
		int choice;
		scanf("%d", &choice);
		getchar();

		//��Ӧ����ʵ��
		switch (choice)
		{
		case 1://�鿴
			print_all(head);
			break;
		case 2://����
			find(head);
			break;
		case 3://���
			add(head);
			break;
		case 4://ɾ��
			delete(head);
			break;
		case 5://�޸�
			modify(head);
			break;
		case 6://ͳ��
			stat(head);
			break;
		case 7://����
			system("cls");
			break;
		case 8://�˳�
			flag = 0;
			printf("���˳�ϵͳ��\n");
			break;
		default:
			if (choice != 7)
				printf("��Чѡ����������롣\n");
			break;
		}
	}
	return 0;
}


//չʾ�˵�
void menu()
{
	printf("**********************\t\n");
	printf("***ѧ����Ϣ����ϵͳ***\t\n");
	printf("**********************\t\n");
	printf("****1.��ʾѧ����Ϣ****\t\n");
	printf("****2.����ѧ����Ϣ****\t\n");
	printf("****3.���ѧ����Ϣ****\t\n");
	printf("****4.ɾ��ѧ����Ϣ****\t\n");
	printf("****5.�޸�ѧ����Ϣ****\t\n");
	printf("****6.ͳ��ѧ���ɼ�****\t\n");
	printf("****7.��յ�ǰҳ��****\t\n");
	printf("****8.�˳�����ϵͳ****\t\n");
	printf("**********************\t\n");
	printf("�����Ӧ������ѡ�����\t\n");
	printf("**********************\t\n");
}

//1.�鿴
void print_all(Node* head)
{
	stunum = count_(head);
	printf("\n");
	if (stunum == 0)
	{
		printf("��ǰϵͳ����ѧ����Ϣ��\n\n");
	}
	else
	{
		printf("��ǰ����%d��ѧ����\n", stunum);
		Node* move = head->next;//��ʼ��moveΪ�����׽ڵ�
		printf("�Ա�\t����\t\tѧ��\t\t����\t����\t��Ӣ\n");
		while (move != NULL)
		{
			printf("%s\t%s\t\t%lu\t", move->student.gender,
				move->student.name, move->student.num);//��ӡ�ձ�����,ѧ��
			for (int i = 0; i < 3; i++)
			{
				printf("%d\t", move->student.score[i]);
			}//��ӡ���ųɼ�
			printf("\n");
			//�ƶ�����һ�ڵ�
			move = move->next;
		}
	}
	printf("\n");
	system("pause");
	printf("\n");
}
void print_one(Node* goal)
{
	printf("�Ա�\t����\t\tѧ��\t\t����\t����\t��Ӣ\n");
	printf("%s\t%s\t\t%lu\t", goal->student.gender,
		goal->student.name, goal->student.num);//��ӡ�ձ�����,ѧ��
	for (int i = 0; i < 3; i++)
	{
		printf("%d\t", goal->student.score[i]);
	}//��ӡ���ųɼ�
	printf("\n");
}
void print_sorted(Node* goal,int a) 
{
	printf("%s\t\t%lu\t", 
	goal->student.name, goal->student.num);//��ӡ����,ѧ��
	printf("%d\t\n", goal->student.score[a-1]);//��ӡ����
}

//2.����
void find(Node* head)
{
out:
	printf("\n");
	printf("��ǰ����������ѧ����Ϣ��\n");
	printf("��ѡ��������ʽ��\n");
	printf("1.��ѧ�Ų���\n");
	printf("2.����������\n");
	printf("���߰�����������˳�������\n");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
	{//��ѧ�Ų���
		find_num(head);
		goto out;
		break;
	}
	case 2://����������
		find_name(head);
		goto out;
		break;
	default:
		printf("���˳�������");
		system("pause");
		printf("\n");
		break;
	}
}
//��ѧ�Ų���
Node* find_num(Node* head)
{
	Node* move = (Node*)malloc(sizeof(Node*));
	move = head->next;
	printf("������Ŀ��ѧ����ѧ�ţ�");
	unsigned long goal_num;
	scanf("%lu", &goal_num);
	printf("\n");
	while (move != NULL)
	{
		if (goal_num == move->student.num)
		{
			printf("Ϊ���ҵ����½����\n");
			print_one(move);
			system("pause");
			printf("\n");
			return move;
		}
		move = move->next;
	}
	printf("���޴��ˡ�\n");
	system("pause");
	return NULL;
}
//����������
Node* find_name(Node* head)
{
	Node* move = (Node*)malloc(sizeof(Node*));
	move = head->next;
	printf("������Ŀ��ѧ����������");
	char goal_name[20];
	scanf("%s", &goal_name);
	while (move != NULL)
	{
		if (strcmp(goal_name, move->student.name) == 0)
		{
			printf("Ϊ���ҵ����½����\n");
			print_one(move);
			system("pause");
			return move;
		}
		move = move->next;
	}
	printf("���޴��ˡ�\n");
	system("pause");
	return NULL;
}

//3.���
void add(Node* head)
{
	printf("��ǰ���������ѧ����Ϣ��\n");
	printf("������Ҫ��ӵ�ѧ��������");
	int h;
	scanf("%d", &h);
	getchar();
	for (int j = 1; j <= h; j++)
	{
		printf("\n");
		printf("��ǰ������ӵ�%dλѧ������Ϣ\n", j);
		//�����µ�ѧ����Ϣ�ڵ�
		Node* new = (Node*)malloc(sizeof(Node));
		new->next = NULL;
		printf("������ѧ�����Ա�");
		char *str1 = "��";
		char *str2 = "Ů";
	//gender_in:
		scanf("%s", new->student.gender);
		//// ||  !(strcmp(new->student.gender, str2))
		//if ( !(strcmp(new->student.gender, str1)))
		//{
		//	printf("������Ч������������:");
		//	goto gender_in;
		//}
		printf("������ѧ����������");
		scanf("%s", new->student.name);
		printf("������ѧ����ѧ�ţ�");
	out:
		scanf("%d", &new->student.num);
		if (!check_num(new->student.num,head))
		{
			printf("ѧ���Ѵ��ڣ�����������:\n");
			goto out;
		}
		printf("������ѧ�������ųɼ�������Ϊ�����������Ӣ,�м��Կո�ָ���\n");
		for (int i = 0; i < 3; i++)
			scanf("%d", &new->student.score[i]);

		Node* move = head;//���������������ݵ��ƶ��ڵ�
		while (move->next != NULL)
		{
			move = move->next;
		}

		//���½ڵ����ӵ�move�ĺ���
		move->next = new;
		save(head);
		printf("��ӳɹ���\n");
	}
	system("pause");
}

//4.ɾ��
void delete(Node* head)
{
	printf("��ǰ������ɾ��ѧ����Ϣ��\n������Ŀ��ѧ����ѧ�ţ�");
	unsigned long goal_num;
	scanf("%lu", &goal_num);
	printf("\n");
	Node* move = head;
	Node* goal = move->next;
	while (goal != NULL)
	{
		if (goal->student.num==goal_num)
		{
			printf("Ϊ���ҵ����½����\n");
			print_one(goal);
			system("pause");
			printf("\n");
			printf("�Ƿ�ȷ��ɾ����ѧ������Ϣ��\n1.ȷ��\n2.ȡ��\n");
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
				printf("\nɾ���ɹ���");
				system("pause");
			}
			else
			{
				printf("\n������ȡ����");
				system("pause");
			}
			return;
		}
		move = goal;
		goal = goal->next;
	}
	printf("���޴��ˡ�\n");
	system("pause");
}

//5.�޸�
void modify(Node* head)
{
	printf("\n");
	printf("��ǰ�������޸�ѧ����Ϣ��\n");
	Node* goal = find_num(head);
	if (goal != NULL)
	{
		modify_which(goal);
		save(head);
	}
	
}
//�޸ľ������Ŀ
void modify_which(Node* goal)
{
	int flag = 1;
	while (flag)
	{
		printf("������������ѡ��Ҫ�޸ĵ���Ŀ��\n");
		printf("1.�Ա�\n2.����\n3.ѧ��\n4.�����ɼ�\n5.����ɼ�\n6.��Ӣ�ɼ�\n0.�˳�\n");
		int a;
		scanf("%d", &a);
		printf("\n");
		switch (a)
		{
			case 1:
			{
				printf("�������޸ĺ���Ա�");
				scanf("%s", goal->student.gender);
				printf("�޸���ɣ�");
				system("pause");
				break;
			}
			case 2:
			{
				printf("�������޸ĺ��������");
				scanf("%s", goal->student.name);
				printf("�޸���ɣ�");
				system("pause");
				break;
			}
			case 3:
			{
				printf("�������޸ĺ��ѧ�ţ�");
				scanf("%lu", &goal->student.num);
				printf("�޸���ɣ�");
				system("pause");
				break;
			}
			case 4:
			{
				printf("�������޸ĺ�ĸ����ɼ���");
				scanf("%d", &goal->student.score[0]);
				printf("�޸���ɣ�");
				system("pause");
				break;
			}
			case 5:
			{
				printf("�������޸ĺ�Ĵ���ɼ���");
				scanf("%d", &goal->student.score[1]);
				printf("�޸���ɣ�");
				system("pause");
				break;
			}
			case 6:
			{
				printf("�������޸ĺ�Ĵ�Ӣ�ɼ���");
				scanf("%d", &goal->student.score[2]);
				printf("�޸���ɣ�");
				system("pause");
				break;
			}
			case 0:
				flag = 0;
				printf("���˳��޸ġ�");
				system("pause");
				break;
		}
		printf("\n");
	}
}


//6.ͳ��
void stat(Node* head)
{
	stunum = count_(head);
	int a;
	printf("��ѡ��Ҫͳ�ƵĿ�Ŀ��\n1.����\n2.����\n3.��Ӣ\n�����������������˳�ͳ�ơ�\n");
	scanf("%d", &a);
	printf("\n");
	if (a < 4)
	{
		if (a == 1)
		{
			printf("��ǰͳ�ƵĿ�ĿΪ������\n\n");
		}
		else if (a == 2)
		{
			printf("��ǰͳ�ƵĿ�ĿΪ���\n\n");
		}
		else
		{
			printf("��ǰͳ�ƵĿ�ĿΪ��Ӣ��\n\n");
		}
		float avg = average_(head, a);
		int max = max_stat(head,a);
		int min = min_stat(head, a);
		printf("��߷�:%d\t\t",max);printf("��ͷ�:%d\n",min);
		printf("ƽ���֣�%.2f\t\t",avg);printf("���%d\n",max-min);
		printf("����:%.2f\n",var_stat(head,a,avg));
		printf("\n");

		int good = good_stat(head, a);
		int bad = bad_stat(head, a);
		printf("��������%d\n",stunum);
		printf("����������%d\t\t",good);printf("�ҿ�������%d\n",bad);
		printf("�����ʣ�%.2f%%\t\t", (good*1.0) / (stunum * 1.0)*100);
		printf("�ҿ��ʣ�%.2f%%\n", (bad * 1.0) /(stunum*1.0)*100);
		printf("\n");
		
		Node** sorted = sort_score(head, a);
		int i; 
		printf("�������£�\n");
		printf("����\t\tѧ��\t\t");
		switch (a)
		{
			case 1:
				printf("����\n");
				break;
			case 2:
				printf("����\n");
				break;
			case 3:
				printf("��Ӣ\n");
				break;
		}

		for (i = 0; i < stunum; i++)
		{
			print_sorted(sorted[i],a);
		}//�������������

		//for (i = 0; i < stunum; i++)
		//{
		//	free(sorted[i]);
		//}//�ͷ�������ڴ棨����
	}
	else
	{
		printf("���˳�ͳ�ơ�");
	}
	printf("\n");
	system("pause");
	printf("\n");
}

//�����ļ�
void save(Node* head)
{
	FILE* file = fopen("./stu.info", "w");
	Node* move = head->next;
	while (move != NULL)
	{
		if (fwrite(&move->student, sizeof(stu), 1, file) != 1)
		{
			printf("����ʧ�ܡ�\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

//��������ʱ���ȶ�ȡ֮ǰ���������
void init(Node* head)
{
	FILE* file = fopen("stu.info", "r");
	if (!file)
	{
		printf("��ǰ��ѧ����Ϣ�ļ���������ȡ��\n");
		return;
	}
	printf("��ȡѧ����Ϣ�ļ��ɹ���\n");
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	Node* move = head;
	while (fread(&temp->student, sizeof(stu), 1, file) == 1)
	{//���ļ��е�ѧ����Ϣ��ȡ���ڴ���
		move->next = temp;
		move = temp;
		temp = (Node*)malloc(sizeof(Node));
		temp->next = NULL;
	};
	free(temp);
	fclose(file);
}

//ͳ���ж���ѧ��
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

//���ѧ��Ψһ��
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

//ͳ��ƽ����
float average_(Node* head, int a)
{
	/*1.����2.����3.��Ӣ*/
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

//ͳ����߷�
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

//ͳ����ͷ�
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

//ͳ�Ʒ���
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

//����
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
	}//ð������
	return sorted;
}

//ͳ����������
int good_stat(Node* head, int a)
{
	int sum = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.score[a - 1] > 89)//>=90��Ϊ����
		{
			sum++;
		}
		move = move->next;
	}
	return sum;
}

//ͳ�ƹҿ�����
int bad_stat(Node* head, int a)
{
	int sum = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.score[a - 1] <60)//<60�ֹҿ�
		{
			sum++;
		}
		move = move->next;
	}
	return sum;
}
