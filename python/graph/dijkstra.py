infinity = float("inf")

def init_graph():
    """
        start -> a = 6
        start -> b = 2
        b -> a = 3
        a -> fin = 1
        b -> fin = 5 
    """
    graph = {}
    graph["start"] = {}
    graph["start"]["a"] = 6
    graph["start"]["b"] = 2
    graph["a"] = {}
    graph["a"]["fin"] = 1
    graph["b"] = {}
    graph["b"]["a"] = 3
    graph["b"]["fin"] = 5
    graph["fin"] = {}
    return graph

def init_costs():
    costs = {}
    costs["a"] = 6
    costs["b"] = 2
    costs["fin"] = infinity
    return costs

def init_parents():
    parents = {}
    parents["a"] = "start"
    parents["b"] = "start"
    parents["fins"] = None
    return parents

def find_lowest_cost_node(costs, processed):
    lowest_cost = infinity
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node

def dijkstra(graph, costs, parents):
    processed = []
    node = find_lowest_cost_node(costs, processed)
    while node is not None:
        cost = costs[node]
        neighbors = graph[node]
        for n in neighbors.keys():
            new_cost = cost + neighbors[n]
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node
        processed.append(node)
        node = find_lowest_cost_node(costs, processed)
    print("Path:", parents)

def main():
    graph = init_graph()
    costs = init_costs()
    parents = init_parents()
    dijkstra(graph, costs, parents)

if __name__ == "__main__":
    main()