// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include "FCardData.h"
using namespace std;

TArray<FName> UMyBlueprintFunctionLibrary::sortNames(TArray<FName> names)
{
	TArray<FString> strings;
	for(FName name : names)
	{
		strings.Push(name.ToString());
	}
	strings.Sort();

	TArray<FName> sortedNames;
	for (FString s : strings)
	{
		sortedNames.Push(FName(s));
	}
	return sortedNames;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByName(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.Name.ToString() < RHS.Name.ToString(); });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortBySetCode(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.SetCode.ToString() < RHS.SetCode.ToString(); });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardType(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.CardType < RHS.CardType; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortBy(TArray<FCard_Data_CPP> cards, uint8 selectedSort)
{
	TArray<FCard_Data_CPP> sortedCards;
	switch ((Sort_Types)selectedSort)
	{
		case Sort_Types::SETCODE:
			sortedCards = sortBySetCode(cards);
			break;
		case Sort_Types::NAME:
			sortedCards = sortByName(cards);
			break;
		case Sort_Types::CARDTYPE:
			sortedCards = sortByCardType(cards);
			break;
		case Sort_Types::CARDNATION:
			break;
		default:
			sortedCards = sortByName(cards);
			break;
	}

	return sortedCards;
}


