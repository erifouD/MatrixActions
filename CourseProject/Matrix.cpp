#include <vector>
#include <iostream>
class Matrix {
public:
	static double Determinant(std::vector<std::vector<double>> A) {
		return (((A[0][0] * A[1][1] * A[2][2]) + (A[1][0] * A[2][1] * A[0][2]) + (A[0][1] * A[1][2] * A[2][0]))
			- ((A[0][2] * A[1][1] * A[2][0]) + (A[0][1] * A[1][0] * A[2][2]) + (A[0][0] * A[1][2] * A[2][1])));
	}
	static void Swap(double& a, double& b) {
		double c = a;
		a = b;
		b = c;
		return;
	}
	static void Transposition(std::vector<std::vector<double>>& A) {
		Swap(A[0][1], A[1][0]);
		Swap(A[2][0], A[0][2]);
		Swap(A[1][2], A[2][1]);
	}
	static void ShowMatix(std::vector<std::vector<double>>& A) {
		for (int i = 0; i < 3; i++) {
			std::cout << "{ ";
			for (int j = 0; j < 3; j++) {
				std::cout << A[i][j] << " ";
			}
			std::cout << "}\n";
		}
	}
	static double Minor(int i, int j, std::vector<std::vector<double>> A) {
		std::vector<double> TT;
		for (int I = 0; I < 3; I++) {
			for (int J = 0; J < 3; J++) {
				if (I == i || J == j) continue;
				TT.push_back(A[I][J]);
			}
		}
		if ((i + j) % 2 == 0)
			return (TT[0] * TT[3] - TT[1] * TT[2]);
		else
			return ((TT[0] * TT[3] - TT[1] * TT[2]) * -1);
	}

	static std::vector<std::vector<double>> MinorMatrix(std::vector<std::vector<double>> A) {
		std::vector<std::vector<double>> MinorMatrix(3, std::vector<double>(3));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				MinorMatrix[i][j] = Minor(i, j, A);
			}
		}
		return MinorMatrix;
	}
	static void SingleMultiplication(double value, std::vector<std::vector<double>>& A) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				A[i][j] *= value;
			}
		}
	}

	static std::vector<std::vector<double>> InverseMatrix(std::vector<std::vector<double>> A) {
		double Det = Determinant(A);
		std::vector<std::vector<double>> MM = MinorMatrix(A);
		Transposition(MM);
		SingleMultiplication((1.f / Det), MM);
		return MM;
	}
};