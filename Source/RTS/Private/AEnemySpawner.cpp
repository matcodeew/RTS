#include "AEnemySpawner.h"

AAEnemySpawner::AAEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	EnemyPool = CreateDefaultSubobject<UAC_EnemyPool>(TEXT("EnemyPool"));
}

AAUnit* AAEnemySpawner::SpawnEnemy(EEnum_UnitType unitType, FVector position)
{
	if (!IsValid(EnemyPool)) { return nullptr; }
		

	AAUnit* newEnemy = EnemyPool->GetEnemyFromPool(unitType);
	if (IsValid(newEnemy))
	{
		newEnemy->SetActorLocation(position);
		return newEnemy;
	}
	return nullptr;
}