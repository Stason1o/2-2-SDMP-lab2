#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std::rel_ops;
typedef std::string						string_t;
typedef std::ifstream					ifstream_t;
typedef std::vector<int>				size_vector;

const string_t PATH = "C:\\Users\\Stas\\Documents\\Visual Studio 2013\\Projects\\SDMP lab2\\SDMP lab2\\file1.txt";

struct Data{// счтывание с файла
	ifstream_t file;

	Data() {
		file.open("somefile.txt", std::ios::in);
		if (!file.is_open())
			std::cout << "File not found" << std::endl;
	}

	Data(const string_t& filename) {
		file.open(filename, std::ios::in);
		if (!file.is_open())
			std::cout << "File " + filename + " not found" << std::endl;
	}

	~Data() {
		if (file.is_open())
			file.close();
		file.clear();
	}

	
};

struct Sort : public Data{//сортировка 
	size_vector vector;
	size_vector copy_vector;
	size_vector heap_vector;
	size_vector qsort_vector;
	size_t size;
	Sort() : Data(), size(0) {}

	Sort(const string_t& filename) : Data(filename) {
		string_t line;
		size_t tmp;
		size = 0;
		//std::getline(file, line);
		//std::stringstream lineStream(line);
		string_t item = "";
		vector.clear();
		if (!file.is_open())
			std::cout << "can't open file" << std::endl;
		while (!file.eof()){
			file >> item;
			tmp = std::stoi(item);
			vector.push_back(tmp);
			size++;
		}
		heap_vector = vector;
		qsort_vector = vector;
	}
	
	std::ostream& operator<<(std::ostream& os) {
		for (auto it = vector.begin(); it != vector.end(); ++it)
			os << *it;
		return os;
	}

	void print(){
		for (auto it = vector.begin(); it != vector.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	void print_sorted(){
		for (auto it = copy_vector.begin(); it != copy_vector.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	void bubleSort(){
		std::vector<int> copy(vector);
		size_t tmp = 0; 
		int step = 1;
		for (size_t i = 0; i < copy.size(); ++i)
			for (size_t j = i + 1; j < copy.size(); ++j){
				if (copy[j] < copy[i]){
					tmp = copy[i];
					copy[i] = copy[j];
					copy[j] = tmp;
					std::cout << "Step " << step << ": ";
					for (auto it = copy.begin(); it != copy.end(); ++it)
						std::cout << *it << " ";
					step++;
					std::cout << std::endl;
				}
				
			}
		copy_vector = copy;
				
	}

	void insertionSort(){
		std::vector<int> copy(vector);
		int temp;
		int step = 1;
		for (size_t i = 0; i < copy.size(); i++){
			size_t j = i;

		while (j > 0 && copy[j] < copy[j - 1]){
			temp = copy[j];
			copy[j] = copy[j - 1];
			copy[j - 1] = temp;
			j--;
		}
		std::cout << "Step " << step << ": ";
		for (auto it = copy.begin(); it != copy.end(); ++it)
			std::cout << *it << " ";
		step++;
		std::cout << std::endl;
		}
		copy_vector = copy;
	}

	void selectionSort(){
		std::vector<int> copy(vector);
		//pos_min is short for position of min
		size_t pos_min, temp;
		int step = 1;

		for (size_t i = 0; i < copy.size(); i++)
		{
			pos_min = i;//set pos_min to the current index of array

			for (size_t j = i + 1; j < copy.size(); j++)
			{

				if (copy[j] < copy[pos_min])
					pos_min = j;

				//pos_min will keep track of the index that min is in, this is needed when a swap happens
			}

			//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
			if (pos_min != i)
			{
				temp = copy[i];
				copy[i] = copy[pos_min];
				copy[pos_min] = temp;
			}
			std::cout << "Step " << step << ": ";
			for (auto it = copy.begin(); it != copy.end(); ++it)
				std::cout << *it << " ";
			step++;
			std::cout << std::endl;
		}
		copy_vector = copy;
	}

	void quickSort(int left, int right){
		int x = qsort_vector[left + (right - left) / 2];
		//запись эквивалентна (l+r)/2, 
		//но не вызввает переполнения на больших данных
		int i = left;
		int j = right;
		//код в while обычно выносят в процедуру particle
		while (i <= j)
		{
			while (qsort_vector[i] < x) i++;
			while (qsort_vector[j] > x) j--;
			if (i <= j)
			{
				swap(qsort_vector[i], qsort_vector[j]);
				i++;
				j--;
			}
		}
		if (i<right)
			quickSort(i, right);

		if (left<j)
			quickSort(left, j);
			
		copy_vector = qsort_vector;
	}

	void shellSort(){
		std::vector<int> copy(vector);
		int i, temp, flag = 1, numLength = copy.size();
		int d = numLength;
		while (flag || (d > 1))      // boolean flag (true when not equal to 0)
		{
			flag = 0;           // reset flag to 0 to check for future swaps
			d = (d + 1) / 2;
			for (i = 0; i < (numLength - d); i++)
			{
				if (copy[i + d] < copy[i])
				{
					temp = copy[i + d];      // swap positions i+d and i
					copy[i + d] = copy[i];
					copy[i] = temp;
					flag = 1;                  // tells swap has occurred
				}
			}
		}
		copy_vector = copy;
		return;
	}

	void makeheap(int c){
		for (int i = 1; i < c; i++)
		{
			int val = heap_vector[i];
			int s = i;
			int f = (s - 1) / 2;
			while (s > 0 && heap_vector[f] < val)
			{
				heap_vector[s] = heap_vector[f];
				s = f;
				f = (s - 1) / 2;
			}
			heap_vector[s] = val;
		}
		copy_vector = heap_vector;
	}

	void heapSort(){
		for (int i = heap_vector.size() - 1; i > 0; i--)
		{
			int ivalue = heap_vector[i];
			heap_vector[i] = heap_vector[0];
			heap_vector[0] = ivalue;
			makeheap(i);

		}
		//copy_vector = heap_vector;
	}
	
};

void menu(string_t filename){
	Sort obj(filename);
	int n;
	int q = 1;
	while (q != 0){
		std::cout << "What sort u wish to use?" << std::endl;
		std::cout << "1 - BubleSort" << std::endl;
		std::cout << "2 - InsertionSort" << std::endl;
		std::cout << "3 - SelectionSort" << std::endl;
		std::cout << "4 - QuickSort ?!?!?!?!?" << std::endl;
		std::cout << "5 - ShellSort" << std::endl;
		std::cout << "6 - HeapSort" << std::endl;
		std::cout << "7 - Exit" << std::endl;
		std::cin >> n;
		switch (n){
		case 1:
			std::cout << "Initial array: "; 
			obj.print();
			obj.bubleSort();
			std::cout << "Sorted array: ";
			obj.print_sorted();
			break;
		case 2:
			std::cout << "Initial array: ";
			obj.print();
			obj.insertionSort();
			std::cout << "Sorted array: ";
			obj.print_sorted();
			break;
		case 3:
			std::cout << "Initial array: ";
			obj.print();
			obj.selectionSort();
			std::cout << "Sorted array: ";
			obj.print_sorted();
			break;
		case 4:
			std::cout << "Initial array: ";
			obj.print();
			obj.quickSort(0, obj.vector.size() - 1);
			std::cout << "Sorted array: ";
			obj.print_sorted();
			break;
		case 5:
			std::cout << "Initial array: ";
			obj.print();
			obj.shellSort();
			std::cout << "Sorted array: ";
			obj.print_sorted();
			break;
		case 6:
			std::cout << "Initial array: ";
			obj.print();
			obj.makeheap(obj.vector.size());
			obj.heapSort();
			std::cout << "Sorted array: ";
			obj.print_sorted();
			break;
		case 7:
			q = 0;
			break;
		}
	}
}

void main(){
	menu(PATH);
	system("pause");
}