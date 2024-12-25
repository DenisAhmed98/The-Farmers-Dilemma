#include <iostream>
using namespace std;

bool check(int *tempe,int *tempw)
{
	for (int i=0; i<2;i++){
		if ((tempe[i] == 1 && tempe[i + 1] == 2) || (tempe[i] == 2 && tempe[i + 1] == 3) || 
			(tempw[i] == 1 && tempw[i + 1] == 2) || (tempw[i] == 2 && tempw[i + 1] == 3))
		{
			return false;
		}
		
	}
	return true;
}

void reset(int *east, int *west, int *tempe, int *tempw)
{
	for (int i = 0; i < 3; i++)
	{
		tempe[i] = east[i];
		tempw[i] = west[i];

	}
}

void solve(int *east, int *west)
{
	int tempe[3];
	int tempw[3];
	bool tempc;
	int end = 0;
	if (end == 3) {
		cout << "1success" << endl;
	}
	else
	{
		reset(east, west,tempe,tempw);
		while (end<3)
		{ 
			for (int i = 0; i < 3; i++)
			{
				if (end > 3) {
					cout << "2success" << endl;
				}
				if (tempw[i] == 0) {
					tempw[i] = tempe[i];
					tempe[i] = 0;
					tempc = check(tempe, tempw);
					if (tempc == false && end < 1)
					{
						reset(east, west, tempe, tempw);
					}
					else end++;

					if (end > 1)
					{
						tempc = check(tempe, tempw);
						if (tempc == false)
						{
							for (int j = 0; j < 1; j++)
							{
								if (tempw[j] == 2) {
									tempe[1] = tempw[j];
									tempw[j] = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		east[i] = tempe[i];
		west[i] = tempw[i];

	}
}

int main()
{
	int goal[3] = { 1,2,3 };
	int east[3] = { 1,2,3 }; // w-wolf g-goat c-cabbage
	int west[3] = { 0,0,0 }; // e-empty
	
	solve(east, west);

	for (int i = 0; i < 3; i++)
	{
		cout << "west" << i << ":" << west[i]<<endl;
	}

	system("pause");
	return 0;
}