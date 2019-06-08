//https://www.nowcoder.com/practice/82424d93369649b98720743c25edc6ce?tpId=3&tqId=10871&tPage=1&rp=&ru=/ta/hackathon&qru=/ta/hackathon/question-ranking
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//�������
/**
*num1 ����1
*num2 ����2
*return ����ַ���
*/
string BigMutiple(string num1, string num2)
{
	string res = "";

	//��������λ��
	int m = num1.size(), n = num2.size();

	//һ��iλ������һ��jλ�������������i+j-1λ��
	vector<long long> tmp(m + n - 1);

	//ÿһλ���еѿ����˷�
	for (int i = 0; i < m; i++) 
	{
		int a = num1[i] - '0';
		for (int j = 0; j < n; j++) 
		{
			int b = num2[j] - '0';
			tmp[i + j] += a*b;
		}
	}
	//���н�λ����ע������Ǵ��Ҳ���С
	int carry = 0;
	for (int i = tmp.size() - 1; i >= 0; i--)
	{
		int t = tmp[i] + carry;
		tmp[i] = t % 10;
		carry = t / 10;
	}
	//����������Ȼ�н�λ
	while (carry != 0) 
	{
		int t = carry % 10;
		carry /= 10;
		tmp.insert(tmp.begin(), t);
	}
	//��������뵽����ֵ��
	for (auto a : tmp)  //���ڷ�Χ��forѭ����a����Ϊtmp��Ԫ��
	{
		res = res + to_string(a);  //����ֵת��Ϊ�ַ�
	}
	if (res.size() > 0 && res[0] == '0')
	{
		return "0";
	}
	return res;
}

//���Ժ���
int main()
{
	string num1, num2, temp, str;
	temp = "628";
	int m;
	while (cin >> num1 >> num2) 
	{
		str = BigMutiple(temp, num2);
		m = str.size();
		str.erase(str.begin() + m - 2, str.end());
		if (num1 <= str)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}