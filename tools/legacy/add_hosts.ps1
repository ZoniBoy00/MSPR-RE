$hosts = "C:\Windows\System32\drivers\etc\hosts"
$needed = @(
    "192.0.2.10 svo.psrewired.com",
    "192.0.2.10 motorstorm2ps3.online.scee.com",
    "192.0.2.10 api.psrewired.com",
    "192.0.2.10 natservice.pdonline.scea.com",
    "192.0.2.10 title.pdonline.scea.com"
)
$current = Get-Content $hosts -Raw
$added = @()
foreach ($e in $needed) {
    if ($current -notmatch [regex]::Escape(($e -split " ")[1])) {
        Add-Content $hosts $e
        $added += $e
    }
}
Write-Output "added: $($added -join '; ')"
ipconfig /flushdns | Out-Null
Write-Output "done"
