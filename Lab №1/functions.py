import sys
def create_file(): #створення основного файлу з іменем, яке вводить користувач
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


def load_file(file_name): #вивантаження данних з основного файлу, для їх подальшого використання
    data = []
    try:
        file = open(file_name, "r")
    except IOError:
        print('Error opening file!')
        return None
    for line in file:
        data.append(line.replace('\n', ''))
    return data


def extract(data, first): #функція, що повертає парні або непарні рядки
    return data[first::2]


def sort_list(data): #функція приймає парні рядки, а потім вже з усіх відсортованих рядків створює єдинну змінну
    spisok = []
    for line in data:
        spisok.append(sort_word(line))
    return spisok


def sort_word(line): #функція приймає парні рядки, розбиваючи їх по слову та додаючи до списку, а потім об'єднує список в рядкову змінну
    spisok = line.split()
    spisok.sort()
    return ' '.join(spisok)


def save_file(data, file_name): #записує та зберігає іфнормацію в файлі
    content = ''
    file = open(file_name, "w+")
    for line in data:
        content += line + '\n'
    file.write(content.rstrip('\n'))
    file.close()


def print_file(file_name): #вивантажує та виводить на єкран інформацію зі збереженого файлу
    file_out = open(file_name)
    print(file_out.read())
    print('*' * 10)