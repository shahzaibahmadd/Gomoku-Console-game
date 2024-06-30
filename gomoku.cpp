
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <fstream>

using namespace std;

#define cap 50


void Init(char B[][cap],  int& Dim,  int& NOP,  int& winc,  char sym[],  string names[],  int& turn)  
{
	cout <<  "Dimension of board: ";
	cin >>  Dim;
	cout  << "Number of Player: ";
	cin  >> NOP;
	for  (int i = 0;  i < Dim; i++)
	{
		 for  (int j = 0;  j < Dim; j++) 
		{
			B[i][j] = '-';
		}
	}
	for (int i = 0;  i < NOP; i++)
	{
		cout  <<  "  Player " << i + 1 << " Name: "  ;
		cin >> names[i];
		cout <<  "Player " << i + 1 << " Symbol: ";
		cin >>  sym[i];
	}
	cout <<  "Max Win: ";
	cin >> winc;
	srand(time(NULL));
	turn = rand() % NOP;
}
void  print(char B[][cap],  int Dim)
{
	for (int i = 0;  i < Dim; i++) 
	{
		for  (int j = 0; j < Dim; j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
} 


void  input(int Dim, int& r, int& c)
{

	cout << "Select Row from(1..." << Dim << "): ";
	cin >> r;
	r = r - 1;
	cout << "Select Column from(1..." << Dim << "): ";
	cin >> c;
	c = c - 1;
}
bool Valid(char B[][cap], int Dim, int r, int c)
{
	if (B[r][c] != '-') {
		return false;
	}
	if (r > Dim || c > Dim)
	{
		return false;
	}
	else {
		return true;
	}
}
bool
void  msg(string name) 
{
	cout << name << "'s Turn..Please enter: " << endl;
}

void move(char B[][cap], int r, int c, char sym) 
{
	B[r][c] = sym;
}
void turn(int& turn, int NOP) 
{
	turn = (turn + 1) % NOP;
}
horizontal(char B[][cap], int Dim, char PSym, int WC, int ri, int ci)
{
	if  (ci +  WC >= Dim) 
	{
		 return false;
	}
	for  (int i = 0;  i < WC;  i++)
	{
		if  (B[ri][ci + i] !=  PSym) 
		{
			return false;
		}
	}
	return true;
}
bool vertical(char B[][cap], int Dim, char PSym, int WC, int ri, int ci) 
{
	  if (ri +  WC >= Dim)
	  {
		 return false;
	}
	for (int i = 0; i < WC; i++)
	{
		  if (B[ri + i][ci] != PSym) 
		   {
			  return false;
		 }  
	}
	return true;
} 


bool L2R(char B[][cap], int Dim, char PSym, int WC, int ri, int ci) 
{
	if (ci + WC - 1 >= Dim || ri + WC - 1 >= Dim) 
	{
		return false;
	}
	for (int i = 0; i < WC; i++) 
	{
		if (B[ri + i][ci + i] != PSym) 
		{
			return false;
		}
	}
	return true;
}



bool R2L(char B[][cap], int Dim, char PSym, int WC, int ri, int ci)
{
	if (ci + WC >= Dim) 
	{
		return false;
	}
	for (int i = 0; i < WC; i++)
	{
		if (B[ri + i][ci - i] != PSym) 
		{
			return false;
		}
	}
	return true;
}
bool do_win(char B[][cap], int Dim, char PSym, int WC, int ri, int ci) 
{

	if (horizontal(B, Dim, PSym, WC, ri, ci) == true) 
	{
		return true;
	}
	else if (vertical(B, Dim, PSym, WC, ri, ci) == true)
	{
		return true;
	}
	else if (L2R(B, Dim, PSym, WC, ri, ci) == true)  
	{
		return true;
	}
	else if (R2L(B, Dim, PSym, WC, ri, ci) == true)  
	{
		return true;
	}
	else  {
		return false;
	}
}
bool win(char B[][cap], int Dim, char Psym, int winc) {
	for (int i = 0; i < Dim; i++)
	{
		for (int j = 0; j < Dim; j++) 
		{
			if (do_win(B, Dim, Psym, winc, i, j))
			{
				return true;
			}
		}
	}
	return false;
}

bool draw(char B[][cap], int Dim)
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (B[ri][ci] == '-')
			{
				return false;
			}
		}
	}
	return true;
}




int main()
{

	int Dim, NOP, r, c, winc = 0;
	bool over = false;
	int winner = -1;
	char B[cap][cap];
	char Sym[cap];
	string names[cap];
	int Turn;
	Init(B, Dim, NOP, winc, Sym, names, Turn);
	print(B, Dim);
	bool isValid = false;
	do {
		msg(names[Turn]);
		do {
			input(Dim, r, c);
			if (isValid = (!Valid(B, Dim, r, c)))
			{
				cout << "Error.....its out of range\nEnter Again: " << endl;
			}
		} while (isValid);
		move(B, r, c, Sym[Turn]);
		system("cls");
		print(B, Dim);
		over = win(B, Dim, Sym[Turn], winc);
		if (over == true) 
		{
			winner = Turn;
		}
		if (over == false)
		{
			over = draw(B, Dim);
		}
		if (over == false) 
		{
			turn(Turn, NOP);
		}
	} while (!over);
	if (winner == -1)
	{
		cout << "Game draw. better luck next time";
	}
	else 
	{
		cout << names[winner] << " is winner!";
	}
	return 0;



}
