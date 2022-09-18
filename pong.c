#include <stdio.h>

int main() {
    int score_1st = 0;
    int score_2st = 0;
    while (score_1st <= 21 || score_2st <= 21) {
    int width = 25;
    int large = 80;
    int racket_1st_position_1st_px = 12;
    int racket_2st_position_1st_px = 12;
    int ball_position_ox = 40;
    int ball_position_oy = 13;
    int ballSpx = -1;
    int ball_sp_oy = 1;
    char ch = 0;
    while (1) {
    ballSpx = score_2st > score_1st ? -1 : 1;
    for (int i = 0; i <= width; i++) {
    for (int j = 0; j <= large; j++) {
    if ((j == 1 && (i == racket_1st_position_1st_px || i == racket_1st_position_1st_px +1 ||
    i == racket_1st_position_1st_px + 2)) || (j == large -1 && (i == racket_2st_position_1st_px ||
    i == racket_2st_position_1st_px + 1 || i == racket_2st_position_1st_px + 2))) {
    printf("H");
    } else if (j == ball_position_ox && i == ball_position_oy) {
    printf("Ф");
    } else if ((i == 0 && j == 0) || (i == 0 && j == large) ||
    (i == width && j == 0) || (i == width && j == large)) {
    printf("+");
    } else if (i == 0 || i == width) {
    printf("=");
    } else if (j == 0 || j == large) {
    printf("|");
    } else if (score_1st >= 10 && i == 2 && j == 1) {
    continue;
    } else if (score_2st >= 10 && i == 2 && j == 70) {
    continue;
    } else if (i == 2 && j == 37) {
    printf("%d", score_1st);
    } else if (i == 2 && j == 38) {
    printf(":");
    } else if (i == 2 && j == 39) {
    printf("%d", score_2st);
    } else {
    printf(" ");
    }
    }
        printf("\n");
    }
    if ((ball_position_ox == large-1) && (((racket_2st_position_1st_px + 1) || racket_2st_position_1st_px ||
    (racket_2st_position_1st_px + 2)) != ball_position_oy)) {
    score_1st++;
    break;
    } else {
    ballSpx*=(-1);
    }
    if (((ball_position_ox == 1) && (ball_position_oy !=
    ((racket_1st_position_1st_px + 1) || (racket_1st_position_1st_px + 2) ||
    racket_1st_position_1st_px)))) {
    score_2st++;
    break;
    }
    else {
    ballSpx*=(-1);
    }
    if ((ball_position_ox == 1 && (racket_1st_position_1st_px == ball_position_oy ||
    racket_1st_position_1st_px + 1 == ball_position_oy ||
    racket_1st_position_1st_px + 2 == ball_position_oy)) ||
    (ball_position_ox == large-1 &&
    (racket_2st_position_1st_px == ball_position_oy ||
    racket_2st_position_1st_px + 1 == ball_position_oy
    || racket_2st_position_1st_px + 2 == ball_position_oy))) {
        ballSpx*=(-1);
    }
    if (ball_position_oy == 1 || ball_position_oy == width-1) {
        ball_sp_oy*=(-1);
    }
    ball_position_ox+=ballSpx;
    ball_position_oy+=ball_sp_oy;
    scanf("%c", &ch);
    if (ch == 'a' && racket_1st_position_1st_px > 1) {
       racket_1st_position_1st_px--;
      } else if (ch == 'z' && racket_1st_position_1st_px < 22) {
        racket_1st_position_1st_px++;
      } else if (ch == 'i' && racket_2st_position_1st_px > 1) {
        racket_2st_position_1st_px--;
      } else if (ch == 'k' && racket_2st_position_1st_px < 22) {
        racket_2st_position_1st_px++;
      }
}
if (score_1st == 21) {
printf("Первый игрок победил.\n");
break;

} else if (score_2st == 21) {
printf("Второй игрок победил.\n");
break;
}
}
return 1;
}


