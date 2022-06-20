// Louise Schmidtgen
//CISS 423
#include <iostream>

#define N 9
using namespace std;
void print_2Darr(int arr[N][N]);
bool check_sudoku(int arr[N][N]);
int main()
{
	int arr1[N][N] = { 
         { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 4, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 3, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 9, 4, 7, 2, 5, 6 },
         { 6, 9, 2, 3, 5, 11, 8, 7, 4 },
         { 7, 4, 5, 2, 8, 6, 3, 1, 9 } };
    bool correct = false;
    print_2Darr(arr1);
    correct = check_sudoku(arr1);

    if (correct)
    {
        cout << "This sudoku is correct.";
    }
    else
    {
        cout << "This sudoku is not correct.";
    }
    

	return 0;
}
void print_2Darr(int arr[N][N])
{
    int r = 0, c = 0;
    for (r = 0; r < N; r++)
    {
        for (c = 0; c <N; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

}

bool check_sudoku(int arr[N][N])
{
    int nums[N] = { 0,0,0,0,0,0,0,0,0}; //0 num is not in checking area, 1 nm is in checking area
    int check_sum = 0, r=0, c=0, i=0, index=0;

    //check rows
    for (r = 0; r < N; r++)
    {
        //reset nums
        for (i = 0; i < N; i++)
        {
            nums[i] = 0;
        }
        //go through row count how many of each num you get
        for (c = 0; c < N; c++)
        {
            index = arr[r][c] - 1; //get num convert num to index position in nums
            if (index > 8)
            {
                return false;
            }
            nums[index] += 1;
        }
        //check that all numbers are in area
        for (i = 0; i < N; i++)
        {
            if (nums[i] != 1)
            {
                return false;
            }
        }
    }
    //cout << "Row is correct.";
    //check columns
    for (c = 0; c < N; c++)
    {
        //reset nums
        for (i = 0; i < N; i++)
        {
            nums[i] = 0;
        }
        //go through row count how many of each num you get
        for (r = 0; r < N; r++)
        {
            index = arr[r][c] - 1; //get num convert num to index position in nums
            if (index > 8)
            {
                return false;
            }
            nums[index] += 1;
        }
        //check that all numbers are in area
        for (i = 0; i < N; i++)
        {
            if (nums[i] != 1)
            {
                return false;
            }
        }
    }
    //cout << "Column is correct.";

    //check squares
    int start_row=0;
    int start_column=0;

    //haha sorry this is so many for loops
    for (start_row = 0; start_row < N; start_row += 3) //0,3,6
    {
        for (start_column = 0; start_column < N; start_column += 3) //0,3,6
        {
            //reset nums
            for (i = 0; i < N; i++)
            {
                nums[i] = 0;
            }
            //go through the square
            for (r = start_row; r < (start_row + 3); r++)
            {
                //go through rows, if num is in area twice return false
                for (c = start_column; c < (start_column + 3); c++)
                {
                    index = arr[r][c] - 1; //get num convert num to index position in nums
                    if (index > 8)
                    {
                        return false;
                    }
                    nums[index] += 1;
                }
            }
            //check that all numbers are in area
            for (i = 0; i < N; i++)
            {
                if (nums[i] != 1)
                {
                    return false;
                }       
            }
        }
    }
    //cout << "Squares are correct.\n";
    return true;
}
