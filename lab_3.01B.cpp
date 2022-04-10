#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;


enum Spec { KN, INF, ME, FI, TN };
string specStr[] = { "KN", "INF", "ME", "FI", "TN"};


struct Student
{
	string prizv;
	int course;
	Spec spec;
	int physic;
	int math;
	
	union
	{
		int prog;
		int chysmet;
		int pedah;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int numberofStudents(Student* p, const int N);
void bestSubject(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	cout << "Кількість студентів, середній бал яких більший за 4,5 :  " << numberofStudents(p, N) << endl;
	bestSubject(p, N);

	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	int course;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент №  " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "   прізвище: "; getline(cin, p[i].prizv);
		cout << "   курс:   "; cin >> p[i].course;
		cout << "  спеціальність(0-KN, 1 - INF, 2 - ME, 3-FI, 4-TN): ";
		cin >> spec;
		cout << "  Оцінка з фізики:  "; cin >> p[i].physic;
		cout << "  Оцінка з математики:  "; cin >> p[i].math;
		//cout << "  Оцінка з інформатики:  "; cin >> p[i].informatyka;

		p[i].spec = (Spec)spec;

		switch (p[i].spec)
		{
		case KN:
			cout << "  Оцінка з програмування:  "; cin >> p[i].prog;
			break;
		case INF:
			cout << "  Оцінка з чисельних методів:  "; cin >> p[i].chysmet;
			break;
		case ME:
		case FI:
		case TN:
			cout << "  Оцінка з педагогіки:  "; cin >> p[i].pedah;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "================================================================================================================"
		<< endl;
	cout << "|  №  |  Прізвище  | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(11) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].course << " "
			<< "| " << setw(14) << left << specStr[p[i].spec]
			<< "| " << setw(6) << right << p[i].physic << " "
			<< "| " << setw(10) << right << p[i].math << " ";
			
		switch (p[i].spec)
		{
		case KN:
			cout << "| " << setw(13) << right << p[i].prog 
				<< " |" << setw(19) << right << " | " << setw(12) << right << "|" << endl;
			break;
		case INF:
			cout << "| " << setw(15) << right <<  " |" << setw(16) << right
				<< p[i].chysmet << " | " << setw(12) << right << "|" << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << "| " << setw(15) << right << " |" << setw(19) << right 
				<< " | " << setw(11) << right << p[i].pedah << "|";
			break;
		}
		cout << endl;
	}
	cout << "================================================================================================================"
		<< endl;
	cout << endl;

}

int numberofStudents(Student* p, const int N)
{
	double ave ;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		ave = 0;
		ave =  (p[i].math + p[i].physic) / 2.;
		if (ave > 4.5)
		{
			count += 1;
		}

	}
	return count;
}

void bestSubject(Student* p, const int N)
{
	int sum_physic = 0;
	int sum_math = 0;
	//int sum_informatyka = 0;
	double eve_physic = 0;
	double eve_math = 0;
	//double eve_informatyka = 0;

	for (int i = 0; i < N; i++)
	{
		sum_physic += p[i].physic;
		sum_math += p[i].math;
		//sum_informatyka += p[i].informatyka;
	}
	eve_physic = sum_physic / N;
	eve_math = sum_math / N;
	//eve_informatyka = sum_informatyka / N;
	if (eve_physic > eve_math )//&& eve_physic >= eve_informatyka)
	{
		cout << "ФІЗИКА";
	}
	else if (eve_math > eve_physic)// && eve_math >= eve_informatyka)
	{
		cout << "МАТЕМАТИКА";
	}
	else
	{
		cout << "ОЦІНКИ РІВНІ";
	}
}