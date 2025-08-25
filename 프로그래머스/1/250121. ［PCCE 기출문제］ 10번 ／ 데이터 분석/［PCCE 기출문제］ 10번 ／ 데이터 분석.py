def solution(data, ext, val_ext, sort_by):
    answer = []
    temp = {"code": 0, "date" : 1, "maximum" : 2, "remain" : 3}
    
    for i in range(len(data)):
        if(data[i][temp[ext]] < val_ext):
            answer.append(data[i])
    
    answer.sort(key=lambda x: x[temp[sort_by]])
    return answer