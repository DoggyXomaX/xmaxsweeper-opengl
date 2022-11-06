let hasOutput = false;
let hasTarget = false;
let hasInput = false;

let targetFolder = "";
let inputFolder = "";

const argvLength = process.argv.length;
for (let i = 0; i < argvLength; i++) {
  const val = process.argv[i];

  if (!hasOutput) {
    if (val === "-o")
      hasOutput = true;
    continue;
  }

  if (!hasTarget) {
    hasTarget = true;
    targetFolder = val;
    continue;
  } 
  
  if (!hasInput) {
    hasInput = true;
    inputFolder = val;
    break;
  }
  console.log(`${i} : ${val}`);
}

if (!hasOutput || !hasTarget || !hasInput) {
  console.error('Failed to compile: no needed args');
  return;
}

console.log(`Compile all shaders from "${inputFolder}" to "${targetFolder}"`);

const fs = require('fs');
const path = require('path');

const inputDir = fs.readdirSync(inputFolder);
const pathedDir = inputDir.map(n => `${inputFolder}/${n}`);
console.log(pathedDir);

for (let i = 0 ; i < pathedDir.length; i++) {
  console.log(`Compiling shader ${pathedDir[i]}...`);
  const file = fs.readFileSync(pathedDir[i], 'utf-8');
  const firstLine = `const char *${inputDir[i].toUpperCase().split('.').join('_')} = (`;
  const splittedFile = file.split('\n').filter(line => line != "");
  const centerLine = splittedFile.map(line => `  "${line}\\n"`).join('\n');
  const lastLine = `);`;

  let outputFile = `${firstLine}\n${centerLine}\n${lastLine}`;
  fs.writeFileSync(`${targetFolder}/${inputDir[i]}.h`, outputFile, 'utf-8');
}

