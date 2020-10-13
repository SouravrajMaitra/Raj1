from os import system

def menu():
    ls=['BoundaryFill','Bresenhaum','BresenhaumCircle','DDAalgo','FloodFill','Reflection','Shearing','Translation','ellipseBresenhaum','PointClipping']
    print("Menu:")
    for i in range(1,len(ls)+1):
        print(i,".",ls[i-1])
    ip=int(input("Enter the choice:"))
    if ip not in range(1,len(ls)+1):
        print("Wrong Choice!!!")
        return
    execv(ls[ip-1]+'.cpp')
    
def execv(arg):
    m='g++ '+arg+' -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32'
    system(m)

menu()
