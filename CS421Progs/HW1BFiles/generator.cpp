#include <iostream>
#include <string>
#include <list>
#include <cmath>

double log_base(const double value, const double base)
{
    return log(value) / log(base);
}

/*
This is a more advanced version of what has been described below.
Each decimal number will be encoded as a trinary number and then its
printed.

0 -> 0
1 -> 1
2 -> 2
3 -> 10
4 -> 11
5 -> 12
6 -> 20
7 -> 21
8 -> 22
9 -> 100
...

*/
void encode_and_print(
    const int decimal, 
    std::ostream & stream = std::cerr)
{
    if(decimal > 0)
    {
        int order = (int)log_base(decimal,3);
        while(order >= 0)
        {
            stream << (decimal/(int)pow(3,order)) % 3;
            order--;
        }
    }
    else
    {
        stream << 0;
    }
    stream << std::endl;
}

// CS421 HW1 Write a generator in C++ for L = {x | x is a binary number}.

// Your name: John Patek

// Copy the recognizer function here from the other file.
// Not necessary since it the generator has a different alphabet

// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C 
//   after 20 strings have been displayed.
int main(const int argc, const char ** argv)
{
    int number = 0;
    while (number < 100)
    {
        encode_and_print(number);
        number++;
    }
    return 0;
}
