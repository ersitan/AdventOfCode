# -*- coding: utf-8 -*-
"""
Created on Wed Apr 10 12:55:08 2024

@author: Ersin
"""
from itertools import islice

numbers = {"zero": "0", "one": "1","two": "2", "three": "3",
           "four": "4", "five": "5",  "six": "6", "seven": "7",
           "eight": "8", "nine": "9"}

def find_index(line) ->list:
    num_list = []
    for num in numbers:
        ind = line.find(num)
        if ind != -1:
            num_list.append(ind)
    num_list.sort()
    print (f'numbers: {num_list}')

def find_digits(line) -> int:
    digits = [int(i) for i in line if i.isdigit()]
    res = int(digits[0] + digits[-1])
    return res

def replace_numbers(line) ->str:
    for key in numbers.keys():
        if key in line:
            line = line.replace(key, numbers[key])
    return line

def main():
    count = 0
    with open ('input.txt', 'r') as file:
        lines = file.readlines()
   
    for line in lines:
        #line = replace_numbers(line)
        #print(line)
        #count += find_digits(line)
        #print(count)
        digits = [] 
        iterator = enumerate(line)
        for i, c in iterator:
            found = False
            if line[i].isdigit():
                digits.append(c)
            else:
                for k in numbers.keys():
                    if line[i:].startswith(k):
                        found = True
                        digits.append(numbers[k])
                        break
                if found:
                    next(islice(iterator, i, len(k), None))
                    continue
        count += int(digits[0]) + int(digits[-1])         
        print("-----")
    print(f'Count : {count}')
    
if __name__ == "__main__":
    main()
