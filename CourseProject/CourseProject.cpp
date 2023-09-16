#include <iostream>
#include <vector>
#include "Matrix.cpp"
int main() {
	std::vector<std::vector<double>> A = { 
		std::vector<double>{ 2, 5, 7 },
		std::vector<double>{ 6, 3, 4 },
		std::vector<double>{5, -2, -3}
	};
	A = Matrix::InverseMatrix(A);
	Matrix::ShowMatix(A);
}