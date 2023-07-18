def solution(sizes):
    answer = 0
    width, height = 0, 0 
    for w,h in sizes:
        if w<h: w,h=h,w
        width = max(w, width)
        height = max(h, height)
    answer = width*height
    return answer