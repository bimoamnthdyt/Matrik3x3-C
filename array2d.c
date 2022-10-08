
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

void gotoxy(int x, int y){
	printf("%c[%d;%df",0x1B,y,x);
}

int main()
{
	int i,j,k,n,min,bar,kol,e,f,
   d[3][3], 
   A[3][3], 
   B[3][3], 
   C[3][3], 
   g[3][3],
   sum[3], 
   jum[3];
   
   system("cls");

	n=3;
	gotoxy(30,1);
	printf(" Jumlah  Terkecil 1  Terkecil 2 \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			gotoxy(j*5+10,i*2);
			scanf ("%i",&A[i][j]);
		}
	}
	printf("\n");
	printf(" Jumlah");
	printf("\n Terkecil 1");
	printf("\n Terkecil 2");
	for(i=1;i<=n;i++)
	{
		sum[i]=0;
		for(j=1;j<=n;j++)
		{
			sum[i]=sum[i]+A[i][j];
		}
		gotoxy(33,i*2);
		printf("%i",sum[i]);
	}
   
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		g[i][j]=A[j][i];
		}
	}

	for(i=1;i<=n;i++)
	{
		jum[i]=0;
		for(j=1;j<=n;j++)
		{
			jum[i]=jum[i]+g[i][j];
		}
		gotoxy(i*5+10,8);
		printf("%i",jum[i]);
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			 B[i][j]=A[i][j];
			 C[i][j]=A[j][i];
			 if (B[i][j] <= min)
			 {
				 min = B[i][j];
				 e=i;
				 f=j;
			 }
		 }
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			bar = B[k][i];
			for(j=i+1; j<=n; j++)
			{
				if (B[k][j] < bar)
				{
					bar=B[k][j];
					B[k][j]=B[k][i];
					B[k][i]=bar;
				}
			}
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			kol=C[k][i];
			for(j=i+1;j<=n;j++)
			{
				if (C[k][j]<kol)
				{
					kol=C[k][j];
					C[k][j]=C[k][i];
					C[k][i]=kol;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=2;j++)
		{
			gotoxy(j*10+34,i*2);
			printf ("%i",B[i][j]);
			gotoxy(i*5+10,j+8);
			printf ("%i",C[i][j]);
		}
	}
	printf("\n");
	printf(" \n Nilai terkecil dari keseluruhan matriks adalah %d,\n", min);
	printf(" yaitu di elemen baris %d dan Kolom %i",e,f);
	getch();
}