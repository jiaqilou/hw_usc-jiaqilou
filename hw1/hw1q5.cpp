#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

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
   string *words = new string [n];
   for (int i=0; i<n; i++)
   {
      file >> words[i];//read in file
   }
   for (int i=0; i<n; i++)
   {
      cout << words[n-i-1]<<endl;//output in reverse sequence
   }
   delete[] words;
   file.close();
   return 0;
}
