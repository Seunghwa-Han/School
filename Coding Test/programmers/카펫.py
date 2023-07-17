def solution(brown, yellow):
    answer = []
    '''
    width, height
    brown = width*2 + 2*(height-2)
    yellow = (width-2)*(height-2)
    
    brown/2 = width + (height-2)
    width+height = brown/2+2
    
    width*height-2*width-2*height+4 = yellow
    width*height-2(width+height)+4=yellow
    width*height-2(brown/2+2)+4 = yellow
    width*height-brown-4+4=yellow
    width*height=brown+yellow
    '''
    summation = int(brown/2)+2
    for h in range(3, summation):
        w = summation-h
        if w*h == brown+yellow:
            answer.append(w)
            answer.append(h)
            break
        
    return answer