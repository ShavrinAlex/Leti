// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalMapWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"

bool UGlobalMapWidget::Initialize()
{
	Super::Initialize();
	/*static ConstructorHelpers::FObjectFinder<UTexture2D> TextureObj(TEXT("Texture2D'/Content/Textures/map"));
	if (TextureObj.Object != NULL)
	{
		map = TextureObj.Object;
	}*/

	ButtonHero->OnClicked.AddDynamic(this, &UGlobalMapWidget::HeroButtonClicked);
	ButtonSkills->OnClicked.AddDynamic(this, &UGlobalMapWidget::SkillsButtonClicked);
	ButtonAchievements->OnClicked.AddDynamic(this, &UGlobalMapWidget::AchievementsButtonClicked);
	ButtonEncylopedia->OnClicked.AddDynamic(this, &UGlobalMapWidget::EncylopediaButtonClicked);
	ButtonSettings->OnClicked.AddDynamic(this, &UGlobalMapWidget::SettingsButtonClicked);
	ButtonClose->OnClicked.AddDynamic(this, &UGlobalMapWidget::CloseButtonClicked);
	ButtonCloseGame->OnClicked.AddDynamic(this, &UGlobalMapWidget::CloseGameButtonClicked);
	return true;
}

void UGlobalMapWidget::HeroButtonClicked()
{
	BorderHero->SetVisibility(ESlateVisibility::Visible);
	ButtonClose->SetVisibility(ESlateVisibility::Visible);
	BorderSkills->SetVisibility(ESlateVisibility::Hidden);
	BorderAchievements->SetVisibility(ESlateVisibility::Hidden);
	BorderEncylopedia->SetVisibility(ESlateVisibility::Hidden);
	BorderSettings->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseGame->SetVisibility(ESlateVisibility::Hidden);

}

void UGlobalMapWidget::SkillsButtonClicked()
{
	BorderSkills->SetVisibility(ESlateVisibility::Visible);
	ButtonClose->SetVisibility(ESlateVisibility::Visible);
	BorderHero->SetVisibility(ESlateVisibility::Hidden);
	BorderAchievements->SetVisibility(ESlateVisibility::Hidden);
	BorderEncylopedia->SetVisibility(ESlateVisibility::Hidden);
	BorderSettings->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseGame->SetVisibility(ESlateVisibility::Hidden);

}

void UGlobalMapWidget::AchievementsButtonClicked()
{
	BorderAchievements->SetVisibility(ESlateVisibility::Visible);
	ButtonClose->SetVisibility(ESlateVisibility::Visible);
	BorderHero->SetVisibility(ESlateVisibility::Hidden);
	BorderSkills->SetVisibility(ESlateVisibility::Hidden);
	BorderEncylopedia->SetVisibility(ESlateVisibility::Hidden);
	BorderSettings->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseGame->SetVisibility(ESlateVisibility::Hidden);

}

void UGlobalMapWidget::EncylopediaButtonClicked()
{
	BorderEncylopedia->SetVisibility(ESlateVisibility::Visible);
	ButtonClose->SetVisibility(ESlateVisibility::Visible);
	BorderHero->SetVisibility(ESlateVisibility::Hidden);
	BorderSkills->SetVisibility(ESlateVisibility::Hidden);
	BorderAchievements->SetVisibility(ESlateVisibility::Hidden);
	BorderSettings->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseGame->SetVisibility(ESlateVisibility::Hidden);

}

void UGlobalMapWidget::SettingsButtonClicked()
{
	BorderSettings->SetVisibility(ESlateVisibility::Visible);
	ButtonClose->SetVisibility(ESlateVisibility::Visible);
	BorderHero->SetVisibility(ESlateVisibility::Hidden);
	BorderSkills->SetVisibility(ESlateVisibility::Hidden);
	BorderAchievements->SetVisibility(ESlateVisibility::Hidden);
	BorderEncylopedia->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseGame->SetVisibility(ESlateVisibility::Visible);

}

void UGlobalMapWidget::CloseButtonClicked()
{
	BorderHero->SetVisibility(ESlateVisibility::Hidden);
	BorderSkills->SetVisibility(ESlateVisibility::Hidden);
	BorderAchievements->SetVisibility(ESlateVisibility::Hidden);
	BorderEncylopedia->SetVisibility(ESlateVisibility::Hidden);
	BorderSettings->SetVisibility(ESlateVisibility::Hidden);
	ButtonClose->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseGame->SetVisibility(ESlateVisibility::Hidden);
}

void UGlobalMapWidget::CloseGameButtonClicked()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}


//void UGlobalMapWidget::Clicked()
//{
//	UE_LOG(LogTemp, Warning, TEXT("\n\nlevels"));
//	float mouseX;
//	float mouseY;
//	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);
//	UE_LOG(LogTemp, Warning, TEXT("Mouse Location: %f, %f"), mouseX, mouseY);
//	FVector2D ScreenSize = GetGameViewportSize();
//	UE_LOG(LogTemp, Warning, TEXT("screen: %f, %f"), ScreenSize.X, ScreenSize.Y);
//
//	//FVector2D Result  = img->Brush.GetImageSize();
//	//UE_LOG(LogTemp, Warning, TEXT("img: %f, %f"), Result.X, Result.Y);
//
//	/*int Result2 = map->GetSizeX();
//	int Result3 = map->GetSizeY();
//
//	UE_LOG(LogTemp, Warning, TEXT("texture: %d, %d"), Result2, Result3);*/
//}
/*
FVector2D UGlobalMapWidget::GetGameViewportSize()
{
	FVector2D Result = FVector2D(1, 1);

	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize( Result);
	}

	return Result;
}

FVector2D UGlobalMapWidget::GetGameResolution()
{
	FVector2D Result = FVector2D(1, 1);

	Result.X = GSystemResolution.ResX;
	Result.Y = GSystemResolution.ResY;

	return Result;
}*/