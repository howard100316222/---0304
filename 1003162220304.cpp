#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Mmatch[2000][2000]={0};
int WMmatch[2000][2000]={0};
int couple[2000][2]={0};
int  single[2000]={0};

/*int ChooseBYM(int men,int number){

};//選擇女性在男性心目中的排名
int ChooseBYWM(int men,int number){

};//選擇男性在女性心目中的排名*/

void randon(int number)//隨機出心中排名
{
	int a=0;
	int count=1;
	for(int i=1;i<=number;i++)//隨機出女在男心中的排名
	{
		while(count>number)
		{
			a=(rand() % number) +1;
			for(int j=1;j<=i;j++)
			{
				if(a==Mmatch[i][j])
				{
					i--;
				}
				else
				{
					Mmatch[i][count]=a;
				}
			}
		}
	}
	for(int i=1;i<=number;i++)//隨機出男在女心中的排名
	{
		while(count>number)
		{
			a=(rand() % number) +1;
			for(int j=1;j<=i;j++)
			{
				if(a==WMmatch[i][j])
				{
					i--;
				}
				else
				{
					WMmatch[i][count]=a;
				}
			}
		}
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
            s = true;         //配對成功
         }
         else{               //有伴先比較
            pman = couple[pwman][0];         //讀取已配好的伴
            if(WMmatch[pwman][man] < WMmatch[pwman][pman]){   //現在的與之前的相比
            couple[pwman][0]=pman;
			couple[pwman][1]=pwman;
               s=true;         //配對成功
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
	int single[2000]={0};
	int n=0;
	printf("請輸入配對男女數(男女數相同):");
	scanf("%d",n);
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