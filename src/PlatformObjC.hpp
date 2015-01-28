/* ========================================================================== */
/*                          STC - SIMPLE TETRIS CLONE                         */
/* -------------------------------------------------------------------------- */
/*   Platform definition for Objective-C bridge.                              */
/*                                                                            */
/*   Copyright (c) 2012 Laurens Rodriguez Oscanoa.                            */
/*   This code is licensed under the MIT license:                             */
/*   http://www.opensource.org/licenses/mit-license.php                       */
/* -------------------------------------------------------------------------- */
#ifndef PLATFORM_OBJC_H_
#define PLATFORM_OBJC_H_

#import <OpenGLES/ES1/gl.h>

#include "../stc/game.hpp"
#include "../targa/TargaImage.h"

namespace stc
{

class PlatformObjC : public Platform
{
    // UI layout (quantities are expressed in pixels)

    // Screen size
    static const int SCREEN_WIDTH  = 320;
    static const int SCREEN_HEIGHT = 480;

    // Size of square tile
    static const int TILE_SIZE = 12;

    // Board up-left corner coordinates
    static const int BOARD_X = 180;
    static const int BOARD_Y = 28;

    // Preview tetromino position
    static const int PREVIEW_X = 112;
    static const int PREVIEW_Y = 232;

    // Score position and length on screen
    static const int SCORE_X      = 72;
    static const int SCORE_Y      = 86;
    static const int SCORE_LENGTH = 10;

    // Lines position and length on screen
    static const int LINES_X      = 108;
    static const int LINES_Y      = 68;
    static const int LINES_LENGTH = 5;

    // Level position and length on screen
    static const int LEVEL_X      = 108;
    static const int LEVEL_Y      = 50;
    static const int LEVEL_LENGTH = 5;

    // Tetromino subtotals position
    static const int TETROMINO_X   = 425;
    static const int TETROMINO_L_Y = 53;
    static const int TETROMINO_I_Y = 77;
    static const int TETROMINO_T_Y = 101;
    static const int TETROMINO_S_Y = 125;
    static const int TETROMINO_Z_Y = 149;
    static const int TETROMINO_O_Y = 173;
    static const int TETROMINO_J_Y = 197;

    // Size of subtotals
    static const int TETROMINO_LENGTH = 5;

    // Tetromino total position
    static const int PIECES_X      = 418;
    static const int PIECES_Y      = 221;
    static const int PIECES_LENGTH = 6;

    // Size of number
    static const int NUMBER_WIDTH  = 7;
    static const int NUMBER_HEIGHT = 9;

    // Use 32 bits per pixel
    static const int SCREEN_BIT_DEPTH = 32;

    // Texture size of compounded images
    static const int TEXTURE_SIZE = 512;

    // Size of background inside texture
    static const int BACKGROUND_WIDTH  = 480;    
    static const int BACKGROUND_HEIGHT = 320;    

    // Touch zones limits
    static const int TX_1 = 50;    
    static const int TX_2 = 270;    

    static const int TX_DROP = 70;    
    static const int TX_DOWN = 250;    
    
    static const int TY_1 = 160;    
    static const int TY_2 = 320;    
    
public:
    
    PlatformObjC(id controller);
    void onTouchEnd(id event);
    void onTouchStart(id event);

    virtual int init(Game *game);
    virtual void end();
    virtual void processEvents();
    virtual void renderGame();
    virtual long getSystemTime();
    virtual void seedRandom(long seed);
    virtual int random();

private:
    
    void drawTile(int x, int y, int tile, bool shadow);
    void drawNumber(int x, int y, long number, int length, int color);
    inline void setSpriteTextureCoord(GLfloat *coords, int x, int y, int w, int h);

    Game *mGame;
    
    id mController;
    double mTimeStart;

    TargaImage  *mTexture;
    unsigned int mTextureId;
    GLubyte     *mTextureIndexes;
    GLfloat     *mBackgroundTexCoord;
    GLfloat     *mBackgroundVertices;
    GLfloat     *mSpriteTexCoord;
    GLfloat     *mSpriteVertices;
};
}

#endif
