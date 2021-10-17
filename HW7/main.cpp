// Author: Istomin Stepan
// Основы C++, Практическое задание 7

#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"

using namespace std;

/* Task 2
Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры)
в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false,
вывести на экран «true» или «false».
*/

#define TASK2_COMPARE (number >= 0 && number < maxNumber) ? cout << "true" : cout << "false";

void task2() {
    int number, maxNumber;
    cout << "Enter your number (integer): ";
    cin >> number;
    cout << "Enter maximum number (integer): ";
    cin >> maxNumber;
    TASK2_COMPARE;
}

/* Task 3
Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через
ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов 
как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
*/

#define ARR_SIZE 10
#define SwapINT(a, b) int temp = a; a = b; b = temp;

void bubbleSort(int* arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        bool swap = false;
        for (size_t j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                //int temp = arr[j];
                //arr[j] = arr[j + 1];
                //arr[j + 1] = temp;
                SwapINT(arr[j], arr[j + 1]);
                swap = true;
            }
        }
        if (swap == false)
            break;
    }
}
void task3() {
    int arrTask3[ARR_SIZE];
    for (size_t i = 0; i < ARR_SIZE; i++) {
        cout << "Enter volume for array[" << i << "]: ";
        cin >> arrTask3[i];
    }
    MyLib::printArr(arrTask3, ARR_SIZE);
    bubbleSort(arrTask3, ARR_SIZE);
    MyLib::printArr(arrTask3, ARR_SIZE);
}

/* Task 4
Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. 
Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. 
Сохраните эту структуру в текстовый или двоичный файл.
*/
#pragma pack(push, 1)
struct Employee
{
    unsigned short id;
    string name;
    double salary;
};
#pragma pack(pop)
void task4() {
    //const string FileName = "001.bin";
    Employee* pEngineer = new Employee;
    pEngineer->id = 1;
    pEngineer->name = "Stepan Istomin";
    pEngineer->salary = 1'567.45;
    cout << "Employee id: " << pEngineer->id << endl;
    cout << "Employee name: " << pEngineer->name << endl;
    cout << "Employee salary: " << pEngineer->salary << endl;
    cout << "structure size: " << sizeof(*pEngineer) << " Bytes" << endl;;


    const string FileName = "001.bin";
    // write to file
    
    ofstream fout(FileName, ios_base::binary);
    if (fout.is_open())
    {
        fout.write((char*)pEngineer, sizeof(*pEngineer));
        fout.close();
    }
    

    // Где то здесь возникает ошибка памяти :(
    // Она уходит если убрать delete pEngineer; или если убрать блок чтения из файла
    // =====================================================================================================
    
    delete pEngineer;    //Memory clear

     // read from file
    Employee readStruct = {0}; // Структура для считывания из файла
    ifstream fin(FileName, ios_base::binary);
    if (fin.is_open())
    {
        fin.read((char*)&readStruct, sizeof(readStruct));
        fin.close();
    }
    cout << readStruct.id << " " << readStruct.name << " " << readStruct.salary << endl;
    
    // =====================================================================================================
}

int main()
{
    cout << "\n------> Task 2 <------\n\n";
    task2();
     
    cout << "\n\n------> Task 3 <------\n\n";
    task3();

    cout << "\n\n------> Task 4 <------\n\n";
    task4();

    
    cout << "\n\n------> Task 5 <------\n\n";
    srand(time(NULL)); // Time randomizer
    
    float * ptrArray;
    size_t arraySize = 10;
    ptrArray = new float[arraySize];

	//without "using namespace"
    MyLib::initArr(ptrArray, arraySize);
    MyLib::printArr(ptrArray, arraySize);
    
    using namespace MyLib;
    countValArr(ptrArray, arraySize);
    arrClear(ptrArray); // Memory clear
    
}
