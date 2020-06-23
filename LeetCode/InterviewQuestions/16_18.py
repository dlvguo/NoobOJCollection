class Solution:
    def patternMatching(self, pattern: str, value: str) -> bool:
        if not pattern: return not value
        if len(pattern) == 1: return True

        # 构造正则表达式：重点是正则表达式的“后向引用”
        rega, regb = ('\\1', '\\2') if pattern[0] == 'a' else ('\\2', '\\1')
        p = pattern.replace('a', '(\\w*)', 1).replace('b', '(\\w*)', 1).replace('a', rega).replace('b', regb)
        p = '^' + p + '$'
        m = re.match(p, value)

        # 匹配到 && (模式长度为1 || 模式长度为2 && 两个模式不相同)
        return bool(m and (len(m.groups()) == 1 or m.groups()[0] != m.groups()[1]))

