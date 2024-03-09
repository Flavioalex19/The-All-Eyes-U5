// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_SETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_INITTER(ClassName, PropertyName)

UCLASS()
class HOLDER_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:
	
};
