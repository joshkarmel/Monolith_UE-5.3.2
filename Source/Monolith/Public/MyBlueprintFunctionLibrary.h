// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FCardData.h"
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

UCLASS(BlueprintType)
class MONOLITH_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	private:
		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByName(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortBySetCode(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardType(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardNation(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardGuild(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByCardClass(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByGrade(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByATK(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByDEF(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByRange(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByMoveRange(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByArtist(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByRarity(TArray<FCard_Data_CPP> actors);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortByRuleText(TArray<FCard_Data_CPP> actors);
	public:
		UFUNCTION(BlueprintCallable, Category="SortList")
		static TArray<FName> sortNames(TArray<FName> names);

		UFUNCTION(BlueprintCallable, Category = "SortList")
		static TArray<FCard_Data_CPP> sortBy(TArray<FCard_Data_CPP> cards, uint8 selectedSort);

};
