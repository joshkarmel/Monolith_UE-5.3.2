// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * 
 */
class MONOLITH_API SortCardList
{
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SortList")
	list<string> stringList;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SortList")
	list<int> intList;
	
	list<string> sortStringList();
	list<int> sortIntList();

	SortCardList(list<string>);
	SortCardList(list<int>);
	~SortCardList();
};
