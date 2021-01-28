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
	
	string name;
	//Если pawn = true: фигура является пешкой, если false, то не пешкой 
	
public:
	int* Test;
	int value;
	bool pawn = false;
	//функция установки значений
	void Read();
	//конструктор со всеми параметрами
	chess_figure(int value, string name, bool pawn);
	//конструктор с одним параметром
	chess_figure(string name);
	chess_figure();
	//функция вывода
	void Display();
	chess_figure Add(chess_figure a, chess_figure b);
	void compare(chess_figure b);
	void zapolnenie_din_mass(chess_figure* mass, int N);
	void pawn_promotion();
};
chess_figure::chess_figure(int value, string name,bool pawn)
{
	this->name = name;
	this->value = value; 
	this->pawn = pawn;
}

chess_figure::chess_figure(string name)
{
	this->name = name;
	this->value = 3;
}
chess_figure::chess_figure()
{
	this->name = "King";
	this->value = 10;
	this->pawn = true;
	Test = new int;
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

void chess_figure::Display()
{

	cout<<name<< " Ценность "<<value<<"\n";
	
	
}


/////////////////////////////////////////////////////////////////////////////
//В случае наличия указателей при присваивании содержимого объектов
//происходит мелкое копирование. 
//И получается ситуация что два адреса указывают на одну и туу же ячейку памяти
//И изменение содержимого в одном объекте влечет изменение в другом
class Chess_player
{
private:
//колличество фигур
int numbers;
string PlayerName;
//РАзряд шахматиста
int rank;


public :
	int* test;
	//сами фигуры
	chess_figure figures[16];
	bool color =true;
	//функция установки значений
	void playerRead();
	//функция получения значений
	void playerInit(string Pn, int numb, chess_figure cf[16], int razryad);
	//функция вывода
	void playerDisplay();
	void playerAdd(Chess_player a, Chess_player b);
	void playerCompare(Chess_player player);
	//Конструктор со всеми параметрами
	Chess_player(string Pn, int numb, chess_figure cf[16], int razryad);
	//конструктор копии
	Chess_player(const Chess_player &player)
	{
		this->PlayerName =  player.PlayerName;
		this->numbers = player.numbers;
		for (int i = 0; i < numbers; i++)
		{
			this->figures[i] = player.figures[i];
		}
		this->rank = player.rank;
		this->color = player.color;
	}
	Chess_player& operator= (Chess_player& player);
	void testDisplay();
};

Chess_player & Chess_player::operator=(Chess_player& player)
{
	//теперь указатели не будут указывать на общуюю облать памяти 
	//Указателю в новом экземпляре выделили другой адрес
	if (test)
		delete test ;
	
	test = NULL;
	this->PlayerName = player.PlayerName;
	this->numbers = player.numbers;
	for (int i = 0; i < numbers; i++)
	{
		this->figures[i] = player.figures[i];
	}
	this->rank = player.rank;
	this->color = player.color;
	this->test = new int;
	*(this->test) = *(player.test);
	return *this;
}
void Chess_player::testDisplay()
{
	cout << "Имя " << PlayerName << "\n";
	cout << "TEST " << *(test) << "\n";
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
Chess_player::Chess_player(string Pn ,int numb, chess_figure cf[16], int razryad)
{
	rank = razryad;
	
	PlayerName = Pn;
	numbers = numb;
	if (sizeof(figures)/sizeof(chess_figure) < numb)
	{
		throw Pn;
	}
	for (int i = 0; i < numbers; i++)
	{
		figures[i] = cf[i];
	}
	color = false;
}
 
/////////////////////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	
	//Инициализация массива шахматных фигур с помощью конструктора
	chess_figure MAS[16];

	for (int i = 0; i < 16; i++)
	{
		chess_figure* buff;
		if (i % 2 == 0)
		{
			buff = new chess_figure("Slon");
		}
		else
		{
			buff = new chess_figure("Kon");
		}
		MAS[i] = *(buff);
	}
	

	//////////
	
	
	try
	{
		int N = sizeof(MAS) / sizeof(chess_figure);
		Chess_player Andrey("Andrey", 17, MAS, 3);
		Chess_player Magnus(Andrey);
		Chess_player Mayke("M", N, MAS, 3);
	}
	//Отлавливаем игроков чей разряд ниже второго(3,4...)
	catch (string name)
	{
		
		cout << "Превышен максимальный размер массива  игроком -  "<<name;
		cout << "\n\n";

	}
	
	
}