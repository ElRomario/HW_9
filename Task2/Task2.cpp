#include <iostream> 
#include <fstream> 
#include <string>
#include <Windows.h>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int _numerator, int _denominator) : numerator{ _numerator }, denominator{ _denominator } {}
    Fraction() : Fraction(1, 1) {}

	void setNumerator(const int numerator) { this->numerator = numerator; }
	void setDenominator(const int denominator) { this->denominator = denominator; }

    void showInfo() const 
	{
        cout << numerator << " / " << denominator << endl;
    }

	void saveDataFraction()
	{
		string path = "dz9_2.txt";
		fstream app_data;
		app_data.open(path, fstream::app);
		if (app_data.is_open())
		{
			string numerator_str;
			string denominator_str;
			numerator_str = to_string(numerator);
			denominator_str = to_string(denominator);
			app_data << numerator_str << " / " << denominator_str << endl;
		}
	}

	friend void loadDataFraction(Fraction*& fraction, const int maxFraction, int& countFraction)
	{
		string path = "dz9_2.txt";
		fstream in_data;
		in_data.open(path, fstream::in);
		if (in_data.is_open())
		{
			for (int i = countFraction; i < maxFraction && !in_data.eof(); i++)
			{
				string numerator_ptr_str;
				string denominator_ptr_str;
				string slesh;
				int numerator_ptr;
				int denominator_ptr;

				in_data >> numerator_ptr_str >> slesh >> denominator_ptr_str;
				numerator_ptr = stoi(numerator_ptr_str);
				denominator_ptr = stoi(denominator_ptr_str);
				fraction[i].setNumerator(numerator_ptr);
				fraction[i].setDenominator(denominator_ptr);
				countFraction++;
			}

		}
	}
};

int main()
{
	/*
		Задание №2
		К уже существующему проекту класса Дробь добавьте механизмы сохранения/загрузки данных класса. 
		Используйте механизм потоков для файловых операций.
	*/
	setlocale(LC_ALL, "ru");
	int maxFraction = 10;
	int countFraction = 0;
	Fraction* fraction = new Fraction[maxFraction];
	loadDataFraction(fraction, maxFraction, countFraction);
	for (int i = 0; i < countFraction; i++)
	{
		fraction[i].showInfo();
	}
	for (int i = countFraction; i < maxFraction; i++)
	{
		fraction[i].saveDataFraction();
	}
	return 0;
}