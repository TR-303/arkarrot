#!python
import fnmatch
import os
import sys
import matplotlib.pyplot as plt
from xml.etree import ElementTree
from PIL import Image


def tree_to_dict(tree):
    d = {}
    for index, item in enumerate(tree):
        if item.tag == 'key':
            if tree[index+1].tag == 'string':
                d[item.text] = tree[index + 1].text
            elif tree[index + 1].tag == 'true':
                d[item.text] = True
            elif tree[index + 1].tag == 'false':
                d[item.text] = False
            elif tree[index+1].tag == 'dict':
                d[item.text] = tree_to_dict(tree[index+1])
    return d


def gen_png_from_plist(plist_filename, png_filename):
    file_path = plist_filename.replace('.plist', '')
    big_image = Image.open(png_filename)
    root = ElementTree.fromstring(open(plist_filename, 'rb').read())
    plist_dict = tree_to_dict(root[0])
    def to_list(x): return x.replace('{', '').replace('}', '').split(',')
    for k, v in plist_dict['frames'].items():
        rectlist = to_list(v['frame'])
        width = int(rectlist[2] if not v['rotated'] else rectlist[3])
        height = int(rectlist[3] if not v['rotated'] else rectlist[2])
        box = (
            int(rectlist[0]),
            int(rectlist[1]),
            int(rectlist[0]) + width,
            int(rectlist[1]) + height,
        )
        sizelist = [int(x) for x in to_list(v['sourceSize'])]
        rect_on_big = big_image.crop(box)
        #plt.imshow(rect_on_big)
        #plt.show()

        if v['rotated']:
            rect_on_big = rect_on_big.rotate(90, expand=True)
            #plt.imshow(rect_on_big)
            #plt.show()

        result_image = Image.new('RGBA', sizelist, (0, 0, 0, 0))
        if not v['rotated']:
            result_box = (
                (sizelist[0]-width)//2,
                (sizelist[1]-height)//2,
                (sizelist[0]+width)//2,
                (sizelist[1]+height)//2,
                )
        else:
            result_box = (
                (sizelist[0]-height)//2,
                (sizelist[1]-width)//2,
                (sizelist[0]+height)//2,
                (sizelist[1]+width)//2,
                )
        result_image.paste(rect_on_big, result_box, mask=0)
        #plt.imshow(result_image)
        #plt.show()

        if not os.path.isdir(file_path):
            os.mkdir(file_path)
        outfile = (file_path+'/' + k).replace('gift_', '')
        print(outfile, "generated")
        result_image.save(outfile)


def split_directory(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if fnmatch.fnmatch(file, '._*'):
                continue
            if fnmatch.fnmatch(file, '*.plist'):
                plist_path = os.path.join(root, file)
                png_path = plist_path[:-6]+'.png'
                if os.path.exists(png_path):
                    gen_png_from_plist(plist_path, png_path)
                else:
                    print(png_path, 'not found\n')

        for subdir in dirs:
            subdir_path = os.path.join(root, subdir)
            split_directory(subdir_path)


split_directory(sys.argv[1])