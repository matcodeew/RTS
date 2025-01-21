#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AUnit.h"
#include "DA_Unit.h"
#include "AC_EnemyPool.generated.h"


UCLASS(Blueprintable, BlueprintType)
class RTS_API UAC_EnemyPool : public UActorComponent
{
	GENERATED_BODY()

public:

	UAC_EnemyPool();

	UFUNCTION(BlueprintCallable, Category = "Enemy Pool")
	void InitializePool(int32 poolSize);

	UFUNCTION(BlueprintCallable, Category = "Enemy Pool")
	void ReturnEnemyToPool(AAUnit* enemy);

	UFUNCTION(BlueprintCallable, Category = "Enemy Pool")
	AAUnit* GetEnemyFromPool(EEnum_UnitType type);

	UFUNCTION(BlueprintCallable, Category = "Enemy Pool")
	void ResetEnemy(AAUnit* enemy);

	void DesactivateUnit(AAUnit* unit, bool active);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool Properties")
	TSubclassOf<AAUnit> UnitClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool Properties")
	TArray<AAUnit*> Pool;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool Properties")
	//TArray<AAUnit*> UnitActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool Properties")
	TMap<EEnum_UnitType, UDA_Unit*> UnitTypeToDataMap;

private:
	FActorSpawnParameters SpawnParams;
};
