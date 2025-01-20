#include "ABuilding.h"


AABuilding::AABuilding()
{
	PrimaryActorTick.bCanEverTick = false;
}


AActor* AABuilding::Build(EEnum_BuildingType type, FVector location)
{
	if (type == EEnum_BuildingType::None) { return nullptr; }

	AABuilding* newBuilding = GetWorld()->SpawnActor<AABuilding>(BuildingClass);
	if (IsValid(newBuilding))
	{
		newBuilding->SetActorLocation(location);
		InitializeBuildingStat(Building[type]);
	}

	return nullptr;
}

void AABuilding::InitializeBuildingStat(UDA_Building* data)
{
	if (IsValid(data))
	{
		BuildingType = data->BuildingType;
		BuildingStat = data->BuildingStat;
	}
}

