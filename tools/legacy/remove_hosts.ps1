$hosts = "C:\Windows\System32\drivers\etc\hosts"
$lines = Get-Content $hosts | Where-Object { $_ -notmatch "svo\.psrewired\.com|motorstorm2ps3\.online\.scee\.com|api\.psrewired\.com" }
Set-Content $hosts $lines
ipconfig /flushdns | Out-Null
Write-Output "removed and flushed"
