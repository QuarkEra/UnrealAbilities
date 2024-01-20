// Fill out your copyright notice in the Description page of Project Settings.


#include "UA_GasCharacter.h"

#include "AbilitySystemComponent.h"
#include "UAAttributeSet.h"
#include "Abilities/GameplayAbility.h"

// Sets default values
AUA_GasCharacter::AUA_GasCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));

}

// Called when the game starts or when spawned
void AUA_GasCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		UuaAttributeSet = AbilitySystemComponent->GetSet<UUAAttributeSet>();
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UuaAttributeSet->GetStaminaAttribute()).AddUObject(this, &AUA_GasCharacter::OnStaminaChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UuaAttributeSet->GetJumpPowerAttribute()).AddUObject(this, &AUA_GasCharacter::OnJumpPowerChangedNative);
	}
	
}

void AUA_GasCharacter::InitializeAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level)
{
	if (!AbilitySystemComponent)
	{
		return;
	}
	if (HasAuthority() && Ability)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, Level, 0));
	}
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

UAbilitySystemComponent* AUA_GasCharacter::GetAbilitySystemComponent() const
{
	if (AbilitySystemComponent)
	{
		return AbilitySystemComponent;
	}
	return nullptr;
}

void AUA_GasCharacter::GetStaminaValues(float& Stamina, float& MaxStamina)
{
	Stamina = UuaAttributeSet->GetStamina();
	MaxStamina = UuaAttributeSet->GetMaxStamina();
}

void AUA_GasCharacter::GetJumpPower(float& JumpPower, float& MaxJumpPower)
{
	JumpPower = UuaAttributeSet->GetJumpPower();
	MaxJumpPower = UuaAttributeSet->GetMaxJumpPower();
}

void AUA_GasCharacter::OnStaminaChangedNative(const FOnAttributeChangeData& Data)
{
	OnStaminaChanged(Data.OldValue, Data.NewValue);
}

void AUA_GasCharacter::OnJumpPowerChangedNative(const FOnAttributeChangeData& Data)
{
	OnJumpPowerChanged(Data.OldValue, Data.NewValue);	
}

// Called every frame
void AUA_GasCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUA_GasCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

