import os

port = '/dev/usb/lp0'
string_to_print = "Testing this function"
os.system(f'sudo box64 ./Picture_printer {port} \"{string_to_print}\n\"')

