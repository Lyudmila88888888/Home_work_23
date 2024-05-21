#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}


// Задача 1.
template <typename T>
void max_element(T num1, T num2, T num3) {
	int maxelem = 0;
	maxelem = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
	num1 = maxelem;
	num2 = maxelem;
	num3 = maxelem;
	std::cout << num1 << ' ' << num2 << ' ' << num3 << std::endl;
}

// Задача 2.
void first_negative_index(int const arr[], int const length, int &index) {
	index = -1;
	for (int i = 0; i < length; i++) {
		if (arr[i] < 0) {
			index = i;
			return;
		}
	}		 
}
// Задача 3.
void two_arrays(int arr1[], int const length1, int arr2[], int const length2 ) {
	for (int i = 0; i < length1; i++)
		for (int j = 0; j < length2; j++)
			if (*(arr1 + i) == *(arr2 + j))
				*(arr2 + j) = 0;		
}

	int main() {
		setlocale(LC_ALL, "Russian");
		
		// Задача 1.
		int n, m, x;
		std::cout << "Задача 1.\nВведите три числа -> ";
		std::cin >> n >> m >> x;
		std::cout << "Замена значений на максимальный элемент -> ";
		max_element(n, m, x);
		std::cout << "\n";

		//Задача 2.
		std::cout << "Задача 2.\n";
		int index;
		int const size = 10;
		int arr[size];
		fill_arr(arr, size, -15, 85);
		print_arr(arr, size);
		first_negative_index(arr, size, index);
		if (index == -1)
			std::cout << "Отрицательных элементов в массиве нет.\n" << std::endl;
		
		else (index != -1); {
			std::cout << "Индекс первого отрицательного элемент массива : " << index  << std::endl;
			std::cout << "\n";
		}
		
		//Задача 3.
		std::cout << "Задача 3.\n";
		int const size1 = 10;
		int arr1[size1]{15,95,7,18,56,23,54,13,2,10};
		int const size2 = 10;
		int arr2[size2]{14,7,52,48,23,13,11,16,2,14};
		std::cout << " Массив 1:";
		print_arr(arr1, size2);
		std::cout << " Массив 2:";
		print_arr(arr2, size2);
		two_arrays(arr1, size1, arr2, size2);
		std::cout << " Массив с обнуленными элементами:\n\t  ";
		print_arr(arr2, size2);
		
		return 0;
	}