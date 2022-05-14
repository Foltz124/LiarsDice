//
//  main.c
//  Extension
//
//  Created by Dave Hayden on 7/30/14.
//  Copyright (c) 2014 Panic, Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "pd_api.h"

static PlaydateAPI* pd_api = NULL;

static int update(void* userdata);
LCDBitmap *loadImageAtPath(const char *path);
void preloadImages(void);

const char* fontpath = "/System/Fonts/Asheville-Sans-14-Bold.pft";
const char* diePath = "";
LCDFont* font = NULL;


LCDBitmap **dieFaces = NULL;
LCDBitmap **dieRolls = NULL;

LCDSprite **dieHandSprites = NULL;

#ifdef _WINDLLL
__declspec(dllexport)
#endif
int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
	(void)arg; // arg is currently only used for event = kEventKeyPressed

    pd_api = pd;
	if ( event == kEventInit )
	{
		const char* err;
		// font = pd->graphics->loadFont(fontpath, &err);
		
		// if ( font == NULL )
		// 	pd->system->error("%s:%i Couldn't load font %s: %s", __FILE__, __LINE__, fontpath, err);

		// Note: If you set an update callback in the kEventInit handler, the system assumes the game is pure C and doesn't run any Lua code in the game
		pd->system->setUpdateCallback(update, pd);

        preloadImages();
        
        dieHandSprites = pd->system->realloc(NULL, sizeof(LCDSprite *) * 5);
        uint8_t i = 0;
        char *path = NULL;

        for ( i = 0; i < 5; i++ )
        {

            dieHandSprites[i] = pd->sprite->newSprite();
            pd->sprite->setImage(dieHandSprites[i], dieFaces[i], kBitmapUnflipped);
            pd->sprite->moveTo(dieHandSprites[i], i * 80, 40);
            pd->sprite->addSprite(dieHandSprites[i]);
            pd->sprite->drawSprites();

        }
	}
	
	return 0;
}



static int update(void* userdata)
{
	PlaydateAPI* pd = userdata;
	
	pd->graphics->clear(kColorBlack);

    
	return 1;
}

LCDBitmap *loadImageAtPath(const char *path)
{
	const char *outErr = NULL;
	LCDBitmap *img = pd_api->graphics->loadBitmap(path, &outErr);
	if ( outErr != NULL ) {
		pd_api->system->logToConsole("Error loading image at path '%s': %s", path, outErr);
	}
	return img;
}


void preloadImages(void)
{
	dieFaces = pd_api->system->realloc(NULL, sizeof(LCDBitmap *) * 6);
	dieRolls = pd_api->system->realloc(NULL, sizeof(LCDBitmap *) * 6);

	uint8_t i = 0;
	char *path = NULL;

	for ( i = 0; i < 6; i++ )
	{
		pd_api->system->formatString(&path, "images/Die_face_%d", i+1);
		dieFaces[i] = loadImageAtPath(path);

		pd_api->system->formatString(&path, "images/Die_roll_%d", i+1);
		dieRolls[i] = loadImageAtPath(path);
	}

}
