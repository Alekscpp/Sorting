#include<iostream>
#include<conio.h>
#include<string>
#include<List>
#include <ctime>
#include <vector>

using std::string;
using namespace std;
#pragma region Sort



//СОРТИРОВКИ
 
//пузырек

void BubleSort(vector<int>&arr ) {
	int arrlen = arr.size();
	int count = 0;

	for (int i = 0; i < arrlen - 1; i++)
	{
		bool sortfinish = 1;
		for (int j = 0; j < arrlen -i- 1; j++)
		{
			
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				sortfinish = false;
			}
		}
		count++;
		if (sortfinish == true)
			break;
	}

//	std::cout << " e ="<<e<<" Выполнена сортировка Пузырьком\nПроходов: " << count << '\n';

}

//быстрая сортировка

void QuickSort(vector<int>&arr, int start  ,int finish) {
	//int start = 0, finish = arr.size() - 1;
	if (start < finish) {
		int left = start;
		int right = finish;
		int midle = arr[(left + right) / 2];
		do {
			while (arr[left] < midle)
				left++;
			while (arr[right] > midle)
				right--;
			if (left <= right) {
				std::swap(arr[left], arr[right]);
				left++;
				right--;
			}
		} while (left < right);
		QuickSort(arr, start, right);
		QuickSort(arr, left, finish);
		
	}
}

//сортировка вставками

void insert_sort(vector<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		int k = i;
		while (k>0 and arr[k-1]>arr[k] ) {
			swap(arr[k], arr[k - 1]);
			k -= 1;
		}
	}
}

#pragma endregion

#pragma region ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ




void PrintArray(int arr[],int size) {
	for (int i = 0; i <size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout  << std::endl;
}

void SetArray(int *arr,int size) {
	bool as;

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%100;
	}


}

void swap(string& a, string& b) {
	std::string tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

#pragma endregion

void Sort(vector<int> &v) {
	
	int n = v.size();
	for (size_t i = 0; i < n; i++)
	{
		for (int  j=i+1; j < n; j++)
		{
			if (v[i] > v[j])
				swap(v[i] , v[j]);
		}
	
	}
}

int main() {
	//srand(time(0));
	
	setlocale(LC_ALL, "ru");
	

	vector<int> vec{ 1,7,3,5,2,0 };
	
	
	Sort(vec);

	for (int i : vec)
		cout << i << ' ';
	cout << endl;

	return 0;
}