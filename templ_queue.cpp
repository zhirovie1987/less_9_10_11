#include <iostream>

using namespace std;

template <class T> 
class t_queue {
public:
t_queue (size_t size) : Size(size) {
	Q_Start = new T [Size];
	Q_End = Q_Start;
}

void Add (T data) {
	if (Q_End != Q_Start + Size) {
		Q_End++;
		*Q_End = data;
	}
}

T Get () {
	if (Q_End != Q_Start) {
		T temp = *Q_End;
		Q_End--;
		return temp;
	}
	
return *(++Q_End);	
}

void Delete () {
	
}

private:	
 T *Q_End;
 T *Q_Start;
 size_t Size;
};

int main () {
	t_queue <float> Q (5);
	
	for (auto i = 0; i < 5; i++) {
		Q.Add(rand()%9);
	}
	
	for (auto i = 0; i < 5; i++) {
		cout<<Q.Get()<<' ';
	}
	
	Q.Add(rand()%9);
	Q.Add(rand()%9);
	Q.Add(rand()%9);
	Q.Add(rand()%9);
	Q.Add(rand()%9);
	Q.Add(rand()%9);
	cout<<endl;
	
	for (auto i = 0; i < 6; i++) {
		cout<<Q.Get()<<' ';
	}
	return 0;
}
