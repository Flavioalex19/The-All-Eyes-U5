// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BasicRevokedEnemy.h"
#include "AbilitySystemComponent.h"
#include "Attribute/MyCharacterAttributeSet.h"

// Sets default values
ABasicRevokedEnemy::ABasicRevokedEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

}

// Called when the game starts or when spawned
void ABasicRevokedEnemy::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(AbilitySystemComponent))
	{
		CharacterAttributeSet = AbilitySystemComponent->GetSet<UMyCharacterAttributeSet>();
	}
	
}

// Called every frame
void ABasicRevokedEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicRevokedEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

