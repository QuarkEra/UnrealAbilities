// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "UA_GasCharacter.generated.h"

struct FOnAttributeChangeData;
class UUAAttributeSet;
class UGameplayAbility;
class UAbilitySystemComponent;

UCLASS()
class UNREALABILITIES_API AUA_GasCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAbilitySystemComponent* AbilitySystemComponent;
	UFUNCTION(BlueprintCallable)
	void InitializeAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Gas")
	const UUAAttributeSet* UuaAttributeSet;

	AUA_GasCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UFUNCTION(BlueprintPure, Category="Gas")
	void GetStaminaValues(float& Stamina, float& MaxStamina);
	UFUNCTION(BlueprintPure, Category="Gas")
	void GetJumpPower(float& JumpPower, float& MaxJumpPower);
	void OnStaminaChangedNative(const FOnAttributeChangeData& Data);
	void OnJumpPowerChangedNative(const FOnAttributeChangeData& Data);
	UFUNCTION(BlueprintImplementableEvent, Category="Gas")
	void OnStaminaChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category="Gas")
	void OnJumpPowerChanged(float OldValue, float NewValue);
};
