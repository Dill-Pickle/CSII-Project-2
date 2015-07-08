#include <iostream>
#include <time.h>
#include <string>
using namespace std;

void show(int [],int);
void creatures(int [], int, int, int, int, int);
void move(int[],int,int,int,int,int);
void gameover();

void main()
{
	srand(time(0));
	const int N = 10;
	int road[N];
	int hero_pos=0;
	int one=0;
	int two=0;
	int three=0;

	for (int i = 0; i < N; i++) road[i] = 0;

	show(road, N);
	creatures(road, N, hero_pos, one, two,three);
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

void creatures(int road[], int N,int hero_pos, int one, int two, int three)
{
	hero_pos = 0;
	one= rand() % 9 + 1;
	two = rand() % 9 + 1;
	three = rand() % 9 + 1;

	road[hero_pos] = 10;

	do
	{
		one = rand() % 9 + 1;
		two = rand() % 9 + 1;
		three = rand() % 9 + 1;
	} while (one == two || one == three || two==three);

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
		

	road[numbers[0]]=3;
	road[numbers[1]] = 7;
	road[numbers[2]] = 5;

	for (int i = 0; i < N; i++)
	{
		cout << road[i];
	}
	
}

void move(int road[], int N, int hero_pos,int one, int two, int three)
{
	char answer;

	cout << "Do you want to move: Left(l), Right(r), or Quit(q) the game?" << endl;
	cin >> answer;

	for (int i = 0; hero_pos == 9; i++)
	{
		if (answer == 'L' || answer== 'l')
		{
			if (hero_pos == 0)
			{
				cout << "You cannot go left." << endl;
			}
			else hero_pos -= 1;
		}
		else if (answer == 'R' || 'r')
		{
			if (hero_pos == 9)
			{
				cout << "You cannot go any further." << endl;
			}
			if (hero_pos == one || hero_pos == two || hero_pos == three)
			{
				cout << "You have come across a Monster!" << endl;
			}
			else hero_pos += 1;
		}
	}
}
