#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AEnemyControler.generated.h"

UENUM(BlueprintType)
enum class EEnum_UnitState : uint8
{
    None,

    ExploreMap UMETA(DisplayName = "Explore map"),
    HarvestRessource UMETA(DisplayName = "Harvest Ressource"),
    BuildBuildings UMETA(DisplayName = "Build Buildings"),
    SpawnUnits UMETA(DisplayName = "Spawn Units"),
    Attack UMETA(DisplayName = "Attack"),
    Reply UMETA(DisplayName = "Reply"),
    Defense UMETA(DisplayName = "Defense"),
};

UCLASS(BlueprintType)
class RTS_API AAEnemyControler : public AActor
{
	GENERATED_BODY()

public:	
	AAEnemyControler();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


private:
    void ExecuteExplore();
    void ExecuteHarvestRessource();
    void ExecuteBuildBuildings();
    void ExecuteSpawnUnits();
    void ExecuteAttack();
    void ExecuteReply();
    void ExecuteDefense();

public:

    UFUNCTION(BlueprintCallable)
    void UpdateState();

    UFUNCTION(BlueprintCallable)
    void InitializePriorities();

    int32 MaxActionPriority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Controller")
    EEnum_UnitState CurrentState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Controller")
    TMap<EEnum_UnitState, int32> StatePriority;

};


