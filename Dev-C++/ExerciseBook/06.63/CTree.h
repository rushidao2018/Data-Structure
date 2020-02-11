/*=============================
 * ���ĺ�������(��˫��)�Ĵ洢��ʾ
 =============================*/

#ifndef CTREE_H
#define CTREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include "Status.h"     //**��01 ����**//
#include "LinkQueue.h"  //**��03 ջ�Ͷ���**//

/* ����������� */
#define MAX_TREE_SIZE 1024

/* ����������ĺ������� */
#define MAX_CHILD_COUNT 8

/* ����Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* ���ӽ�㶨�� */
typedef struct CTNode {
    int child;              // �ú��������е�����
    struct CTNode* next;    // ָ����һ������
} CTNode;

/* ָ���ӽ���ָ�� */
typedef CTNode* ChildPtr;

/* (˫��)���Ľ�㶨�� */
typedef struct {
    int parent;             // ˫��λ����
    TElemType data;         // ��ǰ���
    ChildPtr firstchild;    // ��������ͷָ��
} CTBox;

/*
 * (˫��)�����Ͷ���
 *
 *��ע��
 * 1.���н����nodes��"����"�洢��û�п�϶
 * 2.����r���ܳ�����nodes������λ��
 * 3.��������⣬����������ΰ�����˳�Ÿ�����������У���һ����̲�ͼʾ���ܻ�������
 * 4.nodes������ѭ��ʹ�õģ���һ��̲�δ�ᵽ��
 * 5.�������nodes�ռ����㹻��ģ��������������Ϊ��̬����洢
 */
typedef struct {
    CTBox nodes[MAX_TREE_SIZE]; // �洢���н��
    int r;  // ����λ��(����)
    int n;  // ���Ľ����
} CTree;


/*
 * ����ĳ��������Ϣ
 *
 * ע�����˫�ױ��洢�ṹ������Ҫ�ټ�����ǰ���ĵ�һ�����������е�����
 * */
typedef struct{
    int row;            // ��ǰ�����������
    int col;            // ��ǰ�����������
    int childIndex;     // ��ǰ����ǵڼ�������
    int lastChild;      // ��ǰ�������һ�����������е�����
} Pos;


/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(CTree* T);

/*
 * ����
 *
 * ����Ԥ��Ķ�������������
 * ����Լ��ʹ�á��������С�����������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateTree(CTree* T, char* path);

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty(CTree T);

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(CTree T);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(CTree* T, FILE* fp);

// ��ȡ��T�Ľ����Ϣ�����������Щ��Ϣ�������Pos���͵Ķ���
static void getPos(CTree T, Pos pt[]);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintTree(CTree T);

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(CTree T, Pos pt[], int i);

// ͼ�λ�����������нṹ�������ڲ�����ʹ��
static void PrintFramework(CTree T);

#endif