
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//学生信息构成
typedef struct student
{
	int score[3];//成绩
	//int avg;//平均分
	unsigned long num;//学号
	char gender[3];//性别
	char name[20];//姓名
}stu;

//节点信息
typedef struct Node
{
	stu student;//stu类型的学生信息
	struct node* next;//指向下一个节点的指针
}Node;

void menu();
void add(Node* node); 
void print_all(Node* head);
void print_one(Node* goal);
void find(Node* head);
void save(Node* head);
void init(Node* head);
int count_(Node* head);
void modify(Node* head);
Node* find_name(Node* head);
Node* find_num(Node* head);
void modify_which(Node* goal);
void delete(Node* head);
int check_num(unsigned long goal_num, Node* head);
void stat(Node* head);
float average_(Node* head, int a);
int min_stat(Node* head, int a);
int max_stat(Node* head, int a);
float var_stat(Node* head, int a, float avg);
Node** sort_score(Node* head, int a);
void print_sorted(Node* goal,int a);
int good_stat(Node* head, int a);
int bad_stat(Node* head, int a);