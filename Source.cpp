#include "Header.h"

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
		while (k>0 && arr[k-1]>arr[k] ) {
			swap(arr[k], arr[k - 1]);
			k -= 1;
		}
	}
}

//сортировка выбором


void Selection_sort(vector<int>& v) {

	int n = v.size();
	for (size_t i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[min] > v[j])
				swap(v[min], v[j]);
		}

	}
}






// Сортировка Кучей






void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
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
void heap(vector<int>& v, int n, int i) {
	
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int larg = i;

	if (l<n && v[l]>v[larg])
		larg = l;

	if (r<n && v[r]>v[larg])
		larg = r;

	if (larg != i) {

		swap(v[i], v[larg]);

		heap(v, n, larg);
	}

}

//if (v[j] < v[j - 1])
//	swap(v[j], v[j - 1]);



int main() {
	//srand(time(0));
	
	/*setlocale(LC_ALL, "ru");
	

	vector<int> vec{ 1,7,3,5,2,0 };
	
	
	Sort(vec);

	for (int i : vec)
		cout << i << ' ';
	cout << endl;*/
	vector<int> vec{ 12, 11, 13, 5, 6, 7 };
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
    //heapSort(arr, n);
	Sort(vec);
	for (int p : vec) {
		cout << p << ' ';
	}
	//cout << "Sorted array is \n";
	//printArray(arr, n);
	return 0;
}