
class barang:
  def __init__(self):
    self.nama = ""
    self.harga = 0
    #self.total = 0
    self.topping = []

  def setNama(self, nama):
    self.nama = nama

  #def setJumlah(self, jumlah):
    #self.jumlah = jumlah

  def setHarga(self, harga):
    self.harga = harga

  def reset(self):
    self.jumlah = 0
    self.total = 0
    self.harga = 0

  #def totalHarga(self):
    #return self.jumlah * self.harga
  
  def addTopping(self, topping, hargaTopping):
    self.topping.append(topping)
    self.harga = self.harga + hargaTopping



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
  for i in range(len(string)):
    letter = string[i]
    # Dari state initial (q0)
    if nfa.current_state == 0: 
      if letter == 'a': # Kalo milih nasgor
        nfa.current_state = 1
        nasgor = barang()
        nasgor.setNama = 'Nasi Goreng'
        nasgor.setHarga = 15000

      if letter == 'b': # kalo milih mie
        nfa.current_state = 2
      if letter == 'c': # Kalo milih daging(?)
        nfa.current_state = 3
      if letter == 'd': # Kalo milih Fuyung hai
        nfa.current_state = 4
      if letter == 'e': # Kalo milih sayur
        nfa.current_state = 5
    # Dari state sudah milih nasgor dan sekarang milih topping nasgor
    if nfa.current_state == 1:
      if letter == 'j':
        nfa.current_state = 6
        nasgor.addTopping("Telur", 5000) ## Tambah topping ke nasgor, harga telor 5000
      if letter == 'k':
        nfa.current_state = 7
        nasgor.addTopping("Ayam", 5000)
      if letter == 'l':
        nfa.current_state = 8
        nasgor.addTopping("Udang", 5000)
      if letter == 'm':
        nfa.current_state = 9
        nasgor.addTopping("Sapi", 5000)
      if letter == 'V':
        nfa.current_state = 36

    # Dari state udah milih mie sekarang mau milih mie apa
    if nfa.current_state == 2:
      if letter == 'A':
        nfa.current_state = 11
        mie = barang()
        mie.setNama("Mie Kuah")
        mie.setHarga(7000)

      if letter == 'B':
        nfa.current_state = 12
        mie = barang()
        mie.setNama("Mie Goreng")
        mie.setHarga(7000)

      if letter == 'C':
        nfa.current_state = 13
        mie = barang()
        mie.setNama("Kwetiau")
        mie.setHarga(16000)

      if letter == 'D':
        nfa.current_state = 14
        mie = barang()
        mie.setNama("Bihun")
        mie.setHarga(7000)

      if letter == 'E':
        nfa.current_state = 15
        mie = barang()
        mie.setNama("I Fu Mie")
        mie.setHarga(7000)

    # Milih topping setelah milih jenis mie kuah
    if nfa.current_state == 11:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping setelah milih jenis mie goreng
    if nfa.current_state == 12:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping setelah milih jenis mie kwetiau
    if nfa.current_state == 13:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping setelah milih jenis mie bihun
    if nfa.current_state == 14:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping stelah milih jenis mie i fu mie
    if nfa.current_state == 15:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
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
      if letter == 'G':
        nfa.current_state = 21
      if letter == 'H':
        nfa.current_state = 22

    # Udah milih daging sapi
    if nfa.current_state == 17:
      if letter == 'I':
        nfa.current_state = 23
      if letter == 'J':
        nfa.current_state = 24
      if letter == 'K':
        nfa.current_state = 25

    # Udah milih daging cumi
    if nfa.current_state == 18:
      if letter == 'L':
        nfa.current_state = 26
      if letter == 'M':
        nfa.current_state = 27
      if letter == 'N':
        nfa.current_state = 28

    # Udah milih daging udang
    if nfa.current_state == 19:
      if letter == 'O':
        nfa.current_state = 29
      if letter == 'P':
        nfa.current_state = 30
      if letter == 'Q':
        nfa.current_state = 31

    # Milih fuyunghay
    if nfa.current_state == 4:
      if letter == 'V':
        nfa.current_state = 36

    # Milih sayur
    if nfa.current_state == 5:
      if letter == 'R':
        nfa.current_state = 32
      if letter == 'S':
        nfa.current_state = 33
      if letter == 'T':
        nfa.current_state = 34
      if letter == 'U':
        nfa.current_state = 35

    # Milih topping setelah milih sayur hijau
    if nfa.current_state == 32:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping setelah milih capcay
    if nfa.current_state == 33:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping setelah milih Buncis
    if nfa.current_state == 34:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    # Milih topping setelah milih Kangkung
    if nfa.current_state == 35:
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9
      if letter == 'V':
        nfa.current_state = 36

    if nfa.current_state == 6:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9

    if nfa.current_state == 7:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'l':
        nfa.current_state = 8
      if letter == 'm':
        nfa.current_state = 9

    if nfa.current_state == 8:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'm':
        nfa.current_state = 9

    if nfa.current_state == 9:
      if letter == 'V':
        nfa.current_state = 36
      if letter == 'j':
        nfa.current_state = 6
      if letter == 'k':
        nfa.current_state = 7
      if letter == 'l':
        nfa.current_state = 8

    if nfa.current_state == 36:
      if letter == 'y':
        nfa.current_state = 37
      if letter == 'x':
        nfa.current_state = 38
      
    if nfa.current_state in {37, 38}:
      if letter == 'z':
        nfa.current_state = 39
      if letter == '0':
        nfa.current_state = 40

    if nfa.current_state == 40:
      if letter == 'V':
        nfa.current_state = 41
      if letter == 'Z':
        nfa.current_state = 39
      if letter == 'Y':
        nfa.current_state = 0

    if nfa.current_state == 41:
      if letter == 'q':
        nfa.current_state = 42
      if letter == 'r':
        nfa.current_state = 43
      if letter == 's':
        nfa.current_state = 44
      if letter == 't':
        nfa.current_state = 45

    if nfa.current_state == 42:
      if letter == 'x':
        nfa.current_state = 47
      if letter == 'y':
        nfa.current_state = 48

    if nfa.current_state == 43:
      if letter == 'x':
        nfa.current_state = 47
      if letter == 'y':
        nfa.current_state = 48

    if nfa.current_state == 44:
      if letter == 'x':
        nfa.current_state = 47
      if letter == 'y':
        nfa.current_state = 48

    if nfa.current_state == 45:
      if letter == 'x':
        nfa.current_state = 47
      if letter == 'y':
        nfa.current_state = 48

    if nfa.current_state == 47:
      if letter == 'z':
        nfa.current_state = 40

    if nfa.current_state == 48:
      nfa.current_state = 40

  if nfa.current_state in nfa.final_states:
    return order_list
  else:
    return None