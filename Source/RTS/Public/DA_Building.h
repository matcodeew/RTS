#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "DA_Building.generated.h"

UENUM(BlueprintType)
enum class EEnum_BuildingType : uint8
{
	None,
	SacrificeCircle UMETA(DisplayName = "Sacrifice Circle"),
	HouseOfTheFaithful UMETA(DisplayName = "House of the faithful"),
	CultShrine UMETA(DisplayName = "Cult Shrine"),
	DevotionalAltar UMETA(DisplayName = "Devotional Altar"),
	CryptOfTheDamned UMETA(DisplayName = "Crypt of the Damned "),
};

USTRUCT(BlueprintType)
struct FStruct_BuildingStat
{
	GENERATED_BODY()	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Builing Value")
	FName BuildingName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Builing Value")
	int32 FaithValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Builing Value")
	UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Builing Value")
	FVector ScalingValue;

	FStruct_BuildingStat() : BuildingName("NoName"), FaithValue(0.0f), StaticMesh(NULL), ScalingValue(1.0f, 1.0f, 1.0f) {}
};

UCLASS(BlueprintType)
class RTS_API UDA_Building : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Stat")
	FStruct_BuildingStat BuildingStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Type")
	EEnum_BuildingType BuildingType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	TSubclassOf<class AABuilding> BuildingClass;
	
};
