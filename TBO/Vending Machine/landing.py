from customtkinter import *
from PIL import Image
from orderpage import *

app = CTk()
screen_width = app.winfo_screenwidth()
screen_height = app.winfo_screenheight()
app.geometry("370x600")
x = (screen_width - 370) // 2
y = (screen_height - 600) // 2
app.geometry(f"+{x}+{y}")
app.resizable(0, 0)
app.title("Vending Machine Warung Bejo")
app.configure(fg_color='#FF4B3A')
set_appearance_mode("light")

bg_data = Image.open("img/bg.png")
bg = CTkImage(light_image=bg_data, size=(370, 600))
CTkLabel(master=app, text='', image=bg).place(x=0,y=-20)
font = CTkFont("Bahnschrift", 40)

text = CTkLabel(master=app, text='Chinese Food', font=font, text_color='white', anchor='w', justify='left')
text2 = CTkLabel(master=app, text='For Everyone.', font=font, text_color='white', anchor='w', justify='left')
#text.text_label.place(relx=0, anchor='w')
text.tkraise()
text2.tkraise()
text.place(x=33,y=140)
text2.place(x=33, y=180)
font2 = CTkFont("SF Pro Text", 20)
font3 = CTkFont("SF Pro Text", 40)


bejo = CTkLabel(master=app, text='Dapoer', font=font3, fg_color='white', text_color = '#FF4B3A', corner_radius=0, width=250, anchor='w', justify='right')
bejo.tkraise()
bejo.place(x=210, y=6)

bejo2 = CTkLabel(master=app, text='Bejo', font=font3, fg_color='white', text_color = '#FF4B3A', corner_radius=0, width=250, anchor='w', justify='right')
bejo2.tkraise()
bejo2.place(x=267, y=60)
#bejo.pack(pady=6, padx=30)

muka1_data= Image.open("img/muka4.png")
muka1 = CTkImage(light_image=muka1_data, size=(370, 360))
CTkLabel(master=app, text='', image=muka1).place(x=0, y=280)

# def a(asd, app2):
#     app2.destroy()

# def button_handler(asd):
#     order_page(asd)
#     #order_page.mainloop()
    
    

button1 = CTkButton(master=app, text='Get Started', fg_color='white', font=font2, text_color='#FF460A', width=250, height=50, hover_color='#ffe6de', command=lambda: order_page(app))
button1.tkraise()
button1.place(y=520, x=59)

app.mainloop()