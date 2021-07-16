#include<iostream>
using namespace std;

struct node {
int data;
struct node *pleft;
struct node *pright;
};
typedef struct  node NODE;
typedef NODE* TREE;

void khoitaocay(TREE &t){
t = NULL;
}

void themphantuvaocay(TREE &t, int x)
{ if (t == NULL) {
NODE *p = new NODE;
p->data = x;
p->pleft = NULL;
p->pright = NULL;
t = p;}
else
{ if (t->data > x) {themphantuvaocay(t->pleft, x);}
else if(t->data < x) {themphantuvaocay(t->pright, x);}
}
}

void duyet_NLR(TREE &t) {
if (t != NULL) { cout << t->data << " ";
duyet_NLR(t-> pleft);
duyet_NLR(t-> pright);
}
}

void MENU(TREE &t)
{while (true) {
   system("cls");
   cout << "\n\n\t\t ============= MENU ============";
   cout << "\n1.Nhap du lieu ";
   cout << "\n2.xuat du lieu cua cay ";
   cout << "\n0.ket thuc ";
   int luachon;
   cout << "Nhap lua chon ";
   cin >> luachon;
  if (luachon < 0 || luachon > 2) {cout << "\nLua chon ko hop le";
system ("pause");
}
else if (luachon == 1) {
int x;
cout << "Nhap so nguyen ";
cin >> x;
themphantuvaocay(t, x);}
else if (luachon ==  2) {
cout << "\n\t\t Duyet cay theo NLR ";
duyet_NLR(t);}
}
}
int main()
{ TREE t;
khoitaocay(t);
MENU(t);
system("pause");
return 0;
}
