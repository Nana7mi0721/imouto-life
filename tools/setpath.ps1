
$dirs = @(
  'E:\Study\github program\Imouto Life\tools\bin',
  'E:\Study\github program\Imouto Life\tools\cmake\bin',
  'E:\Study\github program\Imouto Life\tools\ffmpeg\bin',
  "$env:USERPROFILE\.cargo\bin"
)
$cur = [Environment]::GetEnvironmentVariable('Path','User'); if ($null -eq $cur) { $cur='' }
$parts = $cur -split ';' | Where-Object { $_ -ne '' }
foreach ($p in $dirs) { if ($parts -notcontains $p) { $parts += $p; Write-Output "ADDED=$p" } }
[Environment]::SetEnvironmentVariable('Path', ($parts -join ';'), 'User')
Write-Output "FINAL=$([Environment]::GetEnvironmentVariable('Path','User'))"
