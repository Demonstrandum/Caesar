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
`caesar <shift (int)> <input type(text or file)> <input (filename or just the text)>`
1. The first argument is an integer, the rotation (how many letters to shift by).
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
Gives `khoor, zruog!`
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
