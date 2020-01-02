#include "draw.h"

#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <string.h>

/* Diretórios que contém as texturas */
char *const DIR_TEXTURAS = "/texturas/";

/* Vetor que armazenará os identificadores da textura */
GLuint texturas[30];

void adiciona_textura(char *diretorio, char *nome_arquivo, int id_textura) {
    char caminho_arquivo[100] = {0};

    strcat(caminho_arquivo, diretorio);
    strcat(caminho_arquivo, DIR_TEXTURAS);
    strcat(caminho_arquivo, nome_arquivo);

    texturas[id_textura] = SOIL_load_OGL_texture(
        caminho_arquivo, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y |
            SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

void inicializa_texturas(char *diretorio) {

    /* Define os identificadores para textura */
    adiciona_textura(diretorio, "paquito1.jpg", TEX_PAQUITO1);
    adiciona_textura(diretorio, "paquito2.jpg", TEX_PAQUITO2);
    adiciona_textura(diretorio, "camisa_paquito.jpg", TEX_CAMISA_PAQUITO);
    adiciona_textura(diretorio, "rotulo_nortena.jpg", TEX_ROTULO_GARRAFA);
    adiciona_textura(diretorio, "nuvens_ceu.jpg", TEX_CEU);
    adiciona_textura(diretorio, "grama.jpg", TEX_GRAMA);
    adiciona_textura(diretorio, "campo.jpg", TEX_CAMPO);
    adiciona_textura(diretorio, "bola.jpg", TEX_BOLA);
    adiciona_textura(diretorio, "propagandas.jpg", TEX_PROPAGANDAS);
    adiciona_textura(diretorio, "copa_logo.jpg", TEX_COPA_LOGO);
    adiciona_textura(diretorio, "tijolos.jpg", TEX_TIJOLO);
    adiciona_textura(diretorio, "rodovia.jpg", TEX_RODOVIA);
    adiciona_textura(diretorio, "menu_fundo.jpg", TEX_MENU_FUNDO);
    adiciona_textura(diretorio, "menu_iniciar.jpg", TEX_MENU_INICIAR);
    adiciona_textura(diretorio, "menu_opcoes.jpg", TEX_MENU_OPCOES);
    adiciona_textura(diretorio, "menu_sair.jpg", TEX_MENU_SAIR);
    adiciona_textura(diretorio, "tijolos.jpg", TEX_TIJOLO);
    adiciona_textura(diretorio, "parede1.jpg", TEX_PAREDE1);
    adiciona_textura(diretorio, "parede2.jpg", TEX_PAREDE2);
    adiciona_textura(diretorio, "telhado.jpg", TEX_TELHADO);
    adiciona_textura(diretorio, "janelamadeira.jpg", TEX_JANELA);
    adiciona_textura(diretorio, "porta1.jpg", TEX_PORTA1);
    adiciona_textura(diretorio, "porta2.jpg", TEX_PORTA2);
    adiciona_textura(diretorio, "piso1.jpg", TEX_PISO1);
    adiciona_textura(diretorio, "piso2.jpg", TEX_PISO2);
    adiciona_textura(diretorio, "quadra.jpg", TEX_QUADRA);
    adiciona_textura(diretorio, "madeira.jpg", TEX_MADEIRA);
    adiciona_textura(diretorio, "chao.jpg", TEX_CHAO);
    adiciona_textura(diretorio, "ajuda.jpg", TEX_AJUDA);
    adiciona_textura(diretorio, "cartaz_bar.jpg", TEX_CARTAZ_BAR);
}

void desenha_chao_grama() {
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_GRAMA]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-160.0f, 0.0f, -160.0f);
    glTexCoord2f(0.0f, 20.0f);
    glVertex3f(-160.0f, 0.0f, 160.0f);
    glTexCoord2f(20.0f, 20.0f);
    glVertex3f(160.0f, 0.0f, 160.0f);
    glTexCoord2f(20.0f, 0.0f);
    glVertex3f(160.0f, 0.0f, -160.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void desenha_chao_terra() {
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_CHAO]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-160.0f, 0.0f, -160.0f);
    glTexCoord2f(0.0f, 15.0f);
    glVertex3f(-160.0f, 0.0f, 20.0f);
    glTexCoord2f(15.0f, 15.0f);
    glVertex3f(-35.0f, 0.0f, 20.0f);
    glTexCoord2f(15.0f, 0.0f);
    glVertex3f(-35.0f, 0.0f, -160.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void desenha_ceu(GLfloat rotacao) {
    GLUquadric *quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_CEU]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glRotatef(90, 1, 0, 0);
    glRotatef(rotacao, 0, 0, 1);
    gluSphere(quad, 150, 200, 200);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_fundo_menu(GLfloat rotacao) {
    GLUquadric *quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_MENU_FUNDO]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(-rotacao * 2, 0, 0, 1);
    gluSphere(quad, 50, 200, 200);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_paralelepipedo_textura(GLfloat tam_x, GLfloat tam_y, GLfloat tam_z,
                                    int id_textura) {
    glTranslatef(0.0f, tam_y, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[id_textura]);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tam_x, -tam_y, tam_z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tam_x, -tam_y, tam_z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tam_x, tam_y, tam_z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tam_x, tam_y, tam_z);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-tam_x, -tam_y, -tam_z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-tam_x, tam_y, -tam_z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(tam_x, tam_y, -tam_z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(tam_x, -tam_y, -tam_z);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tam_x, tam_y, -tam_z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tam_x, tam_y, tam_z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tam_x, tam_y, tam_z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tam_x, tam_y, -tam_z);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-tam_x, -tam_y, -tam_z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(tam_x, -tam_y, -tam_z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(tam_x, -tam_y, tam_z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-tam_x, -tam_y, tam_z);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tam_x, -tam_y, -tam_z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tam_x, tam_y, -tam_z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(tam_x, tam_y, tam_z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(tam_x, -tam_y, tam_z);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tam_x, -tam_y, -tam_z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-tam_x, -tam_y, tam_z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-tam_x, tam_y, tam_z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tam_x, tam_y, -tam_z);
    glEnd();
}

void desenha_vaso(GLfloat tamanho, int id_textura) {
    GLUquadric *quad = gluNewQuadric();

    glScalef(tamanho, tamanho, tamanho);
    glEnable(GL_TEXTURE_2D);
    glColor4f(0.5f, 0.5f, 0.5f, 0.8f);
    glBindTexture(GL_TEXTURE_2D, texturas[id_textura]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glRotatef(-90, 1, 0, 0);

    /* Parte de baixo */
    glPushMatrix();
    glTranslatef(0, 0, 0);
    gluCylinder(quad, 2, 3.6f, 2.5f, 20, 1);
    glPopMatrix();

    /* Parte do meio */
    glPushMatrix();
    glTranslatef(0, 0, 2.5f);
    gluCylinder(quad, 3.6f, 1.4f, 2.5f, 20, 1);
    glPopMatrix();

    /* Aro do meio */
    glPushMatrix();
    glTranslatef(0, 0, 2.5f);
    glutSolidTorus(0.3f, 3.27f, 40, 20);
    glPopMatrix();

    /* Parte de cima */
    glPushMatrix();
    glTranslatef(0, 0, 5.0f);
    gluCylinder(quad, 1.4f, 1.8f, 1.6f, 20, 1);
    glPopMatrix();

    /* Aro de cima */
    glPushMatrix();
    glTranslatef(0, 0, 6.5f);
    glutSolidTorus(0.3f, 1.8f, 40, 20);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_copo(GLfloat tamanho) {
    GLUquadric *quad = gluNewQuadric();

    glScalef(tamanho, tamanho, tamanho);
    glColor4f(0.0f, 0.2f, 0.5f, 0.5f);

    /* Desenha copo */
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, 0, 0);
    gluCylinder(quad, 2, 2.5f, 5.5f, 20, 1);
    glPopMatrix();
}

void desenha_mesa(GLfloat tamanho, int id_textura) {
    glScalef(tamanho, tamanho, tamanho);
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.5f, 0.5f, 0.5f);

    /* Tampa da mesa */
    glPushMatrix();
    glTranslatef(0.0f, 4.0f, 0.0f);
    desenha_paralelepipedo_textura(4.3f, 0.4f, 2.8f, id_textura);
    glPopMatrix();

    /* Perna direita frente */
    glPushMatrix();
    glTranslatef(3.5f, 0.0f, 2.0f);
    desenha_paralelepipedo_textura(0.3f, 2.0f, 0.3f, id_textura);
    glPopMatrix();

    /* Perna direita tras */
    glPushMatrix();
    glTranslatef(3.5f, 0.0f, -2.0f);
    desenha_paralelepipedo_textura(0.3f, 2.0f, 0.3f, id_textura);
    glPopMatrix();

    /* Perna esquerda frente */
    glPushMatrix();
    glTranslatef(-3.5f, 0.0f, 2.0f);
    desenha_paralelepipedo_textura(0.3f, 2.0f, 0.3f, id_textura);
    glPopMatrix();

    /* Perna esquerda tras */
    glPushMatrix();
    glTranslatef(-3.5f, 0.0f, -2.0f);
    desenha_paralelepipedo_textura(0.3f, 2.0f, 0.3f, id_textura);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_cadeira(GLfloat tamanho, int id_textura) {
    glScalef(tamanho, tamanho, tamanho);
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.5f, 0.5f, 0.5f);

    /* Perna direita frente */
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.7f);
    desenha_paralelepipedo_textura(0.2f, 1.0f, 0.2f, id_textura);
    glPopMatrix();

    /* Perna direita tras */
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, -0.7f);
    desenha_paralelepipedo_textura(0.2f, 2.1f, 0.2f, id_textura);
    glPopMatrix();

    /* Perna que liga direita */
    glPushMatrix();
    glTranslatef(1.0f, 1.6f, 0.0f);
    desenha_paralelepipedo_textura(0.2f, 0.2f, 0.7f, id_textura);
    glPopMatrix();

    /* Perna esquerda frente */
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.7f);
    desenha_paralelepipedo_textura(0.2f, 1.0f, 0.2f, id_textura);
    glPopMatrix();

    /* Perna esquerda tras */
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, -0.7f);
    desenha_paralelepipedo_textura(0.2f, 2.1f, 0.2f, id_textura);
    glPopMatrix();

    /* Perna que liga esquerda */
    glPushMatrix();
    glTranslatef(-1.0f, 1.6f, 0.0f);
    desenha_paralelepipedo_textura(0.2f, 0.2f, 0.7f, id_textura);
    glPopMatrix();

    /* Assento da cadeira */
    glPushMatrix();
    glTranslatef(0.0f, 1.85f, 0.0f);
    desenha_paralelepipedo_textura(1.2f, 0.1f, 0.9f, id_textura);
    glPopMatrix();

    /* Encosto da cadeira */
    glPushMatrix();
    glTranslatef(0.0f, 2.7f, -0.8f);
    desenha_paralelepipedo_textura(0.8f, 0.7f, 0.05f, id_textura);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_banco(GLfloat tamanho, int id_textura) {
    GLUquadric *quad = gluNewQuadric();

    glScalef(tamanho, tamanho, tamanho);
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.5f, 0.5f, 0.5f);
    glBindTexture(GL_TEXTURE_2D, texturas[id_textura]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0.0f, 0.0f, 1.0f);

    /* Perna direita frente */
    glPushMatrix();
    glTranslatef(0.7f, -0.7f, 0.0f);
    glRotatef(-10, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 2, 20, 1);
    glPopMatrix();

    /* Perna direita tras */
    glPushMatrix();
    glTranslatef(0.7f, 0.7f, 0.0f);
    glRotatef(-10, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 2, 20, 1);
    glPopMatrix();

    /* Perna que liga direita */
    glPushMatrix();
    glTranslatef(0.53f, 0.6f, 0.9f);
    glRotatef(90, 1, 0, 0);
    gluCylinder(quad, 0.1f, 0.1f, 1.35f, 20, 1);
    glPopMatrix();

    /* Perna esquerda frente */
    glPushMatrix();
    glTranslatef(-0.7f, -0.7f, 0.0f);
    glRotatef(10, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 2, 20, 1);
    glPopMatrix();

    /* Perna esquerda tras */
    glPushMatrix();
    glTranslatef(-0.7f, 0.7f, 0.0f);
    glRotatef(10, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 2, 20, 1);
    glPopMatrix();

    /* Perna que liga esquerda */
    glPushMatrix();
    glTranslatef(-0.56f, 0.6f, 0.9f);
    glRotatef(90, 1, 0, 0);
    gluCylinder(quad, 0.1f, 0.1f, 1.30f, 20, 1);
    glPopMatrix();

    /* Perna que liga frente */
    glPushMatrix();
    glTranslatef(-0.66f, -0.64f, 0.9f);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 1.30f, 20, 1);
    glPopMatrix();

    /* Perna que liga a parte de tras */
    glPushMatrix();
    glTranslatef(-0.66f, 0.64f, 0.9f);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 1.30f, 20, 1);
    glPopMatrix();

    /* Assento do banco */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 1.8f);
    gluCylinder(quad, 0.9f, 0.9f, 0.3f, 20, 1);
    glTranslatef(0.0f, 0.0f, 0.3f);
    gluDisk(quad, 0.0f, 0.9f, 20, 1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_bola_futebol() {
    GLUquadric *quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_BOLA]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glTranslatef(0, 0.4f, 0);
    glRotatef(90, 0, 1.0f, 0);
    glRotatef(90, 0.1f, 0, 0);
    gluSphere(quad, 0.4f, 200, 200);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_cesta_baquete() {
    GLUquadric *quad = gluNewQuadric();

    /* Bandeja */
    glColor4f(0.5f, 0.5f, 0.5f, 0.8f);

    glPushMatrix();
    glScalef(0.9f, 0.9f, 0.9f);
    glTranslatef(0.0f, 8.5f, 2.7f);

    glBegin(GL_QUADS);
    glVertex3f(-1.9f, -1.9f, 0.0f);
    glVertex3f(-1.9f, 1.9f, 0.0f);
    glVertex3f(1.9f, 1.9f, 0.0f);
    glVertex3f(1.9f, -1.9f, 0.0f);
    glEnd();

    glPopMatrix();

    /* Base */
    glPushMatrix();
    glColor4f(0.5f, 0.5f, 0.5f, 1.0f);

    glBegin(GL_QUADS);
    glVertex3f(-1.5f, 0.11f, -1.5f);
    glVertex3f(1.5f, 0.11f, -1.5f);
    glVertex3f(1.5f, 0.11f, 1.5f);
    glVertex3f(-1.5f, 0.11f, 1.5f);
    glEnd();

    /* Astes */
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quad, 0.2f, 0.2f, 8.0f, 5, 1);
    glTranslatef(0.0f, 0.1f, 7.9f);
    glRotatef(90, 1, 0, 0);
    gluCylinder(quad, 0.2f, 0.2f, 2.5f, 5, 1);
    glPopMatrix();

    /* Cesta */
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0.0f, -3.45f, 7.2f);
    glutSolidTorus(0.1f, 0.9f, 40, 20);
    glPopMatrix();
}

void desenha_quadra_basquete() {
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.8f, 0.8f, 0.8f);

    /* Desenha Quadra */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_QUADRA]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.15f, -15.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 0.15f, 15.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(20.0f, 0.15f, 15.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(20.0f, 0.15f, -15.0f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);

    /* Mini arquibancada esquerda */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 20.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);

    /* Arquibanca de baixo */
    desenha_paralelepipedo_textura(20.0f, 0.5f, 2.0f, TEX_MADEIRA);
    glTranslatef(0.0f, 0.5f, -1.0f);

    /* Arquibanca de cima */
    desenha_paralelepipedo_textura(20.0f, 0.5f, 1.0f, TEX_MADEIRA);
    glPopMatrix();

    /* Mini arquibancada direita */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -20.0f);

    /* Arquibanca de baixo */
    desenha_paralelepipedo_textura(20.0f, 0.5f, 2.0f, TEX_MADEIRA);
    glTranslatef(0.0f, 0.5f, -1.0f);

    /* Arquibanca de cima */
    desenha_paralelepipedo_textura(20.0f, 0.5f, 1.0f, TEX_MADEIRA);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    /* Cesta de basquete da esquerda */
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glTranslatef(0.0f, 0.0f, -16.7f);
    desenha_cesta_baquete();
    glPopMatrix();

    /* Cesta de basquete da direita */
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0.0f, 0.0f, -16.7f);
    desenha_cesta_baquete();
    glPopMatrix();
}

void desenha_garrafa_nortena(GLfloat tamanho) {
    GLUquadric *quad = gluNewQuadric();
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glScalef(tamanho, tamanho, tamanho);

    /* Vidro da garrafa */
    glColor4f(0.2f, 0.1f, 0.0f, 0.8f);
    gluCylinder(quad, 1.0f, 1.0f, 0.5f, 50, 1);
    glTranslatef(0.0f, 0.0f, 0.5f);

    /* Rotulo da garrafa */
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_ROTULO_GARRAFA]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 1.0f, 1.0f, 2.0f, 50, 1);
    glDisable(GL_TEXTURE_2D);

    /* Vidro da garrafa */
    glColor4f(0.2f, 0.1f, 0.0f, 0.8f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    gluCylinder(quad, 1.0f, 1.0f, 0.5f, 50, 1);
    glTranslatef(0.0f, 0.0f, 0.5f);
    gluCylinder(quad, 1.0f, 0.5f, 0.5f, 50, 1);
    glTranslatef(0.0f, 0.0f, 0.3f);
    gluCylinder(quad, 0.5f, 0.35f, 2.0f, 50, 1);

    /* Tampa da garrafa */
    glColor3f(0.2f, 0.2f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    glutSolidTorus(0.21f, 0.21f, 40, 2);
    glPopMatrix();
}

void desenha_boteco_paquito() {
    int i, j;

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);

    /* Desenha paredes */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PAREDE2]);

    glBegin(GL_QUADS);

    /* Parede frente */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 0, 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(6, 0, 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(6, 5, 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-6, 5, 6);

    /* Parede fundo */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 0, -6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(6, 0, -6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-6, 5, -6);

    /* Parede esquerda */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 0, 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(-6, 0, -6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(-6, 5, -6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-6, 5, 6);

    /* Parede direita */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(6, 0, 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(6, 0, -6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(6, 5, 6);
    glEnd();

    /* Chao */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PISO2]);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(6.0f, 0.1f, 6.0f);
    glTexCoord2f(6.0f, 0.0f);
    glVertex3f(6.0f, 0.1f, -6.0f);
    glTexCoord2f(6.0f, 6.0f);
    glVertex3f(-6.0f, 0.1f, -6.0f);
    glTexCoord2f(0.0f, 6.0f);
    glVertex3f(-6.0f, 0.1f, 6.0f);
    glEnd();

    /* Desenha porta */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PORTA2]);

    glBegin(GL_QUADS);

    /* De dentro */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4, 0, 6.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2, 0, 6.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2, 4, 6.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4, 4, 6.01f);

    /* De fora */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4, 0, 5.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2, 0, 5.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2, 4, 5.99f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4, 4, 5.99f);
    glEnd();

    /* Desenha cartaz nortena */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_CARTAZ_BAR]);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 6.05f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, 6.05f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f, 4.0f, 6.05f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 4.0f, 6.05f);
    glEnd();

    /* Desenha telhado */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_TELHADO]);

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, 6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 5, -6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(-6, 5, -6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);
    glEnd();

    /* Poster paquito */
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PAQUITO1]);
    glTranslatef(-3.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 0.5f, -5.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.5f, -5.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 3.5f, -5.99f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 3.5f, -5.99f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PAQUITO2]);
    glTranslatef(3.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 0.5f, -5.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.5f, -5.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 3.5f, -5.99f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 3.5f, -5.99f);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    /* Desenha mesa */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    desenha_mesa(0.25f, TEX_MADEIRA);
    glPopMatrix();

    /* Desenha garrafa nortena */
    glPushMatrix();
    glTranslatef(-0.5f, 1.2f, -0.2f);
    desenha_garrafa_nortena(0.15f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.2f, 0.2f);
    desenha_garrafa_nortena(0.15f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 1.2f, -0.2f);
    desenha_garrafa_nortena(0.15f);
    glPopMatrix();

    /* Desenha copo */
    glPushMatrix();
    glTranslatef(0.8f, 1.2f, 0.4f);
    desenha_copo(0.045f);
    glPopMatrix();

    /* Desenha banquinhos */
    for (i = -1; i <= 1; i++)
        for (j = -2; j <= 2; j += 4) {
            glPushMatrix();
            glTranslatef(j, 0.0f, i);
            desenha_banco(0.25f, TEX_MADEIRA);
            glPopMatrix();
        }

    /* Desenha cadeiras */
    glPushMatrix();
    glTranslatef(5.0f, 0.0f, -5.0f);
    glRotatef(-45, 0.0f, 1.0f, 0.0f);
    desenha_cadeira(0.3f, TEX_MADEIRA);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.0f, 0.0f, -5.0f);
    glRotatef(45, 0.0f, 1.0f, 0.0f);
    desenha_cadeira(0.3f, TEX_MADEIRA);
    glPopMatrix();
}

void desenha_casa() {
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);

    /* Desenha paredes  */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PAREDE1]);

    glBegin(GL_QUADS);

    /* Parede frente */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-5, 0, 5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(5, 0, 5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(5, 5, 5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-5, 5, 5);

    /* Parede fundo */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-5, 0, -5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(5, 0, -5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(5, 5, -5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-5, 5, -5);

    /* Parede esquerda */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-5, 0, 5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(-5, 0, -5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(-5, 5, -5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-5, 5, 5);

    /* Parede direita */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(5, 0, 5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3i(5, 0, -5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3i(5, 5, -5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(5, 5, 5);
    glEnd();

    /* Teto */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_TELHADO]);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(5.0f, 1.0f);
    glVertex3i(-6, 5, -6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3i(-6, 5, 6);
    glEnd();

    /* Piso da casa */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PISO1]);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(5.0f, 0.1f, 5.0f);
    glTexCoord2f(6.0f, 0.0f);
    glVertex3f(5, 0.1f, -5.0f);
    glTexCoord2f(6.0f, 6.0f);
    glVertex3f(-5.0f, 0.1f, -5.0f);
    glTexCoord2f(0.0f, 6.0f);
    glVertex3f(-5.0f, 0.1f, 5.0f);
    glEnd();

    /* Desenha porta */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PORTA1]);

    glBegin(GL_QUADS);

    /* De dentro */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3, 0, 5.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0, 5.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1, 4, 5.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3, 4, 5.01f);

    /* De fora */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3, 0, 4.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0, 4.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1, 4, 4.99f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3, 4, 4.99f);
    glEnd();

    /* Desenha janelas */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_JANELA]);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    /* Janela da frente de fora */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.25f, 1.5f, 5.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.75f, 1.5f, 5.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.75f, 3.5f, 5.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, 3.5f, 5.01f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.75f, 1.5f, 5.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.75f, 1.5f, 5.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.75f, 3.5f, 5.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.75f, 3.5f, 5.01f);

    /* Janela da frente de dentro */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.25f, 1.5f, 4.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.75f, 1.5f, 4.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.75f, 3.5f, 4.99f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, 3.5f, 4.99f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.75f, 1.5f, 4.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.75f, 1.5f, 4.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.75f, 3.5f, 4.99f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.75f, 3.5f, 4.99f);

    /* Janela da esquerda de fora */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(5.01f, 1.5f, -1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(5.01f, 1.5f, -2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(5.01f, 3.5f, -2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(5.01f, 3.5f, -1.25f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(5.01f, 1.5f, 1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(5.01f, 1.5f, 2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(5.01f, 3.5f, 2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(5.01f, 3.5f, 1.25f);

    /* Janela da esquerda de dentro */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.99f, 1.5f, -1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.99f, 1.5f, -2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.99f, 3.5f, -2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.99f, 3.5f, -1.25f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.99f, 1.5f, 1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.99f, 1.5f, 2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.99f, 3.5f, 2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.99f, 3.5f, 1.25f);

    /* Janela da direita de fora */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-5.01f, 1.5f, -1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-5.01f, 1.5f, -2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-5.01f, 3.5f, -2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-5.01f, 3.5f, -1.25f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-5.01f, 1.5f, 1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-5.01f, 1.5f, 2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-5.01f, 3.5f, 2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-5.01f, 3.5f, 1.25f);

    /* Janela da direita de dentro */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.99f, 1.5f, -1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.99f, 1.5f, -2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.99f, 3.5f, -2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.99f, 3.5f, -1.25f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.99f, 1.5f, 1.25f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.99f, 1.5f, 2.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.99f, 3.5f, 2.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.99f, 3.5f, 1.25f);
    glEnd();

    /* Desenha telhado */
    glColor3f(0.8f, 0.8f, 0.8f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_TELHADO]);

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, 6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 5, -6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(-6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(-6, 5, -6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(6, 5, 6);
    glTexCoord2f(5.0f, 0.0f);
    glVertex3i(6, 5, -6);
    glTexCoord2f(2.5f, 3.0f);
    glVertex3i(0, 9, 0);
    glEnd();

    /* Desenha Mesa */
    glPushMatrix();
    desenha_mesa(0.3f, TEX_MADEIRA);
    glPopMatrix();

    /* Desenha Vaso */
    glPushMatrix();
    glTranslatef(0.0f, 1.45f, 0.0f);
    desenha_vaso(0.1f, TEX_MADEIRA);
    glPopMatrix();

    /* Desenha copo */
    glPushMatrix();
    glTranslatef(0.5f, 1.45f, 0.0f);
    desenha_copo(0.05f);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void desenha_conjuntocasa() {
    int i, j;
    for (i = 0; i < 30; i += 15)
        for (j = 0; j < 30; j += 15) {
            glPushMatrix();
            glTranslatef(i, 0.0f, j);
            desenha_casa();
            glPopMatrix();
        }
}

void desenha_campo_futebol() {
    GLUquadric *quad = gluNewQuadric();

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);

    /* Gramado do campo */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_CAMPO]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.1f, -20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 0.1f, 20.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(20.0f, 0.1f, 20.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(20.0f, 0.1f, -20.0f);
    glEnd();

    /* Faixas de propaganda */
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PROPAGANDAS]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0f, 1.0f, 20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0f, 1.0f, 20.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PROPAGANDAS]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 1.0f, -20.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(20.0f, 1.0f, -20.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PROPAGANDAS]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(20.0f, 1.0f, 20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0f, 1.0f, -20.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texturas[TEX_PROPAGANDAS]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0f, 1.0f, -20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 1.0f, 20.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    /* Traves do campo */
    glColor3f(0.5f, 0.5f, 0.5f);
    glRotatef(-90, 1, 0, 0);
    glPushMatrix();
    glTranslatef(-19.0f, 3.0f, 0.0f);
    gluCylinder(quad, 0.1f, 0.1f, 4.0f, 5, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-19.0f, -3.0f, 0.0f);
    gluCylinder(quad, 0.1f, 0.1f, 4.0f, 5, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.0f, 3.0f, 0.0f);
    gluCylinder(quad, 0.1f, 0.1f, 4.0f, 5, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.0f, -3.0f, 0.0f);
    gluCylinder(quad, 0.1f, 0.1f, 4.0f, 5, 1);
    glPopMatrix();

    glRotatef(90, 1, 0, 0);
    glPushMatrix();
    glTranslatef(-19.0f, 4.0f, -3.0f);
    gluCylinder(quad, 0.1f, 0.1f, 6.0f, 5, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.0f, 4.0f, -3.0f);
    gluCylinder(quad, 0.1f, 0.1f, 6.0f, 5, 1);
    glPopMatrix();

    /* Desenha a bola */
    desenha_bola_futebol();
}

void desenha_carro(GLfloat *cor) {
    GLUquadric *quad = gluNewQuadric();
    glColor3f(0.1f, 0.1f, 0.1f);
    glTranslatef(0.0f, 0.25f, 0.0f);

    /* Rodas */
    glPushMatrix();
    glTranslatef(1.5f, 0.25f, 1.01f);
    gluDisk(quad, 0.15f, 0.45f, 20, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5f, 0.25f, 1.01f);
    gluDisk(quad, 0.15f, 0.45f, 20, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0.25f, -1.01f);
    gluDisk(quad, 0.15f, 0.45f, 20, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5f, 0.25f, -1.01f);
    gluDisk(quad, 0.15f, 0.45f, 20, 2);
    glPopMatrix();

    /* Lataria */
    glColor3fv(cor);

    glBegin(GL_QUADS);

    /* Lateral inferior */
    glVertex3f(-2.5f, 0.0f, 1.0f);
    glVertex3f(2.5f, 0.0f, 1.0f);
    glVertex3f(2.5f, 0.9f, 1.0f);
    glVertex3f(-2.5f, 0.9f, 1.0f);

    glVertex3f(-2.5f, 0.0f, -1.0f);
    glVertex3f(2.5f, 0.0f, -1.0f);
    glVertex3f(2.5f, 0.9f, -1.0f);
    glVertex3f(-2.5f, 0.9f, -1.0f);

    /* Capo e portamala */
    glVertex3f(-2.5f, 0.9f, -1.0f);
    glVertex3f(-2.5f, 0.9f, 1.0f);
    glVertex3f(2.5f, 0.9f, 1.0f);
    glVertex3f(2.5f, 0.9f, -1.0f);

    /* Parte frontal */
    glVertex3f(-2.5f, 0.0f, -1.0f);
    glVertex3f(-2.5f, 0.0f, 1.0f);
    glVertex3f(-2.5f, 0.9f, 1.0f);
    glVertex3f(-2.5f, 0.9f, -1.0f);

    /* Parte Traseira */
    glVertex3f(2.5f, 0.0f, -1.0f);
    glVertex3f(2.5f, 0.0f, 1.0f);
    glVertex3f(2.5f, 0.9f, 1.0f);
    glVertex3f(2.5f, 0.9f, -1.0f);

    /* Teto */
    glVertex3f(-0.9f, 1.7f, -0.6f);
    glVertex3f(0.9f, 1.7f, -0.6f);
    glVertex3f(0.9f, 1.7f, 0.6f);
    glVertex3f(-0.9f, 1.7f, 0.6f);

    glColor4f(0.2f, 0.2f, 0.2f, 0.8f);

    /* Lateral superior */
    glVertex3f(-1.6f, 0.9f, 1.0f);
    glVertex3f(1.6f, 0.9f, 1.0f);
    glVertex3f(0.9f, 1.7f, 0.6f);
    glVertex3f(-0.9f, 1.7f, 0.6f);

    glVertex3f(-1.6f, 0.9f, -1.0f);
    glVertex3f(1.6f, 0.9f, -1.0f);
    glVertex3f(0.9f, 1.7f, -0.6f);
    glVertex3f(-0.9f, 1.7f, -0.6f);

    /* Parabrisas */
    glVertex3f(-1.6f, 0.9f, -1.0f);
    glVertex3f(-1.6f, 0.9f, 1.0f);
    glVertex3f(-0.9f, 1.7f, 0.6f);
    glVertex3f(-0.9f, 1.7f, -0.6f);

    glVertex3f(1.6f, 0.9f, -1.0f);
    glVertex3f(1.6f, 0.9f, 1.0f);
    glVertex3f(0.9f, 1.7f, 0.6f);
    glVertex3f(0.9f, 1.7f, -0.6f);
    glEnd();
}

void desenha_rodovia() {

    /* Desenha a rodovia */
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_RODOVIA]);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(00.0f, 00.0f);
    glVertex3f(-160, 0.1f, -5.0f);
    glTexCoord2f(00.0f, 01.0f);
    glVertex3f(-160, 0.1f, 5.0f);
    glTexCoord2f(10.0f, 01.0f);
    glVertex3f(160, 0.1f, 5.0f);
    glTexCoord2f(10.0f, 00.0f);
    glVertex3f(160, 0.1f, -5.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

double rand_double() {

    /* Produz um número aleatório entre 0.0 e 1.0 */
    return (double)rand() / (double)RAND_MAX;
}

void desenha_fila_carros(GLfloat translacao) {
    unsigned int i;
    GLfloat cor_carro[3];

    for (i = 0; i < 600; i += 10) {

        /* Define uma cor pada cada carro */
        srand(i);
        cor_carro[0] = (GLfloat)rand_double();
        cor_carro[1] = (GLfloat)rand_double();
        cor_carro[2] = (GLfloat)rand_double();

        /* Pula alguns carros numa taxa de 40% */
        if (rand_double() < 0.4) {
            glPushMatrix();
            glTranslatef(-translacao + (GLfloat)i + 200, 0.0f, 0.0f);
            desenha_carro(cor_carro);
            glPopMatrix();
        }

        /* Desenha o próximo carro na outra */
        glTranslatef(0.0f, 0.0f, 5.0f);
        glRotatef(180, 0, 1.0f, 0);
    }

    /* Desenha a rodovia */
    glTranslatef(0.0f, 0.0f, 2.5f);
    desenha_rodovia();
}

void desenha_arvore() {
    GLUquadric *quad = gluNewQuadric();

    /* Tronco */
    glColor3f(0.2f, 0.2f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quad, 0.2f, 0.2f, 0.8f, 20, 1);

    /* Folhas */
    glTranslatef(0, 0, 0.8f);
    glColor3f(0.0f, 0.5f, 0.0f);
    gluCylinder(quad, 1, 0, 2.5f, 20, 1);
}

void desenha_floresta() {
    int i, j;
    for (i = 0; i < 40; i += 4)
        for (j = 0; j < 20; j += 4) {
            glPushMatrix();
            glTranslatef(i, 0.0f, j);
            desenha_arvore();
            glPopMatrix();
        }
}

void desenha_totem(GLfloat rotacao) {
    GLUquadric *quad = gluNewQuadric();

    /* Base */
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_TIJOLO]);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quad, 4, 1, 6, 20, 11);
    glDisable(GL_TEXTURE_2D);

    /* Cubo girante */
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 6.0f, 0);
    glRotatef(rotacao * 10, 0, 1.0f, 0);
    desenha_paralelepipedo_textura(2.0f, 2.0f, 2.0f, TEX_COPA_LOGO);
}

void desenha_tela_cena(GLfloat rotacao, GLfloat translacao) {

    /* Executa a funcao para desenhar o céu */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    desenha_ceu(rotacao);
    glPopMatrix();

    /* Executa a funcao para desenhar o chao de grama */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    desenha_chao_grama();
    glPopMatrix();

    /* Executa a funcao para desenhar o chao de terra */
    glPushMatrix();
    glTranslatef(0.0f, 0.08f, 0.0f);
    desenha_chao_terra();
    glPopMatrix();

    /* Executa a funcao para desenhar o campo */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    desenha_campo_futebol();
    glPopMatrix();

    /* Executa a funcao para desenhar o Totem da Copa */
    glPushMatrix();
    glTranslatef(28.0f, 0.0f, -10.0f);
    desenha_totem(rotacao);
    glPopMatrix();

    /* Executa a funcao para desenhar a rodovia movimentada */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 20.0f);
    desenha_fila_carros(translacao);
    glPopMatrix();

    /* Executa a funcao para desenhar a rodovia */
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(142.0f, 0.0f, -30.0f);
    desenha_rodovia();
    glPopMatrix();

    /* Executa a funcao para desenhar casas populares */
    glPushMatrix();
    glTranslatef(-60.0f, 0.0f, -10.0f);
    desenha_conjuntocasa();
    glPopMatrix();

    /* Executa a funcao para desenhar quadra de basquete */
    glPushMatrix();
    glTranslatef(-60.0f, 0.0f, -50.0f);
    desenha_quadra_basquete();
    glPopMatrix();

    /* Executa a funcao para desenhar o boteco do paquito */
    glPushMatrix();
    glTranslatef(40.0f, 0.0f, 0.0f);
    desenha_boteco_paquito();
    glPopMatrix();

    /* Executa a funcao para desenhar a floresta */
    glPushMatrix();
    glTranslatef(-20.0f, 0.0f, -65.0f);
    glScalef(1.8f, 1.8f, 1.8f);
    desenha_floresta();
    glPopMatrix();
}

void desenha_poster_paquito() {
    glColor4f(1.0f, 1.0f, 1.0f, 0.7f);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_CAMISA_PAQUITO]);

    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-10.0f, -12.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10.0f, -12.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(10.0f, 12.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-10.0f, 12.0f, 1.0f);
    glEnd();
}

void desenha_tela_menu(GLfloat rotacao) {

    /* Executa a funcao para desenhar o fundo do menu */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    desenha_fundo_menu(rotacao);
    glPopMatrix();

    /* Executa a funcao para desenhar a foto da camisa do paquito */
    glPushMatrix();
    glTranslatef(5.0f, 1.0f, -10.0f);
    glRotatef(-20, 0.0f, 1.0f, 0.0f);
    desenha_poster_paquito();
    glPopMatrix();

    /* Executa os botoes do menu */
    glPushMatrix();

    /* Botao Iniciar */
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-19.0f, 3.0f, -15.0f);
    glRotatef(rotacao * 10, 0, 1.0f, 0);
    desenha_paralelepipedo_textura(3.0f, 3.0f, 3.0f, TEX_MENU_INICIAR);

    /* Botao Opcoes */
    glTranslatef(0.0f, -11.0f, 0.0f);
    glRotatef(rotacao * 10, 0, 1.0f, 0);
    desenha_paralelepipedo_textura(3.0f, 3.0f, 3.0f, TEX_MENU_OPCOES);

    /* Botao Sair */
    glTranslatef(0.0f, -11.0f, 0.0f);
    glRotatef(rotacao * 10, 0, 1.0f, 0);
    desenha_paralelepipedo_textura(3.0f, 3.0f, 3.0f, TEX_MENU_SAIR);
    glPopMatrix();
}

void desenha_tela_opcoes(GLfloat rotacao) {

    /* Executa a funcao para desenhar o fundo do menu */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    desenha_fundo_menu(rotacao);
    glPopMatrix();

    /* Exibe a tela de ajuda */
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
    glTranslatef(0.0f, 2.0f, -1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[TEX_AJUDA]);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-10.0f, -10.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10.0f, -10.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(10.0f, 10.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-10.0f, 10.0f, 1.0f);
    glEnd();

    glPopMatrix();
}
