"""
このファイルはディレクトリ内にあるファイル名が0.jpg, 1.jpg, ...といった数字の場合、その数字の欠けを直して連番にします。
例: 0.jpg, 2.jpg, 3.jpg -> 0.jpg, 1.jpg, 2.jpg
"""
import os
import argparse


def get_args():
    parser = argparse.ArgumentParser(description='This script fixes the missing of the sequential number of the file '
                                                 'which is the sequential number in the folder.')
    parser.add_argument('--input_dir', required=True, help='path to input folder')
    return parser.parse_args()


def main():
    args = get_args()
    files = os.listdir(args.input_dir)
    _, ext = os.path.splitext(files[0])

    sorted_files = []
    for file in files:
        sorted_files.append(file[:-4])
    sorted_files.sort(key=int)

    for file in sorted_files:
        index = int(file) - 1
        file_next = args.input_dir + '\\' + str(index) + ext
        # 自分の番号の次が欠番か?欠番の場合は前に詰める
        if not os.path.exists(file_next) and file != '0':
            # 若い番号のファイルが見つかるまでindexを更新
            while not os.path.exists(args.input_dir + '\\' + str(index) + ext):
                index -= 1
            # 一番若い番号に+1したところに自分を入れる
            os.rename(args.input_dir + '\\' + file + '.jpg', args.input_dir + '\\' + str(index + 1) + ext)


if __name__ == '__main__':
    main()
