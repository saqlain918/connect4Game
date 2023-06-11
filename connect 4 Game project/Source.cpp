#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;
//the global variable which is used for inupt name of player
string  player1, player2;
//this function is used for give instruction 
void instruction()
{
	cout << "                                      --------------------------------------------------------" << endl;
	cout << "                                     | * This  game  is  only  for   two    players .       | " << endl;
	cout << "                                     | * Game   consist   on   only   one   mode .          | " << endl;
	cout << "                                     | * Game is End after connect 4 in the given table .   | " << endl;
	cout << "                                      --------------------------------------------------------" << endl;
}
//this is for credits
void credits()
{
	cout << "                                           ------------------------------------------" << endl;
	cout << "                                          | Rai muhammad SAQLAIN                    |" << endl;
	cout << "                                           ------------------------------------------" << endl;
}
bool gamewin(char array[8][8], char i)   //for to check winning condition
{

	bool horizontal = false;  //to check horizontal connection 
	int sumh = 1;   //to check horizontal connect 4
	for (int a = 1; a <= 8; a++)
	{
		for (int b = 1; b <= 8; b++)
		{
			if (array[a][b] == i)
			{
				sumh++;
				if (sumh == 5)
				{
					horizontal = true;
					break;
				}
			}
			else
			{
				sumh = 1;
			}
		}
		sumh = 1;
	}

	bool vertical = false;
	int sumv = 1;
	for (int a = 1; a <= 8; a++)
	{
		for (int b = 1; b <= 8; b++)
		{
			if (array[b][a] == i)
			{
				sumv++;
				if (sumv == 5)
				{
					vertical = true;
					break;
				}
			}
			else
			{
				sumv = 1;
			}
		}
		sumv = 1;
	}
	bool digonal1 = false;
	int digonalsum = 1;
	for (int a = 1; a <= 8; a++)
	{
		if (array[a][a] == i)
		{
			digonalsum++;
		}
	}
	if (digonalsum == 5)
	{
		digonal1 = true;
	}
	bool digonalside2 = false;
	int sum2 = 1;
	int b = 1;
	for (int a = 8; a >= 1; a--)
	{
		if (array[a][b] == i)
		{
			sum2++;
		}
		b++;
	}
	if (sum2 == 5)
	{
		digonalside2 = true;

	}

	if (horizontal || vertical || digonal1 || digonalside2)   //check for if 4 balls connect in these type
	{

		return true;
	}
	else
	{
		return false;
	}
}

bool toss()   //for the toss function 
{
	//this is for generate random numbers
	srand(time(0));
	if ((rand() % 10) % 2 == 0)
	{
		cout << "Player 1 won the toss" << endl;
		return true;
	}
	else
	{
		cout << "Player 2 won the toss" << endl;
		return false;
	}
}

bool drawGame(bool draw)   //draw function to check draw condition 
{
	if (draw == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool placement(char array[8][8], int i)  //for the placement of character 
{
	if (array[0][i] == '*')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void player_name()  //this function for name print
{
	cout << " Enter a Player 1 Name is:";
	cin.ignore();
	getline(cin, player1);
	cout << " Enter a Player 2 Name is:";
	getline(cin, player2);
}
void play()
{
	system("color F4");   //for change of color of compiler
	int n = 0;
	while (n != 4)   //for menu print
	{
		cout << "                                                        -----------------" << endl;
		cout << "                                                       | Connect 4 GAME  |" << endl;
		cout << "                                                        -----------------" << endl;
		cout << "                                                       | 1: INSTRUCTIONS |" << endl;
		cout << "                                                        -----------------" << endl;
		cout << "                                                        -----------------" << endl;
		cout << "                                                       | 2: CREDITS      |" << endl;
		cout << "                                                        -----------------" << endl;
		cout << "                                                       | 3: PLAY  GAME   |" << endl;
		cout << "                                                        -----------------" << endl;
		cout << "                                                       | 4: Exit GAME    |" << endl;
		cout << "                                                        -----------------" << endl;
		cout << "Please chose from menu for play game :  " << endl;
		cin >> n;

		if (n == 1)
		{
			instruction();  //calling function of instruction
		}
		else if (n == 2)
		{
			credits();   //calling function of credits 
		}
		else if (n == 3)
		{
			//this genrate a table or grid of game
			char array[8][8];
			for (int a = 1; a <= 8; a++)
			{
				for (int b = 1; b <= 8; b++)
				{
					array[a][b] = '*';
				}
			}
			for (int a = 1; a <= 8; a++)
			{
				cout << a << " ";
			}
			cout << endl;
			for (int a = 1; a <= 8; a++)
			{
				for (int b = 1; b <= 8; b++)
				{
					cout << array[a][b] << " ";
				}
				cout << endl;
			}
			//declaration of variable used in for play game
			int p1 = 0, p2 = 0;
			int moves = 0;
			bool win = false;
			int column;
			bool draw = true;
			bool k;
			k = toss();
			player_name(); //calling play name function
			while (win == false && moves <= 64)
			{
				if (k == true)
					//for input the column fill 
				{
					k = false;
					cout << "player 1 " << player1 << " turn." << endl;
					cout << "please Enter a Column number for placement : ";
					cin >> column;
					p1++;  //for count number of attempts
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "invalid input " << endl;
						cin >> column;
					}
					while (column < 1 || column>8)  //check for that column must be 1-8
					{
						cout << "plaese enter a coulmn b/w 1 to 8 " << endl;
						cout << "player 1 " << player1 << " turn." << endl;
						cout << "please Enter a Column number for placement : ";
						cin >> column;
						p1++;
					}
					while (placement(array, column) == 1)
					{
						cout << "Coulmn is fill so enter new coulmn" << endl;
						cout << "player 1 " << player1 << " turn." << endl;
						cin >> column;
						p1++;
						while (column < 1 || column>8)
						{
							cout << "plaese enter a coulmn b/w 1 to 8 " << endl;
							cout << "player 1 " << player1 << " turn." << endl;
							cout << "please Enter a Column number for placement : ";
							cin >> column;
							p1++;
						}
					}

					moves++;  //for count total attempts of game
					for (int a = 1; a <= 8; a++)
					{
						if (array[a][column] != '*')
						{
							array[a - 1][column] = '$';  //for place charater in turn of first player
							break;
						}
						else if (a == 8)
						{

							array[a][column] = '$';
							break;
						}
					}

					win = gamewin(array, '$');  //this for assign charcater
					if (win == true)
					{
						system("cls");
						for (int a = 1; a <= 8; a++)
						{
							cout << a << " ";
						}
						cout << endl;
						for (int a = 1; a <= 8; a++)
						{
							for (int b = 1; b <= 8; b++)
							{
								cout << array[a][b] << " ";
							}
							cout << endl;
						}
						cout << "Congratulations! " << player1 << " you win the game " << endl;  //to print for winner player
						cout << "number of attempts of  " << player1 << " is : " << p1 << endl;
						draw = false;

					}
					if (win != true)
					{
						system("cls");
						for (int a = 1; a <= 8; a++)
						{
							cout << a << " ";
						}
						cout << endl;
						for (int a = 1; a <= 8; a++)
						{
							for (int b = 1; b <= 8; b++)
							{
								cout << array[a][b] << " ";
							}
							cout << endl;
						}
					}
				}
				if (k == false)
				{
					k = true;
					if (win != true)  //for the player 2
					{
						cout << "player 2 " << player2 << " turn." << endl;
						cout << "please Enter a Column number for placement : ";
						cin >> column;
						p2++;
						while (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "invalid input " << endl;
							cin >> column;
						}

						while (column < 1 || column>8)
						{
							cout << "plaese enter a coulmn b/w 1 to 8 " << endl;
							cout << "player 2 " << player2 << " turn." << endl;
							cout << "please Enter a Column number for placement : ";
							cin >> column;
							p2++;

						}
						while (placement(array, column) == 1)
						{
							cout << "Coulmn is fill so enter new coulmn" << endl;
							cout << "player 2 " << player2 << " turn." << endl;
							cin >> column;
							while (column < 1 || column>8)
							{
								cout << "plaese enter a coulmn b/w 1 to 8 " << endl;
								cout << "player 2 " << player2 << " turn." << endl;
								cout << "please Enter a Column number for placement : ";
								cin >> column;
								p2++;
							}
						}
						moves++;

						for (int a = 1; a <= 8; a++)
						{
							if (array[a][column] != '*')
							{
								array[a - 1][column] = '#';
								break;
							}
							else if (a == 8)
							{

								array[a][column] = '#';
								break;
							}
						}
						win = gamewin(array, '#');
						if (win == true)
						{
							system("cls");
							for (int a = 1; a <= 8; a++)
							{
								cout << a << " ";
							}
							cout << endl;
							for (int a = 1; a <= 8; a++)
							{
								for (int b = 1; b <= 8; b++)
								{
									cout << array[a][b] << " ";
								}
								cout << endl;
							}
							cout << "Congratulations! " << player2 << " you win the game" << endl;
							cout << "number of attempts of " << player2 << "  is : " << p2 << endl;
							draw = false;
						}
					}

					if (win != true)
					{
						system("cls");

						for (int a = 1; a <= 8; a++)
						{
							cout << a << " ";
						}
						cout << endl;

						for (int a = 1; a <= 8; a++)
						{
							for (int b = 1; b <= 8; b++)
							{
								cout << array[a][b] << " ";
							}
							cout << endl;
						}
					}
				}

			}
			cout << " total moves is : " << moves << endl;
			if (draw == true)
				cout << "Game is Draw.  " << endl;
		}
		else if (n == 4)
		{
			cout << "                                                         ------------- " << endl;
			cout << "                                                        |   Good bye  |" << endl;
			cout << "                                                         ------------- " << endl;
			system("pause");
		}
		else
		{
			cout << " Invlid Input! Enter Again in Given Menu:" << endl;
		}

	}
}

int main()
{
	play();  //calling function
}