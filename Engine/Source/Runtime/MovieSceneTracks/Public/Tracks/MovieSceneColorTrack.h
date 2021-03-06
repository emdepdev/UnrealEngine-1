// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MovieScene.h"
#include "MovieSceneTrack.h"
#include "MovieScenePropertyTrack.h"
#include "MovieSceneColorTrack.generated.h"

struct FColorKey
{
	FLinearColor Value;
	FName CurveName;
	bool bIsSlateColor;
};

/**
 * Handles manipulation of float properties in a movie scene
 */
UCLASS( MinimalAPI )
class UMovieSceneColorTrack : public UMovieScenePropertyTrack
{
	GENERATED_UCLASS_BODY()

public:
	/** UMovieSceneTrack interface */
	virtual UMovieSceneSection* CreateNewSection() override;
	virtual TSharedPtr<IMovieSceneTrackInstance> CreateInstance() override;

	/**
	 * Adds a key to a section.  Will create the section if it doesn't exist
	 *
	 * @param Time				The time relative to the owning movie scene where the section should be
	 * @param Value				The value of the key
	 * @param KeyParams         The keying parameters
	 * @return True if the key was successfully added.
	 */
	virtual bool AddKeyToSection( float Time, const FColorKey& Key, FKeyParams KeyParams );
	
	/**
	 * Evaluates the track at the playback position
	 *
	 * @param Position	The current playback position
	 * @param LastPosition	The last plackback position
	 * @param The color at the playback position
	 * @return true if anything was evaluated. Note: if false is returned OutColor remains unchanged
	 */
	virtual bool Eval( float Position, float LastPostion, FLinearColor& OutColor ) const;

	/**
	 * Get whether the track can be keyed at a particular time.
	 *
	 * @param Time				The time relative to the owning movie scene where the section should be
	 * @param Value				The value of the key
	 * @param KeyParams         The keying parameters
	 * @return Whether the track can be keyed
	 */
	virtual bool CanKeyTrack( float Time, const FColorKey& Key, FKeyParams KeyParams ) const;

private:
	UPROPERTY()
	bool bIsSlateColor_DEPRECATED;
};
