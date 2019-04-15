p = [0 for i in range(100000005)]
print 'here'
p[1] = 0
for i in range(2, 100000005):
    for j in range(i * i, 100000005, i):
        p[j] = 1
        
print 'here'
result = 123456789
for i in range(2, 10005):
    if p[i] == 1:
        continue
    for j in range(2, 10005):
        if p[j] == 1:
            continue
        if p[int(str(i) + str(j))] == 1:
            continue
        if p[int(str(j) + str(i))] == 1:
            continue    
        print (i, j)
        for k in range(2, 10005):
            if p[k] == 1:
                continue
            if p[int(str(i) + str(k))] == 1:
                continue
            if p[int(str(k) + str(i))] == 1:
                continue            
            if p[int(str(j) + str(k))] == 1:
                continue 
            if p[int(str(k) + str(j))] == 1:
                continue                
            for q in range(2, 10005):
                if p[q] == 1:
                    continue
                if p[int(str(i) + str(q))] == 1:
                    continue
                if p[int(str(q) + str(i))] == 1:
                    continue                
                if p[int(str(j) + str(q))] == 1:
                    continue 
                if p[int(str(q) + str(j))] == 1:
                    continue                 
                if p[int(str(k) + str(q))] == 1:
                    continue 
                if p[int(str(q) + str(k))] == 1:
                    continue                 
                for l in range(2, 10005):
                    if p[l] == 1:
                        continue
                    if p[int(str(i) + str(l))] == 1:
                        continue
                    if p[int(str(l) + str(i))] == 1:
                        continue                    
                    if p[int(str(j) + str(l))] == 1:
                        continue 
                    if p[int(str(l) + str(j))] == 1:
                        continue                     
                    if p[int(str(k) + str(l))] == 1:
                        continue 
                    if p[int(str(l) + str(k))] == 1:
                        continue                     
                    if p[int(str(q) + str(l))] == 1:
                        continue   
                    if p[int(str(l) + str(q))] == 1:
                        continue                       
                    result = min(result, i + j + k + q + l)

print(result)