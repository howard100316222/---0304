#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Mmatch[2000][2000]={0};
int WMmatch[2000][2000]={0};
int couple[2000][2]={0};
int  single[2000]={0};

/*int ChooseBYM(int men,int number){

};//��ܤk�ʦb�k�ʤߥؤ����ƦW
int ChooseBYWM(int men,int number){

};//��ܨk�ʦb�k�ʤߥؤ����ƦW*/

void randon(int number)//�H���X�ߤ��ƦW
{
	int a=0;
	int count=1;
	for(int i=1;i<=number;i++)//�H���X�k�b�k�ߤ����ƦW
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
	for(int i=1;i<=number;i++)//�H���X�k�b�k�ߤ����ƦW
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
         pwman = Mmatch[man][i];       // Mmatch �� �b�k�ʤߥؤ� ��k�ʪ��ƦW
         if (single[pwman]==0){   //�樭 �����t��
            couple[pwman][0]=man;
			couple[pwman][1]=pwman;
            single[pwman] =1;
            s = true;         //�t�令�\
         }
         else{               //��������
            pman = couple[pwman][0];         //Ū���w�t�n����
            if(WMmatch[pwman][man] < WMmatch[pwman][pman]){   //�{�b���P���e���ۤ�
            couple[pwman][0]=pman;
			couple[pwman][1]=pwman;
               s=true;         //�t�令�\
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
	int single[2000]={0};
	int n=0;
	printf("�п�J�t��k�k��(�k�k�ƬۦP):");
	scanf("%d",n);
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