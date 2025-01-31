#include "ARessourceManager.h"

AARessourceManager::AARessourceManager()
{
}



float AARessourceManager::AddFaith(float addedFaith)
{
	return Faith += addedFaith;
}	

void AARessourceManager::AddSoul(float addedSoul)
{
	Souls += addedSoul;
}



void AARessourceManager::RemoveFaith(float removedFaith)
{
	if (Faith - removedFaith < 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Faith can't be negative"));
		return;
	}

	Faith -= removedFaith;
}

void AARessourceManager::RemoveSoul(float removedSoul)
{
	if (Souls - removedSoul < 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Soul can't be negative"));
		return; 
	}

	Souls -= removedSoul;
}
