import os

path ='./leetcode'
for file in os.listdir(path):
    # print(file.split('.', 1)) # ['38', ' Count and Say.cpp'], split into (num + 1) strings
    num, suffix = file.split('.', 1)
    # num.rjust(4, '0') 原字符串右侧对齐， 左侧补零:
    os.rename(os.path.join(path, file), os.path.join(path, num.rjust(4, '0') + "." + suffix))
