// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LevelSequence.h"
#include "LevelTransition.generated.h"

class ULevelTransition;

USTRUCT(BlueprintType)
struct FLevelInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<UWorld> Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<ULevelSequence> preTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<ULevelSequence> postTransition;

	FLevelInfo()
	{
	}
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTMOTORCYCLE_API ULevelTransition : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "LevelSystem")
	void StartTransition(FLevelInfo from, FLevelInfo to);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "LevelSystem")
	void EndTransition();
};
