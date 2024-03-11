// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "BasicRevokedEnemy.generated.h"

UCLASS()
class HOLDER_API ABasicRevokedEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicRevokedEnemy();

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
