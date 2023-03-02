 "json<<EOF" >> $env:GITHUB_ENV
 (Invoke-WebRequest -Uri "https://example.com").Content >> $env:GITHUB_ENV
 "EOF" >> $env:GITHUB_ENV