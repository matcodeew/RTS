// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AC_EnemyPool.h"
#include "DA_Unit.h"
#include "AEnemySpawner.generated.h"

UCLASS()
class RTS_API AAEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AAEnemySpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	UAC_EnemyPool* EnemyPool;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	AAUnit* SpawnEnemy(EEnum_UnitType type, FVector position);
};
