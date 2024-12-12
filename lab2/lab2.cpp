#include <iostream>
#include <vector>

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
    T getElement(unsigned i, unsigned j)
    {
        return _data[j + i * _n];
    }

    virtual void randMatrix()
    {
        srand(time(0));
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
        MatrixDense res(_m, _n);  
        for (unsigned i = 0; i < _m * _n; i++)
        {
            res._data[i] = _data[i] + m2._data[i];
        }

        return res;
    }
    MatrixDense operator -(const MatrixDense& m2)
    {
        MatrixDense res(_m, _n);
        for (unsigned i = 0; i < _m * _n; i++)
        {
            res._data[i] = _data[i] - m2._data[i];
        }

        return res;
    }

};
//template<typename T = double>
//class MatrixDiagonal
//{
//    const unsigned _m;
//    const unsigned _n;
//
//    vector<int> indexes; // Храним индексы не 0 диагоналей
//    T* _data;
//    _data = new T[indexes.size() * _m];
//};

int main()
{
    MatrixDense<> m(10, 10), m2(10, 10);
    m.randMatrix();

    m2.randMatrix();

    m.Print();
    m2.Print();

    MatrixDense<> m3 = m + m2;
    MatrixDense<> m4 = m3 - m2;

    m3.Print();
    m4.Print();
}
//реализовать класс диагональной матрицы, написать перегрузки +, -, *, T