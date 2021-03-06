// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IMovieSceneTrackInstance.h"


class UMovieSceneParticleTrack;


/**
 * Instance of a UMovieSceneParticleTrack
 */
class FMovieSceneParticleTrackInstance
	: public IMovieSceneTrackInstance
{
public:

	FMovieSceneParticleTrackInstance( UMovieSceneParticleTrack& InTrack )
		: ParticleTrack(&InTrack)
	{ }

	virtual ~FMovieSceneParticleTrackInstance();

	/** IMovieSceneTrackInstance interface */
	virtual void SaveState(const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player) override {}
	virtual void RestoreState(const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player) override {}
	virtual void Update( float Position, float LastPosition, const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player ) override;
	virtual void RefreshInstance( const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player ) override {}
	virtual void ClearInstance( IMovieScenePlayer& Player ) override {}

private:

	/** Track that is being instanced */
	UMovieSceneParticleTrack* ParticleTrack;
};
