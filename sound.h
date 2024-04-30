
#ifndef _SOUND_H_
#define _SOUND_H_
#include <XAudio2.h>
#include <Windows.h>


typedef enum
{
	SOUND_LABEL_GAMEBGM,		// BGM0
	SOUND_LABEL_S2BGM,		// BGM0
	SOUND_LABEL_S3BGM,		// BGM0
	SOUND_LABEL_TITLEBGM,		// BGM0
	SOUND_LABEL_ENDBGM,		// BGM0
	SOUND_LABEL_TBGM,		// BGM0
	SOUND_LABEL_SE_JUMP,
	SOUND_LABEL_SE_START,
	SOUND_LABEL_SE_SPEED,
	SOUND_LABEL_SE_SUPERJUMP,
	SOUND_LABEL_SE_SLOW,
	SOUND_LABEL_SE_CHAOS,
	SOUND_LABEL_SE_GOAL,
	SOUND_LABEL_SE_CHOICE,
	SOUND_LABEL_SE_CHOICE1,
	SOUND_LABEL_SE_DETAH,
	SOUND_LABEL_SE_COIN,

	SOUND_LABEL_MAX,
} SOUND_LABEL;
class tag_Sound
{
private:


	struct SOUNDPARAM
	{
		const char *pFilename;	
		int nCntLoop;		
	};

	SOUNDPARAM g_aParam[SOUND_LABEL_MAX] = {};

	IXAudio2 *g_pXAudio2 = NULL;								
	IXAudio2MasteringVoice *g_pMasteringVoice = NULL;			
	IXAudio2SourceVoice *g_apSourceVoice[SOUND_LABEL_MAX] = {};	
	BYTE *g_apDataAudio[SOUND_LABEL_MAX] = {};					
	DWORD g_aSizeAudio[SOUND_LABEL_MAX] = {};
public:
	HRESULT Init(HWND hWnd);
	void Uninit(void);
	HRESULT Play(SOUND_LABEL label);
	void Stop(SOUND_LABEL label);
	void Stop(void);
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);
};
extern tag_Sound Sound;
#endif
