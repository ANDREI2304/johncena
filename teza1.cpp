

#include<iostream>
using namespace std;
typedef struct element {
                         int info;
                         struct element *next;
                       } termen;

typedef struct {
                int length;
                termen *start,*current,*finalist;
                } lista;

lista *L;

lista *initlist()
{
lista *result=new lista;
result->length=0;
result->start=result->current=result->finalist=NULL;
return result;
}

int isempty(lista *L)
{return  (L->length==0);}

lista *addright(lista *L,int value) {
    if (isempty(L)) {
        termen *newone=new element;
        newone->info=value;
        L->current=L->finalist=L->start=newone;
        L->length++;
        return L;
    }
    if (L->current==L->finalist) {
        termen *newone = new element;
        newone->info = value;
        L->current->next = newone;
        L->current = L->finalist = newone;
        L->length++;
        return L;
    }
    termen *newone=new element;
    newone->info=value;
    newone->next=L->current->next;
    L->current->next=newone;
    L->current=newone;
    L->length++;
    return L;
}


int searchvalue(lista **L,int value) {
    termen *carrier;
    carrier=(*L)->start;
    while ((carrier!=(*L)->finalist)&&(carrier->info!=value)) {
        carrier=carrier->next;
    }
    if ((carrier==(*L)->finalist)&&(carrier->info!=value)) {
        return 0;
    }
    (*L)->current=carrier;
    return 1;
}

int showmeplease(lista *L)
{cout<<endl;
termen *carrier;
carrier=L->start;
int counter=L->length;
while (counter>=0) { cout<<carrier->info<" "; carrier=carrier->next;
                     counter--; }
}

int main()
{
L=initlist();
for(int i=1;i<=3;i++) L=addright(L,i);
showmeplease(L);
searchvalue(&L,2);
L=addright(L,0);
showmeplease(L);
searchvalue(&L,1);
L=addright(L,0);
showmeplease(L);
searchvalue(&L,456);
L=addright(L,-1);
showmeplease(L);
}

/// 1. addright
/// 2. addleft
// 3. delrigth
/// 4. delleft
