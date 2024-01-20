// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "UAAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class UNREALABILITIES_API UUAAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UUAAttributeSet, Stamina)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UUAAttributeSet, MaxStamina)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute")
	FGameplayAttributeData JumpPower;
	ATTRIBUTE_ACCESSORS(UUAAttributeSet, JumpPower)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute")
	FGameplayAttributeData MaxJumpPower;
	ATTRIBUTE_ACCESSORS(UUAAttributeSet, MaxJumpPower)

	UUAAttributeSet();
	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	
};
