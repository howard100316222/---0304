#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Man{
	int NO[2000];
	int point[2000];
};
struct Woman{
	int NO[2000];
	int point[2000];
};

struct Man man[2000]={0};
struct Woman woman[2000]={0};
int couple[2000][2]={0};
int  single[2000]={0};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};

void quicksort(int *data, int left, int right)
{
    int pivot, i, j;
    if (left >= right) { return; }
    pivot = data[left];
    i = left + 1;
    j = right;
    while (1)
    {
        while (i <= right)
        {
            if (data[i] < pivot)
            {
                break;
            }
            i = i + 1;
        }
        while (j > left)
        {
            if (data[j] > pivot)
            {
                break;
            }
            j = j - 1;
        }
        if (i > j) { break; }
        swap(&data[i], &data[j]);
    }
    swap(&data[left], &data[j]);
    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
};

void randon(int number)//�H���X�ߤ��ƦW
{
	int a=0;
	int mcount=1;
	int wmcount=1;
	for(int i=1;i<=number;i++)//�H���X�k�b�k�ߤ�������
	{
		for(int j=1;j<=number;j++)
		{
			a=(rand() % 100) +1;
			man[i].point=a;
		}
	}
	for(int i=1;i<=number;i++)//�H���X�k�b�k�ߤ�������
	{
		for(int j=1;j<=number;j++)
		{
			a=(rand() % 100) +1;
			WMmatch[i][j]=a;
		}
	}
	for(int i=1;i<=number;i++){
	    quicksort(Mmatch[i], 1, number);
		quicksort(WMmatch[i], 1, number);
	}
};
void stableByMan(int man){
	  int pman,pwman,i; 
      int s=NULL;
      i=1;
      while(!s){
         pwman = Mmatch[man][i];       // Mmatch �� �b�k�ʤߥؤ� ��k�ʪ��ƦW
         if (single[pwman]==0){   //�樭 �����t��
            couple[pwman][0]=man;
			couple[pwman][1]=pwman;
            single[pwman] =1;
            s = 1;         //�t�令�\
         }
         else{               //��������
            pman = couple[pwman][0];         //Ū���w�t�n����
            if(WMmatch[pwman][man] < WMmatch[pwman][pman]){   //�{�b���P���e���ۤ�
            couple[pwman][0]=pman;
			couple[pwman][1]=pwman;
               s=1;         //�t�令�\
               stableByMan(pman);   //pm���s�t��
            }
            else{
               i++;         //��U�@��
            }
         }
      }
};

void main(void)
{

	srand(time(NULL));
	int single[2000]={0};
	int n=0;
	printf("�п�J�t��k�k��(�k�k�ƬۦP):");
	scanf("%d",&n);
	randon(n);//�H�����ͱƦW

	  int mw=1; 
      int i;
      for( i=1 ; i <= n ; i++ ){
		  for(int j=1;j<=n;j++){
				single[i]=0;//�M�ų樭���A
		  }
      }
      if(mw == 1){
         for( i = 1; i <= n ; i++){
            stableByMan(i);
         }
      }
      /*else{
         for( i = 1; i <= n ; i++){
            stableByWoman(i);
         }
      }*/
   
	  return;
}