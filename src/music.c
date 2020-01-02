#include "music.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/* Diretórios que contém as músicas */
char *const DIR_MUSICAS = "/musicas/";

/* Variaveis globais para musicas */
char musica_atual[20] = {0};

void inicializa_sdl() {
    /* Inicializa SDL */
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Erro ao inicializar o SDL.\n");
        exit(EXIT_FAILURE);
    }
}

void toca_musica(char *diretorio, char *nome_arquivo, int repeticoes) {
    char caminho_arquivo[100] = {0};

    strcat(caminho_arquivo, diretorio);
    strcat(caminho_arquivo, DIR_MUSICAS);
    strcat(caminho_arquivo, nome_arquivo);

    /* Toca outra musica se a musica atual for diferente da musica a ser tocada */
    if (strcmp(nome_arquivo, musica_atual) != 0) {
        Mix_OpenAudio(32000, AUDIO_S16, 2, 4096);
        Mix_PlayMusic(Mix_LoadMUS(caminho_arquivo), repeticoes);
        Mix_VolumeMusic(MIX_MAX_VOLUME);
        strcpy(musica_atual, nome_arquivo);
    }
}
