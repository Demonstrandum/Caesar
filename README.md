# Caesar
Simple Caesar/rot cipher written in C++

Translates any text given (latin alphabet only) from a command line argument or from a file. Supports and keeps whitespace formatting (tabs, spaces, etc...) as well as special characters (punctuation and such), and guards the capitalisation/case of the letters.

### Installation:
In your terminal, clone and cd into the repository:<br />
`git clone https://github.com/Demonstrandum/Caesar && cd Caesar`<br />
Then run the make file by typing: `make`<br />
Then `make install`, you might need to do `sudo make install`<br />
You must have `/usr/local/bin/` in your `$PATH` variable in your shell.

### Usage:
`caesar <shift (int out of 26)> <input type(text or file)> <input (filename or just the text)>`
1. The first argument is an integer, the rotation (how many letters to shift by) in the alphabet so naturally the range for the integer size is between -26 and 26.
2. The second argument is how to get the input, either by `text` or from a `file`.
3. The third argument is either the filename, if you chose `file` for the previous argument or the text you want to encrypt (in quote marks if it contains spaces or special characters).

For example, encrypting the the alphabet demonstrates what this program does. It shifts the letters in the alphabet over to make the text not immediately recognisable. However the following example shows clearly what it does:
```shell
caesar 1 text abcdefghijklmnopqrstuvwxyz
```
Should yield `bcdefghijklmnopqrstuvwxyza`

And
```shell
caesar 3 text "Hello, World!"
```
Gives `Khoor, Zruog!`
```shell
caesar 0 text "This command is useless."
```
```shell
caesar 26 text "This command is useless."
```
Both yield `This command is useless.`

You can also read from a file for larger translations:
```shell
caesar 4 file myfile.txt
```
This command will translate the contents of `myfile.txt` (supports any file format not just `.txt`) and puts it in the terminal.</br>
To instead put this in another file (creates a new file if it doesn't already exist), type:
```shell
caesar 8 file normaltext.x > encryptedtext.y
```
This will take the contents of `normaltext.x` and spit out the encrypted version of the text into the newly made (or preexisting) `encryptedtext.y`<br />
Same can be done for `text`:
```shell
caesar 19 text "Some piece of text..." > ciphered.txt
```
### Decryption
To decrypt and encrypted message do the opposite if the encryption, so if the rotation for an encrypted message was 7 then to decrypt it rotate by -7.
e.g.
```shell
caesar 7 text "Decrypt me."
```
Outputs `Kljyfwa tl.`,
so to decrypt it:
```shell
caesar -7 text "Kljyfwa tl."
```
Which will give `Decrypt me.`
Same for the decryption of a negative rotation encryption, e.g. to decrypt a -12 rotation, rotate by 12 to decrypt.

If the rotation encryption amount is unknown then you can use brute force to iterate through every possibility; use the argument "bruteforce", "force" or "brute" instead of a rotation amount.

For example:
```shell
caesar bruteforce text "Lipps Xlivi"
```
which produces a list like this:
```
01 => Khoor Wkhuh
02 => Jgnnq Vjgtg
03 => Ifmmp Uifsf
04 => Hello There
05 => Gdkkn Sgdqd
06 => Fcjjm Rfcpc
07 => Ebiil Qebob
08 => Dahhk Pdana
09 => Czggj Oczmz
10 => Byffi Nbyly
11 => Axeeh Maxkx
12 => Zwddg Lzwjw
13 => Yvccf Kyviv
14 => Xubbe Jxuhu
15 => Wtaad Iwtgt
16 => Vszzc Hvsfs
17 => Uryyb Gurer
18 => Tqxxa Ftqdq
19 => Spwwz Espcp
20 => Rovvy Drobo
21 => Qnuux Cqnan
22 => Pmttw Bpmzm
23 => Olssv Aolyl
24 => Nkrru Znkxk
25 => Mjqqt Ymjwj
```
Here we can see 04 goes to 'Hello There', meaning it has been encrypted by a rotation of 4.

Note there is no '26' rotation on the list, just as there is no '00' as they both just yield the same text.
