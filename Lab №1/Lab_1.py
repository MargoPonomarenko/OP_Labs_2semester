# Створити текстовий файл. Кожен парний рядок вихідного файлу переписати в перший новий текстовий файл,
# кожен непарний - у другий. У файлі з парними рядками змінити рядки таким чином,
# щоб слова кожного рядка були лексично впорядковані за алфавітом. Вивести вміст вихідного і створених файлів.

from functions import *
file_name = create_file()
data = []
if file_name is not None:
    data = load_file(file_name)
data_first = extract(data, 0)
data_second = extract(data, 1)
sort_data = sort_list(data_second)

first_file_name = 'firstFile.txt'
second_file_name = 'secondFile.txt'
save_file(sort_data, first_file_name)
save_file(data_first, second_file_name)

print('Inputed data:')
print_file(file_name)
print('Sorted pair lines:')
print_file(first_file_name)
print('Unpaired lines:')
print_file(second_file_name)