#include<stdio.h>

int s[256],x,k;
int PT[8],CT[8],keys[8];

void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}


void KSA(int *key,int l)
{
	int i,j=0,k;

	for(i=0;i<256;i++)
		s[i]=i;
	for(i=0;i<255;i++)
		{
			k=key[i%l];
			j=(j+k+s[i])%256;
			swap(&s[i],&s[j]);
		}
}

void PRGA()
{	
	
	int i,j = 0,t,p; 
	for(p=0;p<8;p++)
	    	{
	    	i = (i + 1)%256; 
			j = (j + s[i])%256; 
			swap(&s[i], &s[j]); 
			t = (s[i] + s[j])%256; 
			keys[p]=s[t];
			CT[p]=PT[p]^s[t];	
		}
}

void RC4(int key[],int l)
{
	KSA(key,l);
	PRGA();
	return;
}

void decrypt()
{
	int i,x;
	for(i=0;i<8;i++)
	{
		x=CT[i]^keys[i];
		printf("%d ",x);
	}
	return;
}

int main()
{
	int l,i;
	printf("enter the length of input key\n");
	scanf("%d",&l);

	int key[l];
	

	printf("enter the input key in binary\n");
	
	for(i=0;i<l;i++)
		scanf("%d",&key[i]);
	printf("enter the plain text binary\n");
	for(i=0;i<8;i++)
		scanf("%d",&PT[i]);
	
	RC4(key,l);

	
	printf("cipher text is\n");
	for(i=0;i<8;i++)
		printf("%d ",CT[i]);
	printf("\n");	
	printf("decrpyted text is :");
	decrypt();
	
}