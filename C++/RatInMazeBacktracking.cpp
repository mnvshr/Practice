#include <iostream>
using namespace std;

// first we will check whether the rat can move in any direction or not

bool isSafe(int** array, int x, int y, int n)
{
    if (x<n && y<n && array[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// main function

bool ratInMaze(int** array, int x, int y, int n, int** solvedArray)
{
    // base condition if rat pohonch gaya
    
    if (x == n - 1 && y == n - 1)
    {
        cout<<endl;
        solvedArray[x][y] = 1;
        return true;
    }

    // safe condition

    if (isSafe(array, x, y, n))
    {
        solvedArray[x][y] = 1; // basically soved array ko true kar rahe hain

        // now x + 1 condition check karenge to check if rat right mein move karega ya nahi if karega then

        if (ratInMaze(array, x + 1, y, n, solvedArray))
        {
            return true;
        }

        // now y + 1 condition to check down move karega ya nahi
        
        else if (ratInMaze(array, x, y + 1, n, solvedArray))
        {
            return true;
        }

        // if right and down dono nahi move kar payega toh solved array 0 ho jayega

        else
        {
            solvedArray[x][y] = 0;
            return false;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;

    // dynamic memory allocation to use minimum storage possible

    int** array = new int*[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    }
    
    // do baar loop to take input dynamically

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>array[i][j];
        }
    }
    
    int** solvedArray = new int*[n];

    for (int i = 0; i < n; i++)
    {
        solvedArray[i] = new int[n]; // dynamic memory allocation
        for (int j = 0; j < n; j++)
        {
            solvedArray[i][j] = 0; // initialize 0 se karna padega warna garbage value aayegi
        }
    }
    
    if (ratInMaze(array, 0, 0, n, solvedArray))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<solvedArray[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
