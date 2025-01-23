#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DA_Building.h"

#include "ABuilding.generated.h"


UCLASS(BlueprintType)
class RTS_API AABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	AABuilding();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Info")
	EEnum_BuildingType BuildingType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Info")
	FStruct_BuildingStat BuildingStat;

	UFUNCTION(BlueprintCallable)
	void InitializeBuildingStat(UDA_Building* data);

};
