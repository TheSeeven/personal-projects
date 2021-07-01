// Tema5_CCIOT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Number {
private:
	int value;
	bool assigned;
public:
	Number() {
		assigned = false;
		value = 0;
	}
	Number(int x) {
		value = x;
		assigned = true;
	}
	~Number() { /*cout << "Number Destructed!" << endl;*/ }

	int getNumber() {
		return value;
	}
	bool exists() {
		return assigned;
	}
	void setNumber(int value) {
		this->value = value;
	}
	void assign() {
		assigned = true;
	}
};

class Matrix {

private:
	unique_ptr<Number[]> matrix;
	int size;
	int rows;
	int columns;
	int transform(int row, int column) {
		return (columns * (row - 1)) + column;
	}
	int transform(int row, int column,int columns) {
		return (columns * (row - 1)) + column;
	}
	int getSize() {
		return columns * rows;
	}
	Matrix(int size, int rows, int columns) { this->size = size; this->rows = rows; this->columns = columns; matrix = make_unique<Number[]>(columns*rows); }
public:
	Matrix() { size = 0; rows = 0; columns = 0; matrix = make_unique<Number[]>(0); }
	~Matrix() { /*cout << "Matrix Destructed!" << endl;*/ }
	Matrix(Matrix&&) = default;
	Matrix(Matrix& other) {
		this->size = other.size;
		this->columns = other.columns;
		this->rows = other.rows;
		this->matrix = make_unique<Number[]>(size);
		for ( int i = 0; i < size; i++ ) {
			matrix[i] = other.matrix[i];
		}
	}

	Matrix operator+(const Matrix& other) {
		if ( this->rows == other.rows && this->columns == other.columns && this->size == other.size ) {
			for ( int i = 0; i < this->size; i++ ) {
				if ( this->matrix[i].exists() && other.matrix[i].exists() )
					this->matrix[i].setNumber(other.matrix[i].getNumber() + this->matrix[i].getNumber());
				else if ( !this->matrix[i].exists() && other.matrix[i].exists() ) {
					this->matrix[i].setNumber(other.matrix[i].getNumber());
					this->matrix[i].assign();
				}		
			}	
		}
		return *this;
	}

	

	void addAt(int row, int column, int number) {
		if ( size == 0 ) {
			rows = row;
			columns = column;
			size = getSize();
			matrix = make_unique<Number[]>(size);
			matrix[transform(row, column) - 1] = Number(number);
		}
		else {
			if ( row <= rows && column <= columns ) {
				matrix[transform(row, column) - 1] = Number(number);
			}
			else {
				int pastColumns = this->columns;
				int pastRows = this->rows;
				int pastSize = this->size;

				int pastRowCounter = 1;
				int pastColumnCounter = 1;
				
				if ( row > rows ) {
					rows = row;
				}
				if ( column > columns ) {
					columns = column;
				}
				size = this->getSize();
				unique_ptr<Number[]> temp = make_unique<Number[]>(size);			
				for ( int i = 1; i <= rows; i++ ) {
					if ( pastRows < pastRowCounter ) { break; }
					for ( int j = 1; j <= columns; j++ ) {
						if ( pastColumns < pastColumnCounter ) { break; }
						temp[transform(i, j)-1] = matrix[transform(pastRowCounter,pastColumnCounter,pastColumns)-1];
						pastColumnCounter++;
					}
					
					pastRowCounter++;
					pastColumnCounter = 1;
				}
				temp[transform(row, column) - 1] = Number(number);
				matrix = move(temp);
				size = getSize();
			}
		}
	}
	void display() {
		int columnCounter = 0;
		for ( int i = 0; i < size; i++ ) {
			if ( columnCounter == columns ) {
				cout << endl;
				columnCounter = 0;
			}
			if ( matrix[i].exists() ) {
				cout << matrix[i].getNumber() << " ";

			}
			else {
				cout << "X" << " ";
			}
			columnCounter++;
		}
		cout << endl << endl;
	}
};



class Animal
{
private:
	string specie;
	string gender;
	unsigned int varsta;

public:
	Animal(string specie, string gender, unsigned int varsta) {
		this->specie = specie;
		this->gender = gender;
		this->varsta = varsta;
	}
	~Animal() {}

	string getSpecie() const {
		return specie;
	}
	string getGender() const {
		return gender;
	}
	unsigned int getVarsta() const {
		return varsta;
	}
	bool operator < (const Animal& p) const {
		return p.getVarsta() < this->getVarsta();
	}

	

};

ostream& operator << (ostream& out, const Animal& obj) {
	return out << "Specie: " << obj.getSpecie() << endl << "Gender: " << obj.getGender() << endl << "Varsta: " << obj.getVarsta() << endl << endl;
}

bool toAdopt(shared_ptr<Animal> cmp, string specie, string gender, unsigned int varsta) {
	if ( cmp.get()->getGender() == gender && cmp.get()->getSpecie() == specie && cmp.get()->getVarsta() == varsta ) {
		return true;
	}
	return false;
}

void adopt(vector< shared_ptr<Animal> > &vector, string specie, string gender, unsigned int varsta) {
	
	std::vector< shared_ptr<Animal> > result;
	for ( shared_ptr<Animal> i : vector ) {
		if ( i.get()->getGender() == gender && i.get()->getSpecie() == specie && i.get()->getVarsta() == varsta ) {
			cout << "A fost adoptat!: " << endl << *i.get() << endl;
			i.reset();
		}
		else {
			result.push_back(i);
		}
	}
	vector = result;
}

void displayVector(vector< shared_ptr<Animal> >&vector) {
	for ( shared_ptr<Animal> i : vector ) {
		cout << *i.get() << endl;
	}
}



int main() {
	cout << "EXERCITIUL 1" << endl << endl;
	Matrix m1 = Matrix();
	m1.addAt(2, 2, 9);
	m1.addAt(1, 2, 7);
	m1.addAt(2, 1, 6);
	m1.addAt(2, 3, 5);
	m1.addAt(3, 2, 4);
	m1.addAt(3, 3, 888);
	cout << "matrix m1:" << endl;
	m1.display();

	Matrix m2 = Matrix();
	m2.addAt(2, 2, 10);
	m2.addAt(1, 2, 666);
	m2.addAt(2, 1, 8);
	m2.addAt(2, 3, -5);
	m2.addAt(3, 2, 77);
	m2.addAt(1, 1, 999);
	cout << "matrix m2:" << endl;
	m2.display();

	Matrix m3 = Matrix(m2);
	cout << "matrix m3 dupa copiere:" << endl;
	m3.display();

	Matrix m4 = m1;
	cout << "matrix m4 dupa asignare:" << endl;
	m4.display();

	
	Matrix m5 = m1 + m2;
	cout << "matrix m5 dupa asignarea adunarii dintre m1 + m2:" << endl;
	m5.display();

	cout << endl << endl << "EXERCITIUL 2" << endl << endl;

	vector< shared_ptr<Animal> > vector;
	vector.push_back(make_shared<Animal>("caine", "mascul", 1));
	vector.push_back(make_shared<Animal>("pisica", "femela", 1));
	vector.push_back(make_shared<Animal>("broasca testoasa", "mascul", 2));
	vector.push_back(make_shared<Animal>("caine", "femela", 2));
	vector.push_back(make_shared<Animal>("papagal", "mascul", 1));
	vector.push_back(make_shared<Animal>("pisica", "mascul", 3));
	vector.push_back(make_shared<Animal>("iepure", "femela", 2));
	vector.push_back(make_shared<Animal>("iepure", "mascul", 2));
	cout << "Toate animalele" << endl;
	displayVector(vector);

	adopt(vector, "papagal", "mascul", 1);
	cout << "Dupa adoptie: " << endl << endl;
	displayVector(vector);
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
