// Fill out your copyR notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include "FCardData.h"
using namespace std;

bool UMyBlueprintFunctionLibrary::compareName(FCard_Data_CPP a, FCard_Data_CPP b)
{
	return a.Name.ToString() < b.Name.ToString();
}

bool UMyBlueprintFunctionLibrary::compareDEF(FCard_Data_CPP a, FCard_Data_CPP b)
{
	return a.DEF == b.DEF ? compareName(a, b) : a.DEF < b.DEF;
}

bool UMyBlueprintFunctionLibrary::compareATK(FCard_Data_CPP a, FCard_Data_CPP b)
{
	return a.ATK == b.ATK ? compareDEF(a, b) : a.ATK < b.ATK;
}

bool UMyBlueprintFunctionLibrary::compareGrade(FCard_Data_CPP a, FCard_Data_CPP b)
{
	return a.Grade == b.Grade ? compareName(a, b) : a.Grade < b.Grade;
}

bool UMyBlueprintFunctionLibrary::compareCardType(FCard_Data_CPP a, FCard_Data_CPP b)
{
	return a.CardType == b.CardType ? compareATK(a, b) : a.CardType < b.CardType;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByName(TArray<FCard_Data_CPP> cardData)
{
	cardData.Sort([](const FCard_Data_CPP& L, const FCard_Data_CPP& R)
		{ return compareName(L, R); });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortBySetCode(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].SetCode.ToString() < R.Cards[0].SetCode.ToString(); });
	return mapSelectMany(cardData);
}

TMap<FName, FCardList> UMyBlueprintFunctionLibrary::sortByCardType(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return compareCardType(L.Cards[0], R.Cards[0]); });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardNation(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].CardNation < R.Cards[0].CardNation; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardGuild(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].CardGuild < R.Cards[0].CardGuild; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByCardClass(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].CardClass < R.Cards[0].CardClass; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByGrade(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].Grade < R.Cards[0].Grade; });
	return mapSelectMany(cardData);
}

TMap<FName, FCardList> UMyBlueprintFunctionLibrary::sortByATK(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return compareATK(L.Cards[0], R.Cards[0]); });
	return cardData;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByDEF(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].DEF < R.Cards[0].DEF; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByRange(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].Range < R.Cards[0].Range; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByMoveRange(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].MoveRange < R.Cards[0].MoveRange; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByArtist(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].Artist.ToString() < R.Cards[0].Artist.ToString(); });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByRarity(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].Rarity < R.Cards[0].Rarity; });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::sortByRuleText(TMap<FName, FCardList> cardData)
{
	cardData.ValueSort([](const FCardList& L, const FCardList& R)
		{ return L.Cards[0].RuleText.ToString() < R.Cards[0].RuleText.ToString(); });
	return mapSelectMany(cardData);
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::mapSelectMany(TMap<FName, FCardList> cardData)
{
	TArray<FCard_Data_CPP> sortedCards;
	for (const TPair<FName, FCardList>& group : cardData)
	{
		for (const FCard_Data_CPP& card : group.Value.Cards)
		{
			sortedCards.Add(card);
		}
	}
	return sortedCards;
}

TMap<FName, FCardList> UMyBlueprintFunctionLibrary::groupByName(TArray<FCard_Data_CPP> cards)
{
	TMap<FName, FCardList> groupedCards;
	for (const FCard_Data_CPP& card : cards)
	{
		if(!groupedCards.Contains(card.Name))
		{
			groupedCards.Add(card.Name, FCardList());
		}
		groupedCards[card.Name].Cards.Add(card);
	}
	return groupedCards;
}

TMap<FName, FCardList> UMyBlueprintFunctionLibrary::groupByAtk(TArray<FCard_Data_CPP> cards)
{
	TMap<FName, FCardList> groupedCards;
	for (const FCard_Data_CPP& card : cards)
	{
		if (!groupedCards.Contains(FName(FString::FromInt(card.ATK))))
		{
			groupedCards.Add(FName(FString::FromInt(card.ATK)), FCardList());
		}
		groupedCards[FName(FString::FromInt(card.ATK))].Cards.Add(card);
	}
	return groupedCards;
}

TMap<FName, FCardList> UMyBlueprintFunctionLibrary::groupByCardType(TMap<FName, FCardList> groups)
{
	TMap<FName, FCardList> groupedCards;
	for (const TPair<FName, FCardList>& group : groups)
	{
		for (const FCard_Data_CPP& card : group.Value.Cards)
		{
			if (!groupedCards.Contains(FName(FString::FromInt(static_cast<uint8_t>(card.CardType)))))
			{
				groupedCards.Add(FName(FString::FromInt(static_cast<uint8_t>(card.CardType))), FCardList());
			}
			groupedCards[FName(FString::FromInt(static_cast<uint8_t>(card.CardType)))].Cards.Add(card);
		}
	}
	return groupedCards;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::SortBy(TArray<FCard_Data_CPP> cards, uint8 selectedSort)
{
	const TMap<FName, FCardList> groupedCards = groupByName(cards);
	TArray<FCard_Data_CPP> sortedCards;
	switch (static_cast<Sort_Types>(selectedSort))
	{
	case Sort_Types::SETCODE:
		sortedCards = sortBySetCode(groupedCards);
		break;
	case Sort_Types::NAME:
		sortedCards = sortByName(mapSelectMany(groupedCards));
		break;
	case Sort_Types::CARDTYPE:
		sortedCards = mapSelectMany(sortByCardType(groupedCards));
		break;
	case Sort_Types::CARDNATION:
		sortedCards = sortByCardNation(groupedCards);
		break;
	case Sort_Types::CARDGUILD:
		sortedCards = sortByCardGuild(groupedCards);
		break;
	case Sort_Types::CARDCLASS:
		sortedCards = sortByCardClass(groupedCards);
		break;
	case Sort_Types::GRADE:
		sortedCards = sortByGrade(groupedCards);
		break;
	case Sort_Types::ATK:
		sortedCards = mapSelectMany(sortByATK(groupedCards));
		break;
	case Sort_Types::DEF:
		sortedCards = sortByDEF(groupedCards);
		break;
	case Sort_Types::RANGE:
		sortedCards = sortByRange(groupedCards);
		break;
	case Sort_Types::MOVERANGE:
		sortedCards = sortByMoveRange(groupedCards);
		break;
	case Sort_Types::ARTIST:
		sortedCards = sortByArtist(groupedCards);
		break;
	case Sort_Types::RARITY:
		sortedCards = sortByRarity(groupedCards);
		break;
	case Sort_Types::RULETEXT:
		sortedCards = sortByRuleText(groupedCards);
		break;
	default:
		sortedCards = sortByName(mapSelectMany(groupedCards));
		break;
	}

	return sortedCards;
}

TArray<FCard_Data_CPP> UMyBlueprintFunctionLibrary::FilterCards(TArray<FCard_Data_CPP> Cards,
	FDeckBuilderFilter Filter)
{
	TArray<FCard_Data_CPP> FilteredCards = Cards;

	if (Filter.NoFilter())
	{
		return Cards;
	}

	if (!Filter.ATK.IsEmpty())
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesAtk(Card.ATK);
			});
	}

	if (!Filter.DEF.IsEmpty())
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesDef(Card.DEF);
			});
	}

	if (!Filter.CardName.IsEmpty())
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesCardName(Card.Name.ToString());
			});
	}

	if (Filter.CardType > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesCardType(Card.CardType);
			});
	}

	if (Filter.CardClass > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesCardClass(Card.CardClass);
			});
	}

	if (Filter.CardNation > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesCardNation(Card.CardNation);
			});
	}

	if (Filter.CardRarity > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesCardRarity(Card.Rarity);
			});
	}

	if (Filter.CardGuild > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesCardGuild(Card.CardGuild);
			});
	}

	if (Filter.RangeType > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{
				return !Filter.MatchesRangeType(Card.Range);
			});
	}

	if (Filter.LocationNotifier > 0)
	{
		FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
			{

				return !(Filter.MatchesLocationNotifier(Card.Loc1) ||
					Filter.MatchesLocationNotifier(Card.Loc2) ||
					Filter.MatchesLocationNotifier(Card.Loc3));
			});
	}

	//if (Filter.EffectNotifier > 0)
	//{
	//	FilteredCards.RemoveAll([&Filter](const FCard_Data_CPP& Card)
	//		{

	//			return !(Filter.MatchesEffectNotifier(Card.Notifier1) ||
	//				Filter.MatchesEffectNotifier(Card.Notifier2) ||
	//				Filter.MatchesEffectNotifier(Card.Notifier3));
	//		});
	//}

	return FilteredCards;
}


