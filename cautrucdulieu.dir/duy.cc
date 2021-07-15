

#include <iostream>
using namespace std;

//  khoi tao cau truc cho node
struct node 
{ int data;
struct node *pnext;
};

// rut gon  struct node thanh NODE
typedef struct node NODE;

// tao 1 node
NODE *khoitaonode(int x)
{ NODE *p = new NODE;
p->data = x;
p->pnext = NULL;
return p;}

//cau truc dau duoi cua danh sach lien ket
struct list
{ NODE *phead;
NODE *ptail;
};

typedef struct list LIST;

void khoitao(LIST &l)
{ l.phead = NULL;
l.ptail = NULL;
};

// them node vao dau danh sach
void them_vao_dauDS(LIST &l, NODE *p)
{ if (l.phead == NULL) {l.phead = l.ptail = p;}
else {p->pnext = l.phead;
    l.phead = p;}
}
void them_vao_cuoiDS(LIST &l, NODE *p)
{ if (l.ptail == NULL) {l.ptail = l.phead = p;}
else {l.ptail->pnext = p;
l.ptail = p;}
}

// them node vao vi tri sau 1 node bat ki
void themnode_vaosaunodeq(LIST &l, NODE *p)
{ int x;
cout << "Nhap gia tri cho data q : ";
cin >> x;
NODE *q = khoitaonode(x);;
if (q->data == l.phead->data && l.phead->pnext == NULL){
them_vao_cuoiDS(l, q);}
else {for (NODE *k = l.phead; k != NULL; k = k->pnext) {
if (q->data == k->data) {
NODE *h = khoitaonode(p->data);
NODE *g = k->pnext;
h->pnext = g;
k->pnext = h;}
}
}
}
//them 1 node vao bat ki
void themnode_p_vaovitribatki(LIST &l, NODE *p, int vt)
{int n = 0;
for (NODE *k = l.phead; k != NULL; k = k ->pnext) {
n++;
}
if (l.phead = = NULL || vt = 1) { them_vao_dauDS(l, p);}
else if (vt == n + 1)
{them_vao_cuoiDS(l, p);}
else { NODE *g = new NODE;
int dem = 0
for (NODE *k = l,phead; k != NULL; k = k->pnext) {
dem++;
if (dem == vt) {
NODE *h = khoitaonode(p->data);
h->pnext = k;
g->pnext = h;
break;}
g = k;
}
}
}

// xuat dsch cac node
void xuatds(LIST l)
{ for (NODE *k = l.phead; k != NULL; k = k->pnext)
{cout << k->data;}
}

int main()
{
LIST l;
khoitao(l);
int n;
cout <<"\n nhap so luong node can them: ";
cin >> n;
for (int i = 1;i <= n; i++){
int x;
cout << "Nhap gia tri so nguyen : ";
cin >> x;
NODE *p = khoitaonode(x);
}
cout  << "nhap gia tri data cho p : ";
int e;
cin >> e;
NODE *m = khoitaonode(e);
themnode_vaosaunodeq(l, m);
xuatds(l);
return 0;
}
