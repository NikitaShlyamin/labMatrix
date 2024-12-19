#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


template<typename T=double>
class MatrixDense
{
    const unsigned _m;
    const unsigned _n;

public:
    T* _data;

    MatrixDense(unsigned m, unsigned n) :
        _m(m),
        _n(n)
    {
        _data = new T[_m * _n];
    }
    ~MatrixDense()
    {
        delete[] _data;
    }
    void setElement(unsigned i, unsigned j, T value)
    {
        unsigned index = j + i * _n;
        _data[index] = value;
    }
    T getElement(unsigned i, unsigned j) const
    {
        return _data[j + i * _n];
    }

    virtual void randMatrix()
    {
        
        for (unsigned i = 0; i < _m; i++)
        {
            for (unsigned j = 0; j < _n; j++)
            {
                setElement(i, j, rand() % 100);
            }
        }
    }
    void Print()
    {
        cout << "_m =" << _m << endl << "_n= " << _n << endl;

        for (unsigned i = 0; i < _m; i++)
        {
            for (unsigned j = 0; j < _n; j++)
            {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
    MatrixDense operator +(const MatrixDense& m2)
    {
        if (_n != m2._n || _m != m2._m)
        {
            throw invalid_argument("Размерность матриц не совместима");
        }
        MatrixDense res(_m, _n);  
        for (unsigned i = 0; i < _m * _n; i++)
        {
            res._data[i] = _data[i] + m2._data[i];
        }

        return res;
    }
    MatrixDense operator -(const MatrixDense& m2)
    {
        if (_n != m2._n || _m != m2._m)
        {
            throw invalid_argument("Размерность матриц не совместима");
        }
        MatrixDense res(_m, _n);
        for (unsigned i = 0; i < _m * _n; i++)
        {
            res._data[i] = _data[i] - m2._data[i];
        }

        return res;
    }

    MatrixDense operator *(const MatrixDense& m2)
    {
        if (_n != m2._m)
        {
            throw invalid_argument("Размерность матриц не совместима");
        }

        MatrixDense res(_m, m2._n);  

        for (unsigned i = 0; i < _m; i++) 
        {
            for (unsigned j = 0; j < m2._n; j++)  
            {
                T sum = 0;  
                for (unsigned k = 0; k < _n; k++)
                {
                    sum += getElement(i, k) * m2.getElement(k, j); 
                }
                res.setElement(i, j, sum); 
            }
        }

        return res;
    }

};


int main()
{
    setlocale(LC_ALL, "RU");
    unsigned m = 5, n = 5;

    srand(time(0));

    MatrixDense<> matrix1(m, n), m2(m, n);

    matrix1.randMatrix();
    m2.randMatrix();

    cout << "\n------------------------\n Матрица1 \n------------------------\n";
    matrix1.Print();
    cout << "\n------------------------\n Матрица2 \n------------------------\n";
    m2.Print();

    MatrixDense<> m3 = matrix1 + m2;
    MatrixDense<> m4 = m3 - m2;
    MatrixDense<> m5 = matrix1 * m2;

    cout << "\n------------------------\n Матрица3 \n------------------------\n";
    m3.Print();
    cout << "\n------------------------\n Матрица4 \n------------------------\n";
    m4.Print();
    cout << "\n------------------------\n Матрица5 \n------------------------\n";
    m5.Print();


}
