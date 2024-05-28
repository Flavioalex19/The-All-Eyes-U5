// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyCharacter.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Animation/AnimMontage.h"
#include "AbilitySystemComponent.h"
#include "Attribute/MyCharacterAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = CameraArmLenght;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("View Camera"));
	ViewCamera->SetupAttachment(CameraBoom);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//APlayerController* PlayerController = Cast<PlayerController>(GetController());
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			
			Subsystem->AddMappingContext(MyMapping, 0);
		}
	}

	if(IsValid(AbilitySystemComponent))
	{
		CharacterAttributeSet = AbilitySystemComponent->GetSet<UMyCharacterAttributeSet>();
	}
	
}

void AMyCharacter::isTragetLockedOn()
{
	if(!TargetLocked)
	{
		TargetLocked = true;
	}
	else
	{
		TargetLocked = false;
	}
}

void AMyCharacter::Attack(const FInputActionValue& Value)
{
	
	if(CanAttack == false || Timer < ResetTimer/2)
	{
		
		CanAttack = true;
		Timer = ResetTimer;
		PlayMontage();
		ActionState = EActionState::Attacking;
	}
}

void AMyCharacter::PlayMontage()
{
	
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && AttackMontage)
	{
		ComboCount++;
		AnimInstance->Montage_Play(AttackMontage);
		int32 Selection = ComboCount;
		FName SectionName = FName();
		if(ComboCount%2 != 0){SectionName = FName("Attack0");}
		else {SectionName = FName("Attack1");}
		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
		
		
		
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(TargetLocked)ActionState = EActionState::LockOnState;
	else ActionState = EActionState::KnightState;

	if (CanAttack)
	{
		Timer-= DeltaTime;
		if (Timer<0)
		{
			CanAttack = false;
			Timer = ResetTimer;
			ComboCount = 0;
		}
	}
	

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//EnhancedInputComponent->BindAction(LockTargetOnAction, ETriggerEvent::Triggered, this, &AMyCharacter::isTragetLockedOn);
		//EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AMyCharacter::Attack);
	}

}

