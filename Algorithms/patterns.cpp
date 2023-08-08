#include <iostream>
using namespace std;

void pattern1(int n)
{
    // * * *
    // * * *
    // * * *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    // *
    // **
    // ***
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    // ***
    // **
    // *
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    // ***
    //  **
    //   *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    //   *
    //  **
    // ***
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    //   *
    //  ***
    // *****
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << " ";
        }
        for (int j = 1; j < i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern7(int n)
{
    // 1
    // 10
    // 101
    // 1010
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                cout << "0";
            }
            else
            {
                cout << "1";
            }
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    // 1
    // 1001
    // 101101
    // 10100101
    for (int i = 1; i <= n; i++)
    {
        string curr = "";
        for (int j = 1; j <= i; j++)
        {
            if (i == 1)
            {
                cout << "1";
                continue;
            }
            if (j % 2 == 0)
            {
                cout << "0";
                curr += "0";
            }
            else
            {
                cout << "1";
                curr += "1";
            }
        }
        for (int k = curr.length() - 1; k >= 0; k--)
        {
            cout << curr[k];
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    for(int i = 1 ; i <= n ; i++){
        int count = i;
        for(int j = 1 ; j <= i ; j++){
            cout << count++;
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    for(int i = 1 ; i <= n ; i++){
        int count = i;
        for(int j = 1 ; j <= i ; j++){
            cout << count--;
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    for(int i = 1 ; i < n ; i++){
        for(int j = i; j < n; j++){
            cout << " " ;
        }
        for(int j = 1 ; j <= i; j++){
            cout << i ;
        }
        cout << endl;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j < i; j++){
            cout << " " ;
        }
        for(int j = n ; j >= i; j--){
            cout << n - i + 1 ;
        }
        cout << endl;
    }
}

void pattern12(int n){
    //diamond
    for(int i= 1 ; i < n ; i++){
        for(int j= i ;j < n ; j ++){
            cout << " ";
        }
        for(int j = 1; j < i ; j++){
            cout << "*" ;
        }
        for( int j = 1; j <= i ; j++){
            cout << "*" ;
        }
        cout << endl;
    }
    for(int i= 1 ; i <=n ; i++){
        for( int j = 1; j < i ; j++){
            cout << " " ;
        }
        for(int j= i ;j < n ; j ++){
            cout << "*";
        }
        for(int j= i ;j <= n ; j ++){
            cout << "*";
        }
        cout << endl;

    }
}
int main(int argc, char const *argv[])
{
    // pattern1(4);
    // pattern2(4);
    // pattern3(4);
    // pattern4(4);
    // pattern5(4);
    // pattern6(4);
    // pattern7(4);
    // pattern8(4);
    // pattern9(4);
    // pattern10(4);
    // pattern11(4);
    pattern12(4);
    return 0;
}
