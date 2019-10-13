


/*
  N�����аڳ�һ�ţ�ÿ�����ж����Լ�����ɫ�������ڷŵ���ɫ��ͬ�ķ���Ϊһ������顱�����磺
  1 2 2 2 2 3 3 3 3 1  ��ʾ���ĸ�����顱��
  ���ÿ�ε��һ������顱��������顱����k�����У���һ��k*k�����֣�������ܻ�õ������֡�
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct Block {
	int color;
	int len;
};

struct Block segment[200];
int score[200][200][200];   //��Ž���������ظ�����

int click_box(int start, int end, int extra_len) {
	int i, result, temp;
	if (score[start][end][extra_len] > 0) {
		return score[start][end][extra_len];
	}
	result = segment[end].len + extra_len;
	result = result*result;  //end�� extra_lenһ����ȥ��ĵ÷�
	if (start == end) {
		score[start][end][extra_len] = result;
		return score[start][end][extra_len];
	}
	result = result + click_box(start, end - 1, 0);

	for (i = end - 1; i >= start; i--) {
		if (segment[i].color != segment[end].color) {
			continue;
		}
		temp = click_box(start, i, segment[end].len + extra_len) + click_box(i + 1, end - 1, 0);
		if (temp > result) {
			result = temp;
		}
	}
	score[start][end][extra_len] = result;
	return score[start][end][extra_len];
}

int main() {
	int t, n, i, j, end, color;
	cin >> t;   //������������

	for (i = 0; i < t; i++) {
		cin >> n;    //��������
		end = 0;     //�������
		cin >> segment[end].color;
		segment[end].len = 1;
		for (j = 1; j < n; j++) {
			cin >> color;
			if (segment[end].color == color) {
				segment[end].len++;
			}
			else {
				end++;
				segment[end].len = 1;
				segment[end].color = color;
			}
		}
		memset(score, 0, sizeof(score));
		cout << "Case��" << i + 1 << " " << click_box(0, end, 0) << endl;
	}

	system("pause");
	return 0;
}