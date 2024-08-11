import os

port = '/dev/usb/lp0'
# string_to_print = "Testing this function"

string_to_print_pt1 = '''There is no end though there is a start in space. ---Infinity.
宇宙に始まりはあるが、終わりはない。　---無限

It has own power, it ruins, and it goes though there is a start also in the star. ---Finite.
星にもまた始まりはあるが、自らの力をもって滅び逝く。　---有限

Only the person who was wisdom can read the most foolish one from the history.
英知を持つ者こそ、最も愚かであること。歴史からも読み取れる。\n'''

os.system('make clean')
os.system('make')
os.system(f'sudo box64 ./Picture_printer {port} \"{string_to_print_pt1}\n\"')

