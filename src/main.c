/* Trabalho de Computação Gráfica
 *
 * Data: 2010-06-29
 * Autor: Cristiano Nunes <cfgnunes@gmail.com>
 */

/* Importacoes necessarias */
#include "main.h"
#include "draw.h"
#include "music.h"

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Diretórios da aplicação */
char dir_base_arquivos[40] = {0};
char *const ARQUIVO_FLAG = "/paquito.txt";
char *const DIR_BASE_ARQUIVOS = "/resource";

/* Constantes dos nomes dos arquivos de música */
char *const MUSICA_PRINCIPAL = "copa.mp3";
char *const MUSICA_BAR = "bebo.mp3";
char *const MUSICA_MENU = "menu.mp3";

/* Variaveis globais diversas */
double angulo_global = 0.0;
GLdouble cam_x = CAM_X_INIT, cam_y = CAM_Y_INIT, cam_z = CAM_Z_INIT;
GLfloat intensidade_luz_camera = 0.1f;
GLfloat rotacao_global = 0.0f;
GLfloat translacao_global = 0.0f;
int tela_atual_global = TELA_MENU;

void busca_diretorio_base() {
    char dir_base[50] = {0};
    char caminho_arquivo_flag[50] = {0};

    /* Tenta encontrar o diretório base em: */
    /* ./resource/<conteudo> */
    strcpy(dir_base, ".");
    strcat(dir_base, DIR_BASE_ARQUIVOS);
    strcpy(caminho_arquivo_flag, dir_base);
    strcat(caminho_arquivo_flag, ARQUIVO_FLAG);
    if (access(caminho_arquivo_flag, F_OK) != -1) {
        strcpy(dir_base_arquivos, dir_base);
        return;
    }

    /* Tenta encontrar o diretório base em: */
    /* ./<conteudo> */
    strcpy(dir_base, ".");
    strcpy(caminho_arquivo_flag, dir_base);
    strcat(caminho_arquivo_flag, ARQUIVO_FLAG);
    if (access(caminho_arquivo_flag, F_OK) != -1) {
        strcpy(dir_base_arquivos, dir_base);
        return;
    }

    /* Tenta encontrar o diretório base em: */
    /* /usr/local/share/paquito/resource/<conteudo> */
    strcpy(dir_base, "/usr/local/share/paquito");
    strcat(dir_base, DIR_BASE_ARQUIVOS);
    strcpy(caminho_arquivo_flag, dir_base);
    strcat(caminho_arquivo_flag, ARQUIVO_FLAG);
    if (access(caminho_arquivo_flag, F_OK) != -1) {
        strcpy(dir_base_arquivos, dir_base);
        return;
    }

    /* Tenta encontrar o diretório base em: */
    /* ../resource/<conteudo> */
    strcpy(dir_base, "..");
    strcat(dir_base, DIR_BASE_ARQUIVOS);
    strcpy(caminho_arquivo_flag, dir_base);
    strcat(caminho_arquivo_flag, ARQUIVO_FLAG);
    if (access(caminho_arquivo_flag, F_OK) != -1) {
        strcpy(dir_base_arquivos, dir_base);
        return;
    }
}

void gerencia_musica(char *diretorio, int tela_atual, double cam_x,
                     double cam_y, double cam_z) {
    if (tela_atual == TELA_MENU || tela_atual == TELA_OPCOES) {
        toca_musica(diretorio, MUSICA_MENU, 1);
    } else {
        /* Verifica se esta dentro do boteco do paquito */
        if (cam_x >= 40.0 - 6.5 && cam_x <= 40.0 + 6.5 && cam_z >= -6.5 &&
            cam_z <= 6.5 && cam_y > 0.0 && cam_y < 6.0)
            toca_musica(diretorio, MUSICA_BAR, -1);
        else
            toca_musica(diretorio, MUSICA_PRINCIPAL, -1);
    }
}

void configura_luzes() {
    GLfloat luz0_ambiente[4] = {0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat luz0_difusa[4] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat luz0_especular[4] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat luz0_posicao[4] = {0.0f, 40.0f, 0.0f, 1.0f};

    GLfloat luz1_ambiente[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat luz1_difusa[4] = {0.15f, 0.14f, 0.12f, 1.0f};
    GLfloat luz1_especular[4] = {0.12f, 0.13f, 0.11f, 1.0f};
    GLfloat luz1_posicao[4] = {90.0f, 90.0f, -90.0f, 1.0f};

    GLfloat luz2_ambiente[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat luz2_difusa[4] = {0.15f, 0.14f, 0.13f, 1.0f};
    GLfloat luz2_especular[4] = {0.13f, 0.15f, 0.12f, 1.0f};
    GLfloat luz2_posicao[4] = {-90.0f, 90.0f, 90.0f, 1.0f};

    GLfloat luz3_difusa[4] = {0.1f, 0.1f, 0.1f, 1.0f};

    /* Define os parametros de LIGHT0 */
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz0_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz0_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz0_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz0_posicao);

    /* Define os parametros de LIGHT1 */
    glLightfv(GL_LIGHT1, GL_AMBIENT, luz1_ambiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luz1_difusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luz1_especular);
    glLightfv(GL_LIGHT1, GL_POSITION, luz1_posicao);

    /* Define os parametros de LIGHT2 */
    glLightfv(GL_LIGHT2, GL_AMBIENT, luz2_ambiente);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, luz2_difusa);
    glLightfv(GL_LIGHT2, GL_SPECULAR, luz2_especular);
    glLightfv(GL_LIGHT2, GL_POSITION, luz2_posicao);

    /* Define os parametros de LIGHT3 - luz que acompanha a camera */
    glLightfv(GL_LIGHT3, GL_DIFFUSE, luz3_difusa);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz0_ambiente);
    glEnable(GL_LIGHTING); /* Habilita iluminacao */
    glEnable(GL_LIGHT0);   /* Habilita LIGHT0 */
    glEnable(GL_LIGHT1);   /* Habilita LIGHT1 */
    glEnable(GL_LIGHT2);   /* Habilita LIGHT2 */
}

void camera_atualiza_luz() {
    /* Luz que acompanha a camera */
    GLfloat luz3_posicao[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat luz3_difusa[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    luz3_posicao[0] = (GLfloat)cam_x;
    luz3_posicao[1] = (GLfloat)cam_y;
    luz3_posicao[2] = (GLfloat)cam_z;
    luz3_difusa[0] = intensidade_luz_camera;
    luz3_difusa[1] = intensidade_luz_camera;
    luz3_difusa[2] = intensidade_luz_camera;

    glLightfv(GL_LIGHT3, GL_DIFFUSE, luz3_difusa);
    glLightfv(GL_LIGHT3, GL_POSITION, luz3_posicao);
}

void camera_atualiza() {
    /* printf("\nCoordenadas 3D da camera: x=%.2f; y=%.2f; z=%.2f;
     * angulo=%.2f;", x, y, z, angulo); */
    GLdouble lx, ly = 0.0, lz;
    lx = sin(angulo_global);
    lz = -cos(angulo_global);
    glLoadIdentity();
    gluLookAt(cam_x, cam_y, cam_z, cam_x + lx, cam_y + ly, cam_z + lz, 0.0, 1.0,
              0.0);
}

void camera_rotaciona(GLdouble sentido) {
    angulo_global += FATOR_ROTAC_CAMERA * sentido;
    camera_atualiza();
}

void camera_movimenta(GLdouble sentido, int direcao) {
    if (direcao == DIR_FRENTE_TRAS) {
        GLdouble lx, lz;
        GLdouble x_mov, z_mov;
        lx = sin(angulo_global);
        lz = -cos(angulo_global);
        /* Estipula limites de area para a camera */
        z_mov = sentido * (lz)*FATOR_PASSO_CAMERA;
        x_mov = sentido * (lx)*FATOR_PASSO_CAMERA;
        if (cam_z > -LIMITE_DE_POS_Z - z_mov && cam_z < LIMITE_DE_POS_Z - z_mov)
            cam_z += z_mov;
        if (cam_x > -LIMITE_DE_POS_X - x_mov && cam_x < LIMITE_DE_POS_X - x_mov)
            cam_x += x_mov;
    } else {
        /* Estipula limites para a camera subir ou descer */
        if ((sentido < 0 && cam_y > 1) ||
            (sentido > 0 && cam_y < LIMITE_DE_POS_Y))
            cam_y += sentido * FATOR_PASSO_CAMERA;
    }
    camera_atualiza();
    camera_atualiza_luz();
}

void reinicializa_variaveis() {
    /* Reinicializa as variaveis globais do programa */
    angulo_global = 0.0;
    cam_x = CAM_X_INIT;
    cam_y = CAM_Y_INIT;
    cam_z = CAM_Z_INIT;
    intensidade_luz_camera = 0.1f;
    glDisable(GL_LIGHT3);
    camera_atualiza();
}

void inicializa_aplicacao() {
    busca_diretorio_base();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    configura_luzes();

    /* Habilita efeito de suavizacao */
    glShadeModel(GL_SMOOTH);

    /* Configuracao do efeito de profundidade */
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    /* Correcao de perpectiva (mais lento e mais real) */
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_COLOR_MATERIAL);

    /* Habilita transparência - canal alpha */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* Carrega as texturas e inicializa as variaveis globais */
    inicializa_texturas(dir_base_arquivos);
    reinicializa_variaveis();

    /* Posiciona a camera para exebicao do menu */
    cam_x = 0.0;
    cam_y = 2.0;
    cam_z = 30.0;
    angulo_global = 0.0;
    camera_atualiza();
}

void callback_teclas_especiais(int key, int x_mouse, int y_mouse) {
    (void)x_mouse;
    (void)y_mouse;

    if (tela_atual_global == TELA_CENA) {
        switch (key) {
        case GLUT_KEY_UP: /* Sobe a camera */
            camera_movimenta(1.0f, DIR_CIMA_BAIXO);
            break;
        case GLUT_KEY_DOWN: /* Desce a camera */
            camera_movimenta(-1.0f, DIR_CIMA_BAIXO);
            break;
        default:
            break;
        }
    }
}

void mapear2d_para3d(int x, int y, GLdouble *x1, GLdouble *y1, GLdouble *z1) {
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLdouble pos_x, pos_y, pos_z;
    GLfloat win_x, win_y, win_z;

    /* Recebe as respectivas matrizes para o calculo */
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    /* Converte a projecao em 3D relativo ao mapeamento 2D */
    win_x = (GLfloat)x;
    win_y = (GLfloat)viewport[3] - (GLfloat)y;
    glReadPixels(x, (int)win_y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &win_z);

    gluUnProject(win_x, win_y, win_z, modelview, projection, viewport, &pos_x,
                 &pos_y, &pos_z);

    /* Retorna coordenada 3D nos respectivos ponteiros */
    *x1 = pos_x;
    *y1 = pos_y;
    *z1 = pos_z;
}

void verifica_menu_selecionado(int x_mouse, int y_mouse) {
    GLdouble x3d_mouse, y3d_mouse, z3d_mouse;
    mapear2d_para3d(x_mouse, y_mouse, &x3d_mouse, &y3d_mouse, &z3d_mouse);

    /* printf("\nCoordenadas 3D do mouse: %.2f %.2f %.2f", x3d_mouse, y3d_mouse,
     * z3d_mouse); */

    /* Verifica se foi clicado em Iniciar */
    if (x3d_mouse >= -22.0 && x3d_mouse <= -16.0 && y3d_mouse >= 3.0 &&
        y3d_mouse <= 9.0) {
        reinicializa_variaveis();
        tela_atual_global = TELA_CENA;
    }
    /* Verifica se foi clicado em Opcoes */
    else if (x3d_mouse >= -22.0 && x3d_mouse <= -16.0 && y3d_mouse >= -5.0 &&
             y3d_mouse <= 1.0) {
        tela_atual_global = TELA_OPCOES;
    }
    /* Verifica se foi clicado em Sair */
    else if (x3d_mouse >= -22.0 && x3d_mouse <= -16.0 && y3d_mouse >= -13.0 &&
             y3d_mouse <= -7.0) {
        exit(EXIT_SUCCESS);
    }
}

/* Funcao callback chamada para gerenciar eventos do mouse */
void callback_mouse(int botao, int estado_botao_mouse, int x_mouse,
                    int y_mouse) {
    if (tela_atual_global == TELA_MENU && botao == GLUT_LEFT_BUTTON &&
        estado_botao_mouse == GLUT_DOWN)
        verifica_menu_selecionado(x_mouse, y_mouse);
}

void callback_desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gerencia_musica(dir_base_arquivos, tela_atual_global, cam_x, cam_y, cam_z);
    switch (tela_atual_global) {
    case TELA_MENU:
        desenha_tela_menu(rotacao_global);
        break;
    case TELA_CENA:
        desenha_tela_cena(rotacao_global, translacao_global);
        break;
    case TELA_OPCOES:
        desenha_tela_opcoes(rotacao_global);
        break;
    default:
        break;
    }

    /* Incrementa o angulo para a rotacao de objetos na cena */
    rotacao_global += FATOR_ROTAC_OBJ;
    if (rotacao_global >= 360)
        rotacao_global = 0;

    /* Incrementa variavel para animacao dos carros */
    translacao_global += FATOR_ANIMA_OBJ;
    if (translacao_global >= 1000)
        translacao_global = 0;

    glutSwapBuffers();
}

/* Operacoes de teclas normais para o menu */
void teclado_menu(unsigned char tecla) {
    tecla = (unsigned char)tolower(tecla);
    switch (tecla) {
    case 27: /* ESC - finaliza a aplicacao */
        exit(0);
    case 13: /* ENTER - inicia */
        reinicializa_variaveis();
        tela_atual_global = TELA_CENA;
        break;
    default:
        break;
    }
}

/* Operacoes de teclas normais para o menu de opcoes */
void teclado_opcoes() {
    /* Retorna ao menu principal ao pressionar qualquer tecla */
    tela_atual_global = TELA_MENU;
}

/* Operacoes de teclas normais para o cenario */
void teclado_cena(unsigned char tecla) {
    tecla = (unsigned char)tolower(tecla);
    switch (tecla) {
    case 27:  /* ESC */
    case 'q': /* Retorna ao menu */
        reinicializa_variaveis();
        cam_x = 0.0;
        cam_y = 2.0;
        cam_z = 30.0;
        angulo_global = 0.0;
        camera_atualiza();
        tela_atual_global = TELA_MENU;
        break;
    case 'w': /* Move a camera para frente */
        camera_movimenta(1.0, DIR_FRENTE_TRAS);
        break;
    case 's': /* Move a camera para tras */
        camera_movimenta(-1.0, DIR_FRENTE_TRAS);
        break;
    case 'a': /* Gira a camera para esquerda */
        camera_rotaciona(-1.0);
        break;
    case 'd': /* Gira a camera para direita */
        camera_rotaciona(1.0);
        break;
    case 'r': /* Retorna ao estado inicial */
        reinicializa_variaveis();
        break;
    case 'o': /* Liga a fonte de luz que acompanha a camera */
        glEnable(GL_LIGHT3);
        break;
    case 'p': /* Desliga a fonte de luz que acompanha a camera */
        glDisable(GL_LIGHT3);
        break;
    case '+': /* Aumenta a intensidade da luz da camera */
        if (intensidade_luz_camera < 0.2f)
            intensidade_luz_camera += 0.01f;
        camera_atualiza_luz();
        break;
    case '-': /* Diminui a intensidade da luz da camera */
        if (intensidade_luz_camera > -0.1f)
            intensidade_luz_camera -= 0.01f;
        camera_atualiza_luz();
        break;
    case '1': /* Posicao de camera 1 - Visao geral */
        cam_x = 0.0;
        cam_y = 13.0;
        cam_z = 67.0;
        angulo_global = 0.0;
        camera_atualiza();
        break;
    case '2': /* Posicao de camera 2 - Campo de Futebol */
        cam_x = 0.00;
        cam_y = 2.30;
        cam_z = 2.00;
        angulo_global = 0.00;
        camera_atualiza();
        break;
    case '3': /* Posicao de camera 3 - Boteco do paquito */
        cam_x = 40.00;
        cam_y = 1.80;
        cam_z = 6.10;
        angulo_global = 0.00;
        camera_atualiza();
        break;
    case '4': /* Posicao de camera 4 - Casa Popular */
        cam_x = -55.63;
        cam_y = 1.90;
        cam_z = 0.71;
        angulo_global = 3.80;
        camera_atualiza();
        break;
    case '5': /* Posicao de camera 5 - Quadra de basquete */
        cam_x = -27.13;
        cam_y = 7.10;
        cam_z = -22.41;
        angulo_global = -0.84;
        camera_atualiza();
        break;
    case '6': /* Posicao de camera 6 - Totem da copa */
        cam_x = 55.92;
        cam_y = 9.40;
        cam_z = -30.89;
        angulo_global = 4.08;
        camera_atualiza();
        break;
    case '7': /* Posicao de camera 7 - Rodovia/Boteco */
        cam_x = 21.65;
        cam_y = 3.80;
        cam_z = 32.98;
        angulo_global = 0.64;
        camera_atualiza();
        break;
    case '8': /* Posicao de camera 8 - Casas populares */
        cam_x = -51.00;
        cam_y = 11.00;
        cam_z = 54.98;
        angulo_global = 0.00;
        camera_atualiza();
        break;
    case '9': /* Posicao de camera 9 - Area da floresta */
        cam_x = -20.12;
        cam_y = 9.00;
        cam_z = 12.73;
        angulo_global = 0.48;
        camera_atualiza();
        break;
    default:
        break;
    }
}

void callback_teclado(unsigned char tecla, int x_mouse, int y_mouse) {
    (void)x_mouse;
    (void)y_mouse;

    switch (tela_atual_global) {
    case TELA_MENU:
        teclado_menu(tecla);
        break;
    case TELA_CENA:
        teclado_cena(tecla);
        break;
    case TELA_OPCOES:
        teclado_opcoes();
        break;
    default:
        break;
    }
}

void callback_redimensiona_janela(int w, int h) {
    GLfloat taxa;

    /* Evita a divisao por zero. */
    if (h == 0)
        h = 1;

    /* Taxa de aspecto */
    taxa = 1.0f * (GLfloat)w / (GLfloat)h;

    /* Reinicia sistema de coordenadas antes de modifica-lo */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* Configura a viewport para a janela atual */
    glViewport(0, 0, w, h);

    /* Configura o volume de visualizacao */
    gluPerspective(45.0f, taxa, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera_atualiza();
}

int main(int argc, char **argv) {
    inicializa_sdl();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Paquito na Copa");

    inicializa_aplicacao();

    glutSpecialFunc(callback_teclas_especiais);
    glutKeyboardFunc(callback_teclado);
    glutDisplayFunc(callback_desenha);
    glutIdleFunc(callback_desenha);
    glutReshapeFunc(callback_redimensiona_janela);
    glutMouseFunc(callback_mouse);

    glutMainLoop();
    return EXIT_SUCCESS;
}
