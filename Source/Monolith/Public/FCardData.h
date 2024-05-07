// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FCardData.generated.h"

UENUM(BlueprintType, meta = (DisplayName = "Card Type"))
enum class Card_Type : uint8 {
	NONE,
	RANGED,
	MELEE,
	CAVALIER,
	ARTILLARY,
	ANTICAV,
	SUPPORT
};

UENUM(BlueprintType, meta = (DisplayName = "Card Nation"))
enum class Card_Nation : uint8 {
	NONE,
	MEMOREX,
	NOMADIC,
	ARAADIA,
	BRIGANTINE,
	WASTELANDS,
	LUNAS,
	CERULIA
};

UENUM(BlueprintType, meta = (DisplayName = "Card Rarity"))
enum class Card_Rarity : uint8 {
	COMMON,
	RARE,
	PLATINUMRARE,
	ALTART
};

UENUM(BlueprintType, meta = (DisplayName = "Card Guild"))
enum class Card_Guild : uint8 {
	NONE,
	DIVINITY,
	NOMADIC,
	ACTINIUM,
	SKYLITE,
	SYMBIOTIC,
	UNDERDARK,
	OCTANE,
	AUROREON
};

UENUM(BlueprintType, meta = (DisplayName = "Card Class"))
enum class Card_Class : uint8 {
	NONE,
	RANGED,
	MELEE,
	CAVALIER,
	ARTILLARY,
	ANTICAV,
	SUPPORT
};

UENUM(BlueprintType, meta = (DisplayName = "RangeType"))
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Type", MakeStructureDefaultValue = "NewEnumerator0"))
	Card_Type CardType;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Nation", MakeStructureDefaultValue = "NewEnumerator0"))
	Card_Nation CardNation;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Guild", MakeStructureDefaultValue = "NewEnumerator0"))
	Card_Guild CardGuild;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Class", MakeStructureDefaultValue = "NewEnumerator0"))
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Range", MakeStructureDefaultValue = "NewEnumerator0"))
	Range_Type Range;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "MoveRange", MakeStructureDefaultValue = "0"))
	uint8 MoveRange;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Artist"))
	FText Artist;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Rarity", MakeStructureDefaultValue = "NewEnumerator0"))
	Card_Rarity Rarity;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "RuleText"))
	FText RuleText;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Card Image", MakeStructureDefaultValue = "None"))
	TObjectPtr<UTexture2D> CardImage;
};
