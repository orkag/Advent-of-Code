#include <bits/stdc++.h>

using namespace std;

int main()
{

    int result=0;

    fstream input;
    input.open("input", ios::in);

    int number;
    string color;

    int red=0, green=0, blue=0;

for(int i=1;!input.eof();){

    input>>number>>color;

    if(color=="red")if(number > red)red=number;
    if(color=="green")if(number > green)green=number;
    if(color=="blue")if(number > blue)blue=number;


if(input.peek()=='\n'){

result+=red*green*blue;
red=0;green=0;blue=0;
i++;
}

}
cout << result;
    input.close();
    return 0;
}
