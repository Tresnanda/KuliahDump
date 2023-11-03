from customtkinter import *
from PIL import Image
from modules.module import *

# class ScrollableButtonFrame(CTkScrollableFrame):
#     def __init__(self, master, command=None, **kwargs):
#         super().__init__(master, **kwargs)
#         self.grid_columnconfigure(0, weight=1)

#         self.command = command
#         self.radiobutton_variable = StringVar()
#         self.label_list = []
#         self.button_list = []

#     def add_item(self, item, image=None):
#         label = CTkLabel(self, text=item, image=image, compound="left", padx=5, anchor="w")
#         button = CTkButton(self, text="Command", width=100, height=24)
#         if self.command is not None:
#             button.configure(command=lambda: self.command(item))
#         label.grid(row=len(self.label_list), column=0, pady=(0, 10), sticky="w")
#         button.grid(row=len(self.button_list), column=1, pady=(0, 10), padx=5)
#         self.label_list.append(label)
#         self.button_list.append(button)

string = ''
kepedasan = ''

# def combo_handler(choice):
#     global string
#     if(choice == 'Nasi Goreng'):


def next_handler(combobox, combobox2, asd, main):
    choice = combobox.get()
    kepedasan_choice = combobox2.get()

    global string
    if choice == 'Nasi Goreng':
        string += 'a'
    elif choice == 'Mie Kuah':
        string += 'bA'
    elif choice == 'Mie Goreng':
        string += 'bB'
    elif choice == 'Kwetiau':
        string += 'bC'
    elif choice == 'Bihun':
        string += 'bD'
    elif choice == 'Ifumie':
        string += 'bE'
    elif choice == 'Ayam Mentega':
        string += 'cfF'
    elif choice == 'Ayam Lada Hitam':
        string += 'cfG'
    elif choice == 'Chicken Katsu':
        string += 'cfH'
    elif choice == 'Sapi Mentega':
        string += 'cgI'
    elif choice == 'Sapi Lada Hitam':
        string += 'cgJ'
    elif choice == 'Sapi Cah Paprika':
        string += 'cgK'
    elif choice == 'Cumi Goreng Tepung':
        string += 'chL'
    elif choice == 'Cumi Mentega':
        string += 'chM'
    elif choice == 'Cumi Asam Manis':
        string += 'chN'
    elif choice == 'Udang Goreng Tepung':
        string += 'ciO'
    elif choice == 'Udang Mentega':
        string += 'ciP'
    elif choice == 'Udang Asam Manis':
        string += 'ciQ'
    elif choice == 'Fuyunghai':
        string += 'd'
    elif choice == 'Sayur Hijau':
        string += 'eR'
    elif choice == 'Cap Cay':
        string += 'eS'
    elif choice == 'Buncis':
        string += 'eT'
    elif choice == 'Kangkung':
        string += 'eU'

    if string[0] in {'a', 'b', 'e'}:
        topping_page(asd, kepedasan_choice, main)
    elif string[0] in {'c', 'd'}:
        string += 'V'
        if(kepedasan_choice == 'Pedas'):
            string += 'y'
        elif(kepedasan_choice == 'TIdak'):
            string += 'x'
        string += 'V'
        drink_page(asd, main)
def topping_next(asd, kepedasan_choice, telor_checkbox, ayam_checkbox, udang_checkbox, sapi_checkbox, main):
    global string
    ayam_choice = ayam_checkbox.get()
    udang_choice = udang_checkbox.get()
    telor_choice = telor_checkbox.get()
    sapi_choice = sapi_checkbox.get()

    if telor_choice == 'on':
        string += 'j'
    if ayam_choice == 'on':
        string += 'k'
    if udang_choice == 'on':
        string += 'l'
    if sapi_choice == 'on':
        string += 'm'

    string += 'V'
    if kepedasan_choice == 'Pedas':
        string += 'yV'
    if kepedasan_choice == 'Tidak':
        string += 'xV'
    drink_page(asd, main)

def food_page(asd, main):
    asd.destroy()
    app = CTkToplevel()
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
    app.geometry(f"{500}x{600}")
    x = (screen_width - 500) // 2
    y = (screen_height - 600) // 2
    app.geometry(f"+{x}+{y}")
    app.resizable(0, 0)
    app.configure(fg_color='white')
    font = CTkFont("SF Pro Rounded", 50)
    font2 = CTkFont("SF Pro Text", 20)

    bg_data = Image.open('img/food_menu.png')
    bg = CTkImage(light_image=bg_data, size=(500, 600))
    CTkLabel(master= app, text='', image=bg,).place(x=0, y=0)

    next_data = Image.open("img/next_button.png")
    next_button = CTkImage(light_image=next_data, size=(336, 140))
    # frame = CTkScrollableFrame(master=app, width=400, height=1000, fg_color='white')
    # button1 = CTkButton(master=frame, text='', image=food_button, fg_color='transparent')
    # button2 = CTkButton(master=frame, text='button 2')
    # button1.pack(pady=10)
    # frame.pack(pady=180)

    combobox = CTkComboBox(master = app, values = ['Nasi Goreng', 'Fuyunghai', 'Mie Kuah', 'Mie Goreng', 'Kwetiau', 'Bihun', 'Ifumie', 'Ayam Mentega', 'Ayam Lada Hitam', 'Chicken Katsu', 
                                                   'Sapi Mentega', 'Sapi Lada Hitam', 'Sapi Cah Paprika', 'Cumi Goreng Tepung', 'Cumi Mentega', 'Cumi Asam Manis', 'Udang Goreng Tepung',
                                                   'Udang Mentega', 'Udang Asam Manis', 'Sayur Hijau', 'Cap Cay', 'Buncis', 'Kangkung'], width=400, 
                                                   border_color='#FF4B3A', button_color='#FF4B3A', font=font2, dropdown_font=font2, dropdown_fg_color='white',
                                                   dropdown_hover_color='#FF4B3A', height=50)
    combobox.pack(pady=250)

    combobox2 = CTkComboBox(master = app, values = ['Pedas', 'Tidak'], width=400, 
                                                   border_color='#FF4B3A', button_color='#FF4B3A', font=font2, dropdown_font=font2, dropdown_fg_color='white',
                                                   dropdown_hover_color='#FF4B3A', height=50)
    combobox2.place(x=50, y=350)
    button_next = CTkButton(master=app, text='', image=next_button, fg_color='transparent', hover=False, command=lambda: (next_handler(combobox, combobox2, app, main)))
    button_next.tkraise()
    button_next.place(x=82, y=440)
    

    # frame = ScrollableButtonFrame(master=self, width=400)


    app.mainloop()

def topping_page(asd, kepedasan_choice, main):
    asd.destroy()
    app = CTkToplevel()
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
    app.geometry(f"{700}x{600}")
    x = (screen_width - 700) // 2
    y = (screen_height - 600) // 2
    app.geometry(f"+{x}+{y}")
    app.resizable(0, 0)
    app.configure(fg_color='white')
    font = CTkFont("SF Pro Rounded", 50)
    font2 = CTkFont("SF Pro Text", 20)

    bg_data = Image.open('img/topping_list.png')
    bg = CTkImage(light_image=bg_data, size=(500, 600))
    CTkLabel(master= app, text='', image=bg,).place(x=100, y=0)

    next_data = Image.open("img/next_button.png")
    next_button = CTkImage(light_image=next_data, size=(336, 140))
    telor_data = Image.open('img/telor.png')
    telor = CTkImage(light_image=telor_data, size=(150, 150))
    ayam_data = Image.open('img/ayam.png')
    ayam = CTkImage(light_image=ayam_data, size=(150, 150))
    udang_data = Image.open('img/udang.png')
    udang = CTkImage(light_image=udang_data, size=(150, 150))
    sapi_data = Image.open('img/sapi.png')
    sapi = CTkImage(light_image=sapi_data, size=(150, 150))
    CTkLabel(master=app, text='', image=telor).place(x=20, y=200) ### Gambar Telor
    CTkLabel(master=app, text='', image=ayam).place(x=190, y=200) ### Gambar Ayam
    CTkLabel(master=app, text='', image=udang).place(x=360, y=200) ### Gambar Udang
    CTkLabel(master=app, text='', image=sapi).place(x=530, y=200) ### Gambar Udang

    telor_checkboxvar = StringVar(value='off')
    telor_checkbox = CTkCheckBox(master=app, onvalue='on', offvalue='off', border_color='#FF4B3A', text='', fg_color='#FF4B3A', variable=telor_checkboxvar)
    telor_checkbox.place(x=85, y=370)

    ayam_checkboxvar = StringVar(value='off')
    ayam_checkbox = CTkCheckBox(master=app, onvalue='on', offvalue='off', border_color='#FF4B3A', text='', fg_color='#FF4B3A', variable=ayam_checkboxvar)
    ayam_checkbox.place(x=255, y=370)

    udang_checkboxvar = StringVar(value='off')
    udang_checkbox = CTkCheckBox(master=app, onvalue='on', offvalue='off', border_color='#FF4B3A', text='', fg_color='#FF4B3A', variable=udang_checkboxvar)
    udang_checkbox.place(x=425, y=370)

    sapi_checkboxvar = StringVar(value='off')
    sapi_checkbox = CTkCheckBox(master=app, onvalue='on', offvalue='off', border_color='#FF4B3A', text='', fg_color='#FF4B3A', variable=sapi_checkboxvar)
    sapi_checkbox.place(x=595, y=370)

    
    button_next = CTkButton(master=app, text='', image=next_button, fg_color='transparent', hover=False, command=lambda: (topping_next(app, kepedasan_choice, 
                                                                                                                                       telor_checkbox, ayam_checkbox, udang_checkbox, sapi_checkbox, main)))
    button_next.tkraise()
    button_next.place(x=182, y=400)

    app.mainloop()

def drink_page(asd, main):
    asd.destroy()
    app = CTkToplevel()
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
    app.geometry(f"{500}x{600}")
    x = (screen_width - 500) // 2
    y = (screen_height - 600) // 2
    app.geometry(f"+{x}+{y}")
    app.resizable(0, 0)
    app.configure(fg_color='white')
    font = CTkFont("SF Pro Rounded", 50)
    font2 = CTkFont("SF Pro Text", 20)

    bg_data = Image.open('img/drink_menu.png')
    bg = CTkImage(light_image=bg_data, size=(500, 600))
    CTkLabel(master= app, text='', image=bg,).place(x=0, y=0)

    next_data = Image.open("img/next_button.png")
    next_button = CTkImage(light_image=next_data, size=(336, 140))
    # frame = CTkScrollableFrame(master=app, width=400, height=1000, fg_color='white')
    # button1 = CTkButton(master=frame, text='', image=food_button, fg_color='transparent')
    # button2 = CTkButton(master=frame, text='button 2')
    # button1.pack(pady=10)
    # frame.pack(pady=180)

    combobox = CTkComboBox(master = app, values = ['Tanpa Minuman', 'Teh', 'Minuman Jeruk', 'Air Mineral', 'Kopi'], width=400, 
                                                border_color='#FF4B3A', button_color='#FF4B3A', font=font2, dropdown_font=font2, dropdown_fg_color='white',
                                                dropdown_hover_color='#FF4B3A', height=50)
    combobox.pack(pady=250)

    combobox2 = CTkComboBox(master = app, values = ['Dingin', 'Tidak'], width=400, 
                                                   border_color='#FF4B3A', button_color='#FF4B3A', font=font2, dropdown_font=font2, dropdown_fg_color='white',
                                                   dropdown_hover_color='#FF4B3A', height=50)
    combobox2.place(x=50, y=350)
    button_next = CTkButton(master=app, text='', image=next_button, fg_color='transparent', hover=False, command=lambda: (drink_next(combobox, combobox2, app, main)))
    button_next.tkraise()
    button_next.place(x=82, y=400)

def drink_next(combobox, combobox2, asd, main):
    global string
    drink_choice = combobox.get()
    dingin_choice = combobox2.get()

    if drink_choice == 'Teh':
        string += 'Wq'
    if drink_choice == 'Minuman Jeruk':
        string += 'Wr'
    if drink_choice == 'Air Mineral':
        string += 'Ws'
    if drink_choice == 'Kopi':
        string += 'Wt'

    if drink_choice != 'Tanpa Minuman':
        if dingin_choice == 'Dingin':
            string += 'yz'
        elif dingin_choice == 'Tidak':
            string += 'xz'

    asd.destroy()
    app = CTkToplevel()
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
    app.geometry(f"{370}x{600}")
    x = (screen_width - 370) // 2
    y = (screen_height - 600) // 2
    app.geometry(f"+{x}+{y}")
    app.resizable(0, 0)
    app.configure(fg_color='#FF4B3A')
    font = CTkFont("SF Pro Rounded Heavy", 50)
    font2 = CTkFont("SF Pro Text", 20)

    text1 = CTkLabel(master = app, text='Add More?', font=font2, text_color='white')
    text1.tkraise()
    text1.pack(pady=30)
    food_data = Image.open('img/food.png')
    food = CTkImage(light_image=food_data, size=(150, 150))
    button1 = CTkButton(master=app, text='', image=food, bg_color='transparent', fg_color='transparent', hover=False, command=lambda: (more_food(app))).pack(pady=10)
    beverage_data = Image.open('img/beverage.png')
    beverage = CTkImage(light_image=beverage_data, size=(150, 150))
    button2 = CTkButton(master=app, text='', image=beverage, fg_color='transparent', hover=False, command=lambda: (drink_page(app, main)))
    button2.tkraise()
    button2.pack(pady=10)

    

    checkout_data = Image.open("img/checkout.png")
    checkout_button = CTkImage(light_image=checkout_data, size=(336, 140))
    button_checkout = CTkButton(master=app, text='', image=checkout_button, fg_color='#FF4B3A', hover=False, command=lambda: (checkout(app, main)))
    button_checkout.tkraise()
    button_checkout.pack(pady=10)

    def more_food(asd):
        global string
        string += 'Y'
        food_page(asd)

    def checkout(asd, main):
        global string
        string += 'Z'
        a = NFA()
        a.setFinal_states({39})
        asd.destroy()
        app = CTkToplevel()
        screen_width = app.winfo_screenwidth()
        screen_height = app.winfo_screenheight()
        app.geometry(f"{370}x{600}")
        x = (screen_width - 370) // 2
        y = (screen_height - 600) // 2
        app.geometry(f"+{x}+{y}")
        app.resizable(0, 0)
        app.configure(fg_color='white')
        font = CTkFont("SF Pro Rounded Heavy", 50)
        font2 = CTkFont("SF Pro Text", 20)

        struk = automata(a, string)

        if struk is not None:
            harga_total = 0

            order_details = ""

            for item in struk:
                if isinstance(item, barang):
                    harga_total += item.harga
                    order_details += f"Food: {item.nama}\n"
                    order_details += f"Harga: {item.harga}\n"
                    if item.topping:
                        order_details += f"Topping: {', '.join(item.topping)}\n"
                    else:
                        order_details += "Topping: Tanpa Topping\n"
                    order_details += f"Pedas: {'Ya' if item.pedas else 'Tidak'}\n"
                elif isinstance(item, minuman):
                    harga_total += item.harga
                    order_details += f"Beverage: {item.nama}\n"
                    order_details += f"Harga: {item.harga}\n"
                    order_details += f"Dingin: {'Ya' if item.dingin else 'Tidak'}\n"
                order_details += "\n"

            order_details += f"Total harga pesanan: {harga_total}"
            
            text_widget = CTkTextbox(app, width=350, height=500, font=font2, fg_color='#FF4B3A', text_color='white')
            text_widget.insert("1.0", order_details)
            text_widget.configure(state="disabled")
            text_widget.pack()

            text2 = CTkButton(master = app, text='Bayar di kasir', font=font2, text_color='white', fg_color='#FF4B3A', hover=False, command=lambda: (exit(app, main)))
            text2.pack(pady = 20)

            
            
            app.mainloop()

        else:
            print("Input ERROR!")
            print(string)

    def exit(asd, app):
        asd.destroy()
        global string
        string = ''
        app.deiconify()


        

    
    
