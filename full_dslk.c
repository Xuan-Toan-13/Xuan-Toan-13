#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char ho_ten[50];
    char sbd[10];
    double diem_toan;
    double diem_ly;
    double diem_tieng_anh;
    double tong;
} Diem_Thi;

typedef struct Node
{
    Diem_Thi data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} List;

Node *node_lt;

void init_list(List *plist)
{
    plist->head=plist->tail=NULL;
}

Node *create_new_node(Diem_Thi *dt, Node *p)
{
    p=(Node*)malloc(sizeof(Node));
    if (p==NULL) return NULL;
    p->data=*dt;
    p->next=NULL;
    return p;
}

void read(Diem_Thi *dt)
{
    printf("SBD: ");
    fflush(stdin);
    gets(dt->sbd);
    printf("Ho ten: ");
    fflush(stdin);
    gets(dt->ho_ten);
    printf("Diem toan: ");
    scanf("%lf",&dt->diem_toan);
    printf("Diem ly: ");
    scanf("%lf",&dt->diem_ly);
    printf("Diem tieng anh: ");
    scanf("%lf",&dt->diem_tieng_anh);
    dt->tong=dt->diem_ly+dt->diem_tieng_anh+dt->diem_toan;
}

void add_tail(List *plist, Node *p)
{
    if (plist->head==NULL)
    {
        plist->head=plist->tail=p;
    }
    else
    {
        plist->tail->next=p;
        plist->tail=p;
    }
}

void add_head(List *plist, Node *p)
{
    if(plist->head==NULL)
    {
        plist->head=plist->tail=p;
    }
    else
    {
        p->next=plist->head;
        plist->head=p;
    }
}

void add_mid(List *plist, Node *p)
{
    char key_sbd[10];
    printf("Nhap so bao danh thi sinh muon chen vao sau: ");
    fflush(stdin);
    gets(key_sbd);
    Node *tmp=plist->head;
    while (tmp!=NULL && strcmp(tmp->data.sbd,key_sbd)!=0)
    {
        tmp=tmp->next;
    }
    if (tmp!=NULL && strcmp(tmp->data.sbd,key_sbd)==0)
    {
        p->next=tmp->next;
        tmp->next=p;
    }
    else
    {
        printf("Khong tim thay so bao danh %s\n",key_sbd);
    }
}

void delete_first(List *plist)
{
    Node *tmp=plist->head;
    plist->head=tmp->next;
    if(plist->head==NULL)
    {
        plist->tail=NULL;
    }
    free(tmp);
}

Node *search(List *plist, char key_sbd[])
{
    node_lt=NULL;
    Node *tmp=plist->head;
    while(tmp!=NULL)
    {
        if(strcmp(tmp->data.sbd,key_sbd)==0)
        {
            return tmp;
        }
        node_lt=tmp;
        tmp=tmp->next;
    }
    return NULL;
}

void delete_node(List *plist)
{
    char key_sbd[10];
    printf("Nhap so bao danh thi sinh muon xoa: ");
    fflush(stdin);
    gets(key_sbd);
    Node *tmp=search(plist,key_sbd);
    if(tmp!=NULL)
    {
        if(tmp==plist->head)
        {
            delete_first(plist);
            return;
        }
        else if(tmp==plist->tail)
        {
            node_lt->next=NULL;
            plist->tail=node_lt;
        }
        else
        {
            node_lt->next=tmp->next;
        }
        free(tmp);
    }
    else
    {
        printf("Khong the xoa thi sinh %s\n",key_sbd);
    }
}

void delete_list(List *plist)
{
    Node *tmp;
    while(plist->head!=NULL)
    {
        tmp=plist->head;
        plist->head=tmp->next;
        free(tmp);
    }
    plist->tail=NULL;
}

void fix_node(List *plist)
{
    char key_sbd[10];
    printf("Nhap so bao danh thi sinh can sua lai: ");
    fflush(stdin);
    gets(key_sbd);
    char ten[50];
    printf("Nhap ten thi sinh sua lai: ");
    fflush(stdin);
    gets(ten);
    double toan;
    printf("Nhap diem toan sua lai: ");
    scanf("%lf", &toan);
    double ly;
    printf("Nhap diem ly sua lai: ");
    scanf("%lf", &ly);
    double ta;
    printf("Nhap diem tieng anh sua lai: ");
    scanf("%lf", &ta);
    Node *tmp=search(plist,key_sbd);
    if (tmp!=NULL)
    {
        strcpy(tmp->data.ho_ten,ten);
        tmp->data.diem_ly=ly;
        tmp->data.diem_tieng_anh=ta;
        tmp->data.diem_toan=toan;
    }
    else
    {
        printf("Khong the sua thi sinh %s\n",key_sbd);
    }
}

void swap(Diem_Thi *dt1, Diem_Thi *dt2)
{
    Diem_Thi tmp=*dt1;
    *dt1=*dt2;
    *dt2=tmp;
}

void sort_down_mark(List *plist)
{
    Node *p,*k;
    for (p=plist->head; p!=NULL; p=p->next)
    {
        for (k=p->next; k!=NULL; k=k->next)
        {
            if (p->data.tong<k->data.tong)
            {
                swap(&p->data,&k->data);
            }
        }
    }
}

void sort_name_AZ(List *plist)
{
     Node *p,*k;
    for (p=plist->head; p!=NULL; p=p->next)
    {
        for (k=p->next; k!=NULL; k=k->next)
        {
            if (strcmp(p->data.ho_ten,k->data.ho_ten)>0)
            {
                swap(&p->data,&k->data);
            }
        }
    }
}

void load_list(List *plist, Diem_Thi *dt)
{
    int n,i;
    printf("Nhap so luong thi sinh: ");
    scanf("%d", &n);
    printf("\n");
    Node *p;
    init_list(plist);
    for(i=0; i<n; i++)
    {
        printf("Nhap thong tin thi sinh thu %d\n",i+1);
        read(dt);
        printf("\n");
        p=create_new_node(dt,p);
        add_tail(plist,p);
    }
}

void print_node(Diem_Thi dt,int i)
{
    printf("\n%10d%10s%20s%15.1f%10.1f%10.1f%10.1f\n",i,dt.sbd,dt.ho_ten,dt.diem_toan,dt.diem_ly,dt.diem_tieng_anh,dt.tong);
}

void show_list(List *plist)
{
    printf("\n\t\t\t\t\tDANH SACH DIEM THI\n");
    printf("\n%10s%10s%20s%15s%10s%10s%10s\n", "STT", "SBD", "Ho ten", "Diem toan", "Diem ly", "Diem TA", "Tong");
    Node *tmp=plist->head;
    int i;
    for (i=1; tmp!=NULL; tmp=tmp->next)
    {
        print_node(tmp->data,i);
        i++;
    }
    printf("\n");
}

void menu()
{
    printf("\n____________________________MENU____________________________\n");
    printf("1.  Tao danh sach\n");
    printf("2.  Hien thi danh sach\n");
    printf("3.  Them vao dau danh sach\n");
    printf("4.  Them vao giua danh sach\n");
    printf("5.  Them vao cuoi danh sach\n");
    printf("6.  Xoa dau danh sach\n");
    printf("7.  Xoa phan tu bat ki danh sach\n");
    printf("8.  Xoa toan bo danh sach\n");
    printf("9.  Sua danh sach\n");
    printf("10. Tim kiem\n");
    printf("11. Sap xep danh sach theo diem\n");
    printf("12. Sap xep danh sach theo ten\n");
    printf("0.  Ket thuc\n");
    printf("Option: ");
}

int main()
{
    List plist;
    init_list(&plist);
    Diem_Thi dt,dt1;
    char key_sbd[10];
    Node *p;
    int option;
    do
    {
        menu();
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            load_list(&plist,&dt);
            break;
        case 2:
            show_list(&plist);
            break;
        case 3:
            printf("Nhap thong tin thi sinh muon chen\n");
            read(&dt1);
            add_head(&plist,create_new_node(&dt1,p));
            break;
        case 4:
            printf("Nhap thong tin thi sinh muon chen\n");
            read(&dt1);
            add_mid(&plist,create_new_node(&dt1,p));
            break;
        case 5:
            printf("Nhap thong tin thi sinh muon chen\n");
            read(&dt1);
            add_tail(&plist,create_new_node(&dt1,p));
            break;
        case 6:
            delete_first(&plist);
            break;
        case 7:
            delete_node(&plist);
            break;
        case 8:
            delete_list(&plist);
            break;
        case 9:
            fix_node(&plist);
            break;
        case 10:
            printf("Nhap so bao danh muon tim kiem: ");
            fflush(stdin);
            gets(key_sbd);
            printf("\n%10s%10s%20s%15s%10s%10s%10s\n", "STT", "SBD", "Ho ten", "Diem toan", "Diem ly", "Diem TA", "Tong");
            print_node(search(&plist,key_sbd)->data,0);
            break;
        case 11:
            sort_down_mark(&plist);
            break;
        case 12:
            sort_name_AZ(&plist);
            break;
        case 0:
            printf("KET THUC\n");
            exit(0);
        default:
            printf("Choose 0 to 12\n");
            break;
        }
    }
    while(option>=0 && option<=12);
    return 0;
}
