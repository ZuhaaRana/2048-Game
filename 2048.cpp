#include<iostream>
#include<string>
using namespace std;

void print(int ARR[][4])
{
	cout << "\n\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "    " << ARR[i][j] ;
		}
		cout << endl;
	}
}

void UP(int GAME[][4])
{
	int i, J, var_l, var_r;
	for (J = 0; J < 4; J++)
	{
		var_l = 0, var_r = J;
		for (i = 1; i < 4; i++)
		{
			if (GAME[i][J] != 0)
			{
				if (GAME[i - 1][J] == 0 || GAME[i - 1][J] == GAME[i][J])
				{
					if (GAME[var_l][var_r] == GAME[i][J])
					{
						GAME[var_l][var_r] *= 2;
						GAME[i][J] = 0;
					}
					else
					{
						if (GAME[var_l][var_r] == 0)
						{
							GAME[var_l][var_r] = GAME[i][J];
							GAME[i][J] = 0;
						}
						else
						{
							GAME[++var_l][var_r] = GAME[i][J];
							GAME[i][J] = 0;
						}
					}
				}
				else var_l++;
			}
		}
	}


}


void DOWN(int GAME[4][4])
{
	int i, X, li, ri;
	for (X = 0; X < 4; X++)
	{
		li = 3, ri = X;
		for (i = 2; i >= 0; i--)
		{
			if (GAME[i][X] != 0)
			{
				if (GAME[i + 1][X] == 0 || GAME[i + 1][X] == GAME[i][X])
				{
					if (GAME[li][ri] == GAME[i][X])
					{
						GAME[li][ri] *= 2;
						GAME[i][X] = 0;
					}
					else
					{
						if (GAME[li][ri] == 0)
						{
							GAME[li][ri] = GAME[i][X];
							GAME[i][X] = 0;
						}
						else
						{
							GAME[--li][ri] = GAME[i][X];
							GAME[i][X] = 0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void LEFT(int GAME[4][4])
{
	int i, X, li, ri;
	for (i = 0; i < 4; i++)
	{
		li = i, ri = 0;
		for (X = 1; X < 4; X++)
		{
			if (GAME[i][X] != 0)
			{
				if (GAME[i][X - 1] == 0 || GAME[i][X - 1] == GAME[i][X])
				{
					if (GAME[li][ri] == GAME[i][X])
					{
						GAME[li][ri] *= 2;
						GAME[i][X] = 0;
					}
					else
					{
						if (GAME[li][ri] == 0)
						{
							GAME[li][ri] = GAME[i][X];
							GAME[i][X] = 0;
						}
						else
						{
							GAME[li][++ri] = GAME[i][X];
							GAME[i][X] = 0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void RIGHT(int GAME[4][4])
{
	int i, X, li, ri;
	for (i = 0; i < 4; i++)
	{
		li = i, ri = 3;
		for (X = 2; X >= 0; X--)
		{
			if (GAME[i][X] != 0)
			{
				if (GAME[i][X + 1] == 0 || GAME[i][X + 1] == GAME[i][X])
				{
					if (GAME[li][ri] == GAME[i][X])
					{
						GAME[li][ri] *= 2;
						GAME[i][X] = 0;
					}
					else
					{
						if (GAME[li][ri] == 0)
						{
							GAME[li][ri] = GAME[i][X];
							GAME[i][X] = 0;
						}
						else
						{
							GAME[li][--ri] = GAME[i][X];
							GAME[i][X] = 0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int GAME[4][4])
{
	int li, ri;
	//srand(time(0));
	while (1)
	{
		li = rand() % 4;
		ri = rand() % 4;
		if (GAME[li][ri] == 0)
		{
			GAME[li][ri] = pow(2, li % 2 + 1);
			break;
		}
	}

}

int check(int tmp[4][4], int GAME[4][4])
{
	int fl = 1, i, X;
	for (i = 0; i < 4; i++)
		for (X = 0; X < 4; X++)
			if (tmp[i][X] != GAME[i][X])
			{
				fl = 0;
				break;
			}
	return fl;
}

int main()
{
	int Co;
	int GAME[4][4] = { 0 }, tmp[4][4] = { 0 };
	cout << "\n\n\t2048 GAME\n";
	print(GAME);
	cout << "\n\n PRESS 1 TO START GAME.\t   ";
	cin >> Co;
	int A, B, C, D;
	srand(0);
	A = rand() % 4;
	B = rand() % 4;
	while (1)
	{
		C = rand() % 4;
		D = rand() % 4;
		if (C != A && D != B) break;
	}
	GAME[A][B] = 2;
	GAME[C][D] = 4;
	print(GAME);
	char choice;
	if (Co == 1)
	{
		while (1)
		{
			for (int i = 0; i < 4; i++)
				for (int X = 0; X < 4; X++)
					tmp[i][X] = GAME[i][X];

			cout << "\n PRESS W TO MOVE UPWARD.\n PRESS S TO MOVE DOWNWARD.";
			cout<<"\n PRESS D TO MOVE RIGHTWARDS.\n PRESS A TO MOVE LEFTWARDS.\n\n";
			cout << " ENTER your choice : \n";
			cin >> choice;
			if (choice == 'W')
			{
				UP(GAME);
			}
			else if (choice == 'S')
			{
				DOWN(GAME);
			}
			else if (choice == 'A')
			{
				LEFT(GAME);
			}
			else if (choice == 'D')
			{
				RIGHT(GAME);
			}
			if (!check(tmp, GAME))
				addblock(GAME);
			print(GAME);
		}
	}
	return 0;
}
