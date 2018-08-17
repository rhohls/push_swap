
from __future__ import print_function
from subprocess import Popen, check_output

import random

def shell_exe(array_string):
    script = "sh pusher.sh"
    args = script 
    args = args.split()
    args.append(array_str)
    popen = Popen(args)
    popen.wait()

    result = open("pusher.txt", "r")
    lines = result.readlines()
    print("Amount of instructions:", len(lines))

    script = "sh checker.sh"
    args = script 
    args = args.split()
    args.append(array_str)
    popen = Popen(args)
    popen.wait()

    result = open("checker.txt", "r")
    lines = result.readlines()
    print("Result from checker:", lines[0])



    if lines[0] == "KO\n":
        script = "sh pusher.sh"
        args = script 
        args = args.split()
        array_string = "-v " + array_string
        args.append(array_string)
        print("args:", args)
        popen = Popen(args)
        popen.wait()

        result = open("pusher.txt", "r")
        lines = result.readlines()
        for line in lines:
            print(line, end='')

length = 100
array = random.sample(range(0, length), length)
array_str = ' '.join(map(str, array))

print(array_str)

shell_exe(array_str)