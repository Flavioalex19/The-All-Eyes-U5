// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Weapon.generated.h"

UCLASS()
class HOLDER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//GameplayAbilities
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS")
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const
	{
		return AbilitySystemComponent;
	};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS")
	const class UMyCharacterAttributeSet* CharacterAttributeSet;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
