function compare(a, b) {
    return (b+a) - (a+b);
}

function solution(numbers) {
    let stringArray = numbers.map(String).sort(compare)
    let answer = stringArray.join('');
    
    return answer[0] === '0' ? '0' : answer;
}