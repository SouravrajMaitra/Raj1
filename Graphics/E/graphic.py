from sys import argv
from os import system

def execv(arg):
    m='g++ '
    for i in arg:
        m+=i+' '
    m+='-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32'
    system(m)

if __name__=='__main__':
    execv(argv[1::])
