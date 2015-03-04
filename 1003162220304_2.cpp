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

void randon(int number)//隨機出心中排名
{
	int a=0;
	int mcount=1;
	int wmcount=1;
	for(int i=1;i<=number;i++)//隨機出女在男心中的分數
	{
		for(int j=1;j<=number;j++)
		{
			a=(rand() % 100) +1;
			man[i].point=a;
		}
	}
	for(int i=1;i<=number;i++)//隨機出男在女心中的分數
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
         pwman = Mmatch[man][i];       // Mmatch 為 在男性心目中 對女性的排名
         if (single[pwman]==0){   //單身 直接配對
            couple[pwman][0]=man;
			couple[pwman][1]=pwman;
            single[pwman] =1;
            s = 1;         //配對成功
         }
         else{               //有伴先比較
            pman = couple[pwman][0];         //讀取已配好的伴
            if(WMmatch[pwman][man] < WMmatch[pwman][pman]){   //現在的與之前的相比
            couple[pwman][0]=pman;
			couple[pwman][1]=pwman;
               s=1;         //配對成功
               stableByMan(pman);   //pm重新配對
            }
            else{
               i++;         //找下一位
            }
         }
      }
};

void main(void)
{

	srand(time(NULL));
	int single[2000]={0};
	int n=0;
	printf("請輸入配對男女數(男女數相同):");
	scanf("%d",&n);
	randon(n);//隨機產生排名

	  int mw=1; 
      int i;
      for( i=1 ; i <= n ; i++ ){
		  for(int j=1;j<=n;j++){
				single[i]=0;//清空單身狀態
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