// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the constructor.
TEST(Dados, Constructor) {
  Dados d;

  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());

}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;

  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;

  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

TEST(Dados, Diferencia) {
  Dados d;

  EXPECT_EQ((d.getDado1()-d.getDado2())||(d.getDado2()-d.getDado1()), d.getDiferencia());
}

TEST(Dados, Lanzamientos) {
  Dados d;

  EXPECT_EQ(0, d.getLanzamientos1());
  EXPECT_EQ(0, d.getLanzamientos2());

  d.setDado1(5);
  d.setDado2(4);
  EXPECT_EQ(1, d.getLanzamientos1());
  EXPECT_EQ(1, d.getLanzamientos2());

  for(int i = 1;i<50;i++){
    d.setDado1(2);
    d.setDado2(3);
    EXPECT_EQ(i+1, d.getLanzamientos1());
    EXPECT_EQ(i+1, d.getLanzamientos2());
  }
}

TEST(Dados, Media) {
  Dados d;

  EXPECT_EQ(0, d.getMedia1());
  EXPECT_EQ(0, d.getMedia2());
  d.lanzamiento();
  float i = d.getDado1();
  float j = d.getDado2();
  EXPECT_EQ(i, d.getMedia1());
  EXPECT_EQ(j, d.getMedia2());
  d.lanzamiento();
  i = i + d.getDado1();
  i = i/2;
  j = j + d.getDado2();
  j = j/2;
  EXPECT_EQ(i, d.getMedia1());
  EXPECT_EQ(j, d.getMedia2());

  d.setDado1(2);
  d.setDado2(3);
  i = (i + 2)/3;
  j = (j+3)/3;

  EXPECT_EQ(i, d.getMedia1());
  EXPECT_EQ(j, d.getMedia2());
}

TEST(Dados, Vector){
  Dados d;
  int *vector1 = d.getUltimos1();
  int *vector2 = d.getUltimos2();
  for(int i=0; i<5;i++){
      EXPECT_EQ(0, vector1[i]);
      EXPECT_EQ(0, vector2[i]);
  }
  for(int i=0;i<5;i++){
    d.lanzamiento();
    vector1 = d.getUltimos1();
    vector2 = d.getUltimos2();
    EXPECT_EQ(d.getDado1(), vector1[0]);
    EXPECT_EQ(d.getDado2(), vector2[0]);
  }
}
