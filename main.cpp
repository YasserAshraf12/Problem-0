// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: Problem 0 --> Assignment 1
// Purpose: Operators Overloading Assignment
// Author:  Yasser Ashraf && Heba Muhammed && Omar Tarek
// Date:    30 September 2018
// Version: 1.0
#include <iostream>
#include <iomanip>
//#include <cassert>
using namespace std;
// A structure to store a matrix
int scalar;//----
int sum;//       |---->This There Global Function Used To Make Them Valuable in All Functions.
int value;//-----
//-------------------------------------------------
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};
//------------------------------------------------------------------
void createMatrix (int row, int col, int num[], matrix& mat) //Create Matrix Function(row no.,Cols no., array 1d array, Matrix )
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];
    for (int i = 0; i < row; i++)
    {
        mat.data[i] = new int [col];
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            mat.data[i][j] = num[i * col + j];}
    }
}
//-----------------------------------------------------------
//(Smallest ID:20170331)(Yasser Ashraf Salah)
matrix operator+ (matrix mat1, matrix mat2)
{
    if(mat1.row==mat2.row &&mat1.col==mat2.col)//Check If The Dimensions Of The Two Added Matrices is Equal
    {
        matrix newMatrix;
        newMatrix.data=new int *[mat1.row];   //Make More Than One Pointer (With The count Of row Number).
        for(int i=0; i< mat1.row; i++)
        {
            newMatrix.data[i]=new int [mat1.col];//Use Pointer To Col.
            for(int j=0; j< mat1.col; j++)
            {
                newMatrix.data[i][j]=(mat1.data[i][j] + mat2.data[i][j]);
            }
        }
        return newMatrix;
    }
    else{cout<<" Not Equal!  "<<endl;}
}
//--------------------------------------
matrix operator- (matrix mat1, matrix mat2)//Check If The Two Matrices Are equal.
{
    if(mat1.row==mat2.row &&mat1.col==mat2.col)
    {
        matrix newMatrix;
        newMatrix.data=new int *[mat1.row];  //Make More Than One Pointer (With The count Of row Number).
        for(int i=0; i< mat1.row; i++)
        {
            newMatrix.data[i]=new int [mat1.col];
            for(int j=0; j< mat1.col; j++)
            {
                newMatrix.data[i][j]=(mat1.data[i][j] - mat2.data[i][j]);
            }
        }
        return newMatrix;
    }
    else{cout<<" Matrices isn't Equal!  "<<endl;}
}
//------------------------------------------------
matrix operator+  (matrix mat1, int scalar)
{
    matrix newMatrix;
    newMatrix.data=new int *[mat1.row];
    cout<<"Please Enter The Scaler Value: ";
    cin>>scalar;
    for(int i=0; i<mat1.row; i++)
    {
        newMatrix.data[i]=new int [mat1.col];
        for(int j=0; j<mat1.col; j++)
        {
            newMatrix.data[i][j]=((mat1.data[i][j]) + (scalar));
        }
    }
    return newMatrix;
}
//----------------------------------------------------
matrix operator- (matrix mat1, int scalar)
{
    matrix newMatrix;
    newMatrix.data=new int *[mat1.row];
    cout<<"Please Enter The Scaler Value: ";
    cin>>scalar;   // Enter The Value Of Scalar ;
    for(int i=0; i<mat1.row; i++)
    {
        newMatrix.data[i]=new int [mat1.col];
        for(int j=0; j<mat1.col; j++)
        {
            newMatrix.data[i][j]=((mat1.data[i][j]) - (scalar));
        }
    }
    return newMatrix;
}
//------------------------------------------------------------
matrix operator* (matrix mat1, int scalar)
{
    matrix newMatrix;
    newMatrix.data= new int *[mat1.row];
    cout<<"Please Enter The Scaler Value: ";
    cin>>scalar;
    for(int i=0; i<mat1.row; i++)
    {
        newMatrix.data[i]=new int[mat1.col];
        for(int j=0; j<mat1.col; j++)
        {
            newMatrix.data[i][j]=((mat1.data[i][j]) * (scalar));
        }
    }
    return newMatrix;
}
//-----------------------------------------------------------------
matrix operator* (matrix mat1, matrix mat2)
{
    matrix newMatrix;
    newMatrix.row=mat1.row;
    newMatrix.col=mat2.col;
    newMatrix.data= new int *[mat1.row];
    for(int i=0; i<mat1.row; i++)
    {
        newMatrix.data[i]=new int [mat2.col];
        for(int j=0; j<mat1.col; j++)
        {
            newMatrix.data[i][j]=0; //initi. elements in matrix.
        }
    }
    //-------------------------------------------
    for(int i = 0; i < mat1.row; ++i){
        for(int j = 0; j < mat2.col; ++j){
            for(int k = 0; k < mat1.col; ++k) //for shifting Of Rows and Cols
            {
                newMatrix.data[i][j] += ((mat1.data[i][k])*(mat2.data[k][j]));
            }
        }
    }
    return newMatrix;

}

//-----------------------------------------------------------------
//(Biggest ID:20170329 (Heba Muhammed Ali)
ostream& operator<< (ostream& out, matrix mat)
{
    int col=mat.col;
    int row= mat.row;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j< col;j++)
        {
            out<< mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
    cout<<endl;
}
//reem ashraf salah////////////////
void reem (matrix mat1,matrix mat2)
{

    cout << (mat1*mat2) <<endl;
}
//------------------------------------------------------------------------
bool   operator== (matrix mat1, matrix mat2)
{
    bool status = true;
    if(mat1.col==mat2.col&&mat1.row==mat2.row)
    {
        for(int i=0;i<mat1.row;i++)
        {
            for(int j=0;j< mat1.col;j++)
            {
                if(mat1.data[i][j]!= mat2.data[i][j])
                {
                    status=false;
                    return status;
                }
            }
        }
    }
    else{status=false;}
    return status;
}
//-----------------------------------------------------------
bool   operator!= (matrix mat1, matrix mat2)
{
    bool status = false;
    if(mat1.col==mat2.col&&mat1.row==mat2.row)
    {
        for(int i=0;i<mat1.row;i++)
        {
            for(int j=0;j< mat1.col;j++)
            {
                if(mat1.data[i][j]!= mat2.data[i][j])
                {
                   status=true;
                   return status;
                }
            }
        }
    }
    else{
        status=true;}
    return status;
}
//--------------------------------------------------------
bool   isSquare  (matrix mat)
{
    bool status = true;
    if(mat.col!=mat.row)
    {
        status= false;
    }
    return status;
}
//----------------------------------------------------------
bool   isSymetric (matrix mat)
{
    bool status= true;
    if(mat.col==mat.row)
    {
        for(int i=0;i<mat.row;i++)
        {
            for(int j=0;j<mat.col;j++)
            {
                if(mat.data[i][j]!= mat.data[j][i])
                {
                    status=false;
                    return status;
                }
            }
        }
    }
    else{status=false;}
    return status;
}
//------------------------------------------------------------
bool   isIdentity(matrix mat)
{
    bool status= true;
    if(isSymetric(mat))
    {
        for(int i = 0;i < mat.row; i++)
        {
            for(int j = 0; j<mat.col; j++)
            {
                if(i==j)
                {
                    if(mat.data[i][j]!=1)
                    {
                        status=false;
                        return status;
                    }
                }
                else{
                    if(mat.data[i][j]!=0)
                    {
                        status=false;
                        return status;
                    }
                }
            }
        }
    }
    else{
        status=false;
        return status;
    }
    return status;
}
//-----------------------------------------------------------
matrix transpose(matrix mat)
{
    matrix MAT;
    int data[mat.col*mat.row];
    int c=0;
    for(int i=0;i<mat.col;i++)
    {
        for(int j=0;j<mat.row;j++)
        {
            data[c]=mat.data[j][i];
            c++;
        }
    }
    createMatrix(mat.col, mat.row, data, MAT);
    cout<<MAT;
    return MAT;
}
//-------------------------------------------------------
//(Middle ID:20170178 (Omar Tarek Abd El Aziz)
matrix operator+= (matrix& mat1, matrix mat2)
{
    matrix newMatrix;
    newMatrix.data=new int *[mat1.row];
    if(mat1.row==mat2.row &&mat1.col==mat2.col)
    {
        for(int i =0; i< mat1.row; i++){
            newMatrix.data[i]=new int [mat1.col];
            for(int j = 0; j<mat1.col; j++){
                mat1.data[i][j]=(mat1.data[i][j]+mat2.data[i][j]);
            }
        }
        for(int i =0; i< mat1.row; i++){
            for(int j = 0; j<mat1.col; j++){
                newMatrix.data[i][j]=mat1.data[i][j];
            }
        }
        return newMatrix;
    }
}
//-------------------------------------------------------
matrix operator+= (matrix& mat1, int scalar)
{
    cout<<"Please Enter The Scalar Value: ";
    cin>>scalar;
    matrix newMatrix;
    newMatrix.data=new int *[mat1.row];
    for(int i =0; i< mat1.row; i++){
        newMatrix.data[i]=new int [mat1.col];
        for(int j = 0; j<mat1.col; j++){
            mat1.data[i][j]=(mat1.data[i][j] + scalar);
        }
    }
    for(int i =0; i< mat1.row; i++){
        for(int j = 0; j<mat1.col; j++){
            newMatrix.data[i][j]=mat1.data[i][j];
        }
    }
    return newMatrix;
}
//---------------------------------------------------------
matrix operator-= (matrix& mat1, matrix mat2)
{
    matrix newMatrix;
    newMatrix.data=new int *[mat1.row];
    if(mat1.row==mat2.row &&mat1.col==mat2.col)
    {
        for(int i =0; i< mat1.row; i++){
            newMatrix.data[i]=new int [mat1.col];
            for(int j = 0; j<mat1.col; j++){
                mat1.data[i][j]=(mat1.data[i][j] - mat2.data[i][j]);
            }
        }
        for(int i =0; i< mat1.row; i++){
            for(int j = 0; j<mat1.col; j++){
                newMatrix.data[i][j]=mat1.data[i][j];
            }
        }
        return newMatrix;
    }
}
//-------------------------------------------------------
matrix operator-= (matrix& mat1, int scalar)
{
    cout<<"Please Enter The scalar Value: ";
    cin>>scalar;
    matrix newMatrix;
    newMatrix.data=new int *[mat1.row];
    for(int i =0; i< mat1.row; i++){
        newMatrix.data[i]= new int [mat1.col];
        for(int j = 0; j<mat1.col; j++){
            mat1.data[i][j]=(mat1.data[i][j] - scalar);
        }
    }
    for(int i =0; i< mat1.row; i++){
        for(int j = 0; j<mat1.col; j++){
            newMatrix.data[i][j]=mat1.data[i][j];
        }
    }
    return newMatrix;
}
//----------------------------------------------------------------------------
matrix operator++ (matrix& mat)// Add 1 to each element ++mat
{
    matrix newMatrix;
    newMatrix.data=new int *[mat.row];
    for(int i = 0; i<mat.row; i++){
        newMatrix.data[i]=new int [mat.col];
        for(int j = 0; j < mat.col; j++)
        {
            mat.data[i][j]=((mat.data[i][j])+1);
        }
    }
    for(int i = 0; i<mat.row; i++){
        for(int j = 0; j < mat.col; j++)
        {
            newMatrix.data[i][j]=mat.data[i][j];
        }
    }
    return newMatrix;
}
//------------------------------------------------------------------------------
matrix operator-- (matrix& mat)// subtract 1 to each element --mat
{
    matrix newMatrix;
    newMatrix.data=new int *[mat.row];
    for(int i = 0; i<mat.row; i++){
        newMatrix.data[i]=new int [mat.col];
        for(int j = 0; j < mat.col; j++)
        {
            mat.data[i][j]=((mat.data[i][j])-1);
        }
    }
    for(int i =0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++){
            newMatrix.data[i][j]=mat.data[i][j];
        }
    }
    return newMatrix;
}
//------------------------------------------------
istream& operator>> (istream& in, matrix& mat)
{
    int col=mat.col;
    int row= mat.row;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j< col;j++)
        {
            in >> mat.data[i][j];
        }
    }
    return in;
}
//-----------------------------------------------------------
int main()
{
    int data1 [] = {1,1,1,1,1,1,1,1,1};
    int data2 [] = {1,1,1,1,1,1,1,1,1};
    int data3 [] = {2,3,5,6,8,9,7,1};

    matrix mat1, mat2, mat3;
    createMatrix (3, 3, data1, mat1);
    createMatrix (3, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
    cout<<mat1*mat2;
    return 0;
}
