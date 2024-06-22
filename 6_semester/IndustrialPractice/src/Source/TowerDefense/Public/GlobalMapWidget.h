// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "GlobalMapWidget.generated.h"
/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UGlobalMapWidget : public UUserWidget
{
	GENERATED_BODY()
	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonHero;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonSkills;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonAchievements;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonEncylopedia;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonSettings;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonClose;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonCloseGame;

	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderHero;

	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderSkills;

	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderAchievements;

	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderEncylopedia;

	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderSettings;



	/*UPROPERTY(meta = (BindWidget))
	class UButton* ButtonLvl1;

	UPROPERTY(meta = (BindWidget))
	class UImage* img;*/

	//TMap <RGB, Level> levels = {
	//	{RGB(45,255,87),Level("name")},
	//	{RGB(255,66,119),Level("name2")},
	//	{RGB(17,33,255),Level("name3")}
	//};

	//UPROPERTY(EditDefaultsOnly)
	//UTexture2D* map;
	//

	//UFUNCTION()
	//void Clicked();

	//FVector2D GetGameViewportSize();
	//FVector2D GetGameResolution();
	UFUNCTION()
	void HeroButtonClicked();
	UFUNCTION()
	void SkillsButtonClicked();
	UFUNCTION()
	void AchievementsButtonClicked();
	UFUNCTION()
	void EncylopediaButtonClicked();
	UFUNCTION()
	void SettingsButtonClicked();
	UFUNCTION()
	void CloseButtonClicked();

	UFUNCTION()
	void CloseGameButtonClicked();

	//TArray<LevelMenuButton*> listLvl;



};
