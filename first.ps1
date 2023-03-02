 "json<<EOF" >> $env:GITHUB_ENV
 ( cat releasenotes.txt )>> $env:GITHUB_ENV
 "EOF" >> $env:GITHUB_ENV
