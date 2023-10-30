l1=int(input("Enter 1st number : "))
l2=int(input("Enter 2nd number : "))

def lcm(l1,l2):
    
    maximum=max(l1, l2, 2)
    
    while(maximum!=0):
        if(maximum%l1==0 and maximum%l2==0):
            return maximum
        else:
            maximum=maximum+1

def gcd(l1,l2):
    
    minimum=min(l1,l2,2)
    
    while(minimum!=0):
        if(l1%minimum==0 and l2%minimum==0):
            return minimum
        
        else:
            minimum=minimum-1

y=gcd(l1,l2)
z=lcm(l1,l2)
print(f'LCM = {z}')
print(f'GCD = {y}')
