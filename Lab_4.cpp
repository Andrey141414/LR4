#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include <math.h>
#include<string>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
string NAMES[5] = {"Пешка","Конь", "Слон", "Ладья", "Ферзь"};
class chess_figure {

private:
	
	
	//Если pawn = true: фигура является пешкой, если false, то не пешкой 
	
public:
	string name;
	int value;
	bool pawn = false;
	//функция установки значений
	void Read();
	//функция получения значений
	void Init(int val, string name);
	//функция вывода
	void Display();
	chess_figure* Add(chess_figure a, chess_figure b);
	void compare(chess_figure b);
	void zapolnenie_din_mass(chess_figure* mass, int N);
	void pawn_promotion();
	chess_figure&  operator ++ ();
	chess_figure operator ++ (int);
	chess_figure operator+( chess_figure right);
	
	
};

chess_figure& chess_figure::operator ++ ()
{
	this->value += 2;
	return *this;

}
chess_figure chess_figure::operator ++ (int)
{
	chess_figure buf;
	buf = (*this);
	++(*this);
	return buf;
}
chess_figure chess_figure:: operator+(chess_figure right)
{
	this->value = right.value+this->value;
	return *this;
	
}
void chess_figure::Read()
{


	
	int vibor;
	puts("Название фигуры");
	for (int i = 0; i < 5; i++)
	{
		
		cout<<i+1<<" "<<NAMES[i]<<"\n";

	}

	cin >> vibor;
	name = NAMES[vibor - 1];
	switch (vibor)
	{
	case 1: {value = 1; pawn = true; }break;
	case 2: {value = 3; }break;
	case 3: {value = 3; }break;
	case 4: {value = 5; }break;
	case 5: {value = 9; }break;
	}
	system("cls");
	
}
void chess_figure::Init(int Val, string Name)
{
	value = Val;
	name = Name;
	if (Name == NAMES[0])
		pawn = true;
	else
		pawn = false;
}
void chess_figure::Display()
{

	cout<<name<< " Ценность "<<value<<"\n";
	
	
}
void chess_figure::compare(chess_figure b)
{
	system("cls");
	string comp;



	if (value > b.value)
	{
		comp =" Лучше чем ";
	}
	if (value < b.value)
	{
		comp =" Хуже чем ";
	}
	if (value == b.value)
	{
		comp = " не хуже и не лучше чем ";
	}
	cout<<name<<" "<<comp << " " <<b.name;

}
chess_figure* chess_figure::Add(chess_figure a, chess_figure b)
{
	system("cls");
	
	this->value = a.value + b.value;
	this->name = a.name + " и " + b.name;
	
	return this;
}
void chess_figure::pawn_promotion()
{
	puts("Ваша пешка дошла до конца доски");
	puts("Выбирите фигуру, в которую она превратится");
	int vibor;
	puts("Название фигуры");
	for (int i = 1; i < 5; i++)
	{

		cout << i  << " " << NAMES[i] << "\n";

	}

	cin >> vibor;
	name = NAMES[vibor];
	switch (vibor)
	{
	
	case 1: {value = 3; }break;
	case 2: {value = 3; }break;
	case 3: {value = 5; }break;
	case 4: {value = 9; }break;
	}
	system("cls");

}

//Заполнение динамического массива
void chess_figure::zapolnenie_din_mass(chess_figure* mass, int N)
{
	int size = sizeof(chess_figure);
	
	for (int i = 0; i < N; i++)
	{
		chess_figure t;
		t.name = NAMES[i];
		switch (i)
		{
		case 0: {t.value = 1; }break;
		case 1: {t.value = 3; }break;
		case 2: {t.value = 3; }break;
		case 3: {t.value = 5; }break;
		case 4: {t.value = 9; }break;
		}
		
		
		
		*(mass +  (i))= t;

		
	}
}


/////////////////////////////////////////////////////////////////////////////
class Chess_player
{
private:
//колличество фигур
int numbers  = 0;
string PlayerName;
//РАзряд шахматиста
int rank;


public :
	//сами фигуры
	chess_figure figures[16];
	bool color =true;
	//функция установки значений
	void playerRead();
	//функция получения значений
	void playerInit(string Pn, int numb, chess_figure cf[16], int razryad);
	//функция вывода
	void playerDisplay();
	Chess_player& playerAdd(Chess_player a, Chess_player b);
	void playerCompare(Chess_player player);
	friend void newDisplay(Chess_player a);

};
void Chess_player :: playerRead()
{
	puts("Имя игрока");
	cin >> PlayerName;
	puts("Укажите разряд игрока");
	cin >> rank;
	puts("Укажите колличество фигур");
	cin >> numbers;
	for (int i = 0; i < numbers; i++)
	{
		printf("\tВвод фигур\nФигур осталось %d\n",numbers-i);
		figures[i].Read();
		system("cls");
	}

}
void Chess_player::playerDisplay()
{
	cout << "Имя " << PlayerName << "\n";
	cout << "Разряд " << rank << "\n";
	if (color)
		cout << "Играет белыми\n";
	else
		cout <<"Играет чёрными\n";
	cout << "Колличество фигур " << numbers << "\n";
	cout << "Фигуры:"<< "\n";
	for (int i = 0; i < numbers; i++)
	{
		cout << i + 1;
		figures[i].Display();
	}
}
void Chess_player::playerInit(string Pn ,int numb, chess_figure cf[16], int razryad)
{
	PlayerName = Pn;
	numbers = numb;
	for (int i = 0; i < numbers; i++)
	{
		figures[i] = cf[i];
	}
	rank = razryad;
	color = false;
}
Chess_player& Chess_player :: playerAdd(Chess_player a, Chess_player b)
{
	
	this->PlayerName = a.PlayerName + "+" + b.PlayerName;
	this->rank = a.rank + b.rank;
	
	
	return *this;
	 
}
 void Chess_player::playerCompare(Chess_player player)
 {
	 cout << PlayerName << " VS " << player.PlayerName;
	 puts("");
	 bool winRank;
	 if (player.rank < rank)
	 {
		 cout <<  " ПОБЕДИТЕЛЬ " << player.PlayerName;
	 }
	 if (player.rank > rank)
	 {
		 cout << " ПОБЕДИТЕЛЬ " << PlayerName;
	 }
	 if (player.rank == rank)
	 {
		 cout << " НИЧЬЯ ";
	 }
 }


 void newDisplay(Chess_player a)
 {
	 int lent = a.PlayerName.length();
	 cout << lent;
 }

/////////////////////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	
	chess_figure MAS[10];
	//Возврат значения через указатель
	chess_figure a,b,d;
	a.Init(3, "Конь");
	a++;
	b.Init(9, "Ферзь");
	//перегрузка оператора '+'
	d = a + b;
	d.Display();
	puts("");
	system("pause");
	system("cls");

	chess_figure* c = new (chess_figure);
	c->Add(a, b);
	c->Display();


	puts("");
	system("pause");
	system("cls");


	//Возврат значения через сслыку
	Chess_player Andrey;
	Chess_player Magnus;
	Magnus.playerInit("Магнус", 10, MAS, 1);
	Andrey.playerInit("Андрей", 10, MAS, 1);
	Chess_player together;
	Chess_player& togetherRef = together;
	togetherRef.playerAdd(Andrey, Magnus);
	togetherRef.playerDisplay();
	newDisplay(together);
	
	/*for (int i = 0; i < 10; i++)
	{
		switch (i%5)
		{
		case 0: {MAS[i].Init(1, NAMES[i % 5]); }; break;
		case 1: {MAS[i].Init(3, NAMES[i % 5]); }; break;
		case 2: {MAS[i].Init(3, NAMES[i % 5]); }; break;
		case 3: {MAS[i].Init(5, NAMES[i % 5]); }; break;
		case 4: {MAS[i].Init(9, NAMES[i % 5]); }; break;
		}
		
	}*/

	//Chess_player Andrey;
	//Chess_player Magnus;
	//Magnus.playerInit("Магнус",10, MAS, 1);

	//Andrey.playerRead();
	//puts("");
	//system("pause");
	//system("cls");
	//Andrey.playerDisplay();
	//puts("");
	//system("pause");
	//system("cls");
	//Magnus.playerDisplay();
	//puts("");
	//system("pause");
	//system("cls");
	////шахматист с самыми сильными сторонами от обоих играков
	//Chess_player *together = new (Chess_player);
	//together->playerAdd(Andrey, Magnus);
	//delete(together);
	//puts("");
	//system("pause");
	//system("cls");
	//Andrey.playerCompare(Magnus);

	
}