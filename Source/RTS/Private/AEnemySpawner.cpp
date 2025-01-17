#include "AEnemySpawner.h"

// Sets default values
AAEnemySpawner::AAEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	EnemyPool = CreateDefaultSubobject<UAC_EnemyPool>(TEXT("EnemyPool"));
}

void AAEnemySpawner::SpawnEnemy(EEnum_UnitType unitType)
{
	if (!IsValid(EnemyPool)) { return; }


	AAUnit* newEnemy = EnemyPool->GetEnemyFromPool(unitType);
	if (IsValid(newEnemy))
	{
		newEnemy->SetActorLocation(FVector(1000, 1000, 0));
	}
}