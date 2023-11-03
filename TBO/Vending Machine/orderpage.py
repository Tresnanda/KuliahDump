from customtkinter import *
from PIL import Image
from food_page import *


def order_page(asd):
    asd.iconify()
    app = CTkToplevel()
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
    app.geometry(f"{370}x{600}")
    x = (screen_width - 370) // 2
    y = (screen_height - 600) // 2
    app.geometry(f"+{x}+{y}")
    app.resizable(0, 0)
    #app.configure(fg_color='#ececec')
    app.configure(fg_color='#FF4B3A')
    font = CTkFont("SF Pro Rounded Heavy", 50)
    font2 = CTkFont("SF Pro Text", 20)
    #bg_data = Image.open('img/order_bg.png')
    #bg = CTkImage(light_image=bg_data, size=(800, 600))
    #CTkLabel(master=app, text='', image=bg, ).place(x=0,y=-30)
    #header = CTkLabel(master=app, text='What do you want to order?', font=font, text_color='#FF4B3A', bg_color='white').pack(pady=10)

    text1 = CTkLabel(master = app, text='What would you like?', font=font2, text_color='white')
    text1.tkraise()
    text1.pack(pady=30)
    food_data = Image.open('img/food.png')
    food = CTkImage(light_image=food_data, size=(200, 200))
    button1 = CTkButton(master=app, text='', image=food, bg_color='transparent', fg_color='transparent', hover=False, command=lambda: (food_page(app, asd))).pack(pady=30)
    beverage_data = Image.open('img/beverage.png')
    beverage = CTkImage(light_image=beverage_data, size=(200, 200))
    button2 = CTkButton(master=app, text='', image=beverage, fg_color='transparent', hover=False, command=lambda: (drink_page(app, asd)))
    button2.tkraise()
    button2.pack(pady=25)
    app.mainloop()

