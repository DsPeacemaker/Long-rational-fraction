#include "../src/LongInt.hpp"
#include <chrono>

void run_tests()
{
    Rational a;
    Rational b;
    Rational c;

    a = 12;
    b = 3;
    std::cout << "15 = 12 + 3 = " << Rational::to_string(a + b) << std:: endl;

    a = Rational(12, 4);
    b = 5;
    std::cout << "8 = 12/4 + 5 = " << Rational::to_string(a + b) << std:: endl;

    a = Rational(12, 4);
    b = Rational(5, 2);
    std::cout << "1/2 = 12/4 - 5/2 = " << Rational::to_string(a - b) << std:: endl;

    a = Rational(3, 5);
    b = Rational(14, 3);
    std::cout << "14/5 = 3/5 * 14/3 = " << Rational::to_string(a * b) << std:: endl;

    a = Rational(3, 5);
    b = Rational(6, 7);
    std::cout << "7/10 = (3/5) / (6/7) = " << Rational::to_string(a / b) << std:: endl;

    a = Rational(1, 3);
    b = Rational(2, 3);
    c = Rational(16, 9);
    std::cout << "2 = 1/3 * 2/3 + 16/9 = " << Rational::to_string(a * b + c) << std:: endl;

    a = Rational(5, 7);
    std::cout << "25/49 = (5/7) ^ 2 = " << Rational::to_string(a.pow(2)) << std:: endl;

    a = Rational(5, 7);
    std::cout << "49/25 = (5/7) ^ -2 = " << Rational::to_string(a.pow(-2)) << std:: endl;

    a = Rational(5, 6);
    b = Rational(6, 7);
    std::cout << "true = 5/6 < 6/7 = " << (a < b) << std:: endl;

    a = Rational(5, 6);
    b = Rational(-6, 7);
    std::cout << "false = 5/6 < -6/7 = " << (a < b) << std:: endl;

    a = Rational(1, 3);
    b = Rational(2, 6);
    std::cout << "true = 1/3 == 2/6 = " << (a == b) << std:: endl;

    a = Rational(1, 3);
    b = Rational(195, 256);
    c = Rational(-1001);

    std::cout << a << ", " << b << ", " << c << std::endl;

    a = Rational(5, 8);
    std::cout << "29/8 = 5/8 + 3 = " << Rational::to_string(a + 3) << std:: endl;

    a = Rational(5, 8);
    std::cout << "29/8 = 3 + 5/8 = " << Rational::to_string(3 + a) << std:: endl;

    a = Rational(5, 8);
    std::cout << "19/8 = 3 - 5/8 = " << Rational::to_string(3 - a) << std:: endl;

    a = Rational(3, 2);
    std::cout << "2/3 = 1 / 3/2 = " << Rational::to_string(1 / a) << std:: endl;
}


void run_rump(void)
{
    Rational a = 77617;
    Rational b = 33096;

    Rational f = Rational(3, 4) + 333;

    f *= b.pow(6);
    f += a.pow(2) * (a.pow(2) * b.pow(2) * 11 - b.pow(6) - b.pow(4) * 121 - 2);
    f += b.pow(8) * 11 / 2;
    f += a / (b * 2);

    std::cout << "-54767/66192 = " << Rational::to_string(f) << std::endl;
}


int get_choice()
{
    std::string action;
    std::cout << "1.  Выполнить ряд базовых проверок." << std::endl;
    std::cout << "2.  Выполнить проверку с помощью многочлена Румпа." << std::endl;
    std::cout << "3.  Протестировать сложение." << std::endl;
    std::cout << "4.  Протестировать вычитание." << std::endl;
    std::cout << "5.  Протестировать умножение." << std::endl;
    std::cout << "6.  Протестировать деление." << std::endl;
    std::cout << "7.  Перемножение матриц." << std::endl;
    std::cout << "0.  Выход" << std::endl;
    std::cout << "Выберите операцию: ";
    getline(std::cin, action);

    return std::stoi(action);
}


void test_add()
{
    Rational a, b;
    std::string s;

    std::cout << "Введите первое слагаемое: ";
    std::getline(std::cin, s);
    a = Rational(s);

    std::cout << "Введите второе слагаемое: ";
    std::getline(std::cin, s);
    b = Rational(s);

    std::cout << "Сумма равна " << a + b << std::endl;
}


void test_subtract()
{
    Rational a, b;
    std::string s;

    std::cout << "Введите уменьшаемое: ";
    std::getline(std::cin, s);
    a = Rational(s);

    std::cout << "Введите вычитаемое: ";
    std::getline(std::cin, s);
    b = Rational(s);

    std::cout << "Разность равна " << a - b << std::endl;
}


void test_multiply()
{
    Rational a, b;
    std::string s;

    std::cout << "Введите первый множитель: ";
    std::getline(std::cin, s);
    a = Rational(s);

    std::cout << "Введите второй множитель: ";
    std::getline(std::cin, s);
    b = Rational(s);

    std::cout << "Произведение равно " << a * b << std::endl;
}


void test_divide()
{
    Rational a, b;
    std::string s;

    std::cout << "Введите делимое: ";
    std::getline(std::cin, s);
    a = Rational(s);

    std::cout << "Введите делитель: ";
    std::getline(std::cin, s);
    b = Rational(s);

    std::cout << "Частное равно " << a / b << std::endl;
}


void matr(){
	int n = 200;
	long double time_start;
    long double time_end;
	Rational a[n][n], b[n][n], res[n][n];
	time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			a[i][j] = Rational(3,4);
			b[i][j] = Rational(1,5);
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++){
			res[i][j] += a[i][k] * b[k][j];
	}
	
	for(int i = 0; i < n; i++){
		std::cout << std::endl;
		for(int j = 0; j < n; j++)
			std::cout << " " << res[i][j];
	}
	  time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
      std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
}


int main()
{
    int action;
    do {
        action = get_choice();
        switch(action) {
        case 1:
            std::cout << "---------------------------------------" << std::endl;
            run_tests();
            std::cout << "---------------------------------------" << std::endl;
            break;

        case 2:
            std::cout << "---------------------------------------" << std::endl;
            run_rump();
            std::cout << "---------------------------------------" << std::endl;
            break;

        case 3:
            std::cout << "---------------------------------------" << std::endl;
            test_add();
            std::cout << "---------------------------------------" << std::endl;
            break;

        case 4:
            std::cout << "---------------------------------------" << std::endl;
            test_subtract();
            std::cout << "---------------------------------------" << std::endl;
            break;

        case 5:
            std::cout << "---------------------------------------" << std::endl;
            test_multiply();
            std::cout << "---------------------------------------" << std::endl;
            break;

        case 6:
            std::cout << "---------------------------------------" << std::endl;
            test_divide();
            std::cout << "---------------------------------------" << std::endl;
            break;
        case 7:
            std::cout << "---------------------------------------" << std::endl;
            matr();
            std::cout << "---------------------------------------" << std::endl;
            break;
        }
        
    } while (action);
    return 0;
}
