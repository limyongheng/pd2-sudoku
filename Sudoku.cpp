#include "Sudoku.h"

using namespace std;
Sudoku::Sudoku ()
{
    ans_count = 0 ;
}
void Sudoku::ReadIn()
{
    int i , j;
    for (i = 0 ; i < 12 ; i++)
    {
        for (j = 0 ; j < 12 ; j++)
        {
            cin >> n[i][j] ;
            correct [i][j] = n[i][j];
        }
    }
}
void Sudoku::Solve()
{
    int i , j ;
    Sudoku_Solve() ;
    if (ans_count == 0)
        cout << "0" << endl;
    if (ans_count == 1)
    {
        cout << "1" << endl;
        for (i = 0 ; i< 12 ; i++)
        {
            for (j = 0 ; j < 12 ; j++)
                cout << correct[i][j] << " " ;
            cout << endl;
        }

    }

}
void Sudoku::Sudoku_Solve()
{
    int i , j ,a ,b , num ;
    if (get_count() == 144)
    {
        ans_count++ ;
        for (i = 0 ; i< 12 ; i++)
        {
            for (j = 0 ; j < 12 ; j++)
                correct[i][j] = n[i][j];
        }
        if (ans_count >= 2)
        {
            cout << "2" << endl ;
            return ;
        }
    }

    for (a = 0; a < 12; a++)
    {
        for (b = 0 ; b < 12 ; b++)
        {
            if (  n[a][b] == 0)
            {
                for ( num = 1 ; num <= 9 ; num ++)
                {
                    if ( compare_row( num , a) == 1 && compar_column( num , b ) == 1 && compar_all( num , b, a) == 1 )
                    {
                        n[a][b] = num ;
                        Sudoku_Solve();

                        n[a][b] = 0;
                        if (ans_count >= 2)
                            return;
                    }
                }
                return ;
            }
        }
    }
}
int Sudoku::get_count ()
{
    int i , j , count = 0;
    for ( i =0 ; i< 12 ; i++)
    {
        for (j = 0 ; j< 12 ; j++)
        {
            if (n[i][j] != 0 )
                count ++;
        }
    }
    return count ;
}
int Sudoku::compare_row( int num , int row)
{
    int i ;
    for ( i = 0 ; i < 12 ; i++)
    {
        if ( n[row][i] == num)
            return 0 ;
    }
    return 1;

}
int Sudoku::compar_column( int num , int column)
{
    int i ;
    for ( i = 0 ; i < 12 ; i++)
    {
        if ( n[i][column] == num)
            return 0 ;
    }
    return 1 ;
}
int Sudoku::compar_all( int num , int row , int column)
{
    int i , j , a , b ;
    if ( row <=2 && row >= 0 && column <=2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column <= 2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column <= 2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
            return 1;
    }
    if ( row <= 11 && row >= 9 && column <= 2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 9 ; j <= 11 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 2  && row >= 0 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 11 && row >= 9 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 9 ; j <= 11 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 2 && row >= 0 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 11 && row >= 9 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 9 ; j <= 11 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 2 && row >= 0 && column >= 9 && column <= 11)
    {
        for ( i = 9 ; i <= 11 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column >= 9 && column <= 11)
    {
        for ( i = 9  ; i <= 11 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column >= 9 && column <= 11)
    {
        for ( i = 9 ; i <= 11 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 11 && row >= 9 && column >= 9 && column <= 11)
    {
        for ( i = 9 ; i <= 11 ; i++)
        {
            for (j = 9 ; j <= 11 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
}
void Sudoku::GiveQuestion()
{
    int i = 0;
    srand(time (NULL));
    i = rand()%4+1 ;
    switch (i)
    {
    case 1:
        cout << "4 2 6 8 7 3 9 5 1 -1 -1 -1\n0 0 3 9 5 0 6 0 4 -1 -1 -1\n9 0 1 6 2 4 8 0 0 -1 -1 -1" <<endl ;
        cout << "-1 -1 -1 1 3 2 0 8 7 9 5 6\n-1 -1 -1 0 8 0 1 9 0 4 2 0\n-1 -1 -1 4 9 6 2 3 0 8 7 1" <<endl ;
        cout << "1 0 0 0 4 0 -1 -1 -1 6 9 5\n0 0 4 0 6 0 -1 -1 -1 1 3 7\n6 9 5 0 1 7 -1 -1 -1 2 8 4" <<endl ;
        cout << "3 1 2 -1 -1 -1 7 4 0 5 0 9\n7 4 8 -1 -1 -1 0 6 9 3 0 2\n0 6 0 -1 -1 -1 3 1 0 7 0 8" <<endl ;
        break ;
    case 2:
        cout << "8 0 7 0 1 3 -1 -1 -1 0 6 0\n3 0 2 9 6 0 -1 -1 -1 8 4 7\n5 0 9 0 4 7 -1 -1 -1 2 1 3" <<endl ;
        cout << "4 8 2 -1 -1 -1 7 1 0 5 9 6\n7 3 1 -1 -1 -1 0 6 0 4 0 0\n5 9 6 -1 -1 -1 0 4 0 0 0 1" <<endl ;
        cout << "1 7 8 0 3 2 6 9 4 -1 -1 -1\n0 2 4 0 9 1 0 8 0 -1 -1 -1\n6 5 9 7 8 0 2 3 1 -1 -1 -1" <<endl ;
        cout << "-1 -1 -1 0 0 8 4 2 6 1 0 9\n-1 -1 -1 4 0 6 0 5 9 3 0 0\n-1 -1 -1 1 5 9 3 7 8 6 2 4" <<endl ;
        break ;
    case 3:
        cout << "-1 -1 -1 6 0 1 5 7 4 9 2 8\n-1 -1 -1 5 2 7 9 3 8 0 0 0\n-1 -1 -1 9 4 8 6 1 2 5 3 7" <<endl ;
        cout << "1 4 0 7 0 0 -1 -1 -1 0 9 0\n5 0 0 8 9 3 -1 -1 -1 4 6 1\n3 0 4 2 0 6 0 0 7 -1 -1 -1" <<endl ;
        cout << "3 0 4 2 0 6 0 0 7 -1 -1 -1\n7 5 2 3 8 9 4 6 1 -1 -1 -1\n8 9 6 1 0 4 0 0 0 -1 -1 -1" <<endl ;
        cout << "6 3 1 -1 -1 -1 0 4 5 2 8 0\n2 0 0 -1 -1 -1 0 0 9 1 4 6\n4 0 9 -1 -1 -1 1 0 6 3 7 0" <<endl ;
        break ;
    case 4:
        cout << "0 7 3 6 0 1 -1 -1 -1 9 0 4\n6 4 1 9 0 0 -1 -1 -1 0 0 2\n2 8 0 4 5 0 -1 -1 -1 1 3 6" <<endl ;
        cout << "-1 -1 -1 0 0 0 4 0 1 6 9 8\n-1 -1 -1 1 6 4 9 8 3 2 5 7\n-1 -1 -1 7 0 0 6 0 2 4 0 3" <<endl ;
        cout << "3 0 7 -1 -1 -1 2 1 0 8 6 9\n1 6 4 -1 -1 -1 8 9 3 0 0 5\n0 9 0 -1 -1 -1 0 0 7 0 4 1" <<endl ;
        cout << "7 3 5 2 1 6 8 4 9 -1 -1 -1\n0 0 0 8 3 9 7 2 5 -1 -1 -1\n8 2 9 4 7 5 1 0 6 -1 -1 -1" <<endl ;
        break ;
    }
}
