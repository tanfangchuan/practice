//https://www.nowcoder.com/practice/0f0badf5f2204a6bb968b0955a82779e?tpId=90&tqId=30777&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string BigMutiple(string num1, string num2)
{
	string res = "";
	int n, m;
	m = num1.size(), n = num2.size();  //��������λ��
	vector<int> temp(m + n - 1);  //һ��iλ������һ��jλ�������������i+j-1λ��
	for (int i = 0; i < m; i++)   //�ѿ����˷�
	{
		int a = num1[i] - '0';
		for (int j = 0; j < n; j++)
		{
			int b = num2[j] - '0';
			temp[i + j] = temp[i + j] + a*b;
		}
	}
	int carry = 0, t;
	for (int i = temp.size() - 1; i >= 0; i--)  //���н�λ����ע������Ǵ��Ҳ���С
	{
		t = temp[i] + carry;
		temp[i] = t % 10;
		carry = t / 10;
	}
	while (carry != 0)  //����������Ȼ�н�λ
	{
		t = carry % 10;
		carry = carry / 10;
		temp.insert(temp.begin(), t);
	}
	for (auto a : temp)   //���ڷ�Χ��forѭ��
	{
		res = res + to_string(a);  //����ֵת��Ϊ�ַ�
	}
	if (res.size() > 0 && res[0] == '0')
	{
		return "0";
	}
	return res;
}
int main()
{
	string str1, str2, str;
	while (cin >> str1 >> str2)
	{
		str = BigMutiple(str1, str2);
		cout << str << endl;
	}
	system("pause");
	return 0;
}