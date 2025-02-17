#include "ARessourceManager.h"

AARessourceManager::AARessourceManager()
{
}



float AARessourceManager::AddFaith(float addedFaith)
{
	return Faith += addedFaith;
}	

float AARessourceManager::AddSoul(float addedSoul)
{
	return Souls += addedSoul;
}



void AARessourceManager::RemoveFaith(float removedFaith)
{
	if (Faith - removedFaith < 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Faith can't be negative"));
		return;
	}

	Faith = std::fmaxf(Faith - removedFaith, 0.0f); 
}

void AARessourceManager::RemoveSoul(float removedSoul)
{
	if (Souls - removedSoul < 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Soul can't be negative"));
		return; 
	}

	Souls = std::fmaxf(Souls - removedSoul, 0.0f);
}
