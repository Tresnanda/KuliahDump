from modules.module import *
a = NFA()
a.setFinal_states({39})

#tes = automata(a, 'bAjlVx0VqxzZ')
tes = automata(a, 'ajVyVYbAVxVUqxzUsyzZ')
#tes = automata(a, 'cgJVx0Z')
if tes is not None:
    harga_total = 0
    for item in tes:
        if isinstance(item, barang):
            harga_total += item.harga
            print(f"Food: {item.nama}")
            print(f"Harga: {item.harga}")
            if item.topping:
                print(f"Topping: {', '.join(item.topping)}")
            else:
                print("Topping: Tanpa Topping")
            print(f"Pedas: {'Ya' if item.pedas else 'Tidak'}")
        elif isinstance(item, minuman): 
            harga_total += item.harga
            print(f"Beverage: {item.nama}")
            print(f"Harga: {item.harga}")
            print(f"Dingin: {'Ya' if item.dingin else 'Tidak'}")
        print("")

    print("Total harga pesanan:", harga_total)
else:
    print("Input Illegal wak")