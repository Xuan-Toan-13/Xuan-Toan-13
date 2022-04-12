#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100

typedef struct
{
    int row;
    int col;
} MATRIX;

void read_matrix(int a[][MAX], int b[][MAX], MATRIX *mt)
{
    FILE *fp;
    fp=fopen("MA_TRAN.C","w");
    if (fp!=NULL)
    {
        int i,j;
        printf("Nhap so dong: ");
        scanf("%d", &mt->row);
        printf("Nhap so cot: ");
        scanf("%d", &mt->col);
        fprintf(fp,"%d, %d\n",mt->row,mt->col);
        printf("Nhap ma tran A\n");
        fprintf(fp,"Ma Tran A\n");
        for (i=0; i<mt->row; i++)
        {
            for (j=0; j<mt->col; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (i=0; i<mt->row; i++)
        {
            for (j=0; j<mt->col; j++)
            {
                fprintf(fp,"%4d", a[i][j]);
            }
            fprintf(fp,"\n");
        }
        printf("Nhap ma tran B\n");
        fprintf(fp,"Ma Tran B\n");
        for (i=0; i<mt->row; i++)
        {
            for (j=0; j<mt->col; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        for (i=0; i<mt->row; i++)
        {
            for (j=0; j<mt->col; j++)
            {
                fprintf(fp,"%4d", b[i][j]);
            }
            fprintf(fp,"\n");
        }
    }
    fclose(fp);
}

void print_sum_matrix(int a[][MAX],int b[][MAX],int c[][MAX], MATRIX *mt)
{
     FILE *fp;
    fp=fopen("MA_TRAN.C","a");
    if (fp!=NULL)
{
        int i,j;
         for (i=0; i<mt->row; i++)
        {
            for (j=0; j<mt->col; j++)
            {
                c[i][j]=a[i][j]+b[i][j];
            }
        }
        printf("MA TRAN C\n");
        fprintf(fp, "MA TRAN C\n");
        for (i=0; i<mt->row; i++)
        {
            for (j=0; j<mt->col; j++)
            {
                printf("%4d", c[i][j]);
                fprintf(fp,"%4d", c[i][j]);
            }
            fprintf(fp,"\n");
            printf("\n");
        }
    }
    fclose(fp);
}

void menu()
{
    printf("\n_____________________MENU_____________________\n");
    printf("1. Doc tep MA_TRAN.C\n");
    printf("2. Ghi ma tran C bo sung vao cuoi tep\n");
    printf("3. Ket thuc\n");
    printf("Option: ");
}
int main()
{
    int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
    MATRIX mt;
    while (1)
    {
        menu();
        int choose;
        scanf("%d", &choose);
        switch(choose)
        {
        case 1:
            read_matrix(a,b,&mt);
            break;
        case 2:
            print_sum_matrix(a,b,c,&mt);
            break;
        case 3:
            printf("KET THUC\n");
            exit(0);
        default:
            printf("Choose 1 to 3\n");
        }
    }
    return 0;
}
