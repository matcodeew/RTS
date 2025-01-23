#include "ABuildingManager.h"

AABuildingManager::AABuildingManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

AABuilding* AABuildingManager::Build(EEnum_BuildingType type, FVector location)
{
	if (type == EEnum_BuildingType::None) { UE_LOG(LogTemp, Error, TEXT("Building Type is NONE")); return nullptr; }

	AABuilding* newBuilding = GetWorld()->SpawnActor<AABuilding>(Building[type]->BuildingClass);

	if (IsValid(newBuilding))
	{
		newBuilding->SetActorLocation(location);
		newBuilding->InitializeBuildingStat(Building[type]);
		return newBuilding;
	}
	return nullptr;
}
