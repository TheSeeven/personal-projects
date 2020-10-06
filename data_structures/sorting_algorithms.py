import random
import time

def bubble_sort(list):
        exchange = True
        while exchange:
                exchange = False
                for i in range(0 , len(list) - 1):
                        if list[i] > list[i+1]:
                                exchange = True
                                list[i],list[i+1] = list[i+1],list[i]     
        return list

def insertion_sort(list):
        for i in range(1,len(list)):
                actual = list[i]
                while i>0 and list[i-1]>actual:
                        list[i] = list[i-1]
                        i= i-1
                        list[i] = actual
        return list

def selection_sort(list):
   
    for i in range(len(list)-1,0,-1):
        index_maxim=0
        for j in range(1,i+1):
            if list[j]>list[index_maxim]:
                index_maxim = j

        list[i],list[index_maxim] = list[index_maxim],list[i] 

def merge_sort(list):
        if len(list)>1:
                middle = len(list)//2
                left = list[:middle]
                right= list[middle:]

                merge_sort(left)
                merge_sort(right)

                left_index=0
                right_index=0
                index_final=0

                while left_index < len(left) and right_index < len(right):
                        if left[left_index] < right[right_index]:
                                list[index_final]=left[left_index]
                                left_index += 1
                        else:
                                list[index_final]=right[right_index]
                                right_index += 1
                        index_final += 1

                while left_index < len(left):
                        list[index_final]=left[left_index]
                        left_index += 1
                        index_final += 1
                
                while right_index < len(right):
                        list[index_final]=right[right_index]
                        right_index += 1
                        index_final += 1
        return list

def Quicksort_sort(list, left, right): 
        left_index = left
        right_index = right
        pivot = list[left + (right-left) // 2]
        while left_index <= right_index:
                while list[left_index] < pivot:
                        left_index += 1
                while list[right_index] > pivot:
                        right_index -= 1
                if left_index <= right_index:
                        list[left_index],list[right_index] = list[right_index],list[left_index]
                        left_index += 1
                right_index -= 1
        if left < right_index:
                Quicksort_sort(list,left,right_index)
        if left_index < right:
                Quicksort_sort(list,left_index,right)
        return list


