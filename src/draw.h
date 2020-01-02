#ifndef DRAW_H
#define DRAW_H

#include <GL/glut.h>

/* Indices dos indentificadores das texturas */
#define TEX_PAQUITO1        0
#define TEX_PAQUITO2        1
#define TEX_CAMISA_PAQUITO  2
#define TEX_ROTULO_GARRAFA  3
#define TEX_CEU             4
#define TEX_GRAMA           5
#define TEX_CAMPO           6
#define TEX_BOLA            7
#define TEX_PROPAGANDAS     8
#define TEX_COPA_LOGO       9
#define TEX_TIJOLO          10
#define TEX_RODOVIA         11
#define TEX_MENU_FUNDO      12
#define TEX_MENU_INICIAR    13
#define TEX_MENU_OPCOES     14
#define TEX_MENU_SAIR       15
#define TEX_PAREDE1         16
#define TEX_PAREDE2         17
#define TEX_TELHADO         18
#define TEX_JANELA          19
#define TEX_PORTA1          20
#define TEX_PORTA2          21
#define TEX_PISO1           22
#define TEX_PISO2           23
#define TEX_QUADRA          24
#define TEX_MADEIRA         25
#define TEX_CHAO            26
#define TEX_AJUDA           27
#define TEX_CARTAZ_BAR      28

/* Protótipo das funções */
double rand_double();
void adiciona_textura(char *diretorio, char *nome_arquivo, int id_textura);
void desenha_arvore();
void desenha_banco(GLfloat tamanho, int id_textura);
void desenha_bola_futebol();
void desenha_boteco_paquito();
void desenha_cadeira(GLfloat tamanho, int id_textura);
void desenha_campo_futebol();
void desenha_carro(GLfloat *cor);
void desenha_casa();
void desenha_cesta_baquete();
void desenha_ceu(GLfloat rotacao);
void desenha_chao_grama();
void desenha_chao_terra();
void desenha_conjuntocasa();
void desenha_copo(GLfloat tamanho);
void desenha_fila_carros(GLfloat translacao);
void desenha_floresta();
void desenha_fundo_menu(GLfloat rotacao);
void desenha_garrafa_nortena(GLfloat tamanho);
void desenha_mesa(GLfloat tamanho, int id_textura);
void desenha_paralelepipedo_textura(GLfloat tam_x, GLfloat tam_y, GLfloat tam_z,
                                    int id_textura);
void desenha_poster_paquito();
void desenha_quadra_basquete();
void desenha_rodovia();
void desenha_tela_cena(GLfloat rotacao, GLfloat translacao);
void desenha_tela_menu(GLfloat rotacao);
void desenha_tela_opcoes(GLfloat rotacao);
void desenha_totem(GLfloat rotacao);
void desenha_vaso(GLfloat tamanho, int id_textura);
void inicializa_texturas(char *diretorio);

#endif /* DRAW_H */
