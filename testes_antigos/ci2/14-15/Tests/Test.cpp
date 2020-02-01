#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include "Supermercado.h"

TEST(test_1, test_a) {
	Item i1(5, 2, 2, "uva", "fruta");
	Item i2(10, 1, 1, "dentifico", "higiene");
	Item i3(7, 3, 3, "detergente", "limpeza");

	vector<Item> v1;
	v1.push_back(i1);
	v1.push_back(i2);
	v1.push_back(i3);
	Cesto c1(v1);
	Cliente joao("Joao", 30);
	joao.addCesto(c1);

	Item i4(10, 1, 1, "coca-cola", "bebida");
	Item i5(7, 3, 3, "arroz", "grao");

	vector<Item> v2;
	v2.push_back(i4);
	v2.push_back(i5);
	Cesto c2(v2);
	joao.addCesto(c2);

	ASSERT_EQ(5, joao.numeroItens());
	ASSERT_EQ(39, joao.valorItens());
}

TEST(test_1, test_b) {
	Item maca(1, 1, 1, "maca", "fruta");
	Item arroz(2, 1, 1, "arroz", "grao");
	Item lixivia(3, 2, 2, "lixivia", "limpeza");
	Item shampoo(5, 2, 2, "shampoo", "higiene");
	Item dentifico(2, 1, 1, "dentifico", "higiene");

	vector<Item> itens;
	itens.push_back(maca);
	itens.push_back(arroz);
	itens.push_back(lixivia);
	itens.push_back(shampoo);
	itens.push_back(dentifico);

	Cesto c1(itens);
	Cesto c2(itens);
	Item shampoo3(1, 2, 2, "shampoo", "higiene");
	c2.pushItem(shampoo3);

	Cliente joao("Joao", 25);
	joao.addCesto(c1);
	joao.addCesto(c2);

	Item shampooBarato(3, 2, 2, "shampoo", "higiene");

	ASSERT_EQ(3, joao.trocarItem(shampooBarato));
}

TEST(test_1, test_c) {
	Item i1(1, 1, 100, "melancia", "fruta");
	Item i2(1, 1, 60, "melao", "fruta");
	Item i3(1, 1, 20, "maca", "fruta");
	Item i4(1, 1, 50, "laranja", "fruta");
	Item i5(1, 1, 10, "uva", "fruta");

	Cesto c;

	c.pushItem(i2);
	c.pushItem(i3);
	c.pushItem(i1);
	c.pushItem(i4);
	c.pushItem(i5);

	Cliente joao("Joao", 25);
	joao.addCesto(c);

	joao.organizarCestos();
	list<Cesto> cs = joao.getCestos();
	list<Cesto>::iterator it = cs.begin();
	stack<Item> temp = (*it).getItens();

	ASSERT_EQ(10, temp.top().peso);
	temp.pop();
	ASSERT_EQ(20, temp.top().peso);
	temp.pop();
	ASSERT_EQ(50, temp.top().peso);
	temp.pop();
	ASSERT_EQ(60, temp.top().peso);
	temp.pop();
	ASSERT_EQ(100, temp.top().peso);
	temp.pop();
}

TEST(test_1, test_d) {
	Item maca(1, 1, 1, "maca", "fruta");
	Item arroz(2, 1, 1, "arroz", "grao");
	Item lixivia(3, 2, 2, "lixivia", "limpeza");
	Item shampoo(5, 2, 2, "shampoo", "higiene");
	Item dentifico(2, 1, 1, "dentifico", "higiene");

	vector<Item> itens;
	itens.push_back(maca);
	itens.push_back(arroz);
	itens.push_back(lixivia);
	itens.push_back(shampoo);
	itens.push_back(dentifico);

	Cesto c1(itens);
	Cesto c2(itens);
	Item shampoo3(1, 2, 2, "shampoo", "higiene");
	c2.pushItem(shampoo3);

	Cliente joao("Joao", 25);

	joao.addCesto(c1);
	joao.addCesto(c2);

	vector<string> contagens = joao.contarItensPorTipo();
	ASSERT_EQ(4, joao.contarItensPorTipo().size());

	vector<string>::iterator it;
	it = find(contagens.begin(), contagens.end(), "higiene 5");

	ASSERT_EQ(it != contagens.end(), true);
}

TEST(test_1, test_e) {
	Item i1(1, 3, 3, "melancia", "fruta");
	Item i2(1, 3, 3, "melao", "fruta");
	Item i3(1, 3, 3, "maca", "fruta");
	Item i4(1, 3, 3, "laranja", "fruta");
	Item i5(1, 3, 3, "uva", "fruta");

	Cesto c;

	ASSERT_EQ(1, c.novoItem(i1));
	ASSERT_EQ(2, c.novoItem(i2));
	ASSERT_EQ(3, c.novoItem(i3));
	ASSERT_EQ(0, c.novoItem(i4));

	Cliente joao("Joao", 25);

	joao.addCesto(c);

	ASSERT_EQ(2, joao.novoItem(i4));
}

TEST(test_1, test_f) {
	Supermercado jumbo;
	Item i1(1, 3, 3, "melancia", "fruta");
	Item i2(1, 3, 3, "melao", "fruta");
	Item i3(1, 3, 3, "maca", "fruta");
	Item i4(1, 3, 3, "laranja", "fruta");
	Item i5(1, 3, 3, "uva", "fruta");

	Cesto c;
	c.pushItem(i1);
	c.pushItem(i2);
	c.pushItem(i3);
	c.pushItem(i4);
	c.pushItem(i5);

	Cliente joao("Joao", 25);
	joao.addCesto(c);
	ASSERT_EQ(1, jumbo.novoCliente(joao));

	Cliente maria("Maria", 70);
	maria.addCesto(c);
	ASSERT_EQ(2, jumbo.novoCliente(maria));

	Cliente pedro("Pedro", 85);
	maria.addCesto(c);
	ASSERT_EQ(3, jumbo.novoCliente(pedro));
	ASSERT_EQ(1, jumbo.tamanhoFilaNormal());
	ASSERT_EQ(2, jumbo.tamanhoFilaPrioritaria());

	Cliente joana("Joana", 65);
	maria.addCesto(c);
	ASSERT_EQ(4, jumbo.novoCliente(joana));
	ASSERT_EQ(2, jumbo.tamanhoFilaNormal());
}

TEST(test_1, test_g) {
	Cliente joao("Joao", 30);
	Cliente maria("Maria", 10);
	Cliente ana("Ana", 72);
	Cliente rui("Rui", 20);
	Cliente vasco("Vasco", 18);
	Supermercado jumbo;

	queue<Cliente> fn;
	fn.push(joao);
	fn.push(rui);
	fn.push(maria);
	fn.push(vasco);

	queue<Cliente> fp;
	fp.push(ana);

	jumbo.setFilaNormal(fn);
	jumbo.setFilaPrioritaria(fp);



	ASSERT_THROW(jumbo.sairDaFila("Ricardo"), Supermercado::ClienteInexistente);
	try {
			jumbo.sairDaFila("Ricardo");
	}
	catch (Supermercado::ClienteInexistente &e) {
			cout << "Apanhou excecao. Cliente nao existe: " << e.getNome() << endl;
			ASSERT_EQ("Ricardo", e.getNome());
	}

	Cliente c1=jumbo.sairDaFila("Rui");
	ASSERT_EQ("Rui",c1.getNome());
	ASSERT_EQ(3,jumbo.tamanhoFilaNormal());
	ASSERT_EQ("Joao",jumbo.getFilaNormal().front().getNome());

	c1=jumbo.sairDaFila("Vasco");
	ASSERT_EQ("Vasco",c1.getNome());
	ASSERT_EQ(2,jumbo.tamanhoFilaNormal());
	ASSERT_EQ("Joao",jumbo.getFilaNormal().front().getNome());

	c1=jumbo.sairDaFila("Ana");
	ASSERT_EQ("Ana",c1.getNome());
	ASSERT_EQ(0,jumbo.tamanhoFilaPrioritaria());
}



