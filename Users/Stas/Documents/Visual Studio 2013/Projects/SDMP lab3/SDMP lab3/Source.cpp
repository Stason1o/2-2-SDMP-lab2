#include <iostream>
#include <fstream>
#include <utility>
#include <string>
using namespace std::rel_ops;
typedef std::string		string_t;
typedef std::ifstream	ifstream_t;
const string_t unsorted_txt = "D:\\unsorted.txt";


// Родительский класс Элемент
class Element {
public:
	virtual void scanFile(std::istream&) = 0;

protected:
	void error(string_t mess) {
		std::cerr << mess << std::endl;
		std::cout << "Press any key to exit." << std::endl;
		getchar();
		exit(1);
	}
};

// Производный класс Студент
class Countries : public Element {
protected:
	int ID;
	string_t country;
	string_t symbol;
	string_t money;
	string_t city;

public:
	Countries()
		: ID(0), country(""), symbol(""), money(""), city("")
	{}

	Countries(int _ID, string_t _country, string_t _symbol, string_t _money, string_t _city)
		: ID(_ID), country(_country), symbol(_symbol), money(_money), city(_city)
	{}

	Countries(const Countries &s)
		: ID(s.ID), country(s.country), symbol(s.symbol), money(s.money), city(s.city)
	{}

	virtual void scanFile(std::istream& fin) {
		fin >> ID >> country >> symbol >> money >> city;
	}

	const int       getID() const       { return ID; }
	const string_t  getCountry() const  { return country; }
	const string_t  getSymbol() const   { return symbol; }
	const string_t  getMoney() const    { return money; }
	const string_t  getCity() const     { return city; }

	bool operator==(const Countries& s) const { return ID == s.ID; }
	bool operator <(const Countries& s) const { return ID < s.ID; }

	~Countries() {}
};

// Перегрузка оператора << для вывода Студента
std::ostream& operator<<(std::ostream& os, const Countries& s) {
	os << s.getID() << "\t" + s.getCountry() + "\t\t" +
		s.getSymbol() + "\t\t" + s.getMoney() + "\t" +
		s.getCity() + "\n";
	return os;
}

// Шаблонный класс Связный список
template <class E>
class List {
protected:
	E *pdata;
	List<E> *pnext;

public:
	List() : pdata(nullptr), pnext(nullptr) {}

	List(string_t filename) : pdata(nullptr), pnext(nullptr) {
		ifstream_t fin(filename, std::ios::in);
		if (!fin.is_open()) {
			error("File not found!");
			return;
		}

		List<E> *pcurr = this;
		E       *pnew;
		while (!fin.eof()) {
			pnew = new E();
			pnew->scanFile(fin);
			if (pcurr->pdata != nullptr) {
				pcurr->pnext = new List<E>();
				pcurr = pcurr->pnext;
			}
			pcurr->pdata = pnew;
		}
		fin.close();
		fin.clear();
	}

	virtual void show() {
		List<E> *pcurr = this;
		if (pcurr->pdata)
			do {
				std::cout << *(pcurr->pdata);
			} while ((pcurr = pcurr->pnext));
	}

	void add(E e, int id) {
		if (id >= 0) {
			List<E> *pcurr = this;
			List<E> *pnew = new List<E>();
			if (id == 0) {  // Добавление в начало списка
				List<E> *pold = new List<E>();
				pold->pdata = pcurr->pdata;
				pold->pnext = pcurr->pnext;
				pcurr->pnext = pold;
				pcurr->pdata = new E(e);
				return;
			}
			while (pcurr) {  // Добавление в середину/конец списка
				if (pcurr->pdata->getID() == id) {
					pnew->pnext = pcurr->pnext;
					pnew->pdata = new E(e);
					pcurr->pnext = pnew;
					break;
				}
				else
					pcurr = pcurr->pnext;
			}
		}
		else
			error("Negative ID!");
	}

	void remove(int id) {
		if (id > 0) {
			List<E> *pcurr = this;
			List<E> *ppre = nullptr;
			List<E> *pdel = nullptr;
			if (pcurr->pdata->getID() == id) {
				pcurr->pdata = pcurr->pnext->pdata;
				pcurr->pnext = pcurr->pnext->pnext;
				return;
			}

			ppre = pcurr;
			pdel = pcurr->pnext;
			while (pdel) {
				if (pdel->pdata->getID() == id) {
					ppre->pnext = pdel->pnext;
					delete pdel;
					break;
				}
				ppre = pdel;
				pdel = pdel->pnext;
			}
		}
		else
			error("Illegal ID!");
	}

	int search(E e) {
		int position = -1;
		List<E> *pcurr = this;
		if (pcurr->pdata) {
			int i = 0;
			do {
				++i;
				if (*(pcurr->pdata) == e)
					position = i;
			} while (position == -1 && (pcurr = pcurr->pnext));
		}
		return position;
	}

protected:
	void error(string_t mess) {
		std::cerr << mess << std::endl;
		std::cout << "Press any key to exit." << std::endl;
		getchar();
		exit(1);
	}
};

// Шаблонный класс Двусвязный список
template <class E>
class BiList {
protected:
	E *pdata;
	BiList<E> *pnext;
	BiList<E> *pprev;

public:
	BiList() : pdata(nullptr), pnext(nullptr), pprev(nullptr) {}

	BiList(string_t filename) : pdata(nullptr), pnext(nullptr), pprev(nullptr) {
		ifstream_t fin(filename, std::ios::in);
		if (!fin.is_open()) {
			error("File not found!");
			return;
		}

		BiList<E> *pcurr = this;
		E         *pnew;
		while (!fin.eof()) {
			pnew = new E();
			pnew->scanFile(fin);
			if (pcurr->pdata != nullptr) {
				pcurr->pnext = new BiList<E>();
				pcurr->pnext->pprev = pcurr;
				pcurr = pcurr->pnext;
			}
			pcurr->pdata = pnew;
		}
		fin.close();
		fin.clear();
	}

	virtual void show() {
		BiList<E> *pcurr = this;
		if (pcurr->pdata)
			do {
				std::cout << *(pcurr->pdata);
			} while ((pcurr = pcurr->pnext));
	}

	virtual void inverseShow() {
		BiList<E> *pcurr = this;
		if (pcurr->pdata) {
			while (pcurr->pnext)
				pcurr = pcurr->pnext;
			do {
				std::cout << *(pcurr->pdata);
			} while ((pcurr = pcurr->pprev));
		}
	}

	void add(E e, int id) {
		if (id >= 0) {
			BiList<E> *pcurr = this;
			if (id == 0) {  // Добавление в начало списка
				BiList<E> *pold = new BiList<E>();
				pold->pdata = pcurr->pdata;
				pold->pnext = pcurr->pnext;
				pold->pprev = pcurr;
				pcurr->pnext = pold;
				pcurr->pdata = new E(e);
				return;
			}
			while (pcurr) {  // Добавление в середину/конец списка
				BiList<E> *pnew = new BiList<E>();
				if (pcurr->pdata->getID() == id) {
					pnew->pnext = pcurr->pnext;
					pnew->pprev = pcurr;
					pnew->pdata = new E(e);
					pcurr->pnext->pprev = pnew;
					pcurr->pnext = pnew;
					break;
				}
				else
					pcurr = pcurr->pnext;
			}
		}
		else
			error("Negative ID!");
	}

	void remove(int id) {
		if (id > 0) {
			BiList<E> *pcurr = this;
			BiList<E> *ppre = nullptr;
			BiList<E> *pdel = nullptr;
			if (pcurr->pdata->getID() == id) {
				pcurr->pdata = pcurr->pnext->pdata;
				pcurr->pnext->pprev = pcurr->pprev;
				pcurr->pnext = pcurr->pnext->pnext;
				return;
			}

			ppre = pcurr;
			pdel = pcurr->pnext;
			while (pdel) {
				if (pdel->pdata->getID() == id) {
					ppre->pnext = pdel->pnext;
					if (pdel->pnext)
						pdel->pnext->pprev = ppre;
					delete pdel;
					break;
				}
				ppre = pdel;
				pdel = pdel->pnext;
			}
		}
		else
			error("Illegal ID!");
	}

	int search(E e) {
		int position = -1;
		BiList<E> *pcurr = this;
		if (pcurr->pdata) {
			int i = 0;
			do {
				++i;
				if (*(pcurr->pdata) == e)
					position = i;
			} while (position == -1 && (pcurr = pcurr->pnext));
		}
		return position;
	}

protected:
	void error(string_t mess) {
		std::cerr << mess << std::endl;
		std::cout << "Press any key to exit." << std::endl;
		getchar();
		exit(1);
	}
};

// Шаблонный класс Стэк
template <class E>
class Stack {
protected:
	E* buffer;
	size_t size;
	int top;

public:
	Stack() : buffer(nullptr), size(0), top(0) {}

	Stack(size_t size = 100) {
		this->size = size;
		buffer = new E[size];
		top = 0;
	}

	Stack(const Stack& s) {
		size = s.size;
		buffer = s.buffer;
		top = s.top;
	}

	Stack(string_t filename, size_t size = 100) {
		this->size = size;
		buffer = new E[size];
		top = 0;

		ifstream_t fin(filename, std::ios::in);
		if (!fin.is_open()) {
			error("File not found!");
			return;
		}

		E e;
		while (!fin.eof()) {
			e.scanFile(fin);
			push(e);
		}
		fin.close();
		fin.clear();
	}

	void push(E e) {
		if (!full())
			buffer[top++] = e;
		else
			error("Stack is full.");
	}

	E pop() {
		if (empty()) {
			error("Stack is empty.");
			return E(0, "", "", "", "");
		}
		return buffer[--top];
	}

	int search(E e) {
		Stack *s = new Stack(*this);
		int steps = 0;
		while (!s->empty()) {
			++steps;
			if (e == s->pop())
				return steps;
		}
		return -1;
	}

	virtual void show() {
		size_t i = top;
		while (i)
			std::cout << buffer[--i];
	}

	bool empty() { return top == 0; }
	bool full() { return top == size; }

	~Stack() {
		delete[] buffer;
	}

protected:
	void error(string_t mess) {
		std::cerr << mess << std::endl;
		std::cout << "Press any key to exit." << std::endl;
		getchar();
		exit(1);
	}
};

// Шаблонный класс Очередь
template <class E>
class Queue {
protected:
	E *buffer;
	size_t size;
	size_t nextin;
	size_t nextout;
	size_t count;

public:
	Queue() : buffer(nullptr), size(0), nextin(0), nextout(0), count(0) {}

	Queue(size_t size = 100) : nextin(0), nextout(0), count(0) {
		this->size = size;
		buffer = new E[size];
	}

	Queue(string_t filename, size_t size = 100) : nextin(0), nextout(0), count(0) {
		this->size = size;
		buffer = new E[size];

		ifstream_t fin(filename, std::ios::in);
		if (!fin.is_open()) {
			error("File not found!");
			return;
		}

		E e;
		while (!fin.eof()) {
			e.scanFile(fin);
			put(e);
		}
		fin.close();
		fin.clear();
	}

	void put(E e) {
		if (count++ < size) {
			buffer[nextin] = e;
			nextin = ++nextin % size;
		}
		else
			error("Queue is full.");
	}

	E get() {
		if (empty()) {
			error("Queue is empty.");
			return E(0, "", "", "", "");
		}
		size_t outpos = nextout;
		nextout = ++nextout % size;
		return buffer[outpos];
	}

	int search(E e) {
		int steps = 0;
		size_t current = nextout;
		do {
			++steps;
			if (e == buffer[current])
				return steps;
		} while ((++current % size) != nextin);
		return -1;
	}

	virtual void show() {
		size_t current = nextout;
		do {
			std::cout << buffer[current];
		} while ((++current % size) != nextin);
	}

	bool empty() { return count == 0; }
	bool full() { return count == size; }

	~Queue() {
		delete[] buffer;
	}

protected:
	void error(string_t mess) {
		std::cerr << mess << std::endl;
		std::cout << "Press any key to exit." << std::endl;
		getchar();
		exit(1);
	}
};

//Шаблонный класс Бинарное дерево
template <class E>
class Bintree {
protected:
	E *pdata;
	Bintree<E> *pleft;
	Bintree<E> *pright;

public:
	Bintree() : pdata(nullptr), pleft(nullptr), pright(nullptr) {}

	Bintree(E e) : pleft(nullptr), pright(nullptr) {
		pdata = new E(e);
	}

	Bintree(string_t filename) : pdata(nullptr), pleft(nullptr), pright(nullptr) {
		ifstream_t fin(filename, std::ios::in);
		if (!fin.is_open()) {
			error("File not found!");
			return;
		}

		Bintree<E> *pcurr;
		E          *pnew;
		while (!fin.eof()) {
			pnew = new E();
			pnew->scanFile(fin);
			pcurr = this;
			while (pcurr->pdata) {
				if (*pnew < *(pcurr->pdata)) {
					if (pcurr->pleft == nullptr)
						pcurr->pleft = new Bintree<E>();
					pcurr = pcurr->pleft;
				}
				else {
					if (pcurr->pright == nullptr)
						pcurr->pright = new Bintree<E>();
					pcurr = pcurr->pright;
				}
			}
			pcurr->pdata = pnew;
		}
		fin.close();
		fin.clear();
	}

	void add(E e) {
		if (!this->pdata) { // Если дерево пустое
			this->pdata = new E(e);
			return;
		}

		Bintree<E> *pnew = this;
		Bintree<E> *ppre = nullptr;
		while (pnew) {
			ppre = pnew;
			if (e < *(pnew->pdata))
				pnew = pnew->pleft;
			else pnew = pnew->pright;
		}

		if (e < *(ppre->pdata))
			ppre->pleft = new Bintree<E>(e);
		else
			ppre->pright = new Bintree<E>(e);

	}

	Bintree<E>* remove(Bintree<E>* root, E e) {
		if (root == nullptr)
			return root;
		else if (e < *(root->pdata))
			root->pleft = remove(root->pleft, e);
		else if (e > *(root->pdata))
			root->pright = remove(root->pright, e);
		else {
			if (root->pleft == nullptr && root->pright == nullptr) {
				delete root;
				root = nullptr;
			}
			else if (root->pleft == nullptr) {
				Bintree<E> *tmp = root;
				root = root->pright;
				delete tmp;
			}
			else if (root->pright == nullptr) {
				Bintree<E> *tmp = root;
				root = root->pleft;
				delete tmp;
			}
			else {
				Bintree<E> *tmp = findMin(root->pright);
				root->pdata = tmp->pdata;
				root->pright = remove(root->pright, e);
			}
		}
		return root;
	}

	int search(E e) {
		int steps = 0;
		Bintree<E> *pcurr = this;
		do {
			steps++;
			if (e == *(pcurr->pdata))
				return steps;
			else if (e < *(pcurr->pdata))
				pcurr = pcurr->pleft;
			else if (e > *(pcurr->pdata))
				pcurr = pcurr->pright;
		} while (pcurr);
		return -1;
	}

	virtual void preShow() {
		if (pdata) std::cout << *pdata;
		if (pleft) pleft->preShow();
		if (pright) pright->preShow();
	}

	virtual void inShow() {
		if (pleft) pleft->inShow();
		if (pdata) std::cout << *pdata;
		if (pright) pright->inShow();
	}

	virtual void postShow() {
		if (pleft) pleft->postShow();
		if (pright) pright->postShow();
		if (pdata) std::cout << *pdata;
	}

protected:
	Bintree<E>* findMin(Bintree<E>* root) {
		while (root->pleft)
			root = root->pleft;
		return root;
	}

	void error(string_t mess) {
		std::cerr << mess << std::endl;
		std::cout << "Press any key to exit." << std::endl;
		getchar();
		exit(1);
	}
};


void linkedList(string_t filename) {
	List<Countries> S(unsorted_txt);
	int choise = -1;

	while (choise) {
		std::cout << "\n=== Linked List ===" << std::endl;
		std::cout << "1 - Show nodes" << std::endl;
		std::cout << "2 - Add node" << std::endl;
		std::cout << "3 - Remove node" << std::endl;
		std::cout << "4 - Search node" << std::endl;
		std::cout << "0 - Exit." << std::endl;

		int id, add_id, pos;
		string_t country, symbol, money , city;
		std::cout << "> ";
		std::cin >> choise;

		switch (choise) {
		case 1:
			S.show();
			break;

		case 2:
			std::cout << "Enter where to insert: ";      std::cin >> add_id;
			std::cout << "Enter country's id: ";         std::cin >> id;
			std::cout << "Enter country's country: ";    std::cin >> country;
			std::cout << "Enter country's symbol: ";     std::cin >> symbol;
			std::cout << "Enter country's money: ";      std::cin >> money;
			std::cout << "Enter country's city: ";		 std::cin >> city;
			S.add(Countries(id, country, symbol, money, city), add_id);
			break;

		case 3:
			std::cout << "Enter student's id to remove: "; std::cin >> id;
			S.remove(id);
			break;

		case 4:
			std::cout << "Enter id to search: ";
			std::cin >> id;
			pos = S.search(Countries(id, "", "", "", ""));
			if (pos < 0)
				std::cout << "Not found!" << std::endl;
			else
				std::cout << "Found on the position " << pos << std::endl;
			break;

		case 0:
			break;

		default:
			std::cout << "Enter the number between 0-4!" << std::endl;
			break;
		}
	}
}

void biLinkedList(string_t filename) {
	BiList<Countries> S(unsorted_txt);
	int choise = -1;

	while (choise) {
		std::cout << "\n=== Bidirectional List ===" << std::endl;
		std::cout << "1 - Show nodes" << std::endl;
		std::cout << "2 - Inverse Show nodes" << std::endl;
		std::cout << "3 - Add node" << std::endl;
		std::cout << "4 - Remove node" << std::endl;
		std::cout << "5 - Search node" << std::endl;
		std::cout << "0 - Exit." << std::endl;

		int id, add_id, pos;
		string_t country, symbol, money, city;
		std::cout << "> ";
		std::cin >> choise;

		switch (choise) {
		case 1:
			S.show();
			break;

		case 2:
			S.inverseShow();
			break;

		case 3:
			std::cout << "Enter where to insert: ";         std::cin >> add_id;
			std::cout << "Enter countries's id: ";          std::cin >> id;
			std::cout << "Enter countries's country: ";     std::cin >> country;
			std::cout << "Enter countries's symbol: ";      std::cin >> symbol;
			std::cout << "Enter countries's money: ";       std::cin >> money;
			std::cout << "Enter countries's city: ";		std::cin >> city;
			S.add(Countries(id, country, symbol, money, city), add_id);
			break;

		case 4:
			std::cout << "Enter student's id to remove: "; std::cin >> id;
			S.remove(id);
			break;

		case 5:
			std::cout << "Enter id to search: ";
			std::cin >> id;
			pos = S.search(Countries(id, "", "", "", ""));
			if (pos < 0)
				std::cout << "Not found!" << std::endl;
			else
				std::cout << "Found on the position " << pos << std::endl;
			break;

		case 0:
			break;

		default:
			std::cout << "Enter the number between 0-5!" << std::endl;
			break;
		}
	}
}

void stack(string_t filename) {
	Stack<Countries> S(unsorted_txt);
	int choise = -1;

	while (choise) {
		std::cout << "\n=== Stack ===" << std::endl;
		std::cout << "1 - Show stack" << std::endl;
		std::cout << "2 - Push element" << std::endl;
		std::cout << "3 - Pop element" << std::endl;
		std::cout << "4 - Search element" << std::endl;
		std::cout << "0 - Exit." << std::endl;

		int id, pos;
		string_t country, symbol, money, city;
		std::cout << "> ";
		std::cin >> choise;

		switch (choise) {
		case 1:
			S.show();
			break;

		case 2:
			std::cout << "Enter countries's id: ";          std::cin >> id;
			std::cout << "Enter countries's country: ";     std::cin >> country;
			std::cout << "Enter countries's symbol: ";      std::cin >> symbol;
			std::cout << "Enter countries's money: ";       std::cin >> money;
			std::cout << "Enter countries's city: ";		std::cin >> city;
			S.push(Countries(id, country, symbol, money, city));
			break;

		case 3:
			std::cout << S.pop();
			break;

		case 4:
			std::cout << "Enter id to search: ";
			std::cin >> id;
			pos = S.search(Countries(id, "", "", "", ""));
			if (pos < 0)
				std::cout << "Not found!" << std::endl;
			else
				std::cout << "Found in " << pos << " operations " << std::endl;
			break;

		case 0:
			break;

		default:
			std::cout << "Enter the number between 0-4!" << std::endl;
			break;
		}
	}
}

void queue(string_t filename) {
	Queue<Countries> S(unsorted_txt);
	int choise = -1;

	while (choise) {
		std::cout << "\n=== Queue ===" << std::endl;
		std::cout << "1 - Show queue" << std::endl;
		std::cout << "2 - Put element" << std::endl;
		std::cout << "3 - Get element" << std::endl;
		std::cout << "4 - Search element" << std::endl;
		std::cout << "0 - Exit." << std::endl;

		int id, pos;
		string_t country, symbol, money, city;
		bool buget;
		std::cout << "> ";
		std::cin >> choise;

		switch (choise) {
		case 1:
			S.show();
			break;

		case 2:
			std::cout << "Enter countries's id: ";         std::cin >> id;
			std::cout << "Enter countries's country: ";    std::cin >> country;
			std::cout << "Enter countries's symbol: ";     std::cin >> symbol;
			std::cout << "Enter countries's money: ";      std::cin >> money;
			std::cout << "Enter countries's city: ";	   std::cin >> city;
			S.put(Countries(id, country, symbol, money, city));
			break;

		case 3:
			std::cout << S.get();
			break;

		case 4:
			std::cout << "Enter id to search: ";
			std::cin >> id;
			pos = S.search(Countries(id, "", "", "", ""));
			if (pos < 0)
				std::cout << "Not found!" << std::endl;
			else
				std::cout << "Found in " << pos << " operations " << std::endl;
			break;

		case 0:
			break;

		default:
			std::cout << "Enter the number between 0-4!" << std::endl;
			break;
		}
	}
}

void binTree(string_t filename) {
	Bintree<Countries> *S = new Bintree<Countries>(unsorted_txt);
	int choise = -1;

	while (choise) {
		std::cout << "\n=== Binary tree ===" << std::endl;
		std::cout << "1 - Show preorder" << std::endl;
		std::cout << "2 - Show inorder" << std::endl;
		std::cout << "3 - Show postorder" << std::endl;
		std::cout << "4 - Add element" << std::endl;
		std::cout << "5 - Remove element" << std::endl;
		std::cout << "6 - Search element" << std::endl;
		std::cout << "0 - Exit." << std::endl;

		int id, pos;
		string_t country, symbol, money, city;
		std::cout << "> ";
		std::cin >> choise;

		switch (choise) {
		case 1:
			S->preShow();
			break;

		case 2:
			S->inShow();
			break;

		case 3:
			S->postShow();
			break;

		case 4:
			std::cout << "Enter countries's id: ";         std::cin >> id;
			std::cout << "Enter countries's country: ";    std::cin >> country;
			std::cout << "Enter countries's symbol: ";     std::cin >> symbol;
			std::cout << "Enter countries's money: ";      std::cin >> money;
			std::cout << "Enter countries's city: ";	   std::cin >> city;
			S->add(Countries(id, country, symbol, money, city));
			break;

		case 5:
			std::cout << "Enter student's id to remove: "; std::cin >> id;
			S->remove(S, Countries(id, "", "", "", ""));
			break;

		case 6:
			std::cout << "Enter id to search: ";
			std::cin >> id;
			pos = S->search(Countries(id, "", "", "", ""));
			if (pos < 0)
				std::cout << "Not found!" << std::endl;
			else
				std::cout << "Found in " << pos << " operations." << std::endl;
			break;

		case 0:
			break;

		default:
			std::cout << "Enter the number between 0-6!" << std::endl;
			break;
		}
	}
	delete S;
}

int main() {
	int choise = -1;
	while (choise) {
		std::cout << "1 - Linked list." << std::endl;
		std::cout << "2 - Bidirectional List." << std::endl;
		std::cout << "3 - Stack." << std::endl;
		std::cout << "4 - Queue." << std::endl;
		std::cout << "5 - Binary Tree." << std::endl;
		std::cout << "0 - Exit." << std::endl;

		std::cout << "> ";
		std::cin >> choise;

		switch (choise) {
		case 1:
			linkedList(unsorted_txt);
			break;

		case 2:
			biLinkedList(unsorted_txt);
			break;

		case 3:
			stack(unsorted_txt);
			break;

		case 4:
			queue(unsorted_txt);
			break;

		case 5:
			binTree(unsorted_txt);
			break;

		case 0:
			break;

		default:
			std::cout << "Enter the number between 0-5!" << std::endl;
			break;
		}
		std::cout << std::endl;
	}
	std::cout << "Good bye!" << std::endl;
	return 0;
}