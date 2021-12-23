start /wait Debug\CalculatorClient.exe
if %ErrorLevel% equ 0 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a F
if %ErrorLevel% equ 0 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Add -s 6
if %ErrorLevel% equ 0 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Add -f 5
if %ErrorLevel% equ 0 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Add -f 5 -s 6
if %ErrorLevel% equ 11 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Sub -f 7 -s 2
if %ErrorLevel% equ 5 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Div -f 8 -s 2
if %ErrorLevel% equ 4 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Mul -f 2 -s -2
if %ErrorLevel% equ -4 (echo True) else (echo False)
start /wait Debug\CalculatorClient.exe -a Add -f Fd -s 7
if %ErrorLevel% equ -1 (echo True) else (echo False)
set /p=Hit ENTER to continue...