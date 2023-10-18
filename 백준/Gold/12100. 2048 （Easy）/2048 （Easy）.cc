#include <iostream>
#include <algorithm>
using namespace std;
int N;
int real_board[22][22], board[22][22];
int direction[5];
void CopyBoard()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] = real_board[i][j];
}

void MoveBlockToRight()
{
	for (int i = 1; i <= N; i++)
		for (int j = N; j >1; j--)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = j - 1;
				while (k > 0)
				{
					if (board[i][k] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k--;
				}
				if (check)
				{
					board[i][j] = board[i][k]; // 현재자리에 넣어줌
					board[i][k] = 0;
				}
			}
		}
	for (int i = 1; i <= N; i++)
		for (int j = N; j > 1; j--)
		{
			if (board[i][j] == board[i][j - 1]) //연속된 자리에서 같은거 찾으면 합쳐줌 
			{
				board[i][j] *= 2;
				board[i][j - 1] = 0;
			}
		}
	for (int i = 1; i <= N; i++)
		for (int j = N; j > 1; j--)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = j - 1;
				while (k > 0)
				{
					if (board[i][k] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k--;
				}
				if (check)
				{
					board[i][j] = board[i][k]; // 현재자리에 넣어줌
					board[i][k] = 0;
				}
			}
		}
}
void MoveBlockToLeft()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j < N; j++)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = j + 1;
				while (k <= N)
				{
					if (board[i][k] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k++;
				}
				if (check)
				{
					board[i][j] = board[i][k]; // 현재자리에 넣어줌
					board[i][k] = 0;
				}
			}
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j < N; j++)
		{
			if (board[i][j] == board[i][j + 1]) //연속된 자리에서 같은거 찾으면 합쳐줌 
			{
				board[i][j] *= 2;
				board[i][j + 1] = 0;
			}
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j < N; j++)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = j + 1;
				while (k <= N)
				{
					if (board[i][k] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k++;
				}
				if (check)
				{
					board[i][j] = board[i][k]; // 현재자리에 넣어줌
					board[i][k] = 0;
				}
			}
		}
}
void MoveBlockToUp()
{
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= N; j++)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = i + 1;
				while (k <= N )
				{
					if (board[k][j] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k++;
				}
				if (check)
				{
					board[i][j] = board[k][j]; // 현재자리에 넣어줌
					board[k][j] = 0;
				}
			}
		}
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] == board[i+1][j]) //연속된 자리에서 같은거 찾으면 합쳐줌 
			{
				board[i][j] *= 2;
				board[i+1][j] = 0;
			}
		}
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= N; j++)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = i + 1;
				while (k <= N)
				{
					if (board[k][j] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k++;
				}
				if (check)
				{
					board[i][j] = board[k][j]; // 현재자리에 넣어줌
					board[k][j] = 0;
				}
			}
		}
}

void MoveBlockToDown()
{
	for (int i = N; i > 1; i--)
		for (int j = 1; j <= N; j++)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = i - 1;
				while (k > 0)
				{
					if (board[k][j] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k--;
				}
				if (check)
				{
					board[i][j] = board[k][j]; // 현재자리에 넣어줌
					board[k][j] = 0;
				}
			}
		}
	for (int i = N; i > 1; i--)
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] == board[i - 1][j]) //연속된 자리에서 같은거 찾으면 합쳐줌 
			{
				board[i][j] *= 2;
				board[i - 1][j] = 0;
			}
		}
	for (int i = N; i > 1; i--)
		for (int j = 1; j <= N; j++)
		{
			bool check = false;
			if (board[i][j] == 0) // 현재자리가 0이라면
			{
				int k = i - 1;
				while (k > 0)
				{
					if (board[k][j] != 0)//움직이는 방향으로 0아닌거 찾아서
					{
						check = true;
						break;
					}
					k--;
				}
				if (check)
				{
					board[i][j] = board[k][j]; // 현재자리에 넣어줌
					board[k][j] = 0;
				}
			}
		}
}
void StartGame()
{
	for (int i = 0; i < 5; i++)
	{
		switch (direction[i])
		{
		case 0: 
			MoveBlockToRight();
			break;
		case 1:
			MoveBlockToLeft();
			break;
		case 2:
			MoveBlockToUp();
			break;
		case 3:
			MoveBlockToDown();
			break;
		}
	}
}

int SetDirection(int cnt)
{
	int answer = 0;
	if (cnt >= 5)
	{
		CopyBoard();
		StartGame();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				answer = max(answer, board[i][j]);
		return answer;
	}
	
	for (int i = 0; i < 4; i++)
	{
		direction[cnt] = i;
		answer = max(answer, SetDirection(cnt + 1));
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> real_board[i][j];
	cout << SetDirection(0);



	return 0;
}