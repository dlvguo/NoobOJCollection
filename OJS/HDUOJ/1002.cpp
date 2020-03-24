#include<stdio.h>
#include<string.h>
int a[1010],b[1010];
char c[1010],d[1010];
main(){
	int i,t;
	__int64 fc,md,c1,d1,max;
	while(scanf("%d",&t)!=EOF){getchar();
		for (i=1;i<=t;i++){
		scanf("%s%s",c,d);getchar(); 
		c1=strlen(c);d1=strlen(d);
		if (c1>d1)max=c1+1;
		else max=d1+1;
		memset(a,0,max*sizeof(int));
		memset(b,0,max*sizeof(int));
		for (fc=c1-1,md=0;fc>=0;fc--,md++)
			a[md]=c[fc]-'0';
		for (fc=d1-1,md=0;fc>=0;fc--,md++)
		b[md]=d[fc]-'0';
		for (fc=0;fc<max-1;fc++){
		a[fc]=a[fc]+b[fc];
		if (a[fc]>9){a[fc+1]++;a[fc]-=10;}}
		printf("Case %d:\n",i);
		printf("%s + %s = ",c,d);
		if (!a[fc]) fc--;
		for (;fc>=0;fc--)
		printf("%d",a[fc]);
		printf("\n");
		if (i!=t)
		printf("\n");
		}}}
