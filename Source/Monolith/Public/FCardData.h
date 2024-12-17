// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FCardData.generated.h"

UENUM(BlueprintType, meta = (DisplayName = "Card_Type"))
enum class Card_Type : uint8 {
	UNIT,
	TOKEN,
	MONOLITH,
	SPELL,
	CATALYST,
	FIELDSPELL,
	QUICKPLAY,
	EQUIP,
	BASESPELL
};

UENUM(BlueprintType, meta = (DisplayName = "Card_Nation"))
enum class Card_Nation : uint8 {
	NONE,
	MEMOREX,
	NOMADIC,
	ARAADIA,
	BRIGANTINE,
	WASTELANDS,
	LUNAS,
	CERULIA,
	VISTA_ISLES
};

UENUM(BlueprintType, meta = (DisplayName = "Card_Rarity"))
enum class Card_Rarity : uint8 {
	COMMON,
	RARE,
	PLATINUMRARE,
	ALTART
};

UENUM(BlueprintType, meta = (DisplayName = "Card_Guild"))
enum class Card_Guild : uint8 {
	NONE,
	DIVINITY,
	NOMADIC,
	ACTINIUM,
	SKYLITE,
	SYMBIOTIC,
	UNDERDARK,
	OCTANE,
	AUROREON,
	NORTH_KEEP,
	HILLCREST,
	PRISTINE_SHORES,
	GRAVESEND

};

UENUM(BlueprintType, meta = (DisplayName = "Card_Class"))
enum class Card_Class : uint8 {
	NONE,
	RANGED,
	MELEE,
	CAVALIER,
	ARTILLARY,
	ANTICAV,
	SUPPORT
};

UENUM(BlueprintType, meta = (DisplayName = "Range_Type"))
enum class Range_Type : uint8 {
	NONE,
	SQUARE,
	LINE,
	LONGLINE,
	ARTILLARY,
	VERTBRICK,
	HORZBRICK,
	DIAMOND,
	MELEE
};

UENUM(BlueprintType, meta = (DisplayName = "Effect_Notifier"))
enum class Effect_Notifier : uint8 {
	ONEPT,
	TWOPT,
	HOPT,
	AURA,
	QUICKEFFECT,
	ACT,
	AUTO,
	SELF,
	CATALYST,
	GLOBAL,
	IGNITION,
	CHARGED,
	TAP,
	AUG1,
	AUG2,
	AUG3
};

UENUM(BlueprintType, meta = (DisplayName = "Location_Notifier"))
enum class Location_Notifier : uint8 {
	NONE, 
	FIELD,
	HAND,
	GRAVEYARD,
	BANISHED,
	FRONTLINE,
	BACKLINE,
	BASE,
	LIFE,
	ACTION,
	ZOC,
	CATALYST
};

/** Please add a struct description */
USTRUCT(BlueprintType)
struct MONOLITH_API FCard_Data_CPP
{
	GENERATED_USTRUCT_BODY()
public:
	FCard_Data_CPP();
	~FCard_Data_CPP();

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Set Code"))
	FText SetCode;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Name", MakeStructureDefaultValue = "None"))
	FName Name;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Type", MakeStructureDefaultValue = "NONE"))
	Card_Type CardType;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Nation", MakeStructureDefaultValue = "NONE"))
	Card_Nation CardNation;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Guild", MakeStructureDefaultValue = "NONE"))
	Card_Guild CardGuild;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Class", MakeStructureDefaultValue = "NONE"))
	Card_Class CardClass;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Grade", MakeStructureDefaultValue = "0"))
	uint8 Grade;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ATK", MakeStructureDefaultValue = "0"))
	int32 ATK;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "DEF", MakeStructureDefaultValue = "0"))
	int32 DEF;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Range", MakeStructureDefaultValue = "NONE"))
	Range_Type Range;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Move Range", MakeStructureDefaultValue = "0"))
	uint8 MoveRange;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Artist"))
	FText Artist;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Rarity", MakeStructureDefaultValue = "COMMON"))
	Card_Rarity Rarity;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Rule Text"))
	FText RuleText;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Image", MakeStructureDefaultValue = "None"))
	TObjectPtr<UTexture2D> CardImage;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Effect 1"))
	FText Effect1;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Effect 2"))
	FText Effect2;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Effect 3"))
	FText Effect3;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Notifier 1"))
	TArray<Effect_Notifier> Notifier1;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Notifier 2"))
	TArray<Effect_Notifier> Notifier2;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Notifier 3"))
	TArray<Effect_Notifier> Notifier3;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Prompt 1"))
	FText Prompt1;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Prompt 2"))
	FText Prompt2;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Prompt 3"))
	FText Prompt3;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Prompt 4"))
	FText Prompt4;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Loc1", MakeStructureDefaultValue = "FIELD"))
	TEnumAsByte<Location_Notifier> Loc1;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Loc2", MakeStructureDefaultValue = "FIELD"))
	TEnumAsByte<Location_Notifier> Loc2;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Loc3", MakeStructureDefaultValue = "FIELD"))
	TEnumAsByte<Location_Notifier> Loc3;

};
