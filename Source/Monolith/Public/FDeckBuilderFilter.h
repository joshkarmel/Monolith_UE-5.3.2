// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FCardData.h"
#include "CoreMinimal.h"
#include "FDeckBuilderFilter.generated.h"
using namespace std;
/**
 *
 */
USTRUCT(BlueprintType)
struct MONOLITH_API FDeckBuilderFilter
{
	GENERATED_BODY()
private:

public:
	FDeckBuilderFilter();
	~FDeckBuilderFilter();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ATK"))
	FString ATK;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "DEF"))
	FString DEF;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Name"))
	FString CardName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Type"))
	int CardType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Nation"))
	int CardNation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Rarity"))
	int CardRarity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Guild"))
	int CardGuild;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Class"))
	int CardClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Range Type"))
	int RangeType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Effect Notifier"))
	int EffectNotifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Location Notifier"))
	int LocationNotifier;

	bool NoFilter();
	bool MatchesAtk(int Atk);
	bool MatchesDef(int Def);
	bool MatchesCardName(FString Name);
	bool MatchesCardType(Card_Type Type);
	bool MatchesCardNation(Card_Nation Nation);
	bool MatchesCardRarity(Card_Rarity Rarity);
	bool MatchesCardGuild(Card_Guild Guild);
	bool MatchesCardClass(Card_Class Class);
	bool MatchesRangeType(Range_Type Nation);
	bool MatchesEffectNotifier(Effect_Notifier Nation);
	bool MatchesLocationNotifier(Location_Notifier Nation);
};
