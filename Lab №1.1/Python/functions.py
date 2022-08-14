import sys


# створення основного файлу з іменем, задане користувачем
def create_file():
    file_name = input('Enter file name: ')
    try:
        file = open(file_name, "w+")
    except IOError:
        print('Error creating file!')
        return None
    print('Press Enter to move to a new line\nPress Ctrl+D to stop data input\nEnter file data:')
    line = sys.stdin.read()
    line = line[:len(line)-1]
    file.write(line)
    file.close()
    return file_name


# вивантаження данних з основного файлу
def load_file(file_name):
    data = []
    try:
        file = open(file_name, "r")
    except IOError:
        print('Error opening file!')
        return None
    for line in file:
        data.append(line.replace('\n', ''))
    return data


# повернення парних або непарних рядків
def extract(data, first):
    return data[first::2]


# прийняття парних рядків та повернення відсортованих
def sort_list(data):
    spisok = []
    for line in data:
        spisok.append(sort_word(line))
    return spisok


# прийняття парних рядків, розбивання їх по слову та додавання до списку
def sort_word(line):
    spisok = line.split()
    spisok.sort()
    return ' '.join(spisok)


# записування та зберігання іфнормації в файлі
def save_file(data, file_name):
    content = ''
    file = open(file_name, "w+")
    for line in data:
        content += line + '\n'
    file.write(content.rstrip('\n'))
    file.close()


# читання та виведення інформації зі збереженого файлу
def print_file(file_name):
    file_out = open(file_name)
    print(file_out.read())
    print('*' * 10)
