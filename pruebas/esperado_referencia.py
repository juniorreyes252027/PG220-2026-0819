"""Calcula a mano (en Python) las salidas esperadas de las pruebas propias.
Sirve para contrastar con el programa en C. No es parte de la solucion."""
import sys, re
def resolver(texto):
    t = texto.split()
    try:
        n, m, q = int(t[0]), int(t[1]), int(t[2]); pos = 3; regs = []
        if not (1<=n<=20 and 1<=m<=8 and 1<=q<=9999): return "ERROR\n"
        for _ in range(n):
            id_, nom, tipo, p = int(t[pos]), t[pos+1], int(t[pos+2]), int(t[pos+3]); pos += 4
            xs = [int(v) for v in t[pos:pos+m]]; pos += m
            if len(xs) < m: return "ERROR\n"
            if not (1<=id_<=9999 and re.fullmatch(r"[A-Za-z0-9_]{1,15}", nom)
                    and tipo in (0,1) and 0<=p<=100 and all(0<=v<=100 for v in xs)):
                return "ERROR\n"
            regs.append((id_, nom.upper(), tipo, p, xs))
    except (IndexError, ValueError):
        return "ERROR\n"
    if len({r[0] for r in regs}) != n: return "ERROR\n"
    out, sc = [], {}
    for id_, nom, tipo, p, xs in regs:
        s = sum(1 for i in range(m) for j in range(i+1, m)
                if (xs[i] > xs[j]+p if tipo == 0 else xs[j] > xs[i]+p))
        sc[id_] = s; out.append(f"{id_} {nom} {s} {1 if s == 0 else 0}")
    out.append(f"TOTAL {sum(sc.values())}")
    out.append("ORDER " + " ".join(str(i) for i in sorted(sc, key=lambda k: (-sc[k], k))))
    out.append(f"FIND {q} {sc.get(q, -1)}")
    return "\n".join(out) + "\n"
if __name__ == "__main__":
    for f in sys.argv[1:]:
        open(f.replace(".in", ".out"), "w").write(resolver(open(f).read()))
