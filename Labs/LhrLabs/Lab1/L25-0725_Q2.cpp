#include<iostream>

using namespace std;

template <typename T> class Matrix {
private:
	T** data;
	int rows;
	int columns;
public:
	Matrix(int r, int c) : rows(r), columns(c) {
		data = new T* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new T[columns];
		}
		cout << "Enter the Entries of the Matrix\n";
	
        // for (int i = 0; i < rows; i++) {
		// 	for (int j = 0; j < columns; j++) {
		// 		cin >> data[i][j];
		// 	}
		// }
	}	

	Matrix() : rows(0) , columns(0) , data(NULL){}

	int countGreater(T key) {
		int count = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (data[i][j] > key) {
					count++;
				}
			}
		}
		return count;
	}

	int countLess(T key) {
		int count = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (data[i][j] < key) {
					count++;
				}
			}
		}
		return count;
	}

    void setElement(T element, int r, int c ){
        data[r][c] = element;
    }

    void display(){
        for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
                T Element = data[i][j]; 
				cout << Element << " ";
			}
            cout<< endl;
		}
    }

    ~Matrix(){
        if(data){
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }
        data =NULL;
    }
};

int main(){

    Matrix<int> integerMatrix(3,3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int element=0;
            cout << "Enter element on index " << i << j<< endl; 
            cin >> element;
            integerMatrix.setElement(element,i,j);
        }
    }

    integerMatrix.display();

    cout << "Number of Elements greater than 5: " << integerMatrix.countGreater(5)<<endl;
    cout << "Number of Elements less than 5: " << integerMatrix.countLess(5)<<endl;

    cout << "\n\n----------- Character Matrix -------------\n\n";
    // Character matrix
    Matrix<char> charMatrix(3,3);

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            char element='0';
            cout << "Enter element on index " << i << j<< endl; 
            cin >> element;
            charMatrix.setElement(element,i,j);
        }
    }

    charMatrix.display();

    cout << "Number of Elements greater than D: " << charMatrix.countGreater('d')<<endl;
    cout << "Number of Elements less than D: " << charMatrix.countLess('d')<<endl;

    return 0;
}