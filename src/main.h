#ifndef MAIN_H
#define MAIN_H

#include <GL/glut.h>

/* Constantes diversas */
#define WIN_HEIGHT          480     /* Define a altura da janela */
#define WIN_WIDTH           640     /* Define a largura da janela */

/* Constantes para posicionar a camera */
#define DIR_CIMA_BAIXO      1
#define DIR_FRENTE_TRAS     0
#define FATOR_PASSO_CAMERA  0.4     /* Define a velocidade com que a camera ira andar - valor padrao = 0.4 */
#define FATOR_ROTAC_CAMERA  0.04    /* Define a velocidade com que a camera ira girar - valor padrao = 0.04 */
#define LIMITE_DE_POS_X     70      /* Define o limite de posicao X */
#define LIMITE_DE_POS_Y     20      /* Define o limite de posicao Y - altura da cena */
#define LIMITE_DE_POS_Z     70      /* Define o limite de posicao Z */

/* Constantes para para animacao de objetos na cena */
#define CAM_X_INIT          00.0f   /* Posicao X inicial da camera */
#define CAM_Y_INIT          13.0f   /* Posicao Y inicial da camera */
#define CAM_Z_INIT          67.0f   /* Posicao Z inicial da camera */
#define FATOR_ANIMA_OBJ     0.2f    /* Define a velocidade de animacao linear dos objetos - valor padrao = 0.2 */
#define FATOR_ROTAC_OBJ     0.05f   /* Define a velocidade de rotacao dos objetos - valor padrao = 0.05 */

/* Constantes para desenhos de telas */
#define TELA_MENU           0
#define TELA_CENA           1
#define TELA_OPCOES         2

/* Protótipo das funções */
void busca_diretorio_base();
void callback_desenha();
void callback_mouse(int botao, int estado_botao_mouse, int x_mouse,
                    int y_mouse);
void callback_redimensiona_janela(int w, int h);
void callback_teclado(unsigned char tecla, int x_mouse, int y_mouse);
void callback_teclas_especiais(int key, int x_mouse, int y_mouse);
void camera_atualiza_luz();
void camera_atualiza();
void camera_movimenta(GLdouble sentido, int direcao);
void camera_rotaciona(GLdouble sentido);
void configura_luzes();
void gerencia_musica(char *diretorio, int tela_atual, double cam_x,
                     double cam_y, double cam_z);
void inicializa_aplicacao();
void mapear2d_para3d(int x, int y, GLdouble *x1, GLdouble *y1, GLdouble *z1);
void reinicializa_variaveis();
void teclado_cena(unsigned char tecla);
void teclado_menu(unsigned char tecla);
void teclado_opcoes();
void verifica_menu_selecionado(int x_mouse, int y_mouse);

#endif /* MAIN_H */
