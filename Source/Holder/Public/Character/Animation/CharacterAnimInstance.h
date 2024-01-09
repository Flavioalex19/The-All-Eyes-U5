// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class HOLDER_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadOnly)
	class AMyCharacter* MyCharacter;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	class UCharacterMovementComponent* MyCharacterMovement;
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float GroundSpeed;

	
};
