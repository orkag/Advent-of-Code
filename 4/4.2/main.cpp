#include <bits/stdc++.h>
int counter=0;
using namespace std;

const int winningScratchards=10;//10 for input, 5 for test
const int numbersYouHave = 25;//25 for input, 8 for test
const int startingCards = 205;//205 for input, 6 for test

fstream temp;
void scratchcard(string line, int card, int cardsQuantity[])
{
    int result=0;
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

    for(int i=0; i< numbersYouHave;i++)
        temp >> your_numbers[i];


    for(int i=0;i< winningScratchards;i++)
        {
        for(int j=0;j<numbersYouHave;j++)
            {
            if(winning[i]==your_numbers[j])
            result++;
            }
        }
    if(counter%1000==0)
        cout << "card:    " << card << "    result:     " << result << "    counter:    " << counter<< endl;
    for(int i=0;i<result;i++){cardsQuantity[card+i+1]+=1;}



        counter++;
        temp.close();

}

int main()
{
    fstream input;
    input.open("input", ios::in);

    int cardsQuantity[startingCards];

    for(int i=0;i<startingCards;i++)cardsQuantity[i]=1;

    string line;
    int a;
    for(int i=0;getline(input, line);i++)
        {
        a=cardsQuantity[i];
        for(int j=0;j<a;j++)
            scratchcard(line, i, cardsQuantity);
                   // cout << "debug";
        }

    int result=0;
    for(int i=0;i<startingCards;i++){
            for(int j=0;j<cardsQuantity[i];j++)
                result++;
    }




  //for(int i=0;i<startingCards;i++)cout <<cardsQuantity[i] << endl;
  cout << result;

    input.close();
    return 0;
}
