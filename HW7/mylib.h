#pragma once

using namespace std;
namespace MyLib
{
	void initArr(float* arr, const size_t size);
	void printArr(const float* arr, const size_t arrSize);
	void printArr(const int* arr, const size_t size);
	void arrClear(float* arr);
	void countValArr(const float* arr, const size_t size);
}