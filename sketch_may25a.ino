#include <GameBoy.h>
#include "Blocks.h"
GameBoy gb;
int paddleX = 3;
int paddleY = 14;
int ballX = 4;
int ballY = 13;
int dirX = 1;
int dirY = -1;
void setup() {
  gb.begin(15);

}
void loop() {                               //Головна Частина
  ball();
  makePaddle();
  drawPaddle(paddle, paddleX, paddleY);
  delay(200);
  gb.drawDisplay();

}
void drawPaddle(byte arr[3], int x, int y) { // Малюємо платформу
  for (int i = 0; i < 3; i++) {

    if (arr[i] == 1) {
      gb.drawPoint(x + i, y);
    }
  }
}
void makePaddle() {                         //Рух Платформи
  if (gb.getKey() == 4 && paddleX > 0) {
    paddleX --;
  }
  if (gb.getKey() == 5 && paddleX < 5) {
    paddleX ++;
  }
}
void ball(){
  ballX += dirX;
  ballY += dirY;

  if (ballX <= 0 || ballX >=7) dirX = - dirX;
  if (ballY <= 0 || ballY >=15) dirY = - dirY;
  
  if (ballY = paddleY - 1 && ballX >= paddleX && ballX<= ballX <= paddleX + 3){
    dirY = +1;
    }
  
  gb.drawPoint(ballX,ballY);

} 
