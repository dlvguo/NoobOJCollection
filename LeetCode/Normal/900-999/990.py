class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        f = {chr(ord('a') + c) : -1 for c in range(26)}
        def find(c):
            while f[c] != -1:
                c = f[c]
            return c
        for i in range(len(equations)):
            eq = equations.pop(0)
            if eq[1:-1] == '!=':
                equations.append(eq)
                continue
            f1, f2 = find(eq[0]), find(eq[-1])
            if f1 != f2:
                f[f2] = f1
        for eq in equations:
            f1, f2 = find(eq[0]), find(eq[-1])
            if f1 == f2:
                return False
        return True             
