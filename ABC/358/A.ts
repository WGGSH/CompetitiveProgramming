import * as readline from "readline";

const stream = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let inputs = "";
stream.on("line", (line) => {
  inputs += line;
  inputs += "\n";
});
stream.on("close", () => {
  const line = inputs.split('\n')[0]
  const [S, T] = line.split(' ')
  console.log(S === 'AtCoder' && T ==='Land' ? 'Yes' : 'No')
});
