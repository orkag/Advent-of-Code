#include <bits/stdc++.h>
const int square = 140;
using namespace std;
string engine[square];
/*bool isTouchingSymbol(int i, int j, string engine[square])
{
    if(i>0)if(j>0)if((engine[i-1][j-1]<'0'||engine[i-1][j-1]>'9')&&engine[i-1][j-1]!='.')return true;
    if(i>0)if((engine[i-1][j]<'0'||engine[i-1][j]>'9')&&engine[i-1][j]!='.')return true;
    if(i>0)if(j<square-1)if((engine[i-1][j+1]<'0'||engine[i-1][j+1]>'9')&&engine[i-1][j+1]!='.')return true;
    if(j>0)if((engine[i][j-1]<'0'||engine[i][j-1]>'9')&&engine[i][j-1]!='.')return true;
    if(j<square-1)if((engine[i][j+1]<'0'||engine[i][j+1]>'9')&&engine[i][j+1]!='.')return true;
    if(i<square-1)if(j>0)if((engine[i+1][j-1]<'0'||engine[i+1][j-1]>'9')&&engine[i+1][j-1]!='.')return true;
    if(i<square-1)if((engine[i+1][j]<'0'||engine[i+1][j]>'9')&&engine[i+1][j]!='.')return true;
    if(i<square-1)if(j<square-1)if((engine[i+1][j+1]<'0'||engine[i+1][j+1]>'9')&&engine[i+1][j+1]!='.')return true;
    return false;
}*/
/*
int PartNumber(int i, int &j, string line[square])
{
    int symbols=0;
    int result=0;
    while(line[i][j]>='0'&&line[i][j]<='9')
        {
        if(isTouchingSymbol(i, j, line))symbols++;
        result*=10;
        result+=line[i][j]-'0';
        j++;
        }

        if(symbols==0)return 0;
        return result;
}*/

int number(int i, int j)
{
    int result=0;
    while(engine[i][j]>='0'&&engine[i][j]<='9')
        {
        j--;
        if(j<0)break;
        }
    j++;

    while(engine[i][j]>='0'&&engine[i][j]<='9')
        {
        result*=10;
        result+=engine[i][j]-'0';
        engine[i][j]='@';
        j++;
        }

    return result;
}

int gearRatio(int i, int j)
{
    int result=1, numbers=0;
    if(engine[i-1][j-1]>='0'&&engine[i-1][j-1]<='9'){result*=number(i-1, j-1);numbers++;}
    if(engine[i-1][j]>='0'&&engine[i-1][j]<='9')    {result*=number(i-1, j);numbers++;}
    if(engine[i-1][j+1]>='0'&&engine[i-1][j+1]<='9'){result*=number(i-1, j+1);numbers++;}
    if(engine[i][j-1]>='0'&&engine[i][j-1]<='9')    {result*=number(i, j-1);numbers++;}
    if(engine[i][j+1]>='0'&&engine[i][j+1]<='9')    {result*=number(i, j+1);numbers++;}
    if(engine[i+1][j-1]>='0'&&engine[i+1][j-1]<='9'){result*=number(i+1, j-1);numbers++;}
    if(engine[i+1][j]>='0'&&engine[i+1][j]<='9')    {result*=number(i+1, j);numbers++;}
    if(engine[i+1][j+1]>='0'&&engine[i+1][j+1]<='9'){result*=number(i+1, j+1);numbers++;}

    if(numbers>1){return result;}
    return 0;
}

int main()
{



    fstream input;
    input.open("input", ios::in);

    string line;
    for(int i=0;getline(input, line);i++){engine[i]=line;};

    int result=0;

//part 2
    for(int i=0;i<square;i++)
        {
        for(int j=0;j<square;j++)
            {
                if(engine[i][j]=='*')
                    {
                    result+=gearRatio(i, j);
                    }

            }
        }
    cout << result;



//part 1
    /*
    for(int i=0;i<square;i++)
        {
        for(int j=0;j<square;j++)
            {
                if(engine[i][j]>='0'&&engine[i][j]<='9')
                    {
                    result+=PartNumber(i, j, engine);
                    }

            }
        }
    cout << result;
    */

    return 0;
}
