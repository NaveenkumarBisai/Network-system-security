#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char ip1[64];
char op1[64];
char key[64]="0001001100110100010101110111100110011011101111001101111111110001";
char left[32],right[32],EP1[48];
char key1[56],key2[48],key3[16][48];
char left1[28],right1[28],a[4];
int s=0;
int IP[] = 
{
	  58, 50, 42, 34, 26, 18, 10, 2,
	  60, 52, 44, 36, 28, 20, 12, 4,
	  62, 54, 46, 38, 30, 22, 14, 6,
	  64, 56, 48, 40, 32, 24, 16, 8,
	  57, 49, 41, 33, 25, 17,  9, 1,
	  59, 51, 43, 35, 27, 19, 11, 3,
	  61, 53, 45, 37, 29, 21, 13, 5,
	  63, 55, 47, 39, 31, 23, 15, 7
};
int EP[] = 
{
	  32,  1,  2,  3,  4,  5,
	   4,  5,  6,  7,  8,  9,
	   8,  9, 10, 11, 12, 13,
	  12, 13, 14, 15, 16, 17,
	  16, 17, 18, 19, 20, 21,
	  20, 21, 22, 23, 24, 25,
	  24, 25, 26, 27, 28, 29,
	  28, 29, 30, 31, 32,  1
};
int KIP[] = 
{
	  57, 49, 41, 33, 25, 17,  9,
	   1, 58, 50, 42, 34, 26, 18,
	  10,  2, 59, 51, 43, 35, 27,
	  19, 11,  3, 60, 52, 44, 36,
	  63, 55, 47, 39, 31, 23, 15,
	   7, 62, 54, 46, 38, 30, 22,
	  14,  6, 61, 53, 45, 37, 29,
	  21, 13,  5, 28, 20, 12,  4
};

int PC2[] = 
{
	  14, 17, 11, 24,  1,  5,
	   3, 28, 15,  6, 21, 10,
	  23, 19, 12,  4, 26,  8,
	  16,  7, 27, 20, 13,  2,
	  41, 52, 31, 37, 47, 55,
	  30, 40, 51, 45, 33, 48,
	  44, 49, 39, 56, 34, 53,
	  46, 42, 50, 36, 29, 32
};
int shift[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

int S1[4][16] = 
{
		14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
		15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
};

int S2[4][16] = 
{
	15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
	 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
	 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
	13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
};

int S3[4][16] = 
{
	10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
	13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
	13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
	 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
};

int S4[4][16] = 
{
	 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
	13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
	10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
	 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
};

int S5[4][16] = 
{
	 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
	14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
	 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
	11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
};

int S6[4][16] = 
{
	12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
	10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
	 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
	 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
};

int S7[4][16]= 
{
	 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
	13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
	 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
	 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
};

int S8[4][16]= 
{
	13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
	 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
	 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
	 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};
int P[] = 
{
	  16,  7, 20, 21,
	  29, 12, 28, 17,
	   1, 15, 23, 26,
	   5, 18, 31, 10,
	   2,  8, 24, 14,
	  32, 27,  3,  9,
	  19, 13, 30,  6,
	  22, 11,  4, 25
};
int FP[] = 
{
	  40, 8, 48, 16, 56, 24, 64, 32,
	  39, 7, 47, 15, 55, 23, 63, 31,
	  38, 6, 46, 14, 54, 22, 62, 30,
	  37, 5, 45, 13, 53, 21, 61, 29,
	  36, 4, 44, 12, 52, 20, 60, 28,
	  35, 3, 43, 11, 51, 19, 59, 27,
	  34, 2, 42, 10, 50, 18, 58, 26,
	  33, 1, 41,  9, 49, 17, 57, 25
};

void converttobin(char *ip)
{
	int i=0,j,k,m,n,x=0;
	while(ip[i]!='\0')
	{
		n=(int)ip[i];
		for(j=7;j>=0;j--)
			{
				m = 1 << j;
				k = n & m;
				if(k==0)
				ip1[x++]='0';
				else
				ip1[x++]='1';	
			}	
			
			i++;
	}
	//printf("%s\n",ip1);
}

void initialPermutation()
{
	int i;
	char temp[64];
   
	for(i=0;i<64;i++)
	{
		temp[i]=ip1[IP[i]-1];

	}
	for(i=0;i<64;i++)
	{
		ip1[i]=temp[i];
	}
//	printf("%s\n",ip1);
}

void ExtendedPermutation()
{
	int i;
	for(i=0;i<48;i++)
		EP1[i]=right[EP[i]-1];
//	printf("%s\n",EP1);	
}

void keyinitialpermutation()
{
	int i;
	for(i=0;i<56;i++)
	{
		key1[i]=key[KIP[i]-1];
	}
//	printf("%s\n",key1);
}

void GenerateKey48()
{
	int i;
	for(i=0;i<48;i++)
	{
		key2[i]=key1[PC2[i]-1];
		//printf("%c ",key2[i]);
	}
//	printf("%s\n",key2);
}

void keypermutation2(int round)
{
	int i,j;
	char x;

	for(i=0;i<28;i++)
		left1[i]=key1[i];
	for(i=28;i<56;i++)
		right1[i-28]=key1[i];

	for(i=0;i<shift[round];i++)
	{
		x=left1[0];
		for(j=1;j<28;j++)
			left1[j-1]=left1[j];
		left1[27]=x;
	}
	for(i=0;i<shift[round];i++)
	{
		x=right1[0];
		for(j=1;j<28;j++)
			right1[j-1]=right1[j];
		right1[27]=x;
	}
	for(i=0;i<28;i++)
		key1[i]=left1[i];
	for(i=28;i<56;i++)
		key1[i]=right1[i-28];
	GenerateKey48();
}
void ToBits(int value)
{

	int k, j, m;
	
	for (j = 3; j >= 0; j--) 
	{
		m = 1 << j;
		k = value & m;
		if (k == 0)
			a[j] = '0';
		else
			a[j] = '1';
	}
}
void GenerateKey()
{
    int i,j;
    keyinitialpermutation();
	
    for(i=0;i<16;i++)
    {
	keypermutation2(i);
	for(j=0;j<48;j++)
	{
	    key3[i][j]=key2[j];
	}
    }
   /* for(i=0;i<16;i++)
    {
    for(j=0;j<48;j++)
    printf("%c",key3[i][j]);
    printf("\n");}*/
}

void SBox()
{
	int i,j,k=0,row=0,column=0,x;

	for(i=0;i<48;i=i+6)
	{
			row=((EP1[i]-48)*2)+(EP1[i+5]-48);
			column=((EP1[i+1]-48)*8)+((EP1[i+2]-48)*4)+((EP1[i+3]-48)*2)+(EP1[i+4]-48);
			//printf("%d %d ",row,column);
			if(s==0)
				x=S1[row][column];
			if(s==1)
				x=S2[row][column];
			if(s==2)
				x=S3[row][column];
			if(s==3)
				x=S4[row][column];
			if(s==4)
				x=S5[row][column];
			if(s==5)
				x=S6[row][column];
			if(s==6)
				x=S7[row][column];
			if(s==7)
				x=S8[row][column];
			s++;
			ToBits(x);
			for(j=0;j<4;j++)
				right[k++]=a[j];
	}
	s=0;
}

void PBox()
{
	int i;
	char abc[32];
	for(i=0;i<32;i++)
		abc[i]=right[P[i]-1];
	for(i=0;i<32;i++)
		right[i]=abc[i];
}

void roundfun(int round)
{
	int i;
	
	for(i=0;i<32;i++)
	   	left[i]=ip1[i];
	for(i=32;i<64;i++)
		right[i-32]=ip1[i];
	for(i=0;i<32;i++)
		ip1[i]=right[i];

	ExtendedPermutation();
//	GenerateKey(round);
	for(i=0;i<48;i++)
	{
		
		if(EP1[i]==key3[round][i])
			EP1[i]='0';
		else
			EP1[i]='1';
	}
    /* for(i=0;i<48;i++)
    printf("%c",key3[round][i]);
    printf("\n");*/
	//printf("%s\n",EP1);
	SBox();
	PBox();
	for(i=0;i<32;i++)
	{
		if(right[i]==left[i])
			right[i]='0';
		else
			right[i]='1';
		
	}

	for(i=32;i<64;i++)
		ip1[i]=right[i-32];
}

void finalpermutation()
{
	int i;
	char abcd[64];
	for(i=0;i<64;i++)
		abcd[i]=ip1[FP[i]-1];
	for(i=0;i<64;i++)
		ip1[i]=abcd[i];
}

void DesEncryption()
{
	int i;
	initialPermutation();
	
	for(i=0;i<16;i++)
	{
		roundfun(i);
	}
     for(i=0;i<32;i++)
     {
          left[i]=ip1[i];
          right[i]=ip1[i+32];
     }
     for(i=0;i<32;i++)
     {
          ip1[i]=right[i];
          ip1[i+32]=left[i];
     }
	finalpermutation();
	for(i=0;i<64;i++)
    	printf("%c",ip1[i]);
    printf("\n");	
	//printf("%s",ip1);
}


void DesDecryption()
{
	int i;
	initialPermutation();
	
	for(i=15;i>=0;i--)
	{
		roundfun(i);
	}
     for(i=0;i<32;i++)
     {
          left[i]=ip1[i];
          right[i]=ip1[i+32];
     }
     for(i=0;i<32;i++)
     {
          ip1[i]=right[i];
          ip1[i+32]=left[i];
     }
	finalpermutation();
	for(i=0;i<64;i++)
    	printf("%c",ip1[i]);
     printf("\n");
	//printf("%s",ip1);
}
void Bintochar()
{
    int i,j;
    int v[8]={0};
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            v[i]=v[i]*2+(ip1[i*8+j]-48);
        }
        printf("%c",v[i]);
    }
}

int main()
{
	
	char ip[MAX];
	printf("Enter the plain text");
	scanf("%s",ip);
	converttobin(ip);	
	printf("plain text in binary\n");
	printf("%s\n",ip1);
	GenerateKey();
	printf("After Encryption,Cipher Text is\n");
	DesEncryption();
	printf("After Decryption,Plain Text is\n");
	DesDecryption();
    Bintochar();
	return 0;
}
