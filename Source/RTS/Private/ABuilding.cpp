#include "ABuilding.h"


AABuilding::AABuilding()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AABuilding::InitializeBuildingStat(UDA_Building* data)
{
	if (IsValid(data))
	{
		BuildingType = data->BuildingType;
		BuildingStat = data->BuildingStat;
	}
}

