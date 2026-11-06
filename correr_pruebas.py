"""Ejecuta cada pruebas/*.in con el programa, guarda pruebas/*.obtenido
y compara con pruebas/*.out. Uso: python3 correr_pruebas.py ./reto
En Windows: py correr_pruebas.py reto.exe"""
import subprocess, sys
from pathlib import Path
exe = str(Path(sys.argv[1]).resolve())
ok = total = 0
for entrada in sorted(Path("pruebas").glob("*.in")):
    esperado = entrada.with_suffix(".out").read_text(encoding="utf-8")
    r = subprocess.run([exe], input=entrada.read_text(encoding="utf-8"),
                       text=True, capture_output=True, timeout=2)
    entrada.with_suffix(".obtenido").write_text(r.stdout, encoding="utf-8")
    pasa = r.returncode == 0 and r.stdout.split() == esperado.split()
    total += 1; ok += pasa
    print(entrada.stem, "OK" if pasa else "FALLO")
print("Pruebas correctas:", ok, "/", total)
sys.exit(0 if ok == total else 1)
