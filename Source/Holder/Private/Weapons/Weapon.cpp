// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Weapon.h"
#include "AbilitySystemComponent.h"
#include "Attribute/MyCharacterAttributeSet.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(AbilitySystemComponent))
	{
		CharacterAttributeSet = AbilitySystemComponent->GetSet<UMyCharacterAttributeSet>();
	}
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

