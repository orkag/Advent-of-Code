#include <bits/stdc++.h>

int fl(std::string line)
{
    int f=-1;
    int l=0;
    for(int i=0;i<line.size();i++)
        {
            if(line[i] >= '1' && line[i] <= '9')
                {
                l=line[i]-'0';
            if(f==-1)f=line[i]-'0';
            }
        }
        return 10*f+l;
}


int main()
{
    std::fstream input;
    input.open("data.txt", std::ios::in);

    std::string line;
    int sum=0;
    while(getline(input, line))
        {
        //std::cout << fl(line) << std::endl;
        sum+=fl(line);
        }
    input.close();
    std::cout << sum;

    return 0;
}
