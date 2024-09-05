#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class matrix 
{
public:
    using value_type = T;
    using iterator = typename vector<T>::iterator;
    using const_iterator = typename vector<T>::const_iterator;

    matrix() : rows(0), cols(0), scheme() {}
    matrix(int _row, int _cols, const T& data = T()) : rows(_row), cols(_cols) {
      scheme = vector<T>(rows * cols, data);
    }
    matrix(const matrix<T>& other) : rows(other.rows), cols(other.cols), scheme(other.scheme) {}

    matrix& operator=(const matrix<T>& other) {
      this->rows = other.rows;
      this->cols = other.cols;  
      this->scheme = other.scheme;

      return *this;
    }

    const T& operator()(int i, int j) const {
      return scheme[ i * cols + j];  
    }

    T& operator()(int i, int j) {
      return scheme[ i * cols + j];  
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << scheme[i * cols + j] << " ";
            }
            cout << endl;
        }
    }

    iterator begin() {
        return scheme.begin();
    }

    iterator end() {
        return scheme.end();
    }

    const_iterator begin() const {
        return scheme.begin();
    }

    const_iterator end() const {
        return scheme.end();
    }

private:
    int rows;
    int cols;
    vector<T> scheme;
};

int main()
{
    matrix<int> x(5, 6, 34);
    x(2, 3) = 100;
    for(typename matrix<int>::iterator i = x.begin(); i != x.end(); i++){  
      cout << *i << " ";
    }
    cout << endl;
    x.print(); 
    int a = x(2, 3);
    cout << a << endl;
    return 0;
}
