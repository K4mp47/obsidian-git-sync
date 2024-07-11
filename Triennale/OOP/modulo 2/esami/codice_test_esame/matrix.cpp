#include <iostream>
#include <vector>
#include <string>

/*
 * const prima della funzione significa che il valore di ritorno non può essere modificato
 * const dopo la funzione significa che la funzione non modifica nessun membro dell'oggetto
 */

/**
 * @class matrix
 * @brief A template class for a 2D matrix.
 *
 * This class provides basic functionalities for a 2D matrix, including
 * element access, size retrieval, and assignment operations.
 *
 * @tparam T The type of elements stored in the matrix.
 */

using namespace std;

template <class T> // cpp template system
class matrix
{
private:
    vector<T> v;
    size_t cols;

public:
    /**
     * @brief Default constructor.
     *
     * Initializes an empty matrix.
     */
    matrix() : v(), cols(0) {} // default constructor

    /**
     * @brief Copy constructor.
     *
     * Initializes a matrix as a copy of another matrix.
     * @param m The matrix to copy.
     */
    matrix(const matrix<T> &m) : v(m.v), cols(m.cols) {} // copy constructor

    template <class S>
    matrix(matrix<S> &m) : cols(m.get_cols()), v(m.get_rows() * m.get_cols()) // conversion constructor
    {
        size_t s = m.get_size();
        for (size_t i = 0; i < s; i++)
        {
            v[i] = T(m(i / cols, i % cols));
        }
    }

    /**
     * @brief Constructor with dimensions.
     *
     * Initializes a matrix with a given number of rows and columns.
     * @param rows The number of rows.
     * @param _cols The number of columns.
     */
    matrix(size_t rows, size_t _cols) : cols(_cols), v(rows * _cols) {} // senza _cols abbiamo shadowing

    /**
     * @brief Constructor with dimensions and initial value.
     *
     * Initializes a matrix with a given number of rows and columns, and
     * fills it with a given initial value.
     *
     * @param rows The number of rows.
     * @param _cols The number of columns.
     * @param x The initial value.
     */
    matrix(size_t rows, size_t _cols, const T &x) : cols(_cols), v(rows * _cols, x) {} // senza _cols abbiamo shadowing

    /**
     * @brief Constructor with square dimensions.
     *
     * Initializes a square matrix with a given number of rows and columns.
     * @param dim The number of rows and columns.
     */
    explicit matrix(size_t dim) : matrix(dim, dim) {} // constructor without implicit convertion

    /**
     * @brief Destructor.
     */
    ~matrix() {} // destructor

    size_t get_cols() const { return cols; }

    size_t get_rows() const { return v.size() / cols; }

    operator const vector<T>() const
    {
        return v;
    }

    const size_t get_size() const
    {
        return v.size();
    }


    const void get_matrix() const
    {
        for (size_t i = 0; i < get_rows(); i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                // get the type of variable and it's value
                cout << typeid(v[i * cols + j]).name() << ":" << v[i * cols + j] << " ";
            }
            cout << endl;
        }
    }

    const T &operator()(size_t i, size_t j) const
    {
        return v[i * cols + j];
    }

    const T &at(size_t i, size_t j) const
    {
        return v[i * cols + j];
    }

    T &operator()(size_t i, size_t j)
    {
        return v[i * cols + j];
    }

    matrix<T> &operator=(const matrix<T> &m)
    {
        cols = m.cols;
        v = m.v;
        return *this; // deferenziare perché ritorno una reference
    }


};

int main()
{
    matrix<int> m(20, 30, 2);
    cout << m.get_cols() << endl;
    cout << m.get_size() << endl;
    m(18, 10) = m(3, 4);

    matrix<int> m2(20, 20, 10);
    m = m2;
    cout << m.get_cols() << endl;
    cout << m.get_size() << endl;

    matrix<double> m3(m);
    cout << m3.get_cols() << endl;
    cout << m3.get_size() << endl;
    m3.get_matrix();
}
