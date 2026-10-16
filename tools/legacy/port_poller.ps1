# Port poller: catch which ports the game SYN-sends to 192.0.2.10
# Run this, then try going online in the game.
Write-Host "polling connections to 192.0.2.10 (20s)..." -ForegroundColor Cyan
$end = (Get-Date).AddSeconds(20)
$seen = @{}
while ((Get-Date) -lt $end) {
    $lines = netstat -ano | Select-String "192.0.2.10"
    foreach ($l in $lines) {
        $k = $l.Line.Trim()
        if (-not $seen[$k]) {
            $seen[$k] = $true
            Write-Host $k
        }
    }
}
Write-Host "done. paste the output above."
