# soal-shift-sisop-modul-3-D10-2021

## Soal 3

![WhatsApp Image 2021-05-23 at 20 21 17](https://user-images.githubusercontent.com/77373958/119262794-bce6cc80-bc06-11eb-9e35-4f1a3e494bfc.jpeg)
![WhatsApp Image 2021-05-23 at 20 21 49](https://user-images.githubusercontent.com/77373958/119262796-bfe1bd00-bc06-11eb-8811-caab4a8ad8ac.jpeg)
![WhatsApp Image 2021-05-23 at 20 22 55](https://user-images.githubusercontent.com/77373958/119262798-c07a5380-bc06-11eb-943d-eb774c18fb82.jpeg)
![WhatsApp Image 2021-05-23 at 20 23 37](https://user-images.githubusercontent.com/77373958/119262800-c1ab8080-bc06-11eb-9f5d-494dc839dd7c.jpeg)
![WhatsApp Image 2021-05-23 at 20 27 29](https://user-images.githubusercontent.com/77373958/119262803-c1ab8080-bc06-11eb-9142-c93bfac413d1.jpeg)
![WhatsApp Image 2021-05-23 at 20 29 32](https://user-images.githubusercontent.com/77373958/119262806-c2dcad80-bc06-11eb-94f8-5eed6c5fa329.jpeg)
![WhatsApp Image 2021-05-23 at 20 31 34](https://user-images.githubusercontent.com/77373958/119262808-c2dcad80-bc06-11eb-8868-527c25792f85.jpeg)
![WhatsApp Image 2021-05-23 at 20 33 22](https://user-images.githubusercontent.com/77373958/119262809-c3754400-bc06-11eb-85f9-d6fb9db910d7.jpeg)
![WhatsApp Image 2021-05-23 at 20 33 59](https://user-images.githubusercontent.com/77373958/119262811-c40dda80-bc06-11eb-8e7a-85184446aa4d.jpeg)
![Capture](https://user-images.githubusercontent.com/77373958/119262840-e4d63000-bc06-11eb-8e86-6ff8ac17a184.JPG)


Pada soal nomer 3, kita membuat program C, yang jika dirun akan mengkategorikan file-file yang ada pada path yang sama dengan program tersebut ke folder-folder sesuai ekstensinya. Semisal program C akan dimasukkan ke path bernama C, dan sebagainya. Dari pokok tersebut, beberapa variasi yang ada seperti :

### A. Jika diberikan opsi -f, maka dapat input argumen yang berisi file yang akan dikategorikan

Dengan menginputkan -f, maka user dapat menginput beberapa argumen yang berisi file yang akan dikategorikan. Bisa lebih dari satu. Jadi, di program nantinya argumen diterima dalam bentuk argv[argc], dengan argv[0] yaitu nama program, dan argv[1] yaitu -f. Nantinya akan dicek, apabila argv[1] adalah -f, maka akan menginput setiap argumen selanjutnya dimulai dari argumen ke dua.

Setiap file akan dimasukkan ke folder sesuai ekstensinya. Kita harus mengecek string ekstensinya, menggunakan strtok. Setelah mendapat nama ekstensi, kita perlu tahu apakah path dengan nama ekstensi tersebut sudah ada atau tidak. Jika tidak ada, maka membuat folder baru. Setelah itu, file akan dipindah dengan menggunakan rename.

### B. Jika diberikan opsi -d, maka dapat input satu argumen yang berisi folder/path yang isinya akan dikategorikan.

Dengan menginputkan -d, maka user dapat menginput satu argumen yang berupa path yang ada pada satu path dengan program. Hal yang dilakukan adalah mengkategorikan semua file pada path tersebut. Yang dilakukan adalah mengecek semua file yang ada pada path tersebut, kemudian pada setiap file, akan dimasukkan fungsi pindah yang sama dengan soal nomer 1.

### C. Jika diberikan opsi *, maka dapat mengkategorikan semua file yang ada pada path yang sama.

Jika input *, maka semua file pada ekstensi tersebut akan dikategorikan. Caranya sama dengan B, perbedaannya adalah pengganti dari argumen pathnya adalah letak dari path dari program itu sendiri.

### D. Jika filenya hidden, maka dimasukkan ke folder "Hidden", dan jika tidak memiliki ekstensi, maka dimasukkan ke folder "Unknown".

File-file tersebut memiliki nama yang berbeda dengan file biasa. Jika tidak memiliki ekstensi, maka berarti nama file tidak memiliki titik (dot), atau tidak ada string lanjutan setelah titik. Jika file hidden, maka terdapat char (.) pada stringnya, dan letaknya terletak pada yang paling awal. Karena itu, pada fungsi pindah, akan dibedakan mana yang merupakan file tanpa ekstensi, file biasa, dan file hidden.

### E. Semua dilakukan pada thread

Pada setiap pemindahan yang dilakukan, akan dilakukan oleh masing-masig thread.

Kendala yang dialami :
-Anggota yang tidak ambil bagian
-Kurang terbiasa mengakses file dengan C
-Error segmentation fault
-Terkadang error ketika mencoba menggabungkan/memisahkan string
