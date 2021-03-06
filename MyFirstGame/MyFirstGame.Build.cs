// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyFirstGame : ModuleRules
{
	public MyFirstGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core",
                                                            "CoreUObject",
                                                            "Engine",
                                                            "InputCore",
                                                           // "HeadMountedDisplay" ,
                                                            "UnrealEd",
                                                            "ImageWrapper",
                                                            "UMG",
                                                            "Renderer",
                                                            "Slate",
                                                            "SlateCore",
                                                            "ProceduralMeshComponent"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {  "RenderCore",
                                                              "RHI",
                                                              "ShaderCore"
        });

        PrivateIncludePathModuleNames.AddRange(new string[] { "ProceduralMeshComponent" });
	}
}
