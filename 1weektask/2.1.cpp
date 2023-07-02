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
    Matrix()
    {
        n=0;
        m=0;
    }
     int&   At(int i,int j)
    {

            return matrix.at(i).at(j);
        throw  out_of_range("");
    }
      int  At(int i,int j)const
    {
        if(((0<=i)&&(i<n))&&((0<=i)&&(j<m)))
        {
            return matrix[i][j];
        }
        throw  out_of_range("" );
    }
    Matrix(pair<int,int> pr)
    {
        Matrix(pr.first,pr.second);
    }
    Matrix(int n,int m)
    {
        if(n<0||m<0)
        {
            throw  out_of_range("");
        }
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
        for(int i=0;i<n;++i)
        {
            matrix[i].resize(m);
            for(int j=0;j<m;++j)
            {
                matrix[i][j]=0;
            }
        }
    }
    void Reset(int n,int m)
    {
        if(n<0||m<0)
        {
            throw  out_of_range("");
        }
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
        for(int i=0;i<n;++i)
        {
            matrix[i].resize(m);
            for(int j=0;j<m;++j)
            {
                matrix[i][j]=0;
            }
        }
    }


    int GetNumRows()const
    {
        return n;
    }
    int GetNumColumns()const
    {
        return m;
    }

    bool operator==(const Matrix& matrix)const
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
    int n,m;
    int tmp;
    in>>n>>m;
    matrix.Reset(n,m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            in>>tmp;
            matrix.At(i,j)=tmp;
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
            out <<matrix.At(i,j)<<" ";
        }
        out<<endl;
    }
    return out;

}
Matrix& operator +(const Matrix& lhs,const Matrix& rhs)
{
    if(lhs.size()!=rhs.size())
    {
        throw  invalid_argument("");
    }
    Matrix *result=new Matrix(lhs.size().first,lhs.size().second);
    for(int i=0;i<lhs.GetNumRows();++i)
    {
        for(int j=0;j<lhs.GetNumColumns();++j)
        {
           // cout<<"nya "<<result->size().first<<"   "<<result->size().second<<endl;
            result[0].At(i,j)=lhs.At(i,j)+rhs.At(i,j);
        }
    }
    return result[0];
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
