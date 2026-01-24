$tag = "v1.0.0-beta"
$url = "https://github.com/sajjadahmed8269/matrix-solver-c/releases/download/v1.0.0-beta/matrix-solver.exe"
$installDir = "$HOME\matrix-solver-test"
$exePath = "$installDir\matrix-solver.exe"

Write-Host "⚠️  Installing Test Version ($tag)..." -ForegroundColor Yellow

# Create test folder
if (!(Test-Path $installDir)) { New-Item -ItemType Directory -Path $installDir }

# Download the file
try {
    Invoke-WebRequest -Uri $url -OutFile $exePath -ErrorAction Stop
} catch {
    Write-Host "❌ Download failed. Check your internet connection and try again." -ForegroundColor Red
    return
}

# Add to User PATH
$oldPath = [Environment]::GetEnvironmentVariable("Path", "User")
if ($oldPath -notlike "*$installDir*") {
    [Environment]::SetEnvironmentVariable("Path", "$oldPath;$installDir", "User")
    Write-Host "✨ Added to PATH. Please RESTART your PowerShell window." -ForegroundColor Cyan
}

Write-Host "✅ Beta Installation Complete!" -ForegroundColor Green