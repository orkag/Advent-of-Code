#include <bits/stdc++.h>

using namespace std;
const int winningScratchards=10;//10 for input, 5 for test
const int numbersYouHave = 25;//25 for input, 8 for test
fstream temp;
int scratchcard(string line)
{
    int pointValue=0;
    temp.open("temp", ios::out);
    int winning[winningScratchards];
    int your_numbers[numbersYouHave];
    string trash;
    temp << line;
    temp.close();
    temp.open("temp", ios::in);

    temp >> trash; temp >> trash;

    for(int i=0; i< winningScratchards;i++)temp >> winning[i];

    temp >> trash;

    int number;
    for(int i=0; i< numbersYouHave;i++)
        temp >> your_numbers[i];


    for(int i=0;i< winningScratchards;i++)
        {
        for(int j=0;j<numbersYouHave;j++)
            {
            if(winning[i]==your_numbers[j])
                if(pointValue==0){pointValue=1;}
                else pointValue*=2;
        }

            }




    /*for(int j;j<winningScratchards;j++){
        if(winning[j]==number){
            if(pointValue==0){pointValue=1;}
            else {pointValue*=2;}
                }

        }*/


        temp.close();
    return pointValue;

}

int main()
{
    fstream input;
    input.open("input", ios::in);



    int result=0;
    string line;

    while(getline(input, line))
        {
        result+=scratchcard(line);
        //cout << scratchcard(line) << endl;
        }

    cout << result;
    input.close();
    return 0;
}
