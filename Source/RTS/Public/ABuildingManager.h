#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DA_Building.h"
#include "ABuilding.h"

#include "ABuildingManager.generated.h"

UCLASS(BlueprintType)
class RTS_API AABuildingManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AABuildingManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Info")
	TSubclassOf<AABuilding> BuildingClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Info")
	TMap<EEnum_BuildingType, UDA_Building*> Building;


private:

	UFUNCTION(BlueprintCallable)
	AABuilding* Build(EEnum_BuildingType type, FVector location);

};
