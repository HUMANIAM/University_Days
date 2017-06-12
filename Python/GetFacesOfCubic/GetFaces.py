#import needed packages
import tkinter as tk
from tkinter import *
from tkinter import messagebox
import webbrowser
import sys,os
from PIL import Image,ImageTk

#this is the main class
class App(tk.Frame):

    #the constuctor of the App class
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)                          #master hold the main window
        self.Intialize()                                         #intialize the window
        self.grid()                                              #USE THE gride method instead of packer
        self.curface = 'U'                                   #the current displayed face
        self.curfacen = 0                                        # Number of inserted faces
        # map selected colors colors we use in the cubic
        self.MapSELcolors = {'White':'U','Red':'R','Green':'F','Yellow':'D','Orange':'L','Blue':'B'}
        self.MapDisedcors = {'U': 'White','R':'Red','F':'Green','D':'Yellow','L':'Orange','B':'Blue'}
        self.SeqOfFaces=['U','R','F','D','L','B'];
        #the default values of  faces
        self.dict={'U' : ["U","U","U","U","U","U","U","U","U"],
                   'R' : ["U","U","U","U","R","U","U","U","U"],
                   'F': ["U","U","U","U","F","U","U","U","U"],
                   'D': ["U","U","U","U","D","U","U","U","U"],
                   'L': ["U","U","U","U","L","U","U","U","U"],
                   'B': ["U","U","U","U","B","U","U","U","U"],
                   }
        self.dictemp=self.dict.copy()
        pass

    #####################
    def Intialize(self):
        scr_wd= self.winfo_screenwidth()                            #get the screen width
        scr_ht= self.winfo_screenheight()                           #get the screen height
        x=scr_wd/2-275                                             #x position
        y=scr_ht/2-300                                              #y position
        self.master.geometry('%dx%d+%d+%d' % (570, 400,x,y ))
        self.master.resizable(0,0)
        self.master.title("Rubik's Cube")
        pass
    ###################
    def GetFaces(self):
        self.createWidgets()     #create controls (button and optionmenus in the window)
        pass
    ###################
    def createWidgets(self):
                             #creation of buttons in the main window
        self.bthelp=Button(self,text="Help",width=13,bg="#9bbcef",padx=5,pady=5,command=self.fd_help)
        self.btsite=Button(self,width=13,text="Algorithm's Site",bg="#9bbcef",padx=5,pady=5,command=self.fd_site)
        self.btsolve=Button(self,text="Solve",width=13,bg="#9bbcef",padx=5,pady=5,state=DISABLED,command=self.fd_solve)
        self.btRest=Button(self,text="Rest",width=13,bg="#9bbcef",padx=5,pady=5,command=self.fd_rest)
        self.btinsert=Button(self,text="Insert",width=13,bg="#9bbcef",padx=5,pady=5,command=self.fd_insert)
        self.btexit= Button(self, text="Exit", width=13, bg="#9bbcef", padx=5,pady=5,command=self.fd_exit)

                             #creation of labels

        self.lbspace    =  Label(self,text="",bg="#EDF1F5",padx=2,pady=2)
        self.lbsolution = Label(self,text="Solution step by step",bg="#E637D7",padx=2,pady=2,width=19)
        self.lbinsertedf   = Label(self,text="Inserted Faces are 0",bg="#A49DF5",padx=2,pady=2,)
        self.lbstbyst   = Label(self,text="",bg="#FCF7FB",padx=2,pady=2,width=19)
        self.lbheader   = Label(self,text="Rubik's Cube",bg="#9966ff",font=("Helvetica", 16),width=15)

                            #creation of optionalmenues
        #create strings to be set to optionmenue as the defual values
        self.var0 = StringVar(self.master)
        self.var1 = StringVar(self.master)
        self.var2 = StringVar(self.master)
        self.var3 = StringVar(self.master)
        self.var4 = StringVar(self.master)
        self.var5 = StringVar(self.master)
        self.var6 = StringVar(self.master)
        self.var7 = StringVar(self.master)
        self.varc = StringVar(self.master)

        self.varc.set("White")
        self.var0.set("White")
        self.var1.set("White")
        self.var2.set("White")
        self.var3.set("White")
        self.var4.set("White")
        self.var5.set("White")
        self.var6.set("White")
        self.var7.set("White")

        self.W0 = OptionMenu(self.master, self.var0, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check0)
        self.W1 = OptionMenu(self.master, self.var1, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check1)
        self.W2 = OptionMenu(self.master, self.var2, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check2)
        self.W3 = OptionMenu(self.master, self.var3, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check3)
        self.W4 = OptionMenu(self.master, self.var4, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check4)
        self.W5 = OptionMenu(self.master, self.var5, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check5)
        self.W6 = OptionMenu(self.master, self.var6, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check6)
        self.W7 = OptionMenu(self.master, self.var7, "White", "Red", "Green","Yellow" ,"Orange","Blue",command=self.fd_check7)
        self.center = OptionMenu(self.master, self.varc ,"White")
        self.W0.config(width=10,font=("Helvetica", 10))
        self.W1.config(width=10,font=("Helvetica", 10))
        self.W2.config(width=10,font=("Helvetica", 10))
        self.W3.config(width=10,font=("Helvetica", 10))
        self.W4.config(width=10,font=("Helvetica", 10))
        self.W5.config(width=10,font=("Helvetica", 10))
        self.W6.config(width=10,font=("Helvetica", 10))
        self.W7.config(width=10,font=("Helvetica", 10))
        self.center.config(width=10,font=("Helvetica", 10))
                     #read an image
        self.im=Image.open("image.jpg")
        self.resized = self.im.resize((350, 140), Image.ANTIALIAS)
        self.tkimage = ImageTk.PhotoImage(self.resized)
        self.myvar = Label(self.master, image=self.tkimage)#

        self.Releas_comps()   # release the created widgets into the window
        pass
    ###################
    def Releas_comps(self):
        self.lbheader.grid(row=0,column=0,columnspan=2)
        self.myvar.grid(row=0, column=1, columnspan=6, rowspan=1)
        self.bthelp.grid(row=1,column=0)
        self.btsite.grid(row=2,column=0)
        self.btsolve.grid(row=3, column=0)
        self.btexit.grid(row=1,column=1)
        self.btRest.grid(row=2,column=1)
        self.btinsert.grid(row=3,column=1)
        self.lbinsertedf.grid(row=4,column=0,columnspan=2)
        self.W0.grid(row=5,column=1)
        self.W1.grid(row=5,column=2)
        self.W2.grid(row=5,column=3)
        self.W3.grid(row=6,column=1)
        self.center.grid(row=6,column=2)
        self.W4.grid(row=6, column=3)
        self.W5.grid(row=7, column=1)
        self.W6.grid(row=7, column=2)
        self.W7.grid(row=7, column=3)
        self.lbspace.grid(row=8,column=1)
        self.lbsolution.grid(row=9,column=0,columnspan=2)
        # self.lbsolbox.grid(row=10,column=0)
        self.lbstbyst.grid(row=11,column=0,columnspan=2)

        pass

     #Feedback functions
    def fd_help(self):
        self.msg="You must put the cubic where the green side face your face " \
            "and white is the top side,and you must insert faces in " \
            "a specific sequence.I 'll show you when insert the faces" \
            ".Insert every face from row by row from top and also from left to right"

        messagebox.showinfo("How To Insert Faces",self.msg)
        pass

    def fd_site(self):        #site of the algorithm
        url = 'http://kociemba.org/cube.htm'
        webbrowser.open(url)
        pass

    #these functions for checked items color in the optionmenu
    def fd_check0(self,value):
        self.dict[self.curface][0]=self.MapSELcolors[value]
        self.W0["bg"] = value.lower()
        pass
    def fd_check1(self,value):
        self.dict[self.curface][1] = self.MapSELcolors[value]  #set the selected value to the dictionary of faces
        self.W1["bg"] = value.lower()                    # color the optionmenu according to the selected value
        pass

    def fd_check2(self,value):
        self.dict[self.curface][2] = self.MapSELcolors[value]
        self.W2["bg"] = value.lower()
        pass

    def fd_check3(self,value):
        self.dict[self.curface][3] = self.MapSELcolors[value]
        self.W3["bg"] = value.lower()
        pass

    def fd_check4(self,value):
        self.dict[self.curface][5] = self.MapSELcolors[value]
        self.W4["bg"] = value.lower()
        pass

    def fd_check5(self,value):
        self.dict[self.curface][6] = self.MapSELcolors[value]
        self.W5["bg"] = value.lower()
        pass

    def fd_check6(self,value):
        self.dict[self.curface][7] = self.MapSELcolors[value]
        self.W6["bg"] = value.lower()
        pass

    def fd_check7(self,value):
        self.dict[self.curface][8] = self.MapSELcolors[value]
        self.W7["bg"] = value.lower()
        pass
        #end of checked callback functions of optionmenu

    def fd_rest(self):             #reset the window to the default state
        self.setext("White")       #reset the values of the optionmenus
        self.setcolors("white")    #reset the colors of optionmenus to white
        self.curface = "White"
        self.curfacen = 0
        self.lbinsertedf["text"] = "Inserted Faces are " + str(self.curfacen)
        self.btinsert["state"] = NORMAL
        self.btsolve["state"] = DISABLED
        self.varc.set("White")
        self.dict.update(self.dictemp)     #return the dictionary to its default values
        pass

    def fd_insert(self):
        self.curfacen +=1
        self.lbinsertedf["text"] = "Inserted Faces are " + str(self.curfacen)
        if (self.curfacen < 6):
            self.curface = self.SeqOfFaces[self.curfacen]
            self.setext(self.MapDisedcors[self.curface])     #before reset we need to map U to white as ex
            self.varc.set(self.MapDisedcors[self.curface])
            self.setcolors(self.MapDisedcors[self.curface])
        else:
            self.btinsert["state"]=DISABLED
            self.btsolve["state"]=NORMAL

        print(self.dict)
        pass

    def fd_exit(self):            #exit from the window
        self.master.destroy()
        pass

    def setext(self,txt):
        self.var0.set("White")
        self.var1.set("White")
        self.var2.set("White")
        self.var3.set("White")
        self.var4.set("White")
        self.var5.set("White")
        self.var6.set("White")
        self.var7.set("White")
        self.varc.set(txt)
        pass
    def setcolors(self,color):
        self.W0["bg"] = "white"
        self.W1["bg"] = "white"
        self.W2["bg"] = "white"
        self.W3["bg"] = "white"
        self.W4["bg"] = "white"
        self.W5["bg"] = "white"
        self.W6["bg"] = "white"
        self.W7["bg"] = "white"
        self.center["bg"] = color
        pass

    def fd_solve(self):
        pass

    pass

R=tk.Tk()
app = App(master=R)
faces=app.GetFaces()
app.mainloop()

