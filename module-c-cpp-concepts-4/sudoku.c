#include<stdio.h>
//#include<conio.h>
#include<curses.h>


int main()
{
	int s,g,h,u,q,t,i,w,e;int n=1;int ae[1];int x,aw,v;int az;int at=11;int ay;int ar=11;int aq=2;
	int m=0;int r=0;int k=1;int a[101];int p[250];int j[200];int c[1];int ax;int ac[1];int al[1];
	//int count=0;
	for(i=0;i<=100;i++){
		a[i]=0;
	}
	a[101]=0;

	printf("enter number of printed numbers");
printf("\n");
scanf("%d",&g);
for(int h=0;h<g;h++)
{
printf("enter location number");
printf("\n");
scanf("%d",&t);
printf("enter value");
printf("\n");
scanf("%d",&aw);
a[t]=aw;
}
for( i=11;i<21;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=21;i<31;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=31;i<41;i++)
{
	printf("%d",a[i]);
}
printf("\n");

for( i=41;i<51;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=51;i<61;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=61;i<71;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=71;i<81;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=81;i<91;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=91;i<101;i++)
{
	printf("%d",a[i]);
}
printf("\n");
s=11;
 v4:if(k<10)

{

c[0]=s;
	q=s/10;
	u=s%10;

if(s>99)
{	
	k=k+1;
	s=11;
	goto v4;
}	
if(a[s]==0)
{

		s=c[0];
		s=s-u+1;
	for(int d=0;d<9;d++)
	{
		if(a[s]==k)
		{

			goto v3;
		}
		s=s+1;
	}
		s=c[0];
		if(s>11)
		{
		v=10*(q-1);
		s=s-v;
	    }
	if(s<21)
	{
		for(int am=0;am<=8;am++)
		{
		if(a[s]==k)
		{ 	goto v3;
		}
		s=s+10;
		
	}
}

s=c[0];	
if(s==11||s==14||s==17||s==41||s==44||s==47||s==71||s==74||s==77)
{
	s=s+11;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+9;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==12||s==15||s==18||s==42||s==45||s==48||s==72||s==75||s==78)
{
	s=s+9;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+2;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+8;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+2;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==13||s==16||s==19||s==43||s==46||s==49||s==73||s==76||s==79)
{
	s=s+8;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+9;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==21||s==24||s==27||s==51||s==54||s==57||s==81||s==84||s==87)
{
	s=s-9;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+20;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-1;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==22||s==25||s==28||s==52||s==55||s==58||s==82||s==85||s==88)
{
	s=s-11;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+2;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+20;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-2;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==23||s==26||s==29||s==53||s==56||s==59||s==83||s==86||s==89)
{
	s=s-11;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-1;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+20;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==31||s==34||s==37||s==61||s==64||s==67||s==91||s==94||s==97)
{
	s=s-9;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-10;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-1;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==32||s==35||s==38||s==62||s==65||s==68||s==92||s==95||s==98)
{
	s=s-9;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-2;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-10;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+2;
	if(a[s]==k)
	{
		goto v3;
	}
}
s=c[0];
if(s==33||s==36||s==39||s==63||s==66||s==69||s==93||s==96||s==99)
{
s=s-11;
if(a[s]==k)
	{
		goto v3;
	}
	s=s-1;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s-10;
	if(a[s]==k)
	{
		goto v3;
	}
	s=s+1;
	if(a[s]==k)
	{
		goto v3;
	}
}

s=c[0];
r=r+1;
p[r]=s;
m=m+1;
j[n]=m;
 v3:s=c[0];
 if(u==9)
{
if(m==0)
{
	s=s+1;
	ae[0]=s;
	goto v7;
}
v6:	s=p[r];   
	a[s]=k;
	m=0;
	s=c[0];
	s=s+1;
	ae[0]=s;
v7:	
	s=c[0];
	u=s%10;
		s=s-u+1;
	for(int d=0;d<9;d++)
	{
		
		if(a[s]==k)
		{
			s=ae[0];
			s=s+1;
			n=n+1;
			j[n]=0;
			goto v4;
		}
		s=s+1;
	}

v5: x=j[n];
if(x==0)
{
	n=n-1;al[0]=n;az=n%9;
	if(az==0)
	{
		k=k-1;
	}
	goto v5;
}
if(x>1)
{

	s=p[r];
	a[s]=0;
	j[n]=j[n]-1;
	r=r-1;
	s=p[r];
	u=s%10;
	s=s-u+9;
	c[0]=s;
	goto v6;
}
	
n=n-1;al[0]=n;
az=n%9;
	if(az==0)
	{
		k=k-1;
	}
s=p[r];
a[s]=0;
r=r-1;
goto v5;
}
s=s+1;
goto v4;
}

goto v3;
}


for( i=11;i<21;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=21;i<31;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=31;i<41;i++)
{
	printf("%d",a[i]);
}
printf("\n");

for( i=41;i<51;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=51;i<61;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=61;i<71;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=71;i<81;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=81;i<91;i++)
{
	printf("%d",a[i]);
}
printf("\n");
for( i=91;i<101;i++)
{
	printf("%d",a[i]);
}
printf("\n");

}
