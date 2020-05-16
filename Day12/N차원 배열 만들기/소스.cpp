// N차원 배열 만들기
#include <iostream>

class Array {
	const int dim;

	class Address {
	public:
		int level; void* next;
	};
	Address* top;

public:
	int* size;
	Array(int dim, int* array_size) : dim(dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];

		top = new Address;
		top->level = 0;

		initialize_address(top);
	}
	~Array() {
		delete_address(top);
		delete[] size;
	}
	void initialize_address(Address* current) {
		if (!current) return;
		if (current->level == dim - 1) {
			current->next = new int[size[current->level]];
		}
		current->next = new Address[size[current->level]];
		for (int i = 0; i < size[current->level]; i++) {
			(static_cast<Address*>(current->next) + i)->level = current->level + 1;
			initialize_address(static_cast<Address*>(current->next) + i);
		}
	}
	void delete_address(Address* current) {
		if (!current) return;
		for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
			delete_address(static_cast<Address*>(current->next) + i);
		}

		delete[] current->next;
	}
};
class Int {
	void* data;

	int level;
	Array* array;

	Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
		: level(_level), data(_data), array(_array) {
		if (_level < 1 || index >= array->size[_level - 1]) {
			data = NULL; return;
		}

	}
};

int main() {

	return 0;
}