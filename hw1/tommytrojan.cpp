#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;//number of students in each floor
  string ***trojans;//3d array store possession of each student
  string curr;
  int ** pos;//2d array to store number of possession each has
  input >> floors>>ws;
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];
  pos = new int* [floors];
  for (int i = 0; i < floors; i++) {//set original value
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
	  pos[i] = NULL;
  }
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
        if ((i>=floors)||(i<0))
        {
          output << "Error - floor"<< i <<"does not exist" << endl;
        }
        else if(floorsizes[i] != 0)
        {
          output << "Error - floor"<< i <<"is not empty" << endl;
        }
        else
        {
          floorsizes[i]=k;//set number of students
          trojans[i] = new string* [k];
          pos[i] =new int [k];
          for (int a=0; a<k; a++)//set possessions to none
          {
            trojans[i][a] = NULL;
            pos[i][a] = 0;
          }
        }
		  }
	  }
	  else if (curr == "MOVEOUT") {
      int i;
      ss >> i;
      if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
        if(floorsizes[i]==0)
        {
          output << "Error -floor"<<i<<" no student"<< endl;
        }
        else if ((i>=floors)||(i<0))
        {
          output << "Error - floor"<< i <<"does not exist" << endl;
        }
        else
        {
          for (int a=0; a< floorsizes[i]; a++)
          {
            if(trojans[i][a] != NULL)//if has possession then delete
            {
               delete trojans[i][a];
            }
          }
          if (pos[i] != NULL)//if has possesion then delete
          {
            delete[] pos[i];
          }
          delete[] trojans[i];//delete the floor of students
          pos[i] = NULL;
          floorsizes[i] = 0;         
        }
	    }
	  }
	  else if (curr == "OBTAIN") {
	    int i, j, k;
	    ss >> i;
	    ss >> j;
	    ss >> k;
	     if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
        if ((j<0)||(j>=floorsizes[i]))
        {
          output << "Error- no student" << j <<endl;
        }
        else if ( trojans[i][j] != NULL)
        {
          output << "Error - student"<< j<< "already has possessions" << endl;
        }
        else
        {
          pos[i][j] = k;//student j has k possessions
          string str;
          trojans[i][j] = new string [k];
          for (int b=0; b<k; b++)//set each possession
          {
            ss >> str;
            trojans[i][j][b] = str;
          }
        }
      }
	  }
	  else if (curr == "OUTPUT") {
	    int i, j;
	    ss >> i;
	    ss >> j;
      if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
		    if ((j<0)||(j>=floorsizes[i]))
        {
          output << "Error- no student"<< j <<endl;
        }
        else if ( trojans[i][j] == NULL)
        {
          output << "Error -student"<<j<<"has no possessions" << endl;
        }
        else
        {
          for (int c=0; c< pos[i][j]; c++)//output the possessions
          {
            output << trojans[i][j][c] <<endl;
          }
        }
		  }
	  }
	  else {
      output << "incorrect command" <<endl;
	  }
  }
  for (int a=0; a < floors; a++)//delete all the memory
  {
    if (pos[a] != NULL)
    {
      delete[] pos[a];
    }
    for (int b=0; b< floorsizes[a]; b++)
    {
      if( trojans[a][b] != NULL)
      {
        delete[] trojans[a][b];
      }
    }
    if(trojans[a]!= NULL)
    {
      delete[] trojans[a];
    }
  }
  delete[] pos;
  delete[] trojans;
  delete[] floorsizes;
  input.close();
  output.close();
  return 0;
}
