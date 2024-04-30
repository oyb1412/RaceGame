#include "scene.h"
#include "fade.h"
#include "Title.h"
#include "Game.h"
#include "scene.h"
#include "Wait.h"
#include "Tutorial.h"
#include "HighScore.h"
#include "End.h"
#include "Name.h"
SCENE g_Scene = SCENE_TITLE;
SCENE g_NextScene = SCENE_TITLE;
//SCENE g_Scene = SCENE_TUTORIAL;
//SCENE g_NextScene = SCENE_TUTORIAL;
//SCENE g_Scene = SCENE_S1;
//SCENE g_NextScene = SCENE_S1;
//SCENE g_Scene = SCENE_S2;
//SCENE g_NextScene = SCENE_S2;
//SCENE g_Scene = SCENE_S3;
//SCENE g_NextScene = SCENE_S3;
//SCENE g_Scene = SCENE_CLEAR;
//SCENE g_NextScene = SCENE_CLEAR;
//SCENE g_Scene = SCENE_RESET;
//SCENE g_NextScene = SCENE_RESET;
//SCENE g_Scene = SCENE_HIGHSCORE;
//SCENE g_NextScene = SCENE_HIGHSCORE;
//static bool SceneIschange = false;
//static bool SceneIsfade = false;
void tag_Scene::Init(void)
{
	switch (g_NextScene)
	{
	case SCENE_TITLE:
		TITLE.Init();
		break;
	case SCENE_TUTORIAL:
		TUTORIAL.Init();
		break;
	case SCENE_S1:
		Game.Init(SCENE_S1);
		break;
	case SCENE_S2:
		Game.Init(SCENE_S2);
		break;
	case SCENE_S3:
		Game.Init(SCENE_S3);
		break;
	case SCENE_S1_WAIT:
		Wait.Init();
		break;
	case SCENE_S2_WAIT:
		Wait.Init();
		break;
	case SCENE_S3_WAIT:
		Wait.Init();
		break;
	case SCENE_CLEAR:
		End.Init();
		break;
	case SCENE_NAME:
		Name.Init();
		break;
	case SCENE_HIGHSCORE:
		HighScore.Init();
		break;
	case SCENE_MAX:
		break;
	default:
		break;
	}
	
}

void tag_Scene::Update(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		TITLE.Update();
		break;
	case SCENE_TUTORIAL:
		TUTORIAL.Update();
		break;
	case SCENE_S1:
		Game.Update(SCENE_S1);
		break;
	case SCENE_S2:
		Game.Update(SCENE_S2);
		break;
	case SCENE_S3:
		Game.Update(SCENE_S3);
		break;
	case SCENE_S1_WAIT:
		Wait.Update(SCENE_S1);
		break;
	case SCENE_S2_WAIT:
		Wait.Update(SCENE_S2);
		break;
	case SCENE_S3_WAIT:
		Wait.Update(SCENE_S3);
		break;
	case SCENE_CLEAR:
		End.Update();
		break;
	case SCENE_NAME:
		Name.Update();
		break;

	case SCENE_HIGHSCORE:
		HighScore.Update();
		break;
	case SCENE_MAX:
		break;
	default:
		break;
	}
	if (Ischange)
	{
			Ischange = false;
			Uninit();
			Init();
			g_Scene = g_NextScene;

	}
}

void tag_Scene::Draw(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		TITLE.Draw();
		break;
	case SCENE_TUTORIAL:
		TUTORIAL.Draw();
		break;
	case SCENE_S1:
		Game.Draw(SCENE_S1);
		break;
	case SCENE_S2:
		Game.Draw(SCENE_S2);
		break;
	case SCENE_S3:
		Game.Draw(SCENE_S3);
		break;
	case SCENE_CLEAR:
		End.Draw();
		break;
	case SCENE_NAME:
		Name.Draw();
		break;
	case SCENE_HIGHSCORE:
		HighScore.Draw();
		break;
	case SCENE_MAX:
		break;
	default:
		break;
	}
}

void tag_Scene::Uninit(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		TITLE.Uninit();
		break;
	case SCENE_TUTORIAL:
		TUTORIAL.Uninit();
		break;
	case SCENE_S1:
		Game.Uninit();
		break;
	case SCENE_S2:
		Game.Uninit();
		break;
	case SCENE_S3:
		Game.Uninit();
		break;
	case SCENE_CLEAR:
		End.Uninit();
		break;
	case SCENE_NAME:
		Name.Uninit();
		break;

	case SCENE_MAX:
		break;
	default:
		break;
	}
}

void tag_Scene::SetNextScene(SCENE nextscene)
{
	g_NextScene = nextscene;
}

bool tag_Scene::Change(void)
{
	if (g_Scene != g_NextScene && !Ischange)
	{
		if (g_NextScene == SCENE_END)
		{
			return true;
		}
		Ischange = true;
		Uninit();
		Init();
		g_Scene = g_NextScene;
	}
	return false;
}


bool tag_Scene::Stage_Type(SCENE Type)
{
	if (g_Scene == Type)
	{
		return true;
	}
	else
	{
		return false;
	}
}

