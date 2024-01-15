// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterStates.h"
#include "MyCharacter.generated.h"

UCLASS()
class HOLDER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(VisibleAnywhere, Category = Variables)
	int32 ComboCount = 0;
	UPROPERTY(EditAnywhere, Category = Variables)
	float ResetTimer;
	UPROPERTY(VisibleAnywhere, Category = Variables)
	float Timer = ResetTimer;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = Variables)
	bool CanAttack = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool TargetLocked = false;

	//Inputs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputMappingContext* MyMapping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputAction* LockTargetOnAction;

	//Combat
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
	class UInputAction* AttackAction;
	UPROPERTY(EditAnywhere, Category = Montages)
	class UAnimMontage* AttackMontage;
	
	
	
	//Camera Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* ViewCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CameraArmLenght = 300.f;

	//stance variables and lock on varuiables
	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool TargetLocked = false;
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float DistanceFromTarget;


	void isTragetLockedOn();
	void Attack(const FInputActionValue& Value);
	void PlayMontage();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::KnightState;
	
};
