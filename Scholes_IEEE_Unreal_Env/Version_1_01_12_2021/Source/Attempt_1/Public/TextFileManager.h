// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextFileManager.generated.h"

/**
 * 
 */
UCLASS()
class ATTEMPT_1_API UTextFileManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
		static bool SaveArray(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting);
	
};
