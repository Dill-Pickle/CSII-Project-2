#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;

void show(int[], int);
void creatures(int[], int, int, int, int, int);
void move(int[], int, int, int, int, int);
void gameover();

void main()
{
	srand(time(0));
	const int N = 10;
	int road[N];
	int hero_pos = 0;
	int one = 0;
	int two = 0;
	int three = 0;

	for (int i = 0; i < N; i++) road[i] = 0;

	show(road, N);
	creatures(road, N, hero_pos, one, two, three);
	move(road, N, hero_pos, one, two, three);
}

void show(int road[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << road[i];
	}
	cout << endl;
}

void creatures(int road[], int N, int hero_pos, int one, int two, int three)
{
	hero_pos = 0;
	one = rand() % 9 + 1;
	two = rand() % 9 + 1;
	three = rand() % 9 + 1;

	road[hero_pos] = 10;

	do
	{
		one = rand() % 9 + 1;
		two = rand() % 9 + 1;
		three = rand() % 9 + 1;
	} while (one == two || one == three || two == three);

	int numbers[3] = { one, two, three };
	int temp;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (numbers[j] <= numbers[i])
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}


	road[numbers[0]] = 3;
	road[numbers[1]] = 7;
	road[numbers[2]] = 5;

	for (int i = 0; i < N; i++)
	{
		cout << road[i];
	}

}

void move(int road[], int N, int hero_pos, int one, int two, int three)
{
	char answer;
	int monsterkilled = 0;
	int heropow = 10;
	int monster;
	int hero;


	for (int i = 0; hero_pos != 9; i++)
	{
		cout << "Do you want to move: Left(l), Right(r), or Quit(q) the game?" << endl;
		cin >> answer;
		if (answer == 'L' || answer == 'l')
		{
			if (hero_pos == 0)
			{
				cout << "You cannot go left." << endl;
			}
			else hero_pos -= 1;
		}
		else if (answer == 'R' || answer == 'r')
		{
			if (hero_pos == 9)
			{
				cout << "You cannot go any further." << endl;
			}
			if (hero_pos == one || hero_pos == two || hero_pos == three)
			{
				cout << "You have come across a Monster!" << endl;

				if (hero_pos == one)
				{
					for (int i = 0; heropow != 0 || hero < monster; i++){
						hero = rand() % heropow;
						monster = rand() % 3;

						cout << "Hero rolled a " << hero << " Monster rolled a " << monster;
						while (hero == monster)
						{
							hero = rand() % heropow;
							monster = rand() % 3;

							cout << "Hero rolled a " << hero << " Monster rolled a " << monster;
						}
						if (hero < monster)
						{
							cout << "You LOST" << endl;
							hero = monster - hero;
							heropow -= hero;
						}
					
					if (hero > monster)
					{
						cout << "You Won!" << endl;
						monsterkilled++;
					}
					}
				}
					if (hero_pos == two)
					{
						hero = rand() % heropow;
						monster = rand() % 5;

						cout << "Hero rolled a " << heropow << " Monster rolled a " << monster;
						while (hero == monster)
						{
							hero = rand() % heropow;
							monster = rand() % 5;

							cout << "Hero rolled a " << hero << " Monster rolled a " << monster;
						}
						if (heropow < monster)
						{
							cout << "You LOST" << endl;
								heropow -= monster;
							hero_pos = heropow;
						}
						if (hero > monster)
						{
							cout << "You Won!" << endl;
							monsterkilled++;
						}
					}
					if (hero_pos == three)
					{
						hero = rand() % heropow;
						monster = rand() % 7;

						cout << "Hero rolled a " << heropow << " Monster rolled a " << monster;
						while (hero == monster)
						{
							hero = rand() % heropow;
							monster = rand() % 7;

							cout << "Hero rolled a " << hero << " Monster rolled a " << monster;
						}
						if (heropow < monster)
						{
							cout << "You LOST" << endl;
								heropow -= monster;
							hero_pos = heropow;
						}
						if (hero > monster)
						{
							cout << "You Won!" << endl;
							monsterkilled++;
						}
					}
				}
				else hero_pos += 1;
			}
			else if (answer == 'q' || answer == 'Q')
			{
				exit(0);
			}

			if (heropow == 0)
			{
				cout << "Your strength has ran out, warrior! Game over" << endl;
				exit(0);
			}

			if (monsterkilled == 3)
			{
				cout << "You have killed all the monsters! Good job" << endl;
				exit(0);
			}
		}
	}
