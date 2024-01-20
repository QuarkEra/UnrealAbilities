// Fill out your copyright notice in the Description page of Project Settings.


#include "UAAttributeSet.h"

#include "GameplayEffectExtension.h"

UUAAttributeSet::UUAAttributeSet()
{
	Stamina = 1.0f;
	MaxStamina = 1.0f;
	JumpPower = 1.0f;
	MaxJumpPower = 1.0f;
}

void UUAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));
	}
	if (Data.EvaluatedData.Attribute == GetJumpPowerAttribute())
	{
		SetJumpPower(FMath::Clamp(GetJumpPower(), 0.0f, GetMaxJumpPower()));
	}
}
