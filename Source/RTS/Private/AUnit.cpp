#include "AUnit.h"

AAUnit::AAUnit()
{
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

	Type = EEnum_UnitType::None;
}

void AAUnit::InitializeUnitData(UDA_Unit* data)
{
	Stat = data->UnitStat;
	Type = data->UnitType;
}

void AAUnit::MoveTo(const FVector& destination)
{
	//faire d�placement.
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
		return;
	}
}

void AAUnit::Die()
{
	OnUnitDeath.Broadcast(this);
}
