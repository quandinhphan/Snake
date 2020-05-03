#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

void Gameplay(SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Rect SourceRect1, SDL_Rect desRect1);

void Menurunning(SDL_Renderer* renderer, SDL_Texture* texture2, SDL_Rect SourceRect2, SDL_Rect desRect2);

#endif // GAME_H
