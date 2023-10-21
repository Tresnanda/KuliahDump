
class barang:
  def __init__(self):
    self.nama = ""
    self.harga = 0
    self.pedas = 0
    self.topping = []

  def setNama(self, nama):
    self.nama = nama

  #def setJumlah(self, jumlah):
    #self.jumlah = jumlah

  def setHarga(self, harga):
    self.harga = harga

  def reset(self):
    self.nama = "a"
    self.harga = 0
    self.pedas = 0
    #self.total = 0
    self.topping = []

  #def totalHarga(self):
    #return self.jumlah * self.harga
  
  def addTopping(self, topping, hargaTopping):
    self.topping.append(topping)
    self.harga = self.harga + hargaTopping
  def setPedas(self, pedas):
    self.pedas = pedas

  def printDetail(self):
    print(self.nama)
    print(self.harga)
    print(self.topping)
    print(self.pedas)

class minuman:
  def __init__(self):
    self.nama = ""
    self.harga = 0
    self.dingin = 0

  def setNama(self, nama):
    self.nama = nama

  def setHarga(self, harga):
    self.harga = harga
  
  def setDingin(self, dingin):
    self.dingin = dingin

  def reset(self):
    self.nama = ""
    self.harga = 0
    self.dingin = 0

  def printDetail2(self):
    print(self.nama)
    print(self.harga)
    print(self.dingin)
    



class NFA:
  def __init__(self):
    self.final_states = []
    self.initial_state = 0
    self.current_state = 0
    self.prev_state = 0

  def setFinal_states(self, final_states):
    for state in final_states:
      self.final_states.append(state)


def automata(nfa, string):
  # Deklarasi jenis barang
  order_list = []
  for letter in string:


    # Dari state initial (q0)
    if nfa.current_state == 0: 
      current_order = barang()
      #current_order.reset()
      if letter == 'a': # Kalo milih nasgor
        nfa.current_state = 1
        current_order.setNama("Nasi Goreng")
        current_order.setHarga(15000)

      if letter == 'b': # kalo milih mie
        nfa.current_state = 2
      if letter == 'c': # Kalo milih daging(?)
        nfa.current_state = 3
      if letter == 'd': # Kalo milih Fuyung hai
        current_order.setNama("Fuyung Hay")
        current_order.setHarga(15000)
        nfa.current_state = 4
      if letter == 'e': # Kalo milih sayur
        nfa.current_state = 5
    # Dari state sudah milih nasgor dan sekarang milih topping nasgor
    if nfa.current_state == 1:
      if letter == 'j':
        nfa.current_state = 6
        current_order.addTopping("Telur", 5000) ## Tambah topping ke nasgor, harga telor 5000
      if letter == 'k':
        nfa.current_state = 7
        current_order.addTopping("Ayam", 5000)
      if letter == 'l':
        nfa.current_state = 8
        current_order.addTopping("Udang", 5000)
      if letter == 'm':
        nfa.current_state = 9
        current_order.addTopping("Sapi", 5000)
      if letter == 'V':
        nfa.current_state = 36

    # Dari state udah milih mie sekarang mau milih mie apa
    if nfa.current_state == 2:
      if letter == 'A':
        nfa.current_state = 11
        current_order.setNama("Mie Kuah")
        current_order.setHarga(7000)

      if letter == 'B':
        nfa.current_state = 12
        current_order.setNama("Mie Goreng")
        current_order.setHarga(7000)

      if letter == 'C':
        nfa.current_state = 13
        current_order.setNama("Kwetiau")
        current_order.setHarga(16000)

      if letter == 'D':
        nfa.current_state = 14
        current_order.setNama("Bihun")
        current_order.setHarga(7000)

      if letter == 'E':
        nfa.current_state = 15
        current_order.setNama("I Fu Mie")
        current_order.setHarga(7000)

    # Milih topping setelah milih jenis mie kuah
    if nfa.current_state in {11, 12, 13, 14, 15}:
      if letter == 'j':
        nfa.current_state = 6
        current_order.addTopping("Telur", 5000)
      if letter == 'k':
        nfa.current_state = 7
        current_order.addTopping("Ayam", 5000)
      if letter == 'l':
        nfa.current_state = 8
        current_order.addTopping("Udang", 5000)
      if letter == 'm':
        nfa.current_state = 9
        current_order.addTopping("Sapi", 5000)
      if letter == 'V':
        nfa.current_state = 36

    # Milih daging
    if nfa.current_state == 3:
      if letter == 'f':
        nfa.current_state = 16
      if letter == 'g':
        nfa.current_state = 17
      if letter == 'h':
        nfa.current_state = 18
      if letter == 'i':
        nfa.current_state = 19

    # Udah milih daging ayam
    if nfa.current_state == 16:
      if letter == 'F':
        nfa.current_state = 20
        current_order.setNama("Ayam Mentega")
        current_order.setHarga(15000)
      if letter == 'G':
        nfa.current_state = 21
        current_order.setNama("Ayam Lada Hitam")
        current_order.setHarga(15000)
      if letter == 'H':
        nfa.current_state = 22
        current_order.setNama("Chicken Katsu")
        current_order.setHarga(15000)

    # Udah milih daging sapi
    if nfa.current_state == 17:
      if letter == 'I':
        nfa.current_state = 23
        current_order.setNama("Sapi Mentega")
        current_order.setHarga(15000)
      if letter == 'J':
        nfa.current_state = 24
        current_order.setNama("Sapi Lada Hitam")
        current_order.setHarga(15000)
      if letter == 'K':
        nfa.current_state = 25
        current_order.setNama("Sapi Cah Paprika")
        current_order.setHarga(15000)

    # Udah milih daging cumi
    if nfa.current_state == 18:
      if letter == 'L':
        nfa.current_state = 26
        current_order.setNama("Cumi Goreng Tepung")
        current_order.setHarga(15000)
      if letter == 'M':
        nfa.current_state = 27
        current_order.setNama("Cumi Mentega")
        current_order.setHarga(15000)
      if letter == 'N':
        nfa.current_state = 28
        current_order.setNama("Cumi Asam Manis")
        current_order.setHarga(15000)

    # Udah milih daging udang
    if nfa.current_state == 19:
      if letter == 'O':
        nfa.current_state = 29
        current_order.setNama("Udang Goreng Tepung")
        current_order.setHarga(15000)
      if letter == 'P':
        nfa.current_state = 30
        current_order.setNama("Udang Mentega")
        current_order.setHarga(15000)
      if letter == 'Q':
        nfa.current_state = 31
        current_order.setNama("Udang Asam Manis")
        current_order.setHarga(15000)
 
    if nfa.current_state in {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31}:
      if letter == 'V':
        nfa.current_state = 36
    # Milih fuyunghay
    if nfa.current_state == 4:
      if letter == 'V':
        nfa.current_state = 36

    # Milih sayur
    if nfa.current_state == 5:
      if letter == 'R':
        nfa.current_state = 32
        current_order.setNama("Sayur Hijau")
        current_order.setHarga(5000)
      if letter == 'S':
        nfa.current_state = 33
        current_order.setNama("Capcay")
        current_order.setHarga(5000)
      if letter == 'T':
        nfa.current_state = 34
        current_order.setNama("Buncis")
        current_order.setHarga(5000)
      if letter == 'U':
        nfa.current_state = 35
        current_order.setNama("Kangkung")
        current_order.setHarga(5000)

    # Milih topping setelah milih sayur hijau
    if nfa.current_state in {32, 33, 34, 35}:
      if letter == 'j':
        nfa.current_state = 6
        current_order.addTopping("Telur", 5000)
      if letter == 'k':
        nfa.current_state = 7
        current_order.addTopping("Ayam", 5000)
      if letter == 'l':
        nfa.current_state = 8
        current_order.addTopping("Udang", 5000)
      if letter == 'm':
        nfa.current_state = 9
        current_order.addTopping("Sapi", 5000)
      if letter == 'V':
        nfa.current_state = 36

    if nfa.current_state == 6:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'k':
        nfa.current_state = 7
        current_order.addTopping("Ayam", 5000)
      if letter == 'l':
        nfa.current_state = 8
        current_order.addTopping("Udang", 5000)
      if letter == 'm':
        nfa.current_state = 9
        current_order.addTopping("Sapi", 5000)

    if nfa.current_state == 7:
      if letter == 'V':
        nfa.current_state = 36
        current_order.addTopping("Telur", 5000)
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'l':
        nfa.current_state = 8
        current_order.addTopping("Udang", 5000)
      if letter == 'm':
        nfa.current_state = 9
        current_order.addTopping("Sapi", 5000)

    if nfa.current_state == 8:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'j':
        nfa.current_state = 6
        current_order.addTopping("Telur", 5000)
      if letter == 'k':
        nfa.current_state = 7
        current_order.addTopping("Ayam", 5000)
      if letter == 'm':
        nfa.current_state = 9
        current_order.addTopping("Sapi", 5000)

    if nfa.current_state == 9:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'j':
        nfa.current_state = 6
        current_order.addTopping("Telur", 5000)
      if letter == 'k':
        nfa.current_state = 7
        current_order.addTopping("Ayam", 5000)
      if letter == 'l':
        nfa.current_state = 8
        current_order.addTopping("Udang", 5000)

    if nfa.current_state == 36:
      if letter == 'y':
        nfa.current_state = 37
        current_order.setPedas(1)
      if letter == 'x':
        nfa.current_state = 38
        current_order.setPedas(0)
      
    if nfa.current_state in {37, 38}:
      #if letter == 'z':
        #nfa.current_state = 39
      if letter == '0':
        nfa.current_state = 40
        order_list.append(current_order)
        #current_order.reset()

    if nfa.current_state == 40:
      if letter == 'V':
        nfa.current_state = 41
      if letter == 'Z':
        nfa.current_state = 39
      if letter == 'Y':
        nfa.current_state = 0
      #order_list.append(current_minuman)

    if nfa.current_state == 41:
      current_minuman = minuman()
      if letter == 'q':
        nfa.current_state = 42
        current_minuman.setNama("Teh")
        current_minuman.setHarga(5000)
      if letter == 'r':
        nfa.current_state = 43
        current_minuman.setNama("Jeruk")
        current_minuman.setHarga(5000)
      if letter == 's':
        nfa.current_state = 44
        current_minuman.setNama("Air Mineral")
        current_minuman.setHarga(5000)
      if letter == 't':
        nfa.current_state = 45
        current_minuman.setNama("Kopi")
        current_minuman.setHarga(5000)

    if nfa.current_state in {42, 43, 44, 45}:
      if letter == 'x':
        nfa.current_state = 47
        current_minuman.setDingin(1)
      if letter == 'y':
        nfa.current_state = 48
        current_minuman.setDingin(0)

    if nfa.current_state in {47, 48}:
      if letter == 'z':
        nfa.current_state = 40
        order_list.append(current_minuman)
        #current_minuman.reset()

  if nfa.current_state in nfa.final_states:
    return order_list
  else:
    return None