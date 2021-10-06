#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

 
double det(int n, double mat[3][3])
{
    double submat[3][3];
    float d;
 
    for (int c = 0; c < n; c++)
    {
        int subi = 0; //submatrix's i value
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == c)
                    continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
 
        }
        d = d + (pow(-1, c) * mat[0][c] * det(n - 1, submat));
    }
    return d;
}
 
int main(int argc, char **argv)
{
 
    cout << "Enter the points of the triangle:\n";
    int x1, x2, x3, y1, y2, y3;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    cin >> x3;
    cin >> y3;
    double mat[3][3];
    mat[0][0] = x1;
    mat[0][1] = y1;
    mat[0][2] = 1;
    mat[1][0] = x2;
    mat[1][1] = y2;
    mat[1][2] = 1;
    mat[2][0] = x3;
    mat[2][1] = y3;
    mat[2][2] = 1;
 
    cout << "\nMatrix formed by the points: \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
 
    float determinant = det(3, mat)*0.5;
    if (determinant < 0)
        cout << "The Area of the triangle formed by (" << x1 << "," << y1
                << "), (" << x2 << "," << y2 << "), (" << x3 << "," << y3
                << ") = " << (determinant * -1);
    else
        cout << "The Area of the triangle formed by (" << x1 << "," << y1
                << "), (" << x2 << "," << y2 << "), (" << x3 << "," << y3
                << ") = " << determinant;
    return 0;
}
