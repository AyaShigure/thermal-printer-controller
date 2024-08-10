#!/usr/bin/env python3
import os

class thermoPrinter():
    def __init__(self, port, cpp_bin_path):
        self.port = port
        self.cpp_bin_path = cpp_bin_path
        pass

    def FeedAndFullCut(self):    
        print('Feeding & executing a full cut.')
        os.system(f'sudo box64 {self.cpp_bin_path}/FeedAndFullCut {self.port}')

    def FeedAndHalfCut(self):
        print('Feeding & execut a half cut.')
        os.system(f'sudo box64 {self.cpp_bin_path}/FeedAndHalfCut {self.port}')

    def FeedDot(self, feed_dots_number):
        print(f'Feeding {feed_dots_number} pixels.')
        os.system(f'sudo box64 {self.cpp_bin_path}/FeedDot {self.port} {feed_dots_number}')

    def FeedLines(self, feed_lines_number):
        print(f'Feeding {feed_lines_number} lines.')
        os.system(f'sudo box64 {self.cpp_bin_path}/FeedLines {self.port} {feed_lines_number}')

    def PrintHorizontalLineSpecifyThickness(self, startPoint, endPoint, lineThickness):
        os.system(f'sudo box64 {self.cpp_bin_path}/PrintHorizontalLineSpecifyThickness {self.port} {startPoint} {endPoint} {lineThickness}')

    def PrintSelftest(self):
        os.system(f'sudo box64 {self.cpp_bin_path}/PrintSelftest {self.port}')

    def PrintRasterImage(self, imgPath):
        print('Printing target .bmp file. (Note that the imgPath should be a absolute path)')
        os.system(f'sudo box64 {self.cpp_bin_path}/PrintRasterImage {self.port} \"{imgPath}\"')

    def PrintTextUTF8(self, str):
        print('Printing.')
        os.system(f'sudo box64 {self.cpp_bin_path}/PrintTextUTF8 {self.port} \"{str}\n\"')


if __name__ == '__main__':
    # Settings
    port = '/dev/usb/lp0'
    cpp_bin_path = './cpp_bin'

    string_to_print_pt1 = '''There is no end though there is a start in space. ---Infinity.
宇宙に始まりはあるが、終わりはない。　---無限

It has own power, it ruins, and it goes though there is a start also in the star. ---Finite.
星にもまた始まりはあるが、自らの力をもって滅び逝く。　---有限

Only the person who was wisdom can read the most foolish one from the history.
英知を持つ者こそ、最も愚かであること。歴史からも読み取れる。\n'''


    string_to_print_pt2 = '''The fish that lives in the sea doesn't know the world in the land. It also ruins and goes if they have wisdom.
海に生ける魚は、陸の世界を知らない。彼らが英知を持てば、それもまた滅び逝く。

It is funnier that man exceeds the speed of light than fish start living in the land.
人間が光の速さを超えるのは、魚たちが陸で生活を始めるよりも滑稽。

It can be said that this is an final ultimatum from the god to the people who can fight.\t\n
これは抗える者たちに対する、神からの最後通告とも言えよう。'''
    

    script_path = os.getcwd()
    imgPath = f'{script_path}/rsz_1logo.bmp'
    print(imgPath)
    # Printer obj


    printer = thermoPrinter(port, cpp_bin_path)

    # printer.PrintTextUTF8(string_to_print)
    # printer.PrintRasterImage(imgPath)




    # printer.FeedLines(3)
    # printer.FeedAndHalfCut()
    printer.FeedLines(1)
    printer.PrintTextUTF8('===============================================')
    printer.FeedLines(1)
    printer.PrintTextUTF8(string_to_print_pt1)
    printer.PrintTextUTF8(string_to_print_pt2)
    printer.FeedLines(1)
    printer.PrintTextUTF8('===============================================')
    printer.FeedLines(1)
    printer.PrintRasterImage(imgPath)
    printer.FeedLines(1)
    printer.PrintTextUTF8('===============================================')
    printer.FeedLines(3)
    printer.FeedAndFullCut()