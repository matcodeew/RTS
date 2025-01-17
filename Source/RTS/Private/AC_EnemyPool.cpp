#include "AC_EnemyPool.h"


void UAC_EnemyPool::InitializePool(int32 poolSize)
{
	if(poolSize <= 0 && IsValid(UnitClass)) { return; }

	for (int i = 0; i < poolSize; i++)
	{
		AAUnit* newUnit = GetWorld()->SpawnActor<AAUnit>(UnitClass);
		if (IsValid(newUnit))
		{
			newUnit->OnUnitDeath.AddDynamic(this, &UAC_EnemyPool::ReturnEnemyToPool);
			newUnit->ResetUnitData();
			DesactivateUnit(newUnit, true);
			Pool.Add(newUnit);
		}
	}
}

void UAC_EnemyPool::ReturnEnemyToPool(AAUnit* enemy)
{
	Pool.Add(enemy);
	DesactivateUnit(enemy, true);
}

AAUnit* UAC_EnemyPool::GetEnemyFromPool(EEnum_UnitType type)
{
	if (Pool.Num() > 0)
	{
		AAUnit* newUnit = Pool.Pop();
		if (IsValid(newUnit) && newUnit->IsHidden())
		{
			ResetEnemy(newUnit);
			DesactivateUnit(newUnit, false);
			newUnit->InitializeUnitData(UnitTypeToDataMap[type]);
			return newUnit;
		}
	}
	return nullptr;
}

void UAC_EnemyPool::ResetEnemy(AAUnit* enemy)
{
	enemy->SetActorLocation(FVector::ZeroVector);
	enemy->SetActorRotation(FRotator::ZeroRotator);
}

void UAC_EnemyPool::DesactivateUnit(AAUnit* unit, bool active)
{
	unit->SetActorEnableCollision(active);
	unit->SetActorHiddenInGame(active);
	unit->SetActorTickEnabled(active);
}