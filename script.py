#!/usr/bin/env python3
import shlex
import subprocess
import numpy as np
import time


def analysis(args):
    array = list()
    for i in range(17):
        runtime = run_process(args)
        array.append(runtime)
    return np.average(array)


def run_process(args):
    start_time = time.time()
    pid = subprocess.Popen(args, shell=False)
    pid.wait()
    stop_time = time.time()
    run_time = stop_time - start_time
    time.sleep(0.01)
    return run_time


for i in range(5):
    for j in range(1000*pow(10, i), 10000*pow(10, i), 1000*pow(10, i)):
        command_line = './arvoreRedBlack teste_' + str(j) + '.txt'
        args = shlex.split(command_line)
        # print(args)
        average = analysis(args)
        print(average)
        print()
