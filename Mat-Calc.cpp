#include <iostream>
#include<cstdlib>
#include<sstream>
#include <math.h>
#include <string>
using namespace std;

float det(float n1[][100],int r1 ,int c1)
{
	int i, j, k;

	if (r1 == 2)
	{

		float d;
		d = (n1[0][0] * n1[1][1]) - (n1[0][1] * n1[1][0]);
		return d;
	}
	if (r1 == 3)
	{
		float d;
		d = (n1[0][0] * ((n1[1][1] * n1[2][2]) - (n1[1][2] * n1[2][1])))
			- (n1[0][1] * ((n1[1][0] * n1[2][2]) - (n1[2][0] * n1[1][2])))
			+ (n1[0][2] * ((n1[1][0] * n1[2][1]) - (n1[1][1] * n1[2][0])));
		return d;
	}

	if (r1 != 2 && r1 != 3)
	{
		float d = 1, f = 0; j = 0;

		for (j = 0; j < r1; f = 0)
		{
			for (i = j; i <= r1; i++)
			{
				if (n1[i + 1][j] == 0)
					break;

				f = n1[i + 1][j] / n1[j][j];
				for (k = 0; k < c1; k++)
				{
					n1[i + 1][k] -= (n1[j][k] * f);
				}

			}
			j++;
		}



		for (int l = 0; l < r1; l++)
		{
			d *= n1[l][l];
		}

		return  d;
	}
}




int test(string a, int r, int c)
{
	int sp = 1;
	for (int j = 1; j < a.length(); j++)
	{
		if (a[j] == ' ')
			sp++;
		if (a[j] == ';' || a[j] == ']')
		{
			if (sp != c)
			{
				return 1;

			}
			if (sp == c)
				sp = 1;
		}
	}
	return 0;
}


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
void sort(string a, string m[][100])
{
	int i = 0, j = 0;

	for (int p = 0; p < a.length(); p++)
	{
		if (a[p] != ' '&& a[p] != '['&& a[p] != ']'&& a[p] != ';')
			m[i][j] += a[p];
		else if (a[p] == ' ')
			j++;
		else if (a[p] == ';')
		{
			i++;
			j = 0;
		}
	}
}


void print(float arr[][100], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		if (i == 0)
			cout << "[";
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j];
			if (j != (c - 1))
				cout << " ";
		}
		if (i != (r - 1))
			cout << ";";
		if (i == (r - 1))
			cout << "]";
	}
}

void tprint(float arr[][100], int r, int c)
{
	for (int i = 0; i < c; i++)
	{
		if (i == 0)
			cout << "[";
		for (int j = 0; j < r; j++)
		{
			cout << arr[j][i];
			if (j != (r - 1))
				cout << " ";
		}
		if (i != (c - 1))
			cout << ";";
		if (i == (c - 1))
			cout << "]";
	}
}



int main()
{
	string s1, s2; int r1, r2, c1, c2; int i, j, k, q, x, y, z, flag;
	string op, n; float p;
	float n1[100][100]; string m1[100][100];
	float n2[100][100]; string m2[100][100];
	float n3[100][100];

	getline(cin, s1);
	sort(s1, m1);
	dim(s1, r1, c1);
	conv(m1, n1, r1, c1);
	getline(cin, op);
	if (test(s1, r1, c1))
	{
		cout << "ERROR";
	}

	else
	{
		if (op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/')
		{
			getline(cin, s2);
			sort(s2, m2);
			dim(s2, r2, c2);
			conv(m2, n2, r2, c2);
		}
		else if (op[0] == '^')
		{
			getline(cin, n);
			p = atof(n.c_str());
		}
		if (op[0] == '+')
		{
			if (r1 == r2 && c1 == c2)
			{
				for (i = 0; i < r1; i++)
				{
					for (j = 0; j < c1; j++)
					{
						n3[i][j] = n1[i][j] + n2[i][j];
					}
				}
				print(n3, r1, c1);
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
						n3[i][j] = n1[i][j] - n2[i][j];
					}
				}
				print(n3, r1, c1);
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
						for (k = 0; k < c1; k++)
							n3[i][j] += (n1[i][k] * n2[k][j]);
					}
				}
				print(n3, r1, c2);
			}
			else cout << "ERROR";
		}

		if (op[0] == 'T')
		{
			tprint(n1, r1, c1);
		}

		if (op[0] == '^')
		{
			if (c1 == r1)
			{
				for (q = 1; q < (p + 1); q++)
				{
					for (i = 0; i < r1; i++)
					{
						for (j = 0; j < c1; j++)
						{
							for (k = 0; k < c1; k++)
							{
								if (q == 1)
								{
									n3[i][j] += (n1[i][k] * n1[k][j]);
								}
								if ((q % 2) == 0)
								{
									n2[i][j] += (n3[i][k] * n1[k][j]);
								}
								if (q % 2 != 0)
									n3[i][j] += (n2[i][k] * n1[k][j]);
							}
						}
					}
					if (q != p)
					{
						if ((q % 2) == 0)
						{
							for (x = 0; x < r1; x++)
							{
								for (y = 0; y < c1; y++)
								{
									n3[x][y] = 0;
								}
							}
						}
						if ((q % 2) != 0)
						{
							for (x = 0; x < r1; x++)
							{
								for (y = 0; y < c1; y++)
								{
									n2[x][y] = 0;
								}
							}
						}
					}
				}

				if ((q % 2) == 0)
					print(n2, r1, c1);
				if ((q % 2) != 0)
					print(n3, r1, c1);
			}
			else cout << "ERROR";
		}

		if (op[0] == 'D')
		{
			if (r1 == c1)
			{
				cout << det(n1, r1, c1);
			}
			else
				cout << "ERROR";
		}

		if (op[0] == 'I')
		{
			if (det(n1, r1, c1) != 0)
			{
				for (i = 0; i < r1; i++)
				{
					for (j = 0; j < r1; j++)
					{
						n1[i][j + r1] = 0;
					}

				}

				j = r1;
				for (i = 0; i < r1; i++)
				{
					n1[i][i+r1] = 1;
				}

				float f;

				for (q = 0; q <r1; q++)
				{
					f = n1[q][q];
					for (k = 0; k < (r1+q+1); k++)
					{
						n1[q][k] /= f;
					}
					float p;
					for (i = 0; i < r1; i++)
					{
						if (i == q)
							continue;
						p= n1[i][q] / n1[q][q];

						for (k = 0; k < (2*c1); k++)
						{
							n1[i][k] -= (n1[q][k] * p);
						}

					}
				}
				for (i = 0; i < r1; i++)
				{
					for (j = 0; j < r1; j++)
					{
						n1[i][j] = n1[i][j + r1];
					}

				}
				print(n1, r1, c1);
			}
			else
				cout << "ERROR";


		}
		if (op[0] == '/')
		{
			if (c1 == r2)
			{
				if (det(n2, r1, c1) != 0)
				{
					for (i = 0; i < r1; i++)
					{
						for (j = 0; j < r1; j++)
						{
							n2[i][j + r1] = 0;
						}

					}

					j = r1;
					for (i = 0; i < r1; i++)
					{
						n2[i][i + r1] = 1;
					}

					float f;

					for (q = 0; q < r1; q++)
					{
						f = n2[q][q];
						for (k = 0; k < (r1 + q + 1); k++)
						{
							n2[q][k] /= f;
						}
						float p;
						for (i = 0; i < r1; i++)
						{
							if (i == q)
								continue;
							p = n2[i][q] / n2[q][q];

							for (k = 0; k < (2 * c1); k++)
							{
								n2[i][k] -= (n2[q][k] * p);
							}

						}
					}
					for (i = 0; i < r1; i++)
					{
						for (j = 0; j < r1; j++)
						{
							n2[i][j] = n2[i][j + r1];
						}

					}

					for (i = 0; i < r1; i++)
					{
						for (j = 0; j < c2; j++)
						{
							for (k = 0; k < c1; k++)
								n3[i][j] += (n1[i][k] * n2[k][j]);
						}
					}
					print(n3, r1, c2);


				}
				else
					cout << "ERROR";

			}
			else
				cout << "ERROR";
		}
	}

	system("pause");

	return 0;
}
