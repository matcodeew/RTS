#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ARessourceManager.generated.h"

UCLASS()
class RTS_API AARessourceManager : public AActor
{
	GENERATED_BODY()

public:
	AARessourceManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ressources")
	float Faith;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ressources")
	float Souls;

	UFUNCTION(BlueprintCallable)
	float AddFaith(float addedFaith);

	UFUNCTION(BlueprintCallable)
	void AddSoul(float addedSoul);

	UFUNCTION(BlueprintCallable)
	void RemoveFaith(float removedFaith);

	UFUNCTION(BlueprintCallable)
	void RemoveSoul(float removedSoul);
};
