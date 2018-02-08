// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyFirstGame.h"
#include "MyPlayerController.generated.h"

class ARunPlatform_Beam;
class ARunPlatform;
class ABonus;
/**
 * 1、自动生成平台
 */
UCLASS()
class MYFIRSTGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

public:
	ARunPlatform* CurPlatform;

	/***/
	ARunPlatform* TempPlatform;
	
	/**当前连接的闪电平台*/
	ARunPlatform_Beam* CurConnectedPlat;

	/**要生成的平台*/
	TSubclassOf<ARunPlatform> SpawnPlatform;

	/**需要触发的平台*/
	TSubclassOf<ARunPlatform> SpawnPlatform_Shoot;

	TSubclassOf<ARunPlatform> SpawnPlatform_Beam;

	/*分数奖励的蓝图对象*/
	TSubclassOf<ABonus> Bonus_Score;

	/**存放当前所有平台的数组*/
	TArray<ARunPlatform*> PlatformArray;

	/**生成的平台中的绝对方向信息*/
	uint8 AbsoluteDir;
	
	TEnumAsByte<EWeaponType::Type> CurrentWeaponType;

	/**当前玩家是否连接着平台*/
	uint8 InConnectedToPlat : 1;

public:
	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction);

	virtual void Destroyed()override;

protected:
	virtual void SetupInputComponent()override;

	virtual void PostInitializeComponents()override;

public:
	/**用于自动生成平台,这是经过触发才能触发的平台*/
	FTransform GetSpawnTransf_Shoot(ARunPlatform* PrePlatform);

	/**根据上个一个平台（相对于数组里的）计算生成平台的位置*/
	FTransform GetRandomSpawnTransf(ARunPlatform* PrePlatform);

	/**获取生成闪电平台的位置*/
	FTransform GetSpawnTransf_Beam(ARunPlatform* PrePlatform);

	/**在当前平台上生成Bonus*/
	void SpawnBonus_Score(ARunPlatform* CurPlatform);

	void ChangeWeaponType(EWeaponType::Type WeaponType);

};
