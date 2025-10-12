def solution(tickets):
    tickets.sort()
    visited = [False] * len(tickets)
    route = []
    
    def dfs(current, path):
        if len(path)  == len(tickets) + 1:
            route.append(path)
            return
        
        for i, (start, end) in enumerate(tickets):
            if not visited[i] and start == current:
                visited[i] = True
                dfs(end, path + [end])
                visited[i] = False

    dfs("ICN", ["ICN"])
    
    return route[0]
    