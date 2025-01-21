#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DA_Unit.h"
#include "AUnit.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitDeath, AAUnit*, unit);

UCLASS()
class RTS_API AAUnit : public APawn
{
	GENERATED_BODY()
	
public:

	AAUnit();

	UPROPERTY(BlueprintAssignable, Category = "Unit Event")
	FOnUnitDeath OnUnitDeath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Properties")
	FStruct_UnitStat Stat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Properties")
	EEnum_UnitType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Properties")
	float DistanceTreshHold;

	void ResetUnitData();
	void InitializeUnitData(UDA_Unit* data);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void MoveTo(FVector TargetLocation, float DeltaTime, float Speed);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void Attack(AAUnit* target);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void TakeDamage(float damage);

	UFUNCTION(BlueprintImplementableEvent, Category = "Unit Actions")
	void Die();


private:
	USkeletalMeshComponent* SkeletalMeshComponent;
};
