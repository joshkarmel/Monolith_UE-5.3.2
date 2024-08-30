// Fill out your copyright notice in the Description page of Project Settings.


#include "FDeckBuilderFilter.h"
using namespace std;

FDeckBuilderFilter::FDeckBuilderFilter()
{
}

FDeckBuilderFilter::~FDeckBuilderFilter()
{
}

bool FDeckBuilderFilter::NoFilter()
{
	return ATK.IsEmpty() &&
		DEF.IsEmpty() &&
		CardName.IsEmpty() &&
		CardType <= 0 &&
		CardNation <= 0 &&
		CardRarity <= 0 &&
		CardGuild <= 0 &&
		CardClass <= 0 &&
		RangeType <= 0 &&
		EffectNotifier <= 0 &&
		LocationNotifier <= 0;
}

bool FDeckBuilderFilter::MatchesAtk(int Atk)
{
	return !ATK.IsEmpty() && FString::FromInt(Atk).Contains(ATK);
}

bool FDeckBuilderFilter::MatchesDef(int Def)
{
	return !DEF.IsEmpty() && FString::FromInt(Def).Contains(DEF);
}

bool FDeckBuilderFilter::MatchesCardName(FString Name)
{
	return !CardName.IsEmpty() && Name.Contains(CardName);
}

bool FDeckBuilderFilter::MatchesCardType(Card_Type Type)
{
	return CardType > 0 && Type == static_cast<Card_Type>(CardType - 1);
}

bool FDeckBuilderFilter::MatchesCardNation(Card_Nation Nation)
{
	return CardNation > 0 && Nation == static_cast<Card_Nation>(CardNation - 1);
}

bool FDeckBuilderFilter::MatchesCardRarity(Card_Rarity Rarity)
{
	return CardRarity > 0 && Rarity == static_cast<Card_Rarity>(CardRarity - 1);
}

bool FDeckBuilderFilter::MatchesCardGuild(Card_Guild Guild)
{
	return CardGuild > 0 && Guild == static_cast<Card_Guild>(CardGuild - 1);
}

bool FDeckBuilderFilter::MatchesCardClass(Card_Class Class)
{
	return CardClass > 0 && Class == static_cast<Card_Class>(CardClass - 1);
}

bool FDeckBuilderFilter::MatchesRangeType(Range_Type Range)
{
	return RangeType > 0 && Range == static_cast<Range_Type>(RangeType - 1);
}

bool FDeckBuilderFilter::MatchesEffectNotifier(Effect_Notifier Effect)
{
	return EffectNotifier > 0 && Effect == static_cast<Effect_Notifier>(EffectNotifier - 1);
}

bool FDeckBuilderFilter::MatchesLocationNotifier(Location_Notifier Location)
{
	return LocationNotifier > 0 && Location == static_cast<Location_Notifier>(LocationNotifier - 1);
}
