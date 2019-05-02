#include <iostream>
#include <cmath>

#define NO_SQUARE 0

using namespace std;

class shape {
	public:
		virtual void Draw () = 0;
		
		virtual float Calc_Square () = 0;
};

class square : public shape {
	public:
	square (uint16_t a) : A(a) {
			
	}
		
	void Draw () {
		cout<< "square draw"<<endl;
	}
	
	float Calc_Square () {
		return (A * A);
	}	
	
	private:
	uint16_t A;
};

class rectangular : public shape {
	public:
	rectangular (uint16_t a, uint16_t b) : A(a), B(b) {
		
	}
	void Draw () {
		cout<< "rectangular draw"<<endl;
	}
	float Calc_Square () {
		return (A * B);
	}
	
	private:
	uint16_t A, B;
};

class triangle : public shape {
	public:
	triangle (uint16_t a, uint16_t b, uint16_t c) : A(a), B(b), C(c) {
		
	}
	void Draw () {
		cout<< "triangle draw"<<endl;
	}
	float Calc_Square () {
		if (((A +B) > C) || ((B + C) > A) || ((A + C) > B)) {
			uint16_t P = (A + B + C) / 2;
			return sqrt(P * (P - A) * (P - B) * (P - C));
		}
		return NO_SQUARE;
	}
	private:
	uint16_t A, B, C;
};

void Func ( shape *data) {
	data->Draw();
	cout << data->Calc_Square() << endl;
}

int main () {
	triangle A(5, 7, 5);
	rectangular B (90, 6);
	square C (90);
	
	shape *p_shape = &A;
	Func (p_shape);
	
	p_shape = &B;
	Func (p_shape);
	
	p_shape = &C;
	Func (p_shape);

	return 0;
}
