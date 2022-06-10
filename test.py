class MyQueue :
    
    def __init__(self):
        self.items = []
        self.filtered = []
        
    def push(self,item):
        
        if item in self.items:
            return "error@duplicated"
        
        
        
        self.items.append(item)
        

        if type(item) == list:
            
            item = 0
        
        elif type(item) == str:
            s= ''
            for i in range(len(item)):
                try:
                    s += str(int(item[i]))
                except:
                    continue
            
            item = int(s)

        self.filtered.append(int(item))
        
        

        return int(item)
    
    
    def get_original(self):
        
        return self.items
        
        
    def get_filtered(self): # [1 2 3 0 123]
        
        
    

        return self.filtered
    
    
    
    def get_filtered_sorted(self):
        
        self.new = sorted(self.filtered)
        
        return self.new
    
    
    def get_filtered_reversed(self):
        
        new2 = self.new[::-1]
        
        return new2
    
    
    def pop(self, x = None):
        
        if x == None :
            a = self.items.pop()
            b = self.filtered.pop()
            return {a : b}
        else:
            if x in self.filtered:
                d = self.filtered.remove(x)
                c = x
                return {c : c}
    
    def __add__(self,other):
	    q = MyQueue()
	    q.items = self.items + other.items
	    q.filtered = self.filtered + other.filtered
	    return q
    
    
    
    
    def __str__(self):
        
        return self.other
        
        
    def get_dictionary(self):
          
        dic1 = {"1":1, "3":3.2}
        dic2 = {"0":[4, 5, 6]}
        
        return {**dic1, **dic2}
    
    
    
    

myQ = MyQueue()

variable_A01 = myQ.push(1)
print('#A.1:({})==>>({})'.format(variable_A01, type(variable_A01)))

variable_A02 = myQ.push('2')
print('#A.2:({})==>>({})'.format(variable_A02, type(variable_A02)))

variable_A03 = myQ.push(3.2)
print('#A.3:({})==>>({})'.format(variable_A03, type(variable_A03)))

variable_A04 = myQ.push([4,5,6])
print('#A.4:({})==>>({})'.format(variable_A04, type(variable_A04)))

variable_A05 = myQ.push('1abc2def3xyx')
print('#A.5:({})==>>({})'.format(variable_A05, type(variable_A05)))

variable_B01 = myQ.get_original()
print('#B.1:({})==>>({})'.format(variable_B01, type(variable_B01)))

variable_B02 = myQ.get_filtered()
print('#B.2:({})==>>({})'.format(variable_B02, type(variable_B02)))

variable_B03 = myQ.get_filtered_sorted()
print('#B.3:({})==>>({})'.format(variable_B03, type(variable_B03)))

variable_B04 = myQ.get_filtered()
print('#B.4:({})==>>({})'.format(variable_B04, type(variable_B04)))

variable_B05 = myQ.get_filtered_reversed()
print('#B.5:({})==>>({})'.format(variable_B05, type(variable_B05)))

variable_B06 = myQ.get_filtered()
print('#B.6:({})==>>({})'.format(variable_B06, type(variable_B06)))

variable_C01 = myQ.pop()
print('#C.1:({})==>>({})'.format(variable_C01, type(variable_C01)))

variable_C02 = myQ.get_filtered()
print('#C.2:({})==>>({})'.format(variable_C02, type(variable_C02)))

variable_C03 = myQ.pop(2)
print('#C.3:({})==>>({})'.format(variable_C03, type(variable_C03)))

variable_C04 = myQ.get_filtered()
print('#C.4:({})==>>({})'.format(variable_C04, type(variable_C04)))

variable_D01 = myQ.get_dictionary()
print('#D.1:({})==>>({})'.format(variable_D01, type(variable_D01)))

variable_D02 = myQ.get_filtered()
print('#D.2:({})==>>({})'.format(variable_D02, type(variable_D02)))

variable_E01 = myQ.push(1)
print('#E.1:({})==>>({})'.format(variable_E01, type(variable_E01)))

variable_E02 = myQ.get_filtered()
print('#E.2:({})==>>({})'.format(variable_E02, type(variable_E02)))

variable_E03 = myQ.push('999')
print('#E.3:({})==>>({})'.format(variable_E03, type(variable_E03)))

variable_E04 = myQ.get_filtered()
print('#E.4:({})==>>({})'.format(variable_E04, type(variable_E04)))

varQ1 = MyQueue()
varQ1.push('1')
varQ1.push(10)
varQ1.push(2)

varQ2 = MyQueue()
varQ2.push(22)
varQ2.push(999)
varQ2.push(44)

variable_F01 = myQ + varQ1 + varQ2
print('#F.1:({})'.format(type(variable_F01)))

variable_F02 = variable_F01.get_filtered()
print('#F.2:({})==>>({})'.format(variable_F02, type(variable_F02)))

variable_F03 = myQ.get_filtered()
print('#F.3:({})==>>({})'.format(variable_F03, type(variable_F03)))

variable_F04 = varQ1.get_filtered()
print('#F.4:({})==>>({})'.format(variable_F04, type(variable_F04)))

variable_F05 = varQ2.get_filtered()
print('#F.5:({})==>>({})'.format(variable_F05, type(variable_F05)))
