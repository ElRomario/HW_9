#include <iostream> 
#include <fstream> 
#include <string>
#include <Windows.h>


using namespace std;

class Student
{
private:
	string name; // имя
	string surname; // фамилия
	string date; // дата рождения 
	string number; // номер телефона 
	string sityLive; // город проживания
	string countryLive; // страна проживания 
	string teg; // название университета 
	string tegSity; // город где находится университет 
	string tegCountry; // страна где находится университет  
	string group; // номер группы 
public:
	// конструкторы 
	Student
	(
		string name_, 
		string surname_, 
		string date_,
		string number_,
		string sityLive_, 
		string countryLive_, 
		string teg_, 
		string tegSity_, 
		string tegCountry_, 
		string group_
	)
	{
		name = name_;
		surname = surname_;
		date = date_;
		number = number_;
		sityLive = sityLive_;
		countryLive = countryLive_;
		teg = teg_;
		tegSity = tegSity_;
		tegCountry = tegCountry_;
		group = group_;
	}

	Student() : Student
	(
	"неизвестный","неизвестный","000000","000000000","неизвестный","неизвестный",
	"неизвестный","неизвестный","неизвестный","неизвестный"
	) {}

	string getName() { return name;	}
	string getSurname() { return surname; }
	string getDate() { return date; }
	string getNumber() { return number; }
	string getSityLive() { return sityLive; }
	string getCountryLive() { return countryLive; }
	string getTeg() { return teg; }
	string getTegSity() { return tegSity; }
	string getTegCountry() { return tegCountry; }
	string getGroup() { return group; }

	// мутаторы
	void setName(const string name) { this->name = name; }
	void setSurname(const string surname) { this->surname = surname; }
	void setDate(const string date) { this->date = date; }
	void setNumber(const string number) { this->number = number; }
	void setSityLive(const string sityLive) { this->sityLive = sityLive; }
	void setCountryLive(const string countryLive) { this->countryLive = countryLive; }
	void setTeg(const string teg) { this->teg = teg; }
	void setTegSity(const string tegSity) { this->tegSity = tegSity; }
	void setTegCountry(const string tegCountry) { this->tegCountry = tegCountry; }
	void setGroup(const string group) { this->group = group; }

	void printStudent()
	{
		cout << "ФИО = " << name << " " << surname << endl;
		cout << "дата рождени = " << date << endl;
		cout << endl << "номер телефона = " << number << endl;
		cout << endl << "город = " << sityLive << endl;
		cout << "страна = " << countryLive << endl;
		cout << "учебное заведение = " << teg << endl;
		cout << "г. уч. заведения = " << tegSity << endl;
		cout << "стр. уч. заведения = " << tegCountry << endl;
		cout << "номер группы = " << group << endl;
	}

	void inputStudent
	(
		int &countStudent,
		string name_,
		string surname_,
		string date_,
		string number_,
		string sityLive_,
		string countryLive_,
		string teg_,
		string tegSity_,
		string tegCountry_,
		string group_
	)
	{
		name = name_;
		surname = surname_;
		date = date_;
		number = number_;
		sityLive = sityLive_;
		countryLive = countryLive_;
		teg = teg_;
		tegSity = tegSity_;
		tegCountry = tegCountry_;
		group = group_;
		countStudent++;
	}

	void saveDataStudent()
	{
		string path = "dz9_1.txt";
		fstream app_data;
		app_data.open(path, fstream::app);
		if (app_data.is_open())
		{
			app_data << name << " " << surname << " " << date << " " << number << " " << sityLive << " " << countryLive << "" << teg << " " << tegSity << " " << tegCountry << " " << group << endl;
		}
	}

	friend void loadDataStudent(Student* &student,const int maxStudent, int &countStudent)
	{
		SetConsoleCP(1251);
		GetConsoleOutputCP();
		string path = "dz9_1.txt";
		fstream in_data;
		in_data.open(path, fstream::in);
		if (in_data.is_open())
		{
			for (int i = countStudent; i < maxStudent || in_data.eof(); i++)
			{
				string name_ptr;
				string surname_ptr;
				string date_ptr;
				string number_ptr;
				string sityLive_ptr;
				string countryLive_ptr;
				string teg_ptr;
				string tegSity_ptr;
				string tegCountry_ptr;
				string group_ptr;
				
				in_data >> name_ptr >> surname_ptr >> date_ptr >> number_ptr >> sityLive_ptr >> countryLive_ptr >> teg_ptr >> tegSity_ptr >> tegCountry_ptr >> group_ptr;
				student[i].setName(name_ptr);
				student[i].setSurname(surname_ptr);
				student[i].setDate(date_ptr);
				student[i].setNumber(number_ptr);
				student[i].setSityLive(sityLive_ptr);
				student[i].setCountryLive(countryLive_ptr);
				student[i].setTeg(teg_ptr);
				student[i].setTegSity(tegSity_ptr);
				student[i].setTegCountry(tegCountry_ptr);
				student[i].setGroup(group_ptr);
				countStudent++;
			}
			
		}
		SetConsoleCP(866);
		GetConsoleOutputCP();
	}
};

int main()
{
    /*
        Задание №1
		К уже существующему проекту класса Student добавьте механизмы сохранения/загрузки данных класса. 
		Используйте механизм потоков для файловых операций.
    */
    setlocale(LC_ALL, "ru");
	int maxStudent = 5;
	int countStudent = 0;
	Student* student = new Student[maxStudent];
	student[0].inputStudent(countStudent, "Артур", "Соколов", "06.06.2002", "+79889234439", "Москва", "Россия", "Академия_ТОР", "Москва", "Россия", "БВ-212");
	loadDataStudent(student, maxStudent, countStudent);
	for (int i = 0; i < countStudent; i++)
	{
		student[i].printStudent();
	}
    return 0;
}