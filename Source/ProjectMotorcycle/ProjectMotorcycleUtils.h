// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProjectMotorcycleUtils.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMOTORCYCLE_API UProjectMotorcycleUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "ProjectMotorcyckeUtils")
	static FName GetAssetName(TAssetPtr<UObject> asset) {
		FString name = FPaths::GetBaseFilename(asset.GetLongPackageName());
		return FName(*name);
	};
};
