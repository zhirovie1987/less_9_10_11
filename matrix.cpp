#include <iostream>
#include <cmath>

using namespace std;
template <typename T>
class matrix {
public:
	matrix (size_t a, size_t b) : A(a), B(b) {
		T_matrix = new T* [A];
		for (auto i = 0; i < A; i++) {
			T_matrix[i] = new T [B];
		}
	}
	~matrix () {
			for (auto i = 0; i < A; i++) {
			delete [] T_matrix[i];
		}
	}
	
	size_t Get_A () {
		return A;
	}
	
	size_t Get_B () {
		return B;
	}
	
	void Set_Cell (size_t a, size_t b, T data) {
		T_matrix[a][b] = data;
	}
	
	T Get_Cell (size_t a, size_t b) {
		return T_matrix[a][b];
	}
	
	matrix <T> operator+ (matrix <T> mtr) {
		matrix <T> temp (A, B);
			
		for (auto i = 0 ; i < A; i++) {
			for (auto j = 0; j < B; j++) {
				temp.Set_Cell(i, j, (mtr.Get_Cell(i, j) + T_matrix[i][j]));
			}
		}
	return temp;
	}
	
	matrix <T> operator- (matrix <T> mtr) {
		matrix <T> temp (A, B);
			
		for (auto i = 0 ; i < A; i++) {
			for (auto j = 0; j < B; j++) {
				temp.Set_Cell(i, j, (T_matrix[i][j] - mtr.Get_Cell(i, j)));
			}
		}
	return temp;
	}
	
	matrix <T> operator* (T val) {
		matrix <T> temp (A, B);
			
		for (auto i = 0 ; i < A; i++) {
			for (auto j = 0; j < B; j++) {
				temp.Set_Cell(i, j, (val * T_matrix[i][j]));
			}
		}
	return temp;
	}
	
	matrix <T> operator* (matrix <T> val) {
		matrix <T> temp (A, B);
  		for(int i = 0; i < B; i++) {
  			T sum = 0;
   			for(int j = 0; j < B; j++) {
      			for(int k = 0; k < B; k++) {
      				sum += T_matrix[i][k] * val.Get_Cell(k, j);
        			temp.Set_Cell(i, j, sum);
      			}
    		}
    	}
	return temp;
	}
	
	void operator= (matrix <T> mtr) {
		for (auto i =0 ; i < A; i++) {
			for (auto j = 0; j < B; j++) {
				T_matrix[i][j] = mtr.Get_Cell(i, j);
			}
		}
	}
	
private:
	size_t A, B;
	T **T_matrix;
};

int main () {
	matrix <float> A(4, 4);
	matrix <float> B(4, 4);
	matrix <float> C(4, 4);
	
	for (auto i =0 ; i < A.Get_A(); i++) {
		for (auto j = 0; j < A.Get_B(); j++) {
			A.Set_Cell (i, j, rand()%9);
		}
	}
	
	for (auto i =0 ; i < B.Get_A(); i++) {
		for (auto j = 0; j < B.Get_B(); j++) {
			B.Set_Cell (i, j, rand()%9);
		}
	}
	
	
	C = A * B;

	for (auto i =0 ; i < A.Get_A(); i++) {
		for (auto j = 0; j < A.Get_B(); j++) {
			cout << A.Get_Cell (i, j) << ' ';
		}
		cout<<endl;
	}
	cout<<endl<<"---------"<<endl;
	
	for (auto i =0 ; i < B.Get_A(); i++) {
		for (auto j = 0; j < B.Get_B(); j++) {
			cout << B.Get_Cell (i, j) << ' ';
		}
		cout<<endl;
	}
	cout<<endl<<"---------"<<endl;
	
	for (auto i =0 ; i < C.Get_A(); i++) {
		for (auto j = 0; j < C.Get_B(); j++) {
			cout << C.Get_Cell (i, j) << ' ';
		}
		cout<<endl;
	}
	cout<<endl<<"---------"<<endl;
	
return 0;
}
