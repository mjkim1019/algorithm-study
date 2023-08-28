function solution(s) {
  let str = s;
  str = str.slice(1, -1);
  
  let arr = str.split('},{');
  arr = arr.map(el => el.replace(/[{}]/g, ''));
  arr = arr.map(element => JSON.parse(`[${element}]`));
  arr.sort((a, b) => {
      return a.length - b.length;
  });
  
  const result = arr[0];
  
  if(arr.length < 2) return result;
  
  for(let i = 1; i < arr.length; i++){
      for(let j = 0; j < arr[i].length; j++){
          if(!result.includes(arr[i][j])) {
              result.push(arr[i][j]);
              break;
          }
      }
  }
  
  return result;
}