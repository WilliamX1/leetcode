import os, sys, getopt


def generate() -> str:
    path = os.getcwd() + '/README.md'
    markdown = os.path.exists(path)
    if not markdown: 
        markdown = open(path, 'w')
        markdown.write('# Leetcode\n\n| Cnt | Problem | Solution | Difficulty | date |\n| :--: | :-- | :-- | :-- | :--: |\n')
        markdown.close()
        return 'REAMDE.md file successfully generated.'
    else: return 'README.md file already exists.'


def append(entry) -> str:
    path = os.getcwd() + '/README.md'
    markdown = os.path.exists(path)
    if not markdown: return "README.md file not exists. Use `generate.py -g` to init."
    else: 
        markdown = open(path, 'w+')
        markdown.write('')


def commit() -> str:
    pass


def main(argv):
    try:
        opts, args = getopt.getopt(argv, "hga:", ["help", "generate", "append="])
    except getopt.GetoptError:
        print('Use `generate.py -h` to get usage information.')
        sys.exit(2)
    for opt, arg in opts:
        if opt in ('-h', '--help'):
            print('generate.py -g : Generate a markdown file using specified formats.')
            print('generate.py -a <English Title> : Append one entry to the markdown file.')
            sys.exit()
        elif opt in ('-g', '--generate'):
            print(generate())
        elif opt in ('-a', '--append'):
            print(append(arg))
        elif opt in ('-c', '--commit'):
            print(commit())
        else: print('Unknown option.')


if __name__ == '__main__':
    main(sys.argv[1:])