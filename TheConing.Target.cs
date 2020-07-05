// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TheConingTarget : TargetRules
{
	public TheConingTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
//		bUseUnityBuild = false;
//		bUsePCHFiles = false;
        ExtraModuleNames.Add("TheConing");
	}
}
