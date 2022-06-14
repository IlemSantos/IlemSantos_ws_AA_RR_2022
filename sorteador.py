#!/usr/bin/env python3
import random


def nome_arquivo(n):
    return 'teste_' + str(n) + '.txt'


def sorteador(n, i):
    array = list()
    while(len(array) != n):
        num = random.randint(0, 10000*pow(10, i))
        array.append(num)
    with open(nome_arquivo(n), 'w') as arquivo:
        for j in array:
            arquivo.write(str(j))
            arquivo.write(' ')


for i in range(5):
    for j in range(1000*pow(10, i), 10000*pow(10, i), 1000*pow(10, i)):
        sorteador(j, i)
