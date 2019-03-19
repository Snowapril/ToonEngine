import matplotlib.pyplot as plt
import os
import sys
import re
import copy

def analyze(sln_name) :
    log_abs_path = parse_log_path(sln_name)
    src_infos = []

    if log_abs_path == "" :
        print("cannot find log file with solution name [{}].".format(sln_name))
    else :
        with open(log_abs_path, 'r', encoding="UTF8") as f :
            extension_line = ["cpp", "c"]

            for line in f :
                parse = line[2:7]
                if parse == "time(" :
                    time = re.search(r'[0-9]+.[0-9]+s', line).group(0)[:-1]
                    src  = ""

                    for extension in extension_line :
                        header = re.search(r'[a-zA-Z0-9]+\.{}\b'.format(extension), line)
                        if header != None :
                            src = header.group(0)
                    
                    src_infos.append([src, float(time)])
    plotting(src_infos)

def parse_log_path(sln_name) :
    cwd         = os.getcwd()
    target_name = sln_name + ".log"
    target_abs  = "" 

    for root, subdirs, files in os.walk(cwd):
        if target_name in files :
            target_abs = root + "\\" + target_name
            break

    return target_abs

def plotting(src_infos) :
    tuples = copy.deepcopy(src_infos)
    tuples.sort(reverse=True, key = lambda pair : pair[1])

    counts  = len(tuples)
    labels  = [label[0] for label in tuples]
    times   = [label[1] for label in tuples]
    explode = [0] * counts  

    def auto_parse(values):
        def auto_pct(pct):
            total = sum(values)
            val = pct*total/100.0
            return "{v:.3f}s".format(v=val)
        return auto_pct

    highlight_length = 5 if counts > 5 else counts
    for idx in range(0, counts) : 
        if idx < highlight_length :
            explode[idx] = 0.1
        else :
            labels[idx] = ""

    fig, ax = plt.subplots()
    ax.pie(times, explode=explode, labels=labels, autopct=auto_parse(times), shadow=True, startangle=90)
    ax.axis('equal')
    plt.show()

if __name__ == "__main__" :
    args = sys.argv
    argc = len(args)
    
    flags = ['-Bt+', '-d1reportTime', '-d2cgsummary']

    if argc == 3 :
        analyze(args[1])
    else :
        print("Usage : python analyze-Bt+ [target solution name]")
