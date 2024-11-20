#pragma once
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UDataAssetReaderSettings.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI, config=Editor,DefaultConfig, meta =(DisplayName ="UDataAssetReader Setting",CategoryName ="UDataAssetReader Setting"))
class UDataAssetReaderSettings : public UObject
{
	GENERATED_BODY()

	UDataAssetReaderSettings(const FObjectInitializer& ObjectInitializer);
public:

	/*
	 * Your Data Asset Folder Path"
	 */
	UPROPERTY(EditAnywhere,BlueprintReadOnly, config, Category = "Jira Settings")
	FString DataAssetPath;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
	
};

