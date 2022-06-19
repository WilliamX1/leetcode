from collections import defaultdict 

class Solution:
    def __init__(self): 
        self.graph = defaultdict(list) 
        self.V = 101

    def addEdge(self,u,v): 
        self.graph[u].append(v) 

    def isCyclicUtil(self, v, visited, recStack): 

        # visited数组元素为true，标记该元素被isCyclicUtil递归调用链处理中，或处理过
        # recStack数组元素为true，表示该元素还在递归函数isCyclicUtil的函数栈中
        visited[v] = True
        recStack[v] = True

        # 深度遍历所有节点。
        for neighbour in self.graph[v]: 
            if visited[neighbour] == False: # 如果该节点没有被处理过，那么继续调用递归
                if self.isCyclicUtil(neighbour, visited, recStack) == True: # 如果邻接点neighbour的递归发现了环
                    return True # 那么返回真
            elif recStack[neighbour] == True: # 如果neighbour被处理中（这里强调了不是处理过），且还在递归栈中，说明发现了环
                return True

        recStack[v] = False # 函数开始时，V节点进栈。所以函数结束时，V节点出栈。
        return False # v的所有邻接点的递归都没有发现环，则返回假

    # 如果该图有环，返回真；否则假
    def isCyclic(self): 
        visited = [False] * self.V 
        recStack = [False] * self.V 
        for node in range(self.V): # 分别以每个节点作为起点，然后开始深度遍历
            if visited[node] == False: # 这里为真，说明之前的深度遍历已经遍历过该节点了，且那次遍历没有发现环
                if self.isCyclicUtil(node,visited,recStack) == True: #如果发现环，直接返回
                    return True
        return False #如果分别以每个节点作为起点的深度遍历都没有发现环，那肯定是整个图没有环
    
    def hasCycle(self, graph: str) -> bool:
      nodelist = graph.split(',')
      for node in nodelist:
        # print(node)
        pre = int(node[0 : node.index('-')])
        last = int(node[node.index('>') + 1 : len(node)])
        # print(pre, last)
        self.addEdge(pre, last)
      return self.isCyclic()
