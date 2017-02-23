#include <stdlib.h>
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashTable
{

  private:
	vector< list<int> > _myTable;
	int _tbSize;

  public:
	~HashTable();
	HashTable(int size);

	vector< list<int> > GetMyTable();
	int GetKey(int target);
	void Insert(int target);
	void PrintKeyList(int target);
	int Count(int target);
};

