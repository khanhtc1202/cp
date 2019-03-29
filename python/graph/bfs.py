import time
from collections import deque

def init_graph():
    graph = {}
    graph["you"] = ["alice", "bob", "claire"]
    graph["bob"] = ["anuj", "peggy"]
    graph["alice"] = ["peggy"]
    graph["claire"] = ["thom", "jonny"]
    graph["anuj"] = []
    graph["peggy"] = []
    graph["thom"] = []
    graph["jonny"] = []
    return graph

def run_time(func, print_output, *args):
    start_time = time.time()
    out = func(*args)
    end_time = time.time()
    if print_output: print out
    return end_time - start_time

def match_search_condition(item):
    return True if item[-1] == 'm' else False

def bfs_search(graph, name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if match_search_condition(person):
                return person
            else:
                search_queue += graph[person]
                searched.append(person)
    return "Not found!"

def main():
    graph = init_graph()
    print("Time taken by BFS %f" % (run_time(bfs_search, True, graph, "you")))

if __name__ == "__main__":
    main()
