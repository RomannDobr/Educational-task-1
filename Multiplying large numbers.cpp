// Написать программу, которая принимает со стандартного потока ввода 
// 2 целых числа произвольной длины и выводит их произведение. 
// Должны поддерживать числа любого размера - большие чем uint64_t. 
// Должна присутствовать валидация данных - если введёно не число 
// в стандартный поток ошибок выводится сообщение.

#include <iostream>
#include <cstdint>
#include <string>
#include <limits>

using namespace std;

int main()
{

const int n = 123; // переменная для циклов и массивов
int a=-1, b=-1; // переменные для подсчёта колличества знаков в числах

string numberOne; // строка для записи первого числа
string numberTwo; // строка для записи второго числа

int num1[n]; // массив для записи первого числа
int num2[n]; // массив для записи второго числа
int res1[n][n]; // массив для записи промежуточных результатов
int result[n+1]; // массив для записи произведения

cout << " Enter first number\n";

for(int i=0; ; i++) // валидация ввода первого числа
    {
    int j = 0;
    cin >> numberOne;
    for(int i=0; ; i++)
    {
        if (numberOne[i] > '9')
        {
            cout << " Ups! Enter number, please!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Enter first number\n";
            j++;
        }
        if (numberOne[i] == '\0') break;
    }
    if (j == 0) break;
}
cout << endl;

for(int i=0; i<n; i++) // преобразование string в int первого числа
    {
    char digit[10];
        for(int j=0; j<10; j++)
        {
            digit[j] = '0'+j;
            if(numberOne[i] == digit[j])
            {
                num1[i] = j;
                break;
            }
        }
        if (numberOne[i] == '\0') break;
        a++;
    }


cout << " Enter second number\n";

for(int i=0; ; i++) // валидация ввода второго числа
    {
    int j = 0;
    cin >> numberTwo;
    for(int i=0; ; i++)
    {
        if (numberTwo[i] > '9')
        {
            cout << " Ups! Enter number, please!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Enter second number\n";
            j++;
        }
        if (numberTwo[i] == '\0') break;
    }
    if (j == 0) break;
}
cout << endl;

for(int i=0; i<n; i++) // преобразование string в int второго числа
    {
    char digit[10];
        for(int j=0; j<10; j++)
        {
            digit[j] = '0'+j;
            if(numberTwo[i] == digit[j])
            {
                num2[i] = j;
                break;
            }
        }
        if (numberTwo[i] == '\0') break;
        b++;
    }

// умножение "столбиком"
for(int i=0; i<=b; i++) // заполнение двумерного массива промежуточными значениями
{
    for(int j=0; j<=a+b+1; j++)
    {
        res1[i][j+i] = num2[b-i]*num1[a-j];
        if(j < i) res1[i][j] = 0;
        if(a-j+i < 0) res1[i][j] = 0;
    }
}
int c=0, s=0, i=0;
for(; i<=a+b+1; i++) // суммирование промежуточных операций
{
    result[i] = 0;
            result[i] += s;
    for(int j=0; j<=b; j++)
    {
        result[i] += res1[j][i];
        if(result[i] > 9 && j>=b)
        {
            c = result[i];
            s = c/10;
            result[i] = c-(s*10);
        }
        else s=0;
    }
}

    cout << endl << " RESULT: ";
    for(int j=-1; j<=a+b; j++) // вывод результата
    {
        if(j<0 && result[a+b-j]==0) continue;
        if(j%3 == 0 && i%3==1 && j>0) cout << "." << result[a+b-j];
        else if((j-1)%3 == 0 && i%3==2) cout << "." << result[a+b-j];
        else if((j-2)%3 == 0 && i%3==0 && j>0) cout << "." << result[a+b-j];
        else cout << result[a+b-j];
    }
    
    cout << endl;

  return 0;
}