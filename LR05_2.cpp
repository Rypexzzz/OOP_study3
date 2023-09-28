#include<iostream>
#include"stack_5.h"

int main() {
	try {
		stack<int> one;
		one.inject(5);
		one.inject(10);
		one.show();
		std::cout << one.extract() << std::endl;
		std::cout << one.extract() << std::endl;
		//std::cout << one.extract() << std::endl;
	}
	catch (int error) {
		if (error == 1) std::cout << "Error, trying to extract of empty stack\n";
	}
}