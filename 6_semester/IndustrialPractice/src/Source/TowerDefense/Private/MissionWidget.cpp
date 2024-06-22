// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

bool UMissionWidget::Initialize()
{
	Super::Initialize();

	//FString levelName = GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelName;
	ButtonSpeed->OnClicked.AddDynamic(this, &UMissionWidget::SpeedButtonClicked);
	//UE_LOG(LogTemp, Warning, TEXT("In Mission Widget %s") , *FString(levelName));
	
	UMissionWidget::Update();
	
	return true;
}

void UMissionWidget::Update()
{
	int32 index = -1;
	if(GetWorld()->GetGameInstance<UMyGameInstance>())
		index = GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelIndex;

	if (index >= 0) {
		FString dataLives = "Lives: " + FString::FromInt(GetWorld()->GetGameInstance<UMyGameInstance>()->lifes);//levelsData[index].lifes);
		TextBlockLifes->SetText(FText::FromString(dataLives));

		FString dataWaves = "Waves: " + FString::FromInt(GetWorld()->GetGameInstance<UMyGameInstance>()->waves);//levelsData[index].waves);
		TextBlockWaves->SetText(FText::FromString(dataWaves));

		FString dataMoney = "Money: " + FString::FromInt(GetWorld()->GetGameInstance<UMyGameInstance>()->money);//levelsData[index].money);
		TextBlockMoney->SetText(FText::FromString(dataMoney));

		FString dataSkills = "Skills: " + GetWorld()->GetGameInstance<UMyGameInstance>()->levelsData[index].skills;
		TextBlockSkills->SetText(FText::FromString(dataSkills));
	}
}

void UMissionWidget::SpeedButtonClicked()
{
	GetWorld()->GetGameInstance<UMyGameInstance>()->isWin = true;
}

