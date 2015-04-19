#include <iostream>
#include<time.h>
#include <cstdio>
#include<cstdlib>
#include<fstream>

using namespace std ;

class Sudoku
{
private:
    int n[12][12];
    int ans_count ;
    int correct[12][12];
public:
    Sudoku ();
    void ReadIn();
    void Solve();
    void Sudoku_Solve();
    int get_count ();
    int compare_row( int num , int row);
    int compar_column( int num , int column);
    int compar_all( int num , int row , int column);
    void GiveQuestion();
};

