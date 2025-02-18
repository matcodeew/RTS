#include "AC_EnemyPool.h"


UAC_EnemyPool::UAC_EnemyPool()
{
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

void UAC_EnemyPool::InitializePool(int32 poolSize, FVector initPos)
{
	if (poolSize <= 0 || !IsValid(UnitClass))
	{
		UE_LOG(LogTemp, Error, TEXT("PoolSize is negative or NULL"));
		return; 
	}


	for (int i = 0; i < poolSize; i++)
	{
		AAUnit* newUnit = GetWorld()->SpawnActor<AAUnit>(UnitClass, initPos, FRotator::ZeroRotator, SpawnParams);
		if (!IsValid(newUnit))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to spawn AAUnit!"));
			return;
		}

		newUnit->OnUnitDeath.AddDynamic(this, &UAC_EnemyPool::ReturnEnemyToPool);
		newUnit->ResetUnitData();
		DesactivateUnit(newUnit, true);
		Pool.Add(newUnit);
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
			DesactivateUnit(newUnit, false);
			newUnit->InitializeUnitData(UnitTypeToDataMap[type]);
			return newUnit;
		}
	}
	return nullptr;
}


void UAC_EnemyPool::DesactivateUnit(AAUnit* unit, bool active)
{
	unit->SetActorEnableCollision(!active); 
	unit->SetActorHiddenInGame(active); 
	unit->SetActorTickEnabled(!active); 
}