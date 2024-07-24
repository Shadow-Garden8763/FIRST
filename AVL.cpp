#define _CRT_SECURE_NO_WARNINGS
const int LH = -1, EH = 0, RH = 1;//cay can bang khi chi so can bang roi vao 3 gia tri nay

#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

struct KhoHang//du lieu cua node
{
	char maKho[51];
	char tenKho[256];
	int sucChua;
};
struct Node
{
	KhoHang data;
	Node* left, * right;
	int balFactor;//chi so can bang cua 1 node
};
Node* search(Node* p, char a[]);
int insert(Node* p, KhoHang a);
int deleteById(Node* p, char id[]);
int deleteByName(Node* p, char name[]);
int deleteByCapacity(Node* p, int capacity);

int main()
{
	int chon;
	do
	{
		system("cls");
		cin >> chon;
		switch (chon)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		default:
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
		_getch();
	} while (true);
}

string cStringToString(char a[])
{
	int i = 0;
	string b = "";
	while (a[i] != '\0')
	{
		b += a[i];
		i++;
	}
	return b;
}
Node* search(Node* p, char a[])
{
	string b = cStringToString(a);
	while (p != NULL)
	{
		if (p->data.maKho == a)
			return p;
		else
		{
			if (p->data.maKho < a)
				p = p->right;
			else
				p = p->left;
		}
	}
	return p;
}
Node* newNode(KhoHang a)
{
	Node* p = new Node;
	p->balFactor = 0;
	p->data = a;
	p->right = p->left = NULL;
	return p;
}
int insert(Node* p, KhoHang a)
{
	if (p == NULL)
	{
		p = newNode(a);
		cout << "inserted successfully!\n";
	}
	else
	{
		Node* q = p;
		while (q != NULL)
		{
			string s1 = cStringToString(a.maKho);
			string s2 = cStringToString(q->data.maKho);
			if (s1 == s2)
				return 0;
			else
			{
				if (s1 < s2)
					q = q->left;
				else
					q = q->right;
			}
		}
		q = newNode(a);
		cout << "inserted successfully!\n";
	}
}
int deleteById(Node* p, char id[])
{
	Node* q = NULL;
	Node* tmp = NULL;
	string b = cStringToString(id);
	while (p != NULL)
	{
		if (p->data.maKho == b)
			break;
		else
		{
			if (p->data.maKho < b)
				p = p->right;
			else
				p = p->left;
		}
	}
	if (q == NULL)
		return 0;
	if (q->left == NULL && q->right == NULL)
	{
		delete q;
		return 1;
	}
	if (q->left != NULL && q->right != NULL)
	{
		Node* a = q->right;//tim node thay the
		Node* b = NULL;//neu node thay the co 1 con thi b la dua phia truoc node thay the
		while (a->left != NULL)
		{
			b = a;
			a = a->left;
		}
		q->data = a->data;
		if (b != NULL)//gan con phai cua node a vao con trai node b
			b->left = a->right;
		delete a;
		return 1;
	}
	if (q->left != NULL || q->right != NULL)
	{
		if (q->left == NULL)//node co 1 con phai
		{
			if (tmp == NULL);
		}
	}
}
int deleteByName(Node* p, char name[]);
int deleteByCapacity(Node* p, int capacity);
