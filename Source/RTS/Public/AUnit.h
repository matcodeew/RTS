#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DA_Unit.h"
#include "AUnit.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitDeath, AAUnit*, unit);

UCLASS()
class RTS_API AAUnit : public AActor
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

	void ResetUnitData();
	void InitializeUnitData(UDA_Unit* data);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void MoveTo(const FVector& destination);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void Attack(AActor* target);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void TakeDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "Unit Actions")
	void Die();
};
