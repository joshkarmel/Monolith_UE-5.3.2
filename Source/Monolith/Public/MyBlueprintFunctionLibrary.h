// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FCardData.h"
#include "FDeckBuilderFilter.h"
#include "MyBlueprintFunctionLibrary.generated.h"
using namespace std;
/**
 * 
 */

enum class Sort_Types : uint8 {
	SETCODE,
	NAME,
	CARDTYPE,
	CARDNATION,
	CARDGUILD,
	CARDCLASS,
	GRADE,
	ATK,
	DEF,
	RANGE,
	MOVERANGE,
	ARTIST,
	RARITY,
	RULETEXT
};

USTRUCT(BlueprintType)
struct FCardList
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TArray<FCard_Data_CPP> Cards;
};

UCLASS(BlueprintType)
class MONOLITH_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	private:
		UFUNCTION(Category = "SortList")
		static bool compareGrade(FCard_Data_CPP a, FCard_Data_CPP b);

		UFUNCTION(Category = "SortList")
		static bool compareName(FCard_Data_CPP a, FCard_Data_CPP b);

		UFUNCTION(Category = "SortList")
		static bool compareDEF(FCard_Data_CPP a, FCard_Data_CPP b);

		UFUNCTION(Category = "SortList")
		static bool compareATK(FCard_Data_CPP a, FCard_Data_CPP b);

		UFUNCTION(Category = "SortList")
		static bool compareCardType(FCard_Data_CPP a, FCard_Data_CPP b);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> mapSelectMany(TMap<FName, FCardList> cardData);

		UFUNCTION(Category = "SortList")
		static TMap<FName, FCardList> groupByName(TArray<FCard_Data_CPP> actors);

		UFUNCTION(Category = "SortList")
		static TMap<FName, FCardList> groupByAtk(TArray<FCard_Data_CPP> cards);

		UFUNCTION(Category = "SortList")
		static TMap<FName, FCardList> groupByCardType(TMap<FName, FCardList> cards);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByName(TArray<FCard_Data_CPP> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortBySetCode(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TMap<FName, FCardList> sortByCardType(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardNation(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardGuild(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardClass(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByGrade(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TMap<FName, FCardList> sortByATK(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByDEF(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByRange(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByMoveRange(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByArtist(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByRarity(TMap<FName, FCardList> actors);

		UFUNCTION(Category = "SortList")
		static TArray<FCard_Data_CPP> sortByRuleText(TMap<FName, FCardList> actors);
	public:
		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> SortBy(TArray<FCard_Data_CPP> Cards, uint8 selectedSort);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> FilterCards(TArray<FCard_Data_CPP> Cards, FDeckBuilderFilter Filter);
};
