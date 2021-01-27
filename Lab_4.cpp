//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<locale.h>
#include<windows.h>
using namespace std;
string NAMES[5] = { "Пешка","Конь", "Слон", "Ладья", "Ферзь" };
class chess_figure {

private:
	string name;
public:
	//Колличество элементов класса
	static int quantity;
	int value;
	bool pawn = false;
	//функция установки значений
	void Read();
	//функция получения значений
	void Init(int val, string name);
	//функция вывода
	void Display();
	//
	void static cut(char ch);
	//
	void static quantityDisplay();
	//
	void static pause();
};

void chess_figure::pause()
{
	cout << "\n\n";
	system("pause");
	system("cls");
}
void chess_figure::cut(char ch)
{
	if (ch == 'c') {
		quantity--;
	}
}
void chess_figure::quantityDisplay()
{
	if (quantity > 0) {
		cout << "You have  " << quantity << " figures";
	}
	else {
		cout << "You lose!!!";
	}
}
void chess_figure::Read()
{



	int vibor;
	puts("Название фигуры");
	for (int i = 0; i < 5; i++)
	{

		cout << i + 1 << " " << NAMES[i] << "\n";

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

	cout << name << " Ценность " << value << "\n";


}

int chess_figure::quantity = 2;

int main()
{

	do
	{
		char ch;
		cin >> ch;

		chess_figure::cut(ch);
		chess_figure::quantityDisplay();
		chess_figure::pause();

	} while (chess_figure::quantity >= 0);

}
