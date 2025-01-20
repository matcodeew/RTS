#include "AEnemyControler.h"

AAEnemyControler::AAEnemyControler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	InitializePriorities();
	CurrentState = EEnum_UnitState::None;
}

void AAEnemyControler::BeginPlay()
{
	Super::BeginPlay();
	
}
void AAEnemyControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAEnemyControler::UpdateState()
{
	EEnum_UnitState NewState = CurrentState;
	int32 HighestPriority = -1;

	for (const auto& Pair : StatePriority)
	{
		if (Pair.Value > HighestPriority)
		{
			NewState = Pair.Key;
			HighestPriority = Pair.Value;
		}
	}
	CurrentState = NewState;
}

void AAEnemyControler::InitializePriorities()
{
	StatePriority.Add(EEnum_UnitState::ExploreMap, 10);
	StatePriority.Add(EEnum_UnitState::HarvestRessource, 9);
	StatePriority.Add(EEnum_UnitState::BuildBuildings, 6);
	StatePriority.Add(EEnum_UnitState::SpawnUnits, 4);
	StatePriority.Add(EEnum_UnitState::Attack, 3);
	StatePriority.Add(EEnum_UnitState::Reply, 0);
	StatePriority.Add(EEnum_UnitState::Defense, 0);
}
