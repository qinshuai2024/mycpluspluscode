#include "Headquarters.h"

void Test1()
{
	int group;
	cin >> group;
	int g = 1;
	while (group--)
	{
		int m, d, n, i, l, w;
		cin >> m;
		cin >> d >> n >> i >> l >> w;
		Headquarters red(m,d,n,i,l,w),blue(m, d, n, i, l, w);
		//1表示红色，2表示蓝色
		bool judgeR = true;
		bool judgeB = true;
		printf("Case:%d\n", g++);
		for (int j = 0; ; j++)
		{	
			if (!judgeR && !judgeB)
				break;
			if (judgeR)
				judgeR = red.WarriorBorn(1, j);
			if (judgeB)
				judgeB = blue.WarriorBorn(2, j);
		}
	}
	
}

int main()
{
	Test1();
	return 0;
}