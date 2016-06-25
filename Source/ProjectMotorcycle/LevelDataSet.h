// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "LevelDataSet.generated.h"

USTRUCT(BlueprintType)
struct FLevelInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<UWorld> Level;

	FLevelInfo()
	{
	}
};

USTRUCT(BlueprintType)
struct FLevelSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLevelInfo> Levels;

	FLevelSet()
	{
	}
};

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTMOTORCYCLE_API ULevelDataSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "LevelSystem")
	FLevelInfo GetFirstLevel() {
		return *LevelSets.GetData()->Levels.GetData();
	};

	UFUNCTION(BlueprintCallable, Category = "LevelSystem")
	FName GetLevelName(FLevelInfo levelInfo) {
		FString name = FPaths::GetBaseFilename(levelInfo.Level.GetLongPackageName());
		return FName(*name);
	};

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FLevelSet> LevelSets;
};
