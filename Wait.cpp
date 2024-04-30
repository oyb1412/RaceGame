
#include "Scene.h"
#include "Fade.h"
#include "Wait.h"
void tag_Wait::Init()
{
	Count = 0;
}
void tag_Wait::Update(SCENE SceneNumber)
{
	Count++;
	if (Count >= 60)
	{
		Scene.SetNextScene(SceneNumber);
	}
}

