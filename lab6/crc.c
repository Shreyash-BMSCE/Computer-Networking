
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char g[]="10001000000100001",p[50],c[50];
int n1,n2;

void xor()
{
	int i;
	for(i=0;i<n1;i++)
	{
		if(c[i]==g[i])
		{
			c[i]='0';
		}
		else
		{
			c[i]='1';
		}
	}
}

void crc()
{
	int i,cnr;
	for(cnr=0;cnr<n1;cnr++)
	{
		c[cnr]=p[cnr];
	}
	do
	{
		 if(c[0]=='1')
		 {
			 xor();
		 }
		 for(i=0;i<n1-1;i++)
		 {
			 c[i]=c[i+1];
		 }
		 c[i]=p[cnr++];
	 }while(cnr<n2+n1);
 }

void main()
{
	int i;
	printf("Enter data :");
	scanf("%s",p);
	n1=strlen(g);
	n2=strlen(p);
	for(i=n2;i<n2+n1;i++)
	{
		p[i]='0';
	}
	crc();
	printf("Checksum is: %s\t",p);
	printf("Current code : %s\n",g);
	for(i=n2;i<n2+n1;i++)
	{
		p[i]=c[i-n2];
	}
	printf("Transmitted code or code word : %s\n",p);
	printf(" Enter code recieved :\t");
	scanf("%s",p);
	crc();
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]=='1')
		{
			printf("Error!!!!!!!!!!\n");
			exit(0);
		}
	}
	printf("No error\n");
}