// gcc -std=c99 fastexp.c -o fastexp

#include <stdio.h>
#include <math.h>

#define ALPHA 0.6563658616549711f               
#define ALPHAc 0.34363413834502887               
#define INV_LN2 1.4426950408889634f

float fast2pxm1_m(float x) { // 0.0 <= x <= 1.0
  return x*(ALPHA+ALPHAc*x);
}

float fast2px(float x) {
  float m, mp;
  float e;

  m = modff(x, &e);

  if (m < 0.0f) {
     m += 1.0f;
     e -= 1.0f;
  }

  mp = fast2pxm1_m(m) + 1.0f;
  
  return ldexpf(mp, e);
}

float fastexp(float x) {  // exportable
  return fast2px(x*INV_LN2);
}

int main(int argc, char *argv[]) {
  float x;

  for (int i = -10; i <= 10; i++) {
     x= (float) i/10.0*2;
     printf("%.8f => %.8f\n",x,fastexp(x));
  }
  return 0;
}
