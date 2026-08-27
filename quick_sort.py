def quick_sort(a,left,right):
    pivot = a[(left+ right ) // 2]
    i = left 
    j = right
    while i <=j :
        while a[i] <pivot:
            i+=1
        while a[j]> pivot:
            j-=1
        if i<=j:
            tam = a[i]
            a[i] = a[j]
            a[j] = tam
            i+=1
            j-=1
    if left < j :
        quick_sort(a, left , j)
    if i < right :
        quick_sort(a, i, right)            
a=[]
n=int(input("nhap n: "))
for i in range(0,n,1):
    x = input()
    a.append(x)
quick_sort(a,0,n-1)
print(a)  
     