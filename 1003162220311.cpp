#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
int RSet[MAX];
int Set[MAX];
int Indep[MAX];
int matrix[MAX][MAX]={0};
int randK(int n)
{
	int a=0;
	a = (rand()%n)+1;
	return a;
};
void getSet(int rq,int n)
{
	int a=0;
	int counr=0;
	for(int k=0;k<rq;k++){
		RSet[k] = 0; 
	}
	for(int i=0;i<rq;i++)
	{
		counr=0;
		a= (rand()%n)+1;
		for(int j=0;j<rq;j++){
			if(a==RSet[j])
			{
				i--;
				counr++;
				break;
			}
		}
		if(counr==0)
		{
			RSet[i]=a;
		}
	}
	printf("Set��: ");
	for(int i=0;i<rq;i++)
	{
		printf("%d ",RSet[i]);
	}
	printf("\n");
};
void test(int b,int S[])
{
	int jump=0;
		for(int k=0;k<b;k++)
		{
			int c = S[k];
			for(int i=0;i<b;i++)
			{
				if(i>k)
				{
					int d=S[i];
					if(matrix[c-1][d-1]==1&&c!=d)
					{
						printf("%d�P%d�۳s ",c,d);
						printf("�ҥH��Set��dependent Set\n");
						jump++;
					}
					else if(jump!=0)
					{
						break;
					}
				}
			}
		}
		if(jump==0){
			for(int i=0;i<b;i++)
			{
				printf("%d ",S[i]);
			}
			printf("��Set��independent Set\n");
		}
};

void main()
{
	int n=0;
	int b=0;
	int h=0;
	int q=0;
	int rq=0;
	int point=0;
	int count=0;
	int number=0;
	srand(time(NULL));
	printf("�п�J�}�C���Ӽ�(N*N):");
	scanf("%d",&n);
	while(1)
	{
		if(count>(2*n))
		{
			break;
		}
		else
		{
			count=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j>i){
						matrix[i][j] = rand()%2;
						if(matrix[i][j]==1)
						{
							count++;
						}
					}
				}
			}
		}
	}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j>i){
						matrix[j][i] = matrix[i][j];
					}
				}
			}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",matrix[i][j]);
			}
			printf("\n");
		}

			printf("�п�JK���Ӽ�:");
			scanf("%d",&b);
			printf("�п�J�I\n(�Фp��%d���o����,-1�}�l����):\n",n);
			for(int i=0;i<b;i++)
			{
				scanf("%d",&point);
				if(point==-1){
					break;
				}
				Set[i] = point;
			}
			test(b,Set);

			printf("�п�J�n�q�����Ҧh�֦�:");
			scanf("%d",&h);
			for(int i=0;i<h;i++)
			{	
				//q = randK(n);
				if(q>=rq)
				{
					//rq = q;
					getSet(2,n);
					test(2,RSet);
				}
				else
				{
					i--;
				}
			}



	system("PAUSE");
	return ;
}