// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"

UCLASS()
class HOLDER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Inputs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputMappingContext* MyMapping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Input)
	class UInputAction* LockTargetOnAction;

	//Camera Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* ViewCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CameraArmLenght = 300.f;

	//stance variables and lock on varuiables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool TargetLocked = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float DistanceFromTarget;


	void isTragetLockedOn();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
