function solution(s)
{
    const strArr = s.split('');
    const stack = [];
    
    strArr.forEach(el => {
        if(stack.length > 0 && stack[stack.length - 1] == el)
            stack.pop();
        else
            stack.push(el);
    })
    
    if(stack.length == 0) return 1;
    
    return 0;
}