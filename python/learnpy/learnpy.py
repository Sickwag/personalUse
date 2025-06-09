
# 冒泡排序
# def bubble_sort(list):
#     unsorted_list = len(list)-1
#     sorted = False
#     while not sorted :
#         sorted = True
#         for i in range(unsorted_list):
#             if list[i] > list[i+1]:
#                 sorted = False
#                 list[i],list[i+1] = list[i+1],list[i]
#         unsorted_list -= 1

# list = [3,7,9,2,8,12,7]
# bubble_sort(list)
# print(list)

# 选择排序
# def selection_sort(list):
#     for i in range(len(list)):# 假设当前索引时列表中最小的索引
#         min_index = i
#         for j in range(i+1,len(list)):# 检查列表剩余部分是否有更小的元素
#             if list[j] < list[min_index]:
#                 min_index = j
#         list[i],list[min_index] = list[min_index],list[i]
#     return list

# def interval_selection(list):
#     new_list = []
#     for i in range(0,len(list),2):
#         new_list.append(list[i])
#     return new_list
            

# list = [3,7,9,2,8,12,7]
# print(selection_sort(list))
# print(interval_selection(list))


import numpy as np
import matplotlib.pyplot as plt

theta = np.linspace(0, 2 * np.pi, 100)
amplitudes = [1, 3]
plt.figure(figsize=(10, 5))

for amp in amplitudes:
    plt.subplot(1, 2, amplitudes.index(amp) + 1)
    plt.plot(np.real(amp * np.exp(1j * theta)), np.imag(amp * np.exp(1j * theta)), 'o-')
    plt.title(f'Amplitude {amp}')
    plt.xlabel('I (In-phase)')
    plt.ylabel('Q (Quadrature)')
    plt.grid(True)
    plt.axis('equal')

plt.tight_layout()
plt.show()