#include <iostream>
#include<cstdlib>
#include<sstream>
#include <math.h>
#include <string>
using namespace std;

void conv(string ms[][100], float mf[][100], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			mf[i][j] = atof(ms[i][j].c_str());
		}
	}
}
void dim(string a, int& r, int& c)
{
	r = 1; c = 1; int i, j;
	for (i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ')
			c++;
		if (a[i] == ';')
			break;
	}
	for (j = 0; j < a.length(); j++)
	{
		if (a[j] == ';')
			r++;
	}

}
void sort(string a, string mr[][100], string mi[][100])
{
	int i = 0, j = 0; int flag = 0, subflag = 0;

	for (int p = 0; p < a.length(); p++)
	{

		if (a[p] == '+' || a[p] == '-')
		{
			if (subflag == 0)
				subflag = 1;
			else if (subflag == 1)
				flag = 1;

			}


		if (a[p] != ' ' && a[p] != '[' && a[p] != ']' && a[p] != ';'
			&& a[p] != '+' && a[p] != 'i')
		{
			if (flag && subflag)
				mi[i][j] += a[p];
			else
				mr[i][j] += a[p];
		}

		if (a[p] == ' ')
		{
			if (a[p + 1] == '-')
			{
				subflag = 0;
			}
			else
			{
				subflag = 1;
			}
			j++;
			flag = 0;
		}
		else if (a[p] == ';')
		{
			if (a[p + 1] == '-')
			{
				subflag = 0;
			}
			else
			{
				subflag = 1;
			}
			i++;
			j = 0;
			flag = 0;
		}
	}
	mr[0][0] = "";
	mi[0][0] = "";
	flag = 0;
	subflag = 0;
	for (int v = 1; v < a.length(); v++)
	{
		if (a[v] == ' ')
			break;

		if (a[1] == '+' || a[1] == '-')
		{
			if (v == 1)
				mr[0][0] += a[v];
			if (v != 1)
			{
				if (a[v] == '+' || a[v] == '-')
					flag = 1;
				if (flag)
					mi[0][0] += a[v];
				else  mr[0][0] += a[v];

			}

		}

		if (a[1] != '+' && a[1] != '-')
		{
			if (a[v] == '-' || a[v] == '+')
				flag = 1;
			if (flag)
				mi[0][0] += a[v];
			else
				mr[0][0] += a[v];
		}
	}




}


void cprint(float arr[][100], float iarr[][100], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		if (i == 0)
			cout << "[";
		for (int j = 0; j < c; j++)
		{
			if (iarr[i][j] == 0)
				cout << arr[i][j] << "+" << "0" << "i";
			else if (iarr[i][j] > 0)
				cout << arr[i][j] << "+" << iarr[i][j] << "i";
			else if (iarr[i][j] < 0)

				cout << arr[i][j] << iarr[i][j] << "i";


			if (j != (c - 1))
				cout << " ";

		}
		if (i != (r - 1))
			cout << ";";
		if (i == (r - 1))
			cout << "]";
	}
}



int main()
{
	string s1, s2; int r1, r2, c1, c2; int i, j, k; string op, n; float p;
	float nr1[100][100]; string mr1[100][100];
	float nr2[100][100]; string mr2[100][100];
	float nr3[100][100]; string mi1[100][100];
	float ni1[100][100]; string mi2[100][100];
	float ni2[100][100];
	float ni3[100][100];
	getline(cin, s1);
	sort(s1, mr1, mi1);
	dim(s1, r1, c1);
	conv(mr1, nr1, r1, c1);
	conv(mi1, ni1, r1, c1);
	getline(cin, op);
	if (op[0] == '+' || op[0] == '-' || op[0] == '*')
	{
		getline(cin, s2);

		sort(s2, mr2, mi2);
		dim(s2, r2, c2);
		conv(mr2, nr2, r2, c2);
		conv(mi2, ni2, r2, c2);

	}
	if (op[0] == '+')
	{
		if (r1 == r2 && c1 == c2)
		{
			for (i = 0; i < r1; i++)
			{
				for (j = 0; j < c1; j++)
				{
					nr3[i][j] = nr1[i][j] + nr2[i][j];
					ni3[i][j] = ni1[i][j] + ni2[i][j];

				}
			}
			cprint(nr3, ni3, r1, c1);
		}
		else cout << "ERROR";
	}

	if (op[0] == '-')
	{
		if (r1 == r2 && c1 == c2)
		{
			for (i = 0; i < r1; i++)
			{
				for (j = 0; j < c1; j++)
				{
					nr3[i][j] = nr1[i][j] - nr2[i][j];
					ni3[i][j] = ni1[i][j] - ni2[i][j];
				}
			}
			cprint(nr3, ni3, r1, c1);
		}
		else cout << "ERROR";
	}
	if (op[0] == '*')
	{
		if (c1 == r2)
		{
			for (i = 0; i < r1; i++)
			{
				for (j = 0; j < c2; j++)
				{
					nr3[i][j] = 0; ni3[i][j] = 0;
					for (k = 0; k < c1; k++)
					{
						nr3[i][j] += (nr1[i][k] * nr2[k][j]) -
							(ni1[i][k] * ni2[k][j]);

						ni3[i][j] += (nr1[i][k] * ni2[k][j]) +
							(ni1[i][k] * nr2[k][j]);
					}
				}

			}
			cprint(nr3, ni3, r1, c2);
		}
		else cout << "ERROR";
	}



	return 0;
}
