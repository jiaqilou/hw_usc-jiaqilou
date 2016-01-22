#include <iostream>
using namespace std;
#include<sstream>
#include<fstream>
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
      cerr << "Please provide a file" << endl;
      return 1;
   }
   ifstream file;
   file.open(argv[1]);
   int n;
   file >> n;
   stringstream ss;
   for (int i=0; i<n ; i++)
   {
      ss << file;
   }
   int i = helper(n , ss);
   cout<< i <<endl;
   return 0;
}

int helper(int number, stringstream &input)
{
   string word;
   input >>word;
   number--;
   if (number == 0)
   {
      //cout << word;
      return 1;
   }
   else
   {
      helper(number, input);
   }
}
