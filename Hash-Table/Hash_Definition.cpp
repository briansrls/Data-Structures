#include "Hash_Definition.h"

#include <stdlib.h>
#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

HashTable::HashTable(int size):
	_tbSize(size),
	_myTable(size)
{};
HashTable::~HashTable()
{
	_myTable.erase(_myTable.begin(), _myTable.end());
};
vector< list<int> > HashTable::GetMyTable(){
	return _myTable;
}

int HashTable::GetKey(int target)
{
	return target%_tbSize;
}

void HashTable::Insert(int target)
{
	_myTable[GetKey(target)].push_back(target);
}

void HashTable::PrintKeyList(int target)
{
	for(list<int>::iterator it = _myTable[GetKey(target)].begin(); it!=_myTable[GetKey(target)].end(); ++it)
	{
		cout << *it << ' ';	
	}
	cout << endl;
}

int HashTable::Count(int target)
{
	int sum;
	for(list<int>::iterator it = _myTable[GetKey(target)].begin(); it!=_myTable[GetKey(target)].end(); ++it)
	{
		if( *it == target ) sum++;
	}
	return sum;
}

int main(){

  HashTable HashList(1000);
  vector< list<int> > MyTable = HashList.GetMyTable();
  
  HashList.Insert(100);
  HashList.PrintKeyList(HashList.GetKey(100));
  HashList.Insert(100);
  HashList.Insert(1100);
  cout << HashList.Count(100) << endl;

}
