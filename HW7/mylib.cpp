#include <iostream>
#include "mylib.h"
using namespace std;
namespace MyLib
{ 
    void initArr(float* arr, const size_t size) {
        for (size_t i = 0; i < size; i++) {
            arr[i] = (float)(rand() % 10000) / 10 - (float)(rand() % 10000) / 10;
        }
    }
    void printArr(const float* arr, const size_t size) {
        cout << "[ ";
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
    void printArr(const int* arr, const size_t size) {
        cout << "[ ";
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
    void arrClear(float* arr) {
        delete[] arr;
        arr = nullptr;

    }
    void countValArr (const float* arr, const size_t size) {
        size_t positive = 0;
        size_t negative = 0;
        size_t zero = 0;
        for (size_t i = 0; i < size; i++) {
            if (arr[i] > 0)
                positive++;
            else if (arr[i] < 0)
                negative++;
            else
                zero++;
        }
        cout << "Positive elements: " << positive << endl;
        cout << "Negative elements: " << negative << endl;
        cout << "Zero elements: " << zero << endl;
    }
}