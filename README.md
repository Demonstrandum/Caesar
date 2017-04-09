# Caesar
Simple Caesar/rot cipher written in C++

### Installation:
In your terminal, clone and cd into the repository:<br />
`git clone https://github.com/Demonstrandum/Caesar && cd Caesar`<br />
Then run the make file by typing: `make`<br />
Then `make install`, you might need to do `sudo make install`<br />
You must have `/usr/local/bin/` in your `$PATH` variable in your shell.

### Usage:
`caesar <shift (int)> <input type(text or file)> <input (filename or just the text)>`
1. The first argument is an integer, the rotation (how many letters to shift by)
2. The second argument is how to get the input, either by `text` or from a `file`
3. The third argument is either the filename, if you chose `file` for the previous argument or the text you want to encrypt (in quote marks if it contains spaces or special characters.)

For example, encrypting the word 'hello':
```shell
caesar 4 text hello
```
Should yield `lipps`
```shell
caesar 0 text "This command is useless."
```
```shell
caesar 26 text "This command is useless."
```
Both yield `This command is useless`

You can also read from a file for larger translations:
```shell
caesar 3 file myfile.txt
```
This command will translate the contents of `myfile.txt` (supports any file format not just `.txt`) and puts it in the terminal.</br>
To put this in another file (it will create a new file if it doesn't already exist), type:
```shell
caesar 8 file normaltext.x > encryptedtext.y
```
This will take the contents of `normaltext.x` and spit out the encrypted version of the text into the newly made (or preexisting) `encryptedtext.y`<br />
Same can be done for `text`:
```shell
caesar 19 text "Some piece of text..." > ciphered.txt
```
