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

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardNation(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.CardNation < RHS.CardNation; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardGuild(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.CardGuild < RHS.CardGuild; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardClass(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.CardClass < RHS.CardClass; });
	return cardData;
}


TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByGrade(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.Grade < RHS.Grade; });
	return cardData;
}


TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByATK(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.ATK < RHS.ATK; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByDEF(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.DEF < RHS.DEF; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByRange(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.Range < RHS.Range; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByMoveRange(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.MoveRange < RHS.MoveRange; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByArtist(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.Artist.ToString() < RHS.Artist.ToString(); });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByRarity(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.Rarity < RHS.Rarity; });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByRuleText(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& LHS, const FCard_Data_CPP& RHS) { return LHS.RuleText.ToString() < RHS.RuleText.ToString(); });
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
			sortedCards = sortByCardNation(cards);
			break;
		case Sort_Types::CARDGUILD:
			sortedCards = sortByCardGuild(cards);
			break;
		case Sort_Types::CARDCLASS:
			sortedCards = sortByCardClass(cards);
			break;
		case Sort_Types::GRADE:
			sortedCards = sortByGrade(cards);
			break;
		case Sort_Types::ATK:
			sortedCards = sortByATK(cards);
			break;
		case Sort_Types::DEF:
			sortedCards = sortByDEF(cards);
			break;
		case Sort_Types::RANGE:
			sortedCards = sortByRange(cards);
			break;
		case Sort_Types::MOVERANGE:
			sortedCards = sortByArtist(cards);
			break;
		case Sort_Types::RARITY:
			sortedCards = sortByRarity(cards);
			break;
		case Sort_Types::RULETEXT:
			sortedCards = sortByRuleText(cards);
			break;
		default:
			sortedCards = sortByName(cards);
			break;
	}

	return sortedCards;
}


