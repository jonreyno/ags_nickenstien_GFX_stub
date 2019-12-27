// Nickenstien's NGFX Graphics Library plugin stub
// No copyright. This is public domain.


// Windows DLL entry point

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Do any Windows specific constructor/destructor work here.
// Do NOT use for plugin initialization code.
// DllMain will never be called on non-Windows platforms.
BOOL APIENTRY DllMain(HANDLE hModule, DWORD ulReason, LPVOID lpReserved) {
	return TRUE;
}
#endif


// Includes and macros

#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cstdarg>

#define THIS_IS_THE_PLUGIN
#include "agsplugin.h"

#define NGFX_PLUGIN_NAME "Nickenstien's NGFX Graphics Library Stub"
#define NGFX_MESSAGE_PREFIX NGFX_PLUGIN_NAME ": "

#ifdef DEBUG
#define debug_printf(args...) NGFX_Printf("[DEBUG] " NGFX_MESSAGE_PREFIX args)
#else
#define debug_printf(...)
#endif


// Declarations

const char *NGFX_SCRIPT_HEADER =
"import void NGFX_GRAPHICS_Initialise(int GameNativeScreenWidth, int GameNativeScreenHeight);\r\n"
"import void NGFX_GRAPHICS_Enable(bool OnOff);\r\n"
"import void NGFX_GRAPHICS_SetTimeScalar(float TimeScalar);\r\n"
"import void NGFX_GRAPHICS_FullScreenFadeOut(int Time);\r\n"
"import void NGFX_GRAPHICS_FullScreenFadeIn(int Time);\r\n"
"import void NGFX_GRAPHICS_FullScreenFadeOut_2(int Time, int BlendMode, int R, int G, int B, int NumLayers, float BackSpeed, float FrontSpeed, String TextureFilename);\r\n"
"import void NGFX_GRAPHICS_FullScreenFadeOut_2_SetBackgroundColour(int Back_R, int Back_G, int Back_B);\r\n"
"import void NGFX_GRAPHICS_FullScreenFadeIn_2(int Time);\r\n"
"import void NGFX_GRAPHICS_SetAnisotropicFilter(int TrueFalse);\r\n"
"import int NGFX_TEXTURE_Load(String Filename);\r\n"
"import void NGFX_TEXTURE_Release(int TextureHandle);\r\n"
"import int NGFX_TEXTURE_GetWidth(int TextureHandle);\r\n"
"import int NGFX_TEXTURE_GetHeight(int TextureHandle);\r\n"
"import int NGFX_PARTICLE_EMITTER_Create(int MaxParticlesForThisEmitter);\r\n"
"import void NGFX_PARTICLE_EMITTER_Release(int ParticleEmitterHandle);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetType(int ParticleEmitterHandle, int EmitterType);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetLife(int ParticleEmitterHandle, float EmitterLife);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEmittionRate(int ParticleEmitterHandle, float EmittionRate);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetParticlesPerEmittion(int ParticleEmitterHandle, int ParticlesPerEmittion);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetPosition1(int ParticleEmitterHandle, float PosX, float PosY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetPosition2(int ParticleEmitterHandle, float PosX, float PosY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartVelocity(int ParticleEmitterHandle, float VelocityX, float VelocityY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartVelocity_Deviation(int ParticleEmitterHandle, float VelocityDeviationX, float VelocityDeviationY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndVelocity(int ParticleEmitterHandle, float VelocityX, float VelocityY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndVelocity_Deviation(int ParticleEmitterHandle, float VelocityDeviationX, float VelocityDeviationY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartWidth(int ParticleEmitterHandle, float Width);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartWidth_Deviation(int ParticleEmitterHandle, float WidthDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndWidth(int ParticleEmitterHandle, float Width);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndWidth_Deviation(int ParticleEmitterHandle, float WidthDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartHeight(int ParticleEmitterHandle, float Height);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartHeight_Deviation(int ParticleEmitterHandle, float HeightDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndHeight(int ParticleEmitterHandle, float Height);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndHeight_Deviation(int ParticleEmitterHandle, float HeightDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartAngle(int ParticleEmitterHandle, float Angle);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartAngle_Deviation(int ParticleEmitterHandle, float AngleDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetRotation(int ParticleEmitterHandle, float Rotation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetRotation_Deviation(int ParticleEmitterHandle, float RotationDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartColour(int ParticleEmitterHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetStartColour_Deviation(int ParticleEmitterHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndColour(int ParticleEmitterHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetEndColour_Deviation(int ParticleEmitterHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetBlendMode(int ParticleEmitterHandle, int BlendMode);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetTexture(int ParticleEmitterHandle, int TextureHandle);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetForce(int ParticleEmitterHandle, float ForceX, float ForceY);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetParticleLife(int ParticleEmitterHandle, float Life);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetParticleLife_Deviation(int ParticleEmitterHandle, float LifeDeviation);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetNoTimeOut(int ParticleEmitterHandle, int TrueFalse);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetDrawOrderReversed(int ParticleEmitterHandle, int TrueFalse);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetProcessWhenOffScreen(int ParticleEmitterHandle, int TrueFalse);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetUseVelocityParticles(int ParticleEmitterHandle, int TrueFalse);\r\n"
"import void NGFX_PARTICLE_EMITTER_SetChannelID(int ParticleEmitterHandle, int ChannelID);\r\n"
"import void NGFX_PARTICLE_EMITTER_Start(int ParticleEmitterHandle);\r\n"
"import int NGFX_PARTICLE_EMITTER_Clone(int SourceParticleEmitterHandle);\r\n"
"import void NGFX_PARTICLE_EMITTER_ReleaseAll();\r\n"
"import void NGFX_PARTICLE_EMITTER_Evolve(int ParticleEmitterHandle, float TimeToEvolveBy);\r\n"
"import bool NGFX_HasGameRoomChanged(int CurrentGameRoom);\r\n"
"import bool NGFX_HasGameRoomChanged_SecondTest(int CurrentGameRoom);\r\n"
"import void NGFX_SPRITE_ResetForNewRoom();\r\n"
"import int NGFX_SPRITE_Create();\r\n"
"import void NGFX_SPRITE_Release(int SpriteHandle);\r\n"
"import void NGFX_SPRITE_SetChannelID(int SpriteHandle, int ChannelID);\r\n"
"import void NGFX_SPRITE_SetPosition(int SpriteHandle, float x, float y);\r\n"
"import void NGFX_SPRITE_SetPivot(int SpriteHandle, float x, float y);\r\n"
"import void NGFX_SPRITE_SetTexture(int SpriteHandle, int TextureHandle);\r\n"
"import void NGFX_SPRITE_SetBlendMode(int SpriteHandle, int BlendMode);\r\n"
"import void NGFX_SPRITE_SetWidth(int SpriteHandle, float Width);\r\n"
"import void NGFX_SPRITE_SetHeight(int SpriteHandle, float Height);\r\n"
"import void NGFX_SPRITE_SetAngle(int SpriteHandle, float Angle);\r\n"
"import void NGFX_SPRITE_SetColour_1(int SpriteHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_SPRITE_SetColour_2(int SpriteHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_SPRITE_SetColour_3(int SpriteHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_SPRITE_SetColour_4(int SpriteHandle, int R, int G, int B, int A);\r\n"
"import void NGFX_SPRITE_SetClipRectangle(int SpriteHandle, float x, float y, float x2, float y2);\r\n"
"import void NGFX_SPRITE_SetGourard(int SpriteHandle, int TrueFalse);\r\n"
"import void NGFX_SPRITE_SetFlipped_H(int SpriteHandle, int TrueFalse);\r\n"
"import void NGFX_SPRITE_SetFlipped_V(int SpriteHandle, int TrueFalse);\r\n"
"import void NGFX_SPRITE_AddToDrawList(int SpriteHandle);\r\n"
"import void NGFX_InitForNewGameLoop();\r\n";

// Global state
static IAGSEditor *NGFX_editor = 0;
static IAGSEngine *NGFX_engine = 0;
static bool NGFX_initialized = false;

// Helper function declarations
static void NGFX_Printf(const char *format, ...);
static int NGFX_New(IAGSEngine *engine);
static void NGFX_Delete();
int NGFX_PrevHandle = 0;

// Script interface declarations
static void NGFX_GRAPHICS_Initialise(int GameNativeScreenWidth, int GameNativeScreenHeight);
static void NGFX_GRAPHICS_Enable(bool OnOff);
static void NGFX_GRAPHICS_SetTimeScalar(float TimeScalar);
static void NGFX_GRAPHICS_FullScreenFadeOut(int Time);
static void NGFX_GRAPHICS_FullScreenFadeIn(int Time);
static void NGFX_GRAPHICS_FullScreenFadeOut_2(int Time, int BlendMode, int R, int G, int B, int NumLayers, float BackSpeed, float FrontSpeed, char *TextureFilename);
static void NGFX_GRAPHICS_FullScreenFadeOut_2_SetBackgroundColour(int Back_R, int Back_G, int Back_B);
static void NGFX_GRAPHICS_FullScreenFadeIn_2(int Time);
static void NGFX_GRAPHICS_SetAnisotropicFilter(int TrueFalse);
static int NGFX_TEXTURE_Load(char *Filename);
static void NGFX_TEXTURE_Release(int TextureHandle);
static int NGFX_TEXTURE_GetWidth(int TextureHandle);
static int NGFX_TEXTURE_GetHeight(int TextureHandle);
static int NGFX_PARTICLE_EMITTER_Create(int MaxParticlesForThisEmitter);
static void NGFX_PARTICLE_EMITTER_Release(int ParticleEmitterHandle);
static void NGFX_PARTICLE_EMITTER_SetType(int ParticleEmitterHandle, int EmitterType);
static void NGFX_PARTICLE_EMITTER_SetLife(int ParticleEmitterHandle, float EmitterLife);
static void NGFX_PARTICLE_EMITTER_SetEmittionRate(int ParticleEmitterHandle, float EmittionRate);
static void NGFX_PARTICLE_EMITTER_SetParticlesPerEmittion(int ParticleEmitterHandle, int ParticlesPerEmittion);
static void NGFX_PARTICLE_EMITTER_SetPosition1(int ParticleEmitterHandle, float PosX, float PosY);
static void NGFX_PARTICLE_EMITTER_SetPosition2(int ParticleEmitterHandle, float PosX, float PosY);
static void NGFX_PARTICLE_EMITTER_SetStartVelocity(int ParticleEmitterHandle, float VelocityX, float VelocityY);
static void NGFX_PARTICLE_EMITTER_SetStartVelocity_Deviation(int ParticleEmitterHandle, float VelocityDeviationX, float VelocityDeviationY);
static void NGFX_PARTICLE_EMITTER_SetEndVelocity(int ParticleEmitterHandle, float VelocityX, float VelocityY);
static void NGFX_PARTICLE_EMITTER_SetEndVelocity_Deviation(int ParticleEmitterHandle, float VelocityDeviationX, float VelocityDeviationY);
static void NGFX_PARTICLE_EMITTER_SetStartWidth(int ParticleEmitterHandle, float Width);
static void NGFX_PARTICLE_EMITTER_SetStartWidth_Deviation(int ParticleEmitterHandle, float WidthDeviation);
static void NGFX_PARTICLE_EMITTER_SetEndWidth(int ParticleEmitterHandle, float Width);
static void NGFX_PARTICLE_EMITTER_SetEndWidth_Deviation(int ParticleEmitterHandle, float WidthDeviation);
static void NGFX_PARTICLE_EMITTER_SetStartHeight(int ParticleEmitterHandle, float Height);
static void NGFX_PARTICLE_EMITTER_SetStartHeight_Deviation(int ParticleEmitterHandle, float HeightDeviation);
static void NGFX_PARTICLE_EMITTER_SetEndHeight(int ParticleEmitterHandle, float Height);
static void NGFX_PARTICLE_EMITTER_SetEndHeight_Deviation(int ParticleEmitterHandle, float HeightDeviation);
static void NGFX_PARTICLE_EMITTER_SetStartAngle(int ParticleEmitterHandle, float Angle);
static void NGFX_PARTICLE_EMITTER_SetStartAngle_Deviation(int ParticleEmitterHandle, float AngleDeviation);
static void NGFX_PARTICLE_EMITTER_SetRotation(int ParticleEmitterHandle, float Rotation);
static void NGFX_PARTICLE_EMITTER_SetRotation_Deviation(int ParticleEmitterHandle, float RotationDeviation);
static void NGFX_PARTICLE_EMITTER_SetStartColour(int ParticleEmitterHandle, int R, int G, int B, int A);
static void NGFX_PARTICLE_EMITTER_SetStartColour_Deviation(int ParticleEmitterHandle, int R, int G, int B, int A);
static void NGFX_PARTICLE_EMITTER_SetEndColour(int ParticleEmitterHandle, int R, int G, int B, int A);
static void NGFX_PARTICLE_EMITTER_SetEndColour_Deviation(int ParticleEmitterHandle, int R, int G, int B, int A);
static void NGFX_PARTICLE_EMITTER_SetBlendMode(int ParticleEmitterHandle, int BlendMode);
static void NGFX_PARTICLE_EMITTER_SetTexture(int ParticleEmitterHandle, int TextureHandle);
static void NGFX_PARTICLE_EMITTER_SetForce(int ParticleEmitterHandle, float ForceX, float ForceY);
static void NGFX_PARTICLE_EMITTER_SetParticleLife(int ParticleEmitterHandle, float Life);
static void NGFX_PARTICLE_EMITTER_SetParticleLife_Deviation(int ParticleEmitterHandle, float LifeDeviation);
static void NGFX_PARTICLE_EMITTER_SetNoTimeOut(int ParticleEmitterHandle, int TrueFalse);
static void NGFX_PARTICLE_EMITTER_SetDrawOrderReversed(int ParticleEmitterHandle, int TrueFalse);
static void NGFX_PARTICLE_EMITTER_SetProcessWhenOffScreen(int ParticleEmitterHandle, int TrueFalse);
static void NGFX_PARTICLE_EMITTER_SetUseVelocityParticles(int ParticleEmitterHandle, int TrueFalse);
static void NGFX_PARTICLE_EMITTER_SetChannelID(int ParticleEmitterHandle, int ChannelID);
static void NGFX_PARTICLE_EMITTER_Start(int ParticleEmitterHandle);
static int NGFX_PARTICLE_EMITTER_Clone(int SourceParticleEmitterHandle);
static void NGFX_PARTICLE_EMITTER_ReleaseAll();
static void NGFX_PARTICLE_EMITTER_Evolve(int ParticleEmitterHandle, float TimeToEvolveBy);
static bool NGFX_HasGameRoomChanged(int CurrentGameRoom);
static bool NGFX_HasGameRoomChanged_SecondTest(int CurrentGameRoom);
static void NGFX_SPRITE_ResetForNewRoom();
static int NGFX_SPRITE_Create();
static void NGFX_SPRITE_Release(int SpriteHandle);
static void NGFX_SPRITE_SetChannelID(int SpriteHandle, int ChannelID);
static void NGFX_SPRITE_SetPosition(int SpriteHandle, float x, float y);
static void NGFX_SPRITE_SetPivot(int SpriteHandle, float x, float y);
static void NGFX_SPRITE_SetTexture(int SpriteHandle, int TextureHandle);
static void NGFX_SPRITE_SetBlendMode(int SpriteHandle, int BlendMode);
static void NGFX_SPRITE_SetWidth(int SpriteHandle, float Width);
static void NGFX_SPRITE_SetHeight(int SpriteHandle, float Height);
static void NGFX_SPRITE_SetAngle(int SpriteHandle, float Angle);
static void NGFX_SPRITE_SetColour_1(int SpriteHandle, int R, int G, int B, int A);
static void NGFX_SPRITE_SetColour_2(int SpriteHandle, int R, int G, int B, int A);
static void NGFX_SPRITE_SetColour_3(int SpriteHandle, int R, int G, int B, int A);
static void NGFX_SPRITE_SetColour_4(int SpriteHandle, int R, int G, int B, int A);
static void NGFX_SPRITE_SetClipRectangle(int SpriteHandle, float x, float y, float x2, float y2);
static void NGFX_SPRITE_SetGourard(int SpriteHandle, int TrueFalse);
static void NGFX_SPRITE_SetFlipped_H(int SpriteHandle, int TrueFalse);
static void NGFX_SPRITE_SetFlipped_V(int SpriteHandle, int TrueFalse);
static void NGFX_SPRITE_AddToDrawList(int SpriteHandle);
static void NGFX_InitForNewGameLoop();


// Helper functions

static void NGFX_Printf(const char *format, ...) {
	va_list args;
	va_start(args, format);
	char *buffer = new char[256];
	if (buffer) {
		if (vsnprintf(buffer, 255, format, args) != -1) {
			if (NGFX_engine) {
				NGFX_engine->PrintDebugConsole(buffer);
			} else {
				puts(buffer);
			}
		}
		delete[] buffer;
	}
	va_end(args);
}

static int NGFX_New(IAGSEngine *engine) {
	if (!NGFX_initialized) {
		if (engine->version < 17) {
			engine->AbortGame(NGFX_MESSAGE_PREFIX "Plugin needs a newer version of AGS to run (engine interface version 17)");
		} else {
			NGFX_engine = engine;

			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_Initialise", reinterpret_cast<void *>(NGFX_GRAPHICS_Initialise));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_Enable", reinterpret_cast<void *>(NGFX_GRAPHICS_Enable));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_SetTimeScalar", reinterpret_cast<void *>(NGFX_GRAPHICS_SetTimeScalar));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_FullScreenFadeOut", reinterpret_cast<void *>(NGFX_GRAPHICS_FullScreenFadeOut));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_FullScreenFadeIn", reinterpret_cast<void *>(NGFX_GRAPHICS_FullScreenFadeIn));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_FullScreenFadeOut_2", reinterpret_cast<void *>(NGFX_GRAPHICS_FullScreenFadeOut_2));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_FullScreenFadeIn_2", reinterpret_cast<void *>(NGFX_GRAPHICS_FullScreenFadeIn_2));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_FullScreenFadeOut_2_SetBackgroundColour", reinterpret_cast<void *>(NGFX_GRAPHICS_FullScreenFadeOut_2_SetBackgroundColour));
			NGFX_engine->RegisterScriptFunction("NGFX_GRAPHICS_SetAnisotropicFilter", reinterpret_cast<void *>(NGFX_GRAPHICS_SetAnisotropicFilter));
			NGFX_engine->RegisterScriptFunction("NGFX_TEXTURE_Load", reinterpret_cast<void *>(NGFX_TEXTURE_Load));
			NGFX_engine->RegisterScriptFunction("NGFX_TEXTURE_Release", reinterpret_cast<void *>(NGFX_TEXTURE_Release));
			NGFX_engine->RegisterScriptFunction("NGFX_TEXTURE_GetWidth", reinterpret_cast<void *>(NGFX_TEXTURE_GetWidth));
			NGFX_engine->RegisterScriptFunction("NGFX_TEXTURE_GetHeight", reinterpret_cast<void *>(NGFX_TEXTURE_GetHeight));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_Create", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_Create));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_Release", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_Release));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetType", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetType));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetLife", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetLife));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEmittionRate", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEmittionRate));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetParticlesPerEmittion", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetParticlesPerEmittion));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetPosition1", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetPosition1));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetPosition2", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetPosition2));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartVelocity", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartVelocity));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartVelocity_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartVelocity_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndVelocity", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndVelocity));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndVelocity_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndVelocity_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartWidth", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartWidth));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartWidth_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartWidth_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndWidth", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndWidth));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndWidth_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndWidth_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartHeight", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartHeight));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartHeight_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartHeight_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndHeight", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndHeight));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndHeight_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndHeight_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartAngle", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartAngle));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartAngle_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartAngle_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetRotation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetRotation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetRotation_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetRotation_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartColour", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartColour));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetStartColour_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetStartColour_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndColour", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndColour));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetEndColour_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetEndColour_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetBlendMode", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetBlendMode));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetTexture", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetTexture));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetForce", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetForce));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetParticleLife", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetParticleLife));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetParticleLife_Deviation", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetParticleLife_Deviation));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetNoTimeOut", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetNoTimeOut));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetDrawOrderReversed", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetDrawOrderReversed));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetProcessWhenOffScreen", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetProcessWhenOffScreen));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetUseVelocityParticles", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetUseVelocityParticles));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_SetChannelID", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_SetChannelID));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_Start", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_Start));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_Clone", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_Clone));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_ReleaseAll", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_ReleaseAll));
			NGFX_engine->RegisterScriptFunction("NGFX_PARTICLE_EMITTER_Evolve", reinterpret_cast<void *>(NGFX_PARTICLE_EMITTER_Evolve));
			NGFX_engine->RegisterScriptFunction("NGFX_HasGameRoomChanged", reinterpret_cast<void *>(NGFX_HasGameRoomChanged));
			NGFX_engine->RegisterScriptFunction("NGFX_HasGameRoomChanged_SecondTest", reinterpret_cast<void *>(NGFX_HasGameRoomChanged_SecondTest));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_ResetForNewRoom", reinterpret_cast<void *>(NGFX_SPRITE_ResetForNewRoom));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_Create", reinterpret_cast<void *>(NGFX_SPRITE_Create));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_Release", reinterpret_cast<void *>(NGFX_SPRITE_Release));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetChannelID", reinterpret_cast<void *>(NGFX_SPRITE_SetChannelID));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetPosition", reinterpret_cast<void *>(NGFX_SPRITE_SetPosition));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetPivot", reinterpret_cast<void *>(NGFX_SPRITE_SetPivot));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetTexture", reinterpret_cast<void *>(NGFX_SPRITE_SetTexture));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetBlendMode", reinterpret_cast<void *>(NGFX_SPRITE_SetBlendMode));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetWidth", reinterpret_cast<void *>(NGFX_SPRITE_SetWidth));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetHeight", reinterpret_cast<void *>(NGFX_SPRITE_SetHeight));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetAngle", reinterpret_cast<void *>(NGFX_SPRITE_SetAngle));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetColour_1", reinterpret_cast<void *>(NGFX_SPRITE_SetColour_1));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetColour_2", reinterpret_cast<void *>(NGFX_SPRITE_SetColour_2));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetColour_3", reinterpret_cast<void *>(NGFX_SPRITE_SetColour_3));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetColour_4", reinterpret_cast<void *>(NGFX_SPRITE_SetColour_4));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetClipRectangle", reinterpret_cast<void *>(NGFX_SPRITE_SetClipRectangle));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetGourard", reinterpret_cast<void *>(NGFX_SPRITE_SetGourard));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetFlipped_H", reinterpret_cast<void *>(NGFX_SPRITE_SetFlipped_H));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_SetFlipped_V", reinterpret_cast<void *>(NGFX_SPRITE_SetFlipped_V));
			NGFX_engine->RegisterScriptFunction("NGFX_SPRITE_AddToDrawList", reinterpret_cast<void *>(NGFX_SPRITE_AddToDrawList));
			NGFX_engine->RegisterScriptFunction("NGFX_InitForNewGameLoop", reinterpret_cast<void *>(NGFX_InitForNewGameLoop));

			NGFX_initialized = true;
			debug_printf("New(%p): %d\n", engine, NGFX_initialized);
			NGFX_Printf(NGFX_MESSAGE_PREFIX "Loaded\n");
		}
	}
	return NGFX_initialized ? 1 : 0;
}

static void NGFX_Delete() {
	debug_printf("Delete()\n");
	NGFX_Printf(NGFX_MESSAGE_PREFIX "Unloaded\n");
	NGFX_engine = 0;
	NGFX_initialized = false;
}

int NGFX_GetNewHandle()
{
	return NGFX_PrevHandle += 1;
}

// Script interface


void NGFX_GRAPHICS_Initialise(int GameNativeScreenWidth, int GameNativeScreenHeight)
{

}

void NGFX_GRAPHICS_Enable(bool OnOff)
{

}

void NGFX_GRAPHICS_SetTimeScalar(float TimeScalar)
{

}

void NGFX_GRAPHICS_FullScreenFadeOut(int Time)
{

}

void NGFX_GRAPHICS_FullScreenFadeIn(int Time)
{

}

void NGFX_GRAPHICS_FullScreenFadeOut_2(int Time, int BlendMode, int R, int G, int B, int NumLayers, float BackSpeed, float FrontSpeed, char *TextureFilename)
{

}

void NGFX_GRAPHICS_FullScreenFadeOut_2_SetBackgroundColour(int Back_R, int Back_G, int Back_B)
{

}

void NGFX_GRAPHICS_FullScreenFadeIn_2(int Time)
{

}

void NGFX_GRAPHICS_SetAnisotropicFilter(int TrueFalse)
{

}

int NGFX_TEXTURE_Load(char *Filename)
{
	return NGFX_GetNewHandle();
}

void NGFX_TEXTURE_Release(int TextureHandle)
{

}

int NGFX_TEXTURE_GetWidth(int TextureHandle)
{
	return 1;
}

int NGFX_TEXTURE_GetHeight(int TextureHandle)
{
	return 1;
}

int NGFX_PARTICLE_EMITTER_Create(int MaxParticlesForThisEmitter)
{
	return NGFX_GetNewHandle();
}

void NGFX_PARTICLE_EMITTER_Release(int ParticleEmitterHandle)
{

}

void NGFX_PARTICLE_EMITTER_SetType(int ParticleEmitterHandle, int EmitterType)
{

}

void NGFX_PARTICLE_EMITTER_SetLife(int ParticleEmitterHandle, float EmitterLife)
{

}

void NGFX_PARTICLE_EMITTER_SetEmittionRate(int ParticleEmitterHandle, float EmittionRate)
{

}

void NGFX_PARTICLE_EMITTER_SetParticlesPerEmittion(int ParticleEmitterHandle, int ParticlesPerEmittion)
{

}

void NGFX_PARTICLE_EMITTER_SetPosition1(int ParticleEmitterHandle, float PosX, float PosY)
{

}

void NGFX_PARTICLE_EMITTER_SetPosition2(int ParticleEmitterHandle, float PosX, float PosY)
{

}

void NGFX_PARTICLE_EMITTER_SetStartVelocity(int ParticleEmitterHandle, float VelocityX, float VelocityY)
{

}

void NGFX_PARTICLE_EMITTER_SetStartVelocity_Deviation(int ParticleEmitterHandle, float VelocityDeviationX, float VelocityDeviationY)
{

}

void NGFX_PARTICLE_EMITTER_SetEndVelocity(int ParticleEmitterHandle, float VelocityX, float VelocityY)
{

}

void NGFX_PARTICLE_EMITTER_SetEndVelocity_Deviation(int ParticleEmitterHandle, float VelocityDeviationX, float VelocityDeviationY)
{

}

void NGFX_PARTICLE_EMITTER_SetStartWidth(int ParticleEmitterHandle, float Width)
{

}

void NGFX_PARTICLE_EMITTER_SetStartWidth_Deviation(int ParticleEmitterHandle, float WidthDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetEndWidth(int ParticleEmitterHandle, float Width)
{

}

void NGFX_PARTICLE_EMITTER_SetEndWidth_Deviation(int ParticleEmitterHandle, float WidthDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetStartHeight(int ParticleEmitterHandle, float Height)
{

}

void NGFX_PARTICLE_EMITTER_SetStartHeight_Deviation(int ParticleEmitterHandle, float HeightDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetEndHeight(int ParticleEmitterHandle, float Height)
{

}

void NGFX_PARTICLE_EMITTER_SetEndHeight_Deviation(int ParticleEmitterHandle, float HeightDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetStartAngle(int ParticleEmitterHandle, float Angle)
{

}

void NGFX_PARTICLE_EMITTER_SetStartAngle_Deviation(int ParticleEmitterHandle, float AngleDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetRotation(int ParticleEmitterHandle, float Rotation)
{

}

void NGFX_PARTICLE_EMITTER_SetRotation_Deviation(int ParticleEmitterHandle, float RotationDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetStartColour(int ParticleEmitterHandle, int R, int G, int B, int A)
{

}

void NGFX_PARTICLE_EMITTER_SetStartColour_Deviation(int ParticleEmitterHandle, int R, int G, int B, int A)
{

}

void NGFX_PARTICLE_EMITTER_SetEndColour(int ParticleEmitterHandle, int R, int G, int B, int A)
{

}

void NGFX_PARTICLE_EMITTER_SetEndColour_Deviation(int ParticleEmitterHandle, int R, int G, int B, int A)
{

}

void NGFX_PARTICLE_EMITTER_SetBlendMode(int ParticleEmitterHandle, int BlendMode)
{

}

void NGFX_PARTICLE_EMITTER_SetTexture(int ParticleEmitterHandle, int TextureHandle)
{

}

void NGFX_PARTICLE_EMITTER_SetForce(int ParticleEmitterHandle, float ForceX, float ForceY)
{

}

void NGFX_PARTICLE_EMITTER_SetParticleLife(int ParticleEmitterHandle, float Life)
{

}

void NGFX_PARTICLE_EMITTER_SetParticleLife_Deviation(int ParticleEmitterHandle, float LifeDeviation)
{

}

void NGFX_PARTICLE_EMITTER_SetNoTimeOut(int ParticleEmitterHandle, int TrueFalse)
{

}

void NGFX_PARTICLE_EMITTER_SetDrawOrderReversed(int ParticleEmitterHandle, int TrueFalse)
{

}

void NGFX_PARTICLE_EMITTER_SetProcessWhenOffScreen(int ParticleEmitterHandle, int TrueFalse)
{

}

void NGFX_PARTICLE_EMITTER_SetUseVelocityParticles(int ParticleEmitterHandle, int TrueFalse)
{

}

void NGFX_PARTICLE_EMITTER_SetChannelID(int ParticleEmitterHandle, int ChannelID)
{

}

void NGFX_PARTICLE_EMITTER_Start(int ParticleEmitterHandle)
{

}

int NGFX_PARTICLE_EMITTER_Clone(int SourceParticleEmitterHandle)
{
	return NGFX_GetNewHandle();
}

void NGFX_PARTICLE_EMITTER_ReleaseAll()
{

}

void NGFX_PARTICLE_EMITTER_Evolve(int ParticleEmitterHandle, float TimeToEvolveBy)
{

}

bool NGFX_HasGameRoomChanged(int CurrentGameRoom)
{
	return false;
}

bool NGFX_HasGameRoomChanged_SecondTest(int CurrentGameRoom)
{
	return false;
}

void NGFX_SPRITE_ResetForNewRoom()
{

}

int NGFX_SPRITE_Create()
{
	return NGFX_GetNewHandle();
}

void NGFX_SPRITE_Release(int SpriteHandle)
{

}

void NGFX_SPRITE_SetChannelID(int SpriteHandle, int ChannelID)
{

}

void NGFX_SPRITE_SetPosition(int SpriteHandle, float x, float y)
{

}

void NGFX_SPRITE_SetPivot(int SpriteHandle, float x, float y)
{

}

void NGFX_SPRITE_SetTexture(int SpriteHandle, int TextureHandle)
{

}

void NGFX_SPRITE_SetBlendMode(int SpriteHandle, int BlendMode)
{

}

void NGFX_SPRITE_SetWidth(int SpriteHandle, float Width)
{

}

void NGFX_SPRITE_SetHeight(int SpriteHandle, float Height)
{

}

void NGFX_SPRITE_SetAngle(int SpriteHandle, float Angle)
{

}

void NGFX_SPRITE_SetColour_1(int SpriteHandle, int R, int G, int B, int A)
{

}

void NGFX_SPRITE_SetColour_2(int SpriteHandle, int R, int G, int B, int A)
{

}

void NGFX_SPRITE_SetColour_3(int SpriteHandle, int R, int G, int B, int A)
{

}

void NGFX_SPRITE_SetColour_4(int SpriteHandle, int R, int G, int B, int A)
{

}

void NGFX_SPRITE_SetClipRectangle(int SpriteHandle, float x, float y, float x2, float y2)
{

}

void NGFX_SPRITE_SetGourard(int SpriteHandle, int TrueFalse)
{

}

void NGFX_SPRITE_SetFlipped_H(int SpriteHandle, int TrueFalse)
{

}

void NGFX_SPRITE_SetFlipped_V(int SpriteHandle, int TrueFalse)
{

}

void NGFX_SPRITE_AddToDrawList(int SpriteHandle)
{

}

void NGFX_InitForNewGameLoop()
{

}

// AGS engine interface

const char *AGS_GetPluginName() {
	debug_printf("AGS_GetPluginName()\n");
	return NGFX_PLUGIN_NAME;
}

int AGS_EditorStartup(IAGSEditor *lpEditor) {
	int ret = 0;
	if (lpEditor->version >= 1) {
		NGFX_editor = lpEditor;
		NGFX_editor->RegisterScriptHeader(NGFX_SCRIPT_HEADER);
	}
	debug_printf("AGS_EditorStartup(%p): %d", lpEditor, ret);
	return ret;
}

void AGS_EditorShutdown() {
	debug_printf("AGS_EditorShutdown()\n");
	NGFX_editor->UnregisterScriptHeader(NGFX_SCRIPT_HEADER);
	NGFX_editor = 0;
}

void AGS_EditorProperties(HWND parent) {
	debug_printf("AGS_EditorProperties(%d)\n", parent);
	printf("NGFX stub plugin\n");
}

int AGS_EditorSaveGame(char *buffer, int bufsize) {
	int ret = 0;
	debug_printf("AGS_EditorSaveGame(%p, %d): %d\n", buffer, bufsize, ret);
	return ret;
}

void AGS_EditorLoadGame(char *buffer, int bufsize) {
	debug_printf("AGS_EditorLoadGame(%p, %d)\n", buffer, bufsize);
}

void AGS_EngineStartup(IAGSEngine *lpGame) {
	NGFX_New(lpGame);
	debug_printf("AGS_EngineStartup(%p)\n", lpGame);
}

void AGS_EngineShutdown() {
	debug_printf("AGS_EngineShutdown()\n");
	NGFX_Delete();
	return;
}

int AGS_EngineOnEvent(int event, int data) {
	int ret = 0;
	debug_printf("AGS_EngineOnEvent(%d, %d): %d\n", event, data, ret);
	return ret;
}
