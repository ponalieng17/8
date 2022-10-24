#include <iostream>
#include <string>
using namespace std;

void sys(int digit, int syst);
void Task_1_sys();

void bros(int kubik);
int res();
void Task_2_Play_Kubik();


bool Prime_Num(int n);
void Task_3_Prime_Num();

void Aray(int size[10]);
void Task_4_Aray_MAX_MIN();

void Task_5_Revers_Array(int* n, int m);

int main()
{
    setlocale(LC_ALL, "rus");
	Task_1_sys();
	Task_2_Play_Kubik();
	Task_3_Prime_Num();
	Task_4_Aray_MAX_MIN();
	cout << "ЗАДАНИЕ № 5: Написать функцию, меняющую порядок следования элементов передаваемого ей массива на противоположный\n\n";
	int n[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Task_5_Revers_Array(n, 6);// можно выводить значения с указаной в параметрах цифры
	Task_5_Revers_Array(n, 10);


}
void sys(int digit, int syst)
{
	int i = 0, A[50];
	for (; digit > 0; i++)
	{
		A[i] = digit % syst;
		digit /= syst;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		if (A[j] < 10)
			cout << A[j];
		else
			cout << char(A[j] - 10 + 'A');
	}
}
void Task_1_sys() {
	int digit;
	cout << "ЗАДАНИЕ № 1: Написать функцию, которая получает в качестве аргументов целое положительное число и систему счисления,\n";
	cout << "в которую это число должно переводится(системы счисления от 2 до 36).\n\n";
		cout << "Эта программа переводит число в любую систему счисления.\nПожалуйста введите число: ";
		cin >> digit;
		cout << "\nВведите систему счисления: ";
		int syst;
		cin >> syst;
		sys(digit, syst);
		cout << "\n\n\n";
}

void bros(int kubik)
{
	switch (kubik)
	{
	case 1:
		cout << "******************\n";
		cout << "*                *\n";
		cout << "*                *\n";
		cout << "*        *       *\n";
		cout << "*                *\n";
		cout << "*                *\n";
		cout << "******************\n";
		break;
	case 2:
		cout << "******************\n";
		cout << "*                *\n";
		cout << "*        *       *\n";
		cout << "*                *\n";
		cout << "*        *       *\n";
		cout << "*                *\n";
		cout << "******************\n";
		break;
	case 3:
		cout << "******************\n";
		cout << "*                *\n";
		cout << "*    *           *\n";
		cout << "*        *       *\n";
		cout << "*            *   *\n";
		cout << "*                *\n";
		cout << "******************\n";
		break;
	case 4:
		cout << "******************\n";
		cout << "*                *\n";
		cout << "*    *      *    *\n";
		cout << "*                *\n";
		cout << "*    *      *    *\n";
		cout << "*                *\n";
		cout << "******************\n";
		break;
	case 5:
		cout << "******************\n";
		cout << "*                *\n";
		cout << "*    *      *    *\n";
		cout << "*       *        *\n";
		cout << "*    *      *    *\n";
		cout << "*                *\n";
		cout << "******************\n";
		break;
	case 6:
		cout << "******************\n";
		cout << "*                *\n";
		cout << "*    *      *    *\n";
		cout << "*    *      *    *\n";
		cout << "*    *      *    *\n";
		cout << "*                *\n";
		cout << "******************\n";
		break;
	}
}
int res()
{
	int kubik_1 = rand() % 6 + 1;
	bros(kubik_1);
	int kubik_2 = rand() % 6 + 1;
	bros(kubik_2);
	int rezult;
	rezult = kubik_1 + kubik_2;
	cout << "Результат: " << rezult << "\n\n";
	return rezult;
}
void Task_2_Play_Kubik() {
	char brosok;
	
		
		srand(time(NULL));

		cout << "ЗАДАНИЕ № 2: ИГРА  \"КУБИКИ\"\n\n";
		
		string name;
		cout << "Введите имя: ";
		cin >> name;

		int total_chel = 0;
		int total_komp = 0;

		do
		{
			cout << name << ", нажмите * для определения очерёдности броска\n\n";
			cin >> brosok;
		} while (brosok != '*');

		int res_chel, res_komp;
		do
		{
			res_chel = res();
			cout << name << ", Ваш результат: " << res_chel << "\n";
			res_komp = res();
			cout << "Результат компьютера: " << res_komp << "\n\n";
		} while (res_chel == res_komp);

		if (res_chel > res_komp)
		{
			cout << name << ", Вы начинаете первым.\n";
			for (int i = 1; i <= 5; i++)
			{
				do
				{
					cout << "Нажми * для броска\n";
					cin >> brosok;
				} while (brosok != '*');
				cout << name << " :" << endl;
				total_chel += res();
				cout << "Компьютер:\n";
				total_komp += res();
				cout << "Следующий ход:\n\n";
			}
			cout << name << ", Ваш общий результат (сумма очков за 5 бросков): " << total_chel << "\n\n";
			cout << "Общий результат компьютера (сумма очков за 5 бросков): " << total_komp << "\n\n";
		}
		else
		{
			cout << "Компьютер начинат первым :)\n";
			for (int i = 1; i <= 5; i++)
			{
				cout << "Компьютер:\n";
				total_komp += res();
				do
				{
					cout << "Нажми * для броска\n";
					cin >> brosok;
				} while (brosok != '*');
				cout << name << " :" << endl;
				total_chel += res();
				cout << "Следующий ход:\n";
			}
			cout << name << ", Ваш общий результат (сумма очков за 5 бросков): " << total_chel << "\n";
			cout << "\nОбщий результат компьютера (сумма очков за 5 бросков): " << total_komp << "\n";
		}

		if (total_chel == total_komp)
		{
			cout << "\n\nНИЧЬЯ!\n\n";
		}
		else
		{
			if (total_chel > total_komp)
			{
				cout<< name << ", Вы выиграли!\n\n";
			}
			if (total_chel < total_komp)
			{
				cout << "\n\nКомпьютер выиграл!\n\n";
			}
		}
		
}

bool Prime_Num(int n) {
	if (n > 1)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return false;

		return true;
	}
	else
		return false;
}
void Task_3_Prime_Num() {
    cout << "ЗАДАНИЕ № 3: Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется простым,\n";
    cout << "если оно делится без остатка только на себя и на единицу.\n\n";
    int n;
    cout << "Введите число для проверки условия (является ли оно простым): ";
    cin >> n;
    if (Prime_Num(n))
        cout << "Число " << n << " является простым";
    else
        cout << "Число " << n << " не является простым";
	cout << "\n\n";
}

void Aray(int size[10]) {
	int i;
	int max = size[0];
	int min = size[0];
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		size[i] = rand() % 100;
		if (min > size[i])
			min = size[i];

		if (max < size[i])
			max = size[i];
	}
	cout << "Максимальное значение массива " << max << "\n\n";
	cout << "Минимальное значение массива " << min << "\n\n";

}
void Task_4_Aray_MAX_MIN() {
	cout << "ЗАДАНИЕ № 4: Написать функцию, определяющую минимум и максимум (значение и номер) элементов передаваемого ей массива\n\n";
	int  size[10]{ rand() };
	Aray(size);
}

void Task_5_Revers_Array(int* n, int m) {
	for (int i = m - 1; i > -1; i--)
		cout << n[i] << " ";
	cout << endl;
}