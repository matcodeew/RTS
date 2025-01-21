#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Unit.generated.h"


UENUM(BlueprintType)
enum class EEnum_UnitType : uint8
{
    None,

    B_FanaticDevotee UMETA(DisplayName = "Fanatic Devotee"),
    B_AbyssDogs UMETA(DisplayName = "Abyss Dogs"),
    B_ChainedBeasts UMETA(DisplayName = "Chained Beasts"),
    B_ShootersFromTheAbyss UMETA(DisplayName = "Shooter From The Abyss"),

    //make elite name
};


USTRUCT(BlueprintType)
struct FStruct_UnitStat
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    FName Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    float AttackDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    float MaxLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    float CurrentLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    float MovementSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    float SpawnRate;

    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info") //mettre enum de la type de ressource a mettre (soul or faith)
    //float RessourceValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    float RessourceValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    USkeletalMesh* SkeletalMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Info")
    FVector SkeletalMeshScale;

    FStruct_UnitStat() : Name("Null"), AttackDamage(0.0f), MaxLife(0.0f), CurrentLife(MaxLife), MovementSpeed(0.0f), SpawnRate(0.0f), RessourceValue(0.0f), SkeletalMesh(nullptr), SkeletalMeshScale(0.5f, 0.5f, 0.5f) {}
};



UCLASS(BlueprintType)
class RTS_API UDA_Unit : public UDataAsset
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Stat")
    FStruct_UnitStat UnitStat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Type")
    EEnum_UnitType UnitType;

   // UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Icon")
    
};
