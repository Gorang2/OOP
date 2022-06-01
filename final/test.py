class MyQueue :
    
    def __init__(self):
        self.items = []
        self.filtered = []

    def push(self,item):
        
	if item in self.items:
		return __str__
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
        
        
    def __str__(self, dup=False):
            if dup:
                return "error@duplicated"

            
        
        
        
    def get_original(self):
        
        return self.items
        
        
    def get_filtered(self):      
        
  

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
            return { a : b}
        else:
            if x in self.filtered:
                c = x
                return {c : c}
        
        
        
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



#A.1:(1)==>>(<class 'int'>)
#A.2:(2)==>>(<class 'int'>)
#A.3:(3)==>>(<class 'int'>)
#A.4:(0)==>>(<class 'int'>)
#A.5:(123)==>>(<class 'int'>)
#B.1:([1, '2', 3.2, [4, 5, 6], '1abc2def3xyx'])==>>(<class 'list'>)
#B.2:([1, 2, 3, 0, 123])==>>(<class 'list'>)
#B.3:([0, 1, 2, 3, 123])==>>(<class 'list'>)
#B.4:([1, 2, 3, 0, 123])==>>(<class 'list'>)
#B.5:([123, 0, 3, 2, 1])==>>(<class 'list'>)
#B.6:([1, 2, 3, 0, 123])==>>(<class 'list'>)
#C.1:({'1abc2def3xyx': 123})==>>(<class 'dict'>)
#C.2:([1, 2, 3, 0])==>>(<class 'list'>)
#C.3:({'2': 2})==>>(<class 'dict'>)
#C.4:([1, 3, 0])==>>(<class 'list'>)
#D.1:({1: 1, 3: 3.2, 0: [4, 5, 6]})==>>(<class 'dict'>)
#D.2:([1, 3, 0])==>>(<class 'list'>)
#E.1:(error@duplicated)==>>(<class 'str'>)
#E.2:([1, 3, 0])==>>(<class 'list'>)
#E.3:(999)==>>(<class 'int'>)
#E.4:([1, 3, 0, 999])==>>(<class 'list'>)
#F.1:(<class '__main__.MyQueue'>)
#F.2:([1, 3, 0, 999, 10, 2, 22, 44])==>>(<class 'list'>)
#F.3:([1, 3, 0, 999])==>>(<class 'list'>)
#F.4:([1, 10, 2])==>>(<class 'list'>)
#F.5:([22, 999, 44])==>>(<class 'list'>)
