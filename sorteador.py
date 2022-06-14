#!/usr/bin/env python3
import random
_index = 0
nome_arquivo = ['teste_1000.txt', 'teste_2000.txt', 'teste_3000.txt', 'teste_4000.txt', 'teste_5000.txt', 'teste_6000.txt', 'teste_7000.txt', 'teste_8000.txt', 'teste_9000.txt', 'teste_10000.txt', 'teste_20000.txt', 'teste_30000.txt',
                'teste_40000.txt', 'teste_50000.txt', 'teste_60000.txt', 'teste_70000.txt', 'teste_80000.txt', 'teste_90000.txt', 'teste_100000.txt', 'teste_100000.txt', 'teste_200000.txt', 'teste_300000.txt', 'teste_400000.txt', 'teste_500000.txt', 'teste_600000.txt', 'teste_700000.txt', 'teste_800000.txt', 'teste_900000.txt', 'teste_1000000.txt']


def sorteador(n, i):
    array = list()
    while(len(array) != n):
        num = random.randint(0, 10000*pow(10, i))
        if num not in array:
            array.append(num)
    with open(nome_arquivo[_index], 'w') as arquivo:
        for j in array:
            arquivo.write(str(j))
            arquivo.write(' ')


for i in range(3):
    for j in range(1000*pow(10, i), 10000*pow(10, i) + 1, 1000*pow(10, i)):
        sorteador(j, i)
        _index += 1
        # print(array)
