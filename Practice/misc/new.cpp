#include<iostream>
using namespace std;
int main()
{
	int upperheight;
	cout << "Enter upper height of the kite \n";
	cin >> upperheight;
	int radius = 2 * upperheight;

	//-----Upper Portion of the Kite---

	for (int i = 0; i <= upperheight; i++)
	{
		for (int j = -radius; j <= radius; j++)
		{
			if (j + i * 2 == 0 || j - i * 2 == 0)
			{
				cout << "*";
			}
			else
			{
				if (j == 0)
				{
					cout << "|";
				}
				if (i == upperheight)
				{
					cout << "-";
				}
				if (j != 0 && i != upperheight)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	//----Lower Part of Kite---
	for (int i = upperheight * 2; i >= 0; i--)
	{
		for (int j = -radius; j <= radius; j++)
		{
			if (j + i == 0 || j - i == 0)
			{
				cout << "*";
			}
			else
			{
				if (j == 0)
				{
					cout << "|";
				}
				else
				{
					cout << " ";
				}
			}

		}
		cout << endl;
	}
}