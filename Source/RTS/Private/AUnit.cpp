#include "AUnit.h"

AAUnit::AAUnit()
{
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));

	RootComponent = SkeletalMeshComponent;
}

void AAUnit::ResetUnitData()
{
	Stat.AttackDamage = 0;
	Stat.CurrentLife = 0;
	Stat.MaxLife = 0;
	Stat.SkeletalMesh = NULL;
	Stat.MovementSpeed = 0;
	Stat.Name = "";
	Stat.RessourceValue = 0;
	Stat.SpawnRate = 0;
	Stat.SkeletalMeshScale = FVector::ZeroVector;

	Type = EEnum_UnitType::None;
}

void AAUnit::InitializeUnitData(UDA_Unit* data)
{
	Stat = data->UnitStat;
	Type = data->UnitType;
	
	if (SkeletalMeshComponent && Stat.SkeletalMesh)
	{
		SkeletalMeshComponent->SetSkeletalMesh(Stat.SkeletalMesh);
		SkeletalMeshComponent->SetRelativeScale3D(Stat.SkeletalMeshScale);
	}
}

void AAUnit::MoveTo(FVector targetLocation, float DeltaTime, float Speed)
{
	FVector CurrentLocation = GetActorLocation();
	FVector Direction = (targetLocation - CurrentLocation).GetSafeNormal();
	FVector NewLocation = CurrentLocation + (Direction * Speed * DeltaTime);

	if (FVector::Dist(NewLocation, targetLocation) <= DistanceTreshHold)
	{
		NewLocation = targetLocation;
	}

	SetActorLocation(NewLocation);
}

void AAUnit::Attack(AActor* target)
{
	if (IsValid(target))
	{
		AAUnit* enemy = Cast<AAUnit>(target);
		if (IsValid(enemy))
		{
			enemy->TakeDamage(Stat.AttackDamage);
		}
	}
}

void AAUnit::TakeDamage(float damage)
{
	Stat.CurrentLife -= damage;
	if (Stat.CurrentLife <= 0)
	{
		Die();
		OnUnitDeath.Broadcast(this);
		return;
	}
}