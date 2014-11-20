#include <iostream>
#include <fstream>
using namespace std;

int const MAX = 25;


struct Database{
	string first;
	string last;
	string email;
};

void lookup(char* identifier, Database databases[], int counter){
	
	 for(int i = 0; i < counter; i++)
      {
		if (identifier == databases[i].first || identifier == databases[i].last || identifier == databases[i].email)	
		{
                	cout << databases[i].first << " " << databases[i].last << " "<< databases[i].email << endl;
		}
      }

	
}
void add(Database databases[], char *arg2, char *arg3, char *arg4, int counter)	
{
	fstream phonebook;
	phonebook.open("phonedir", fstream::app);
	
	phonebook << arg2 << " " << arg3 << " " << arg4 << endl;

	phonebook.close();	
}
int main(int argc, char *argv[]){

	
	fstream phonebook;
	phonebook.open("phonedir");
	
	if(argc < 3){cout << "not found" << endl; exit(1);}

	string arg1 = argv[1];

	Database databases[MAX];

	int counter = 0;

	phonebook >> databases[counter].first;
	phonebook >> databases[counter].last;
	phonebook >> databases[counter].email;

	while(!phonebook.fail()){

		counter++;
		phonebook >> databases[counter].first;
		phonebook >> databases[counter].last;
		phonebook >> databases[counter].email;

	}

	if (arg1 == "lookup"){lookup(argv[2], databases, counter);}
	if (arg1 == "add"){add(databases, argv[2], argv[3], argv[4], counter);}

	phonebook.close();
}
