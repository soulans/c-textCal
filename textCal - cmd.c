#include "stdio.h"
#include "string.h"
#include "windows.h"

int pr(int y, int m, int t) {
	int ye, me, i;
	ye = (m+t-2)/12+y;
	me = (m+t-2)%12+1;
	printf("       %d-%0d ~ %d-%0d\n", y, m, ye, me);
	ye = y; me = m;
	for(i = 0; i < t; ++i){
		//printf("%d %d\n",ye, me);
		prmonth(ye, me);
		me+=1; 
		if (me>12) {ye+=1; me=1;}
	}
	return 0;
}

int yam(int y, int m) {
	char* st[] = {"未定义", "  一月", "  二月", "  三月",
				  "  四月", "  五月", "  六月", "  七月",
				  "  八月", "  九月", "  十月", "十一月",
				  "十二月"};
	printf("   %d                %s\n", y, st[m]);
	printf("  ----------------------------\n");
	return 0;
}

int ryear(int y) {
	if ((y%400 == 0) || ((y%100!=0) && (y%4==0)))
		return 1;
	else return 0;
}

int mday(int y, int m){
	int day[] = {0, 31, 28, 31, 30, 31, 30, 31,
						   31, 30, 31, 30, 31};
	int ad = 0;
	if(m == 2)
		ad = ryear(y);
	return day[m] + ad;
}

int monday(int y, int m) {
	int md = 6, i, daynum;
	for(i = 1916; i < y; ++i){
		daynum = 365+ryear(i);
		md = (md+daynum)%7;
	}
	for(i = 1; i < m; ++i){
		md = (md+mday(y, i))%7;
	}
	return md;
}

int prmonth(int y, int m){
	int md = monday(y, m);
	int daysnum = mday(y, m);
	int days = daysnum+md;
	int i;
	yam(y, m);
	printf("   日  一  二  三  四  五  六");

	for (i = 0; i < days; ++i) {
		 
		if(i % 7 == 0) printf("\n\n ");
		if((i - md)>=0)
			printf("  %2d", i-md+1);
		else printf("    ");
	}
	printf("\n\n");
	
	return 0;
}

int main()
{
	//freopen("cal.txt", "w", stdout);
	int y, m, t;
	begin:;
	scanf("%d%d%d", &y, &m, &t);
	if (y < 100) y+=2000;
	if(y< 1916 || m > 200) {
		printf("ERROR");
		goto begin;
	}
	pr(y, m, t);
	//close(stdout);
	return 0;
}
