## Лаборатнорная работа №2

**Вариант 10**
*Создать класс Twelve для работы с беззнаковыми целыми двенадцатиричными числами, используя для представления числа массив из элементов типа unsigned char, каждый из которых является двенадцатиричными
цифрой. Младшая цифра имеет меньший индекс (единицы – в нулевом элементе массива).*

Для того чтобы сбилдить программу необходимо создать директорию build и в ней выполнить следующие действия:
1. ```cmake ..```
2. ```cmake --build .```

После билда появится исполняемый файл lab который и нужен для запуска программы.



По сути программа представляет собой калькулятор для 12-ричной системы счисления (которая работает исключительно с двумя операндами). Этот калькулятор может:
- Складывать двенадцатиричные числа
- Вычитать двенадцатиричные числа (результат не может быть отрицательным)
- Умножать двенадцатиричные числа друг на друга
- Делить двенадцитиричные числа друг на друга
- Переводить числа из двендцатиричной системы в десятичную
- Переводить числа из десятичной системы в двенадцатиричную
- Сравнивать двенадцатиричные числа (больше, меньше, равно)


**Примеры работы программы:**
```
123AB + 123AB
2479A

123AB - 123AB
0

123AB*2
2479A

2479A/2
123AB

123AB->10
24755

24755->12
123AB

123AB > 234
True

123AB < 98B
False

123AB = 123AB
True
```
**Важно!** *Программа работает только с заглавными буквами!*