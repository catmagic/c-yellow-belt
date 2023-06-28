#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream+
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix+
// * оператор сложения двух объектов класса Matrix
class Matrix
{
public:
    Matrix(){n=0;m=0;}
    void Reset(size_t n,size_t m)
    {
        if(n==0||m==0)
        {
            this->n=0;
            this->m=0;
            matrix.resize(0);
            return;
        }
        matrix.resize(n);
        this->n=n;
        this->m=m;
        for(size_t i=0;i<n;++i)
        {
            matrix[i].resize(m);
            for(size_t j=0;j<m;++j)
            {
                matrix.set(i,j,0);
            }
        }
    }
    void set(size_t i,size_t j,int num)
    {
        matrix[i][j]=num;
    }
    int get(size_t i,size_t j)const
    {
        return matrix[i][j];
    }
    bool operator==(const Matrix& matrix)
    {
        return this->n==matrix.n&&this->m==matrix.m&&this->matrix==matrix.matrix;
    }
    pair<size_t,size_t> size()const
    {
        return {n,m};
    }

private:
    size_t n,m;
    vector<vector<int>> matrix;
};
istream& operator>>(istream& in,Matrix& matrix)
{
    size_t n,m;
    int tmp;
    in>>n>>m;
    matrix.Reset(n,m);
    for(size_t i=0;i<n;++i)
    {
        for(size_t j=0;j<m;++j)
        {
            in>>tmp;
            matrix.set(i,j,tmp);
        }
    }
    return in;

}
ostream& operator<<(ostream& out,const Matrix& matrix)
{
    auto sizeM=matrix.size();
    out<<sizeM.first<<" "<<sizeM.second<<endl;
    for(size_t i=0;i<sizeM.first;++i)
    {
        for(size_t j=0;j<sizeM.second;++j)
        {
            out <<matrix.get(i,j)<<" ";
        }
        out<<endl;
    }
    return out;

}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
 // cout<<(one==two);
  cout << one + two << endl;
  return 0;
}
