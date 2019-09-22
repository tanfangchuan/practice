
//https://www.nowcoder.com/practice/93f6c5b032bf473696373ab0d834b0fc?tpId=98&tqId=32897&tPage=4&rp=4&ru=/ta/2019test&qru=/ta/2019test/question-ranking
#include<iostream>
#include<string>
using namespace std;

void palindrome_length(string& str)
{
	for (int i = 0; i <= str.size(); i = i + 2)
	{
		str.insert(i, 1, '#');
	}
	int len = str.size();   //������ַ�������
	int rightside = 0;      //�ұ߽�
	int rightSidecenter = 0;//�ұ߽��Ӧ���Ĵ�����
	int *halflenArr = new int[len]();  //������ÿ���ַ�Ϊ���ĵĻ��Ĵ����ȵ�һ��
	int center = 0;         //��¼��������
	int longestHalf = 0;    //��¼����ĳ���
	bool needcalc;
	for (int i = 0; i < len; i++)
	{
		needcalc = true;
		if (rightside > i)  //������ұ߽�ĸ���֮��
		{
			int leftCenter = rightSidecenter * 2 - i;  // �������rightSideCenter�ĶԳ�λ��
			halflenArr[i] = halflenArr[leftCenter];    //���ݻ������ʵõ����Գƣ�
			if (i + halflenArr[i] > rightside)      // ����������ұ߽磬���е���
			{
				halflenArr[i] = rightside - i;
			}
			if (i + halflenArr[i] < rightside)   // ���������֪��������ó��������С���ұ߽磬����Ҫ��չ��
			{
				needcalc = false;
			}
		}
		if (needcalc)
		{
			while (i - 1 - halflenArr[i] >= 0 && i + 1 + halflenArr[i] < len)
			{
				if (str[i + 1 + halflenArr[i]] == str[i - 1 - halflenArr[i]])
				{
					halflenArr[i]++;
				}
				else
				{
					break;
				}
			}

			// �����ұ߽缰����
			rightside = i + halflenArr[i];
			rightSidecenter = i;

			// ��¼����Ĵ�
			if (halflenArr[i] > longestHalf)
			{
				center = i;
				longestHalf = halflenArr[i];
			}
		}
	}
	for (int i = center - longestHalf + 1; i <= center + longestHalf; i = i + 2)
	{
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		palindrome_length(str);
	}
	system("pause");
	return 0;
}