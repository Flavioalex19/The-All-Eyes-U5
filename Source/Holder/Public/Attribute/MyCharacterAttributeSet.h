// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MyCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName,PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName,PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class HOLDER_API UMyCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, Level);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData MaxXP;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, MaxXP);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData CurrentXP;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, CurrentXP);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, Damage);

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UMyCharacterAttributeSet, Defense);
};
