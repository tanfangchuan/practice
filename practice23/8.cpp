

//����ֻ�����������
//��С����С�ڵ��� 1 ʱ����ô���Ľ������a + b�ĺ��ٳ���c
//����С������ 1�����������Ȼ�������Ļ�
//����������Ϊ 1�����Ϊ 3
//https://www.nowcoder.com/practice/3e483fe3c0bb447bb17ffb3eeeca78ba?tpId=98&tqId=32836&tPage=1&rp=1&ru=/ta/2019test&qru=/ta/2019test/question-ranking
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int *pt = new int[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> pt[i];
	}
	sort(pt, pt + 3);
	int sum = 0;
	if (pt[0] == 1)
	{
		sum = (pt[0] + pt[1])*pt[2];
	}
	else if (pt[0] == 1 && pt[1] == 1 && pt[2] == 1)
	{
		sum = 3;
	}
	else
	{
		sum = pt[0] * pt[1] * pt[2];
	}
	cout << sum << endl;
	
	system("pause");
	return 0;
}