#include <iostream>
#include <cstdio>
using namespace std;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    // TODO: Read matrix data from the file
    //    Make sure to handle potential errors and invalid input 
    FILE *file=fopen(file_name.c_str(), "r"); //open the file in read mode 
    int n; 
    fscanf(file, "%d", &n); //gets the size of the matrix 
    Matrix temp_matrix_1(n); //initilize new matricies since other ones werent initlized with a size
    Matrix temp_matrix_2(n);
    //matrix_1.matrix_size=n; //check if i can just directly change size; it cant do anything like this will check in debugger l8r 
    //matrix_2.matrix_size=n;
    for (int i=0; i<n; i++) //read each line of file into first matrix
    {
        for (int j=0; j<n; j++) //read each elemnt of each line into matrix properly 
        {fscanf(file, "%lf", &temp_matrix_1.matrix_data[i][j]);}
    }
    for (int i=0; i<n; i++) //read each line of file into first matrix
    {
        for (int j=0; j<n; j++) //read each elemnt of each line into matrix properly 
        {fscanf(file, "%lf", &temp_matrix_2.matrix_data[i][j]);}
    }

    fclose(file); //close file
    //swap data between temp matrices and real matrices
    std::swap(matrix_1.matrix_size, temp_matrix_1.matrix_size);
    std::swap(matrix_1.matrix_data, temp_matrix_1.matrix_data);
    std::swap(matrix_2.matrix_size, temp_matrix_2.matrix_size);
    std::swap(matrix_2.matrix_data, temp_matrix_2.matrix_data);
    
}

void print_matrix(const Matrix& matrix) {
    // TODO: Print the matrix to the console
    for (int i=0; i<matrix.matrix_size; i++) 
    {
        for (int j=0; j<matrix.matrix_size; j++) 
        {
            cout << matrix.matrix_data[i][j] << " ";
        }
        cout << endl; //print end line after each row so that each element in in the same printed row 
    }
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Print both matrices to the console
    print_matrix(matrix_1); 
    cout << endl; //this seems to basically be equivalent to \n plus clears the input buffer line 
    print_matrix(matrix_2); 
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Implement matrix addition
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Implement matrix multiplication
}

// Overloaded + operator for matrix addition
Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2);

// Overloaded * operator for matrix multiplication
Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2);

void get_diagonal_sum(const Matrix& matrix) {
    // TODO: Calculate and print the sum of the diagonal elements
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    // TODO: Swap the rows 'row1' and 'row2' in the matrix
    //    Handle invalid row indices
}

int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

    cout << "print_matrix" << endl;
    print_matrix(matrix_1, matrix_2);

    // cout << "add_matrices result:" << endl;
    // Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    // Matrix add_result_2 = matrix_1 + matrix_2;
    // print_matrix(add_result_1);
    // print_matrix(add_result_2);

    // cout << "multiply_matrices result:" << endl;
    // Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    // Matrix multiply_result_2 = matrix_1 * matrix_2;
    // print_matrix(multiply_result_1);
    // print_matrix(multiply_result_2);

    // cout << "get matrix diagonal sum" << endl;
    // get_diagonal_sum(matrix_1);

    // cout << "swap matrix rows" << endl;
    // swap_matrix_row(matrix_1, 0, 1);

    return 0;
}