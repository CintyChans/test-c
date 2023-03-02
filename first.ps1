 "json<<EOF" >> $env:GITHUB_ENV
 ( cat releasenotes.md )>> $env:GITHUB_ENV
 "EOF" >> $env:GITHUB_ENV
