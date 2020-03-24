#include<stdio.h>
struct milk{
	char s[1000];
  int P,V;
  double fc;
};
main(){
	int t,i,l,k,kk;
	struct milk zz,max;
	while (scanf("%d",&t)!=EOF){
		while (t--){
	scanf("%d",&l);k=0;
	for(i=1;i<=l;i++){ 
	scanf("%s%d%d",&zz.s,&zz.P,&zz.V);
	  if (zz.V<200) continue;
		kk=zz.V/200;
		if (kk>5)kk=5;
		zz.fc=1.0*zz.P/kk;
		if (k==0) {
			max=zz;k++;continue;
		} 
		if (zz.fc<max.fc||(zz.fc==max.fc&&zz.V<max.V))
		max=zz;
		
		}
	 printf("%s\n",max.s);
}
}}
