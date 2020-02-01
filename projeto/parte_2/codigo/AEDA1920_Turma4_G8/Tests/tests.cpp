/*#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Condomino.h"
#include "Servico.h"
#include <string>


using testing::Eq;


TEST(test_1, CriarHabitacoes) {
    Morada m("Rua das Flores", "Porto", "4200-001");
    Vivenda v1(4500, m, 1700, true);
    Apartamento a1(5000, m, "T0", 1);
    ASSERT_EQ(4500, v1.getAreaHabitacional());
    ASSERT_EQ(5000, a1.getAreaHabitacional());
}

TEST(test_1, CriarCondomino) {
    Morada m("Rua das Flores", "Porto", "4200-001");
    Condomino condomino;
    ASSERT_EQ(0, condomino.numeroHabitacoes());
    ASSERT_EQ(0, condomino.menorHabitacao());
    Habitacao *v1 = new Vivenda(4500, m, 1700, true);
    Habitacao *v2 = new Apartamento(5000, m, "T0", 1);
    condomino.adicionaHabitacao(v1);
    condomino.adicionaHabitacao(v2);
    ASSERT_EQ(2, condomino.numeroHabitacoes());
    ASSERT_EQ(4500, condomino.menorHabitacao());
}

TEST(test_1, InfoHabitacao){
    Morada m("Rua das Flores", "Porto", "4200-001");
    Vivenda v1(4500, m, 1700, true);
    Apartamento a1(5000, m, "T0", 1);
    ASSERT_EQ(4,a1.info());
    ASSERT_EQ(4,v1.info());
}

TEST(test_1, InfoCondomino){
    Morada m("Rua das Flores", "Porto", "4200-001");
    Habitacao *v1 = new Vivenda(4500, m, 1700, true);
    Habitacao *v2 = new Apartamento(5000, m, "T0", 1);
    Habitacao *v3 = new Apartamento(7000, m, "T4", 17);
    Condomino condomino;
    condomino.adicionaHabitacao(v1);
    condomino.adicionaHabitacao(v2);
    condomino.adicionaHabitacao(v3);
    ASSERT_TRUE(true);
    cout << condomino;
}

TEST(test_1, OperadorMenor) {
    Morada m("Rua das Flores", "Porto", "4200-001");
    Vivenda v1(4500, m, 1700, true);
    Apartamento a1(2000, m, "T0", 1);
    Vivenda v2(3000, m, 1700, true);
    Apartamento a2(7000, m, "T0", 1);
    ASSERT_EQ(true, a1<v1);
    ASSERT_EQ(false,a2<v2);
    ASSERT_EQ(true,v1<a2);
}

TEST(test_1, OperadorFuncao) {
    Condomino condomino;
    Morada m("Rua das Flores", "Porto", "4200-001");
    Habitacao *v1 = new Vivenda(4500, m, 1600, true);
    Habitacao *v2 = new Apartamento(5000, m, "T0", 1);
    Habitacao *v3 = new Apartamento(7000, m, "T4", 17);
    Habitacao *v4 = new Vivenda(4500, m, 1700, true);
    Habitacao *v5 = new Apartamento(900, m, "T2", 6);
    condomino.adicionaHabitacao(v1);
    condomino.adicionaHabitacao(v2);
    condomino.adicionaHabitacao(v3);
    condomino.adicionaHabitacao(v4);
    condomino.adicionaHabitacao(v5);
    ASSERT_EQ(5, condomino.numeroHabitacoes());
    vector<Habitacao*> v;
    v = condomino(4500);
    ASSERT_EQ(2, v.size());
    v = condomino(7001);
    ASSERT_EQ(0, v.size());
    v = condomino(7000);
    ASSERT_EQ(1, v.size());
}

TEST(test_1, CondominioHabitacao) {
    Morada m("Rua das Flores", "Porto", "4200-001");
    Vivenda v1(4500, m, 1700, true);
    Apartamento a1(2000, m, "T0", 3);
    Vivenda v2(3000, m, 1700, false);
    Apartamento a2(2000, m, "T4", 1);
    ASSERT_NEAR(9500, v1.calculaCondominio(),0.001);
    ASSERT_NEAR(2200,a1.calculaCondominio(),0.001);
    ASSERT_NEAR(6100,v2.calculaCondominio(),0.001);
    ASSERT_NEAR(2500,a2.calculaCondominio(),0.001);
}

TEST(test_1, ImpostoCondomino) {
    Morada m("Rua das Flores", "Porto", "4200-001");
    Habitacao *v1 = new Vivenda(4500, m, 1700, true);
    Habitacao *v2 = new Apartamento(2000, m, "T0", 3);
    Habitacao *v3 = new Apartamento(2000, m, "T4", 1);
    Condomino condomino;
    condomino.adicionaHabitacao(v1);
    condomino.adicionaHabitacao(v2);
    condomino.adicionaHabitacao(v3);
    ASSERT_NEAR(14200, condomino.totalCondominio(),0.001);
}

TEST(test_1, CriarServicos) {
    //ServicoLimpeza s1("S-45", "Quartos", 4.5);
    //ServicoLimpeza s2("S-46", "WC", 2.5);
    //ASSERT_EQ(4.5, s1.getDuracao());
    //ASSERT_EQ("S-46", s2.getId());
}
*/