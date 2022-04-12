#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char ten_hang[20];
    int don_gia;
    int so_luong;
    int thanh_tien;
} so_lieu;

void nhap_du_lieu(char *file_name)
{
    FILE *fp;
    fp=fopen(file_name,"wb");
    if (fp!=NULL)
    {
        so_lieu sl;
        printf("Nhap so luong mat hang: ");
        int n;
        scanf("%d", &n);
        int i;
        for (i=0; i<n; i++)
        {
            printf("Loai hang thu %d\n", i+1);
            printf("Ten hang: ");
            fflush(stdin);
            gets(sl.ten_hang);
            printf("Don gia: ");
            scanf("%d", &sl.don_gia);
            printf("So luong: ");
            scanf("%d", &sl.so_luong);
            sl.thanh_tien=sl.don_gia*sl.so_luong;
            fwrite(&sl,sizeof(so_lieu),1,fp);
        }
    }
    fclose(fp);
}

void hien_thi(char *file_name)
{
    FILE *fp;
    fp=fopen(file_name,"rb");
    if (fp!=NULL)
    {
        printf("\t\t\t\t\t\tSO LIEU BAN HANG\n");
        char stt[10]="STT";
        char ten_hang[10]="Ten Hang";
        char don_gia[10]="Don gia";
        char so_luong[10]="So luong";
        char thanh_tien[15]="Thanh tien";
        char tong_so_tien[15]="Tong tien";
        printf("%20s%20s%20s%20s%20s\n",stt,ten_hang,don_gia,so_luong,thanh_tien);
        so_lieu sl;
        int i=1,tong_tien=0;
        while(fread(&sl,sizeof(so_lieu),1,fp)!=NULL)
        {
            printf("%20d%20s%20d%20d%20d\n",i,sl.ten_hang,sl.don_gia,sl.so_luong,sl.thanh_tien);
            tong_tien+=sl.thanh_tien;
            i++;
        }
        printf("%80s%20d",tong_so_tien,tong_tien);
    }
    fclose(fp);
}

void bo_sung_du_lieu(char *file_name)
{
    FILE *fp;
    fp=fopen(file_name,"ab");
    if (fp!=NULL)
    {
        so_lieu sl;
        int t,i;
        do
        {
            printf("So luong so lieu bo sung: ");
            scanf("%d", &t);
        }
        while (t<2);
        for (i=0; i<t; i++)
        {
            printf("Ten hang: ");
            fflush(stdin);
            gets(sl.ten_hang);
            printf("Don gia: ");
            scanf("%d", &sl.don_gia);
            printf("So luong: ");
            scanf("%d", &sl.so_luong);
            sl.thanh_tien=sl.don_gia*sl.so_luong;
            fwrite(&sl,sizeof(so_lieu),1,fp);
        }
    }
    fclose(fp);
}

void menu()
{
    printf("\n\n");
    printf("__________________MENU__________________\n");
    printf("1. Nhap so lieu ban hang len tep\n");
    printf("2. Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.C\n");
    printf("3. Hien thi noi dung tep SO_LIEU.C\n");
    printf("4. Ket thuc\n");
    printf("Option: ");
}

int main()
{
    char *file_name="SO_LIEU.C";
    while (1)
    {
        menu();
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            nhap_du_lieu(file_name);
            break;
        case 2:
            bo_sung_du_lieu(file_name);
            break;
        case 3:
            hien_thi(file_name);
            break;
        case 4:
            exit(0);
        default:
            printf("Moi nhap lai >.<");
            break;
        }
    }
    return 0;
}
