def nearestNeighbour(s,c):    #Nearest Neighbourhood Algorithm
    if len(p)==n:
        c+=cost[s][source]
        global nearestNeighbourCost
        nearestNeighbourCost = c
    else:
        ne, nc=0, 999
        for x in [[i,cost[s][i]] for i in range(1,n+1) if i not in p and cost[s][i]!=999]:
            if nc>x[1]: 
                ne=x[0]
                nc=x[1]
        p.append(ne)
        c+=nc
        nearestNeighbour(ne,c)

def bruteFore(s,c):   #Brute Force Approach
    if len(p)==n:
        global bruteForceCost,end
        if bruteForceCost > c and cost[s][source]!=999:
            bruteForceCost = c
            end=s
            path.clear()
            path.extend(p)
    else:
        for i in range(1,n+1):
            if i not in p and cost[s][i]!=999:
                p.append(i)
                c+=cost[s][i]
                bruteFore(i,c)
                p.remove(i)
                c-=cost[s][i]

n=int(input("No. of vertices: "))
cost=[0]*(n+1)

for i in range(1,n+1):
    cost[i]=[0]+list(map(int,input().split()))

source = int(input("Enter source: "))
p, path, end, bruteForceCost , nearestNeighbourCost = [source], [], 0, 9999, 0

bruteFore(source,0)
print("Total Cost for Brute Force approach:",
    bruteForceCost+cost[end][source],"and path is:",path+[source])

nearestNeighbour(source,0)
print("Total Cost for Nearest Neighbourhood Alogorithm:",
    nearestNeighbourCost,"and path is:",p+[source])

print("Error in approxiamation:", nearestNeighbourCost/bruteForceCost)