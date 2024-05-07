// Fill out your copyright notice in the Description page of Project Settings.


#include "SortCardList.h"

SortCardList::SortCardList(list<string> strings)
{
	stringList = strings;
}
SortCardList::SortCardList(list<int> ints)
{
	intList = ints;
}

SortCardList::~SortCardList()
{
}

list<string> SortCardList::sortStringList()
{
	stringList.sort();
	return stringList;
}

list<int> SortCardList::sortIntList()
{
	intList.sort();
	return intList;
}
